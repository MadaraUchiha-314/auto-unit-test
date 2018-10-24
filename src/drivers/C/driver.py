import json
import sys
from constants import *

# Suite to test
suite = sys.argv[1]

# Since its a C-Driver it knows its template file.
template = "src/drivers/C/template.c"

# Whether we should reuse variable names.
reuse_variables = False
variable_name_prefix = "var_"
current_variable_index = -1

# TODO: Convert this to a generator
def get_next_variable() :
    global current_variable_index
    current_variable_index += 1
    return variable_name_prefix + str(current_variable_index)

# Below are various functions to generate strings of various parts of the code.

# Generate the header files string in C style given a list of header files.
def generate_header_files(list_of_headers) :
    # This will be the final string that contains all the header files for the test case.
    header_file_string = ""
    for headerFile in list_of_headers :
        header_file_include = INCLUDE.format(headerFileName=headerFile) +  NEW_LINE
        # Appending to the header files string
        header_file_string += header_file_include
    return header_file_string

def is_primitive(value) :
    try :
        _ = value["type"]
    except :
        return True
    return False

def is_pointer(value) :
    try :
        if value["type"][-1] == STAR :
            return True
        else :
            return False
    except :
        return False

def get_pointer_data_type(value) :
    return value["type"][:-1] # Removing the * from the Pointer

# Given an argument whether its a primitive type or a struct, it will construct it.
# Things to keep in mind :
# Nested structs.
# Self-Referential structs.
def construct_argument(argument, top_level=True) :
    arg_init = ""
    arg_string = ""
    # First lets find out if the argument is primitive or not.
    if not is_primitive(argument) :
        # Not a primitive argument.
        for key in argument["value"] :
            np_arg_init, np_arg_string = construct_argument(argument["value"][key], False)
            arg_init += np_arg_init
            arg_string += DOT + key + EQUAL + np_arg_string + COMMA
        arg_string = arg_string[:-1] # Removing the comma
        # We will add the opening and closing braces now.
        arg_string = OPEN_BRACE + arg_string + CLOSE_BRACE
        if not top_level :
            if is_pointer(argument) :
                var_name = get_next_variable()
                pointer_variable_dec = STRUCT_POINTER_DEC.format(dataType=get_pointer_data_type(argument), variableName=var_name)
                pointer_variable_init = POINTER_INIT.format(variableName=var_name,value=arg_string)
                arg_init += pointer_variable_dec + pointer_variable_init
            return arg_init, var_name
        else :
            if is_pointer(argument) :
                var_name = get_next_variable()
                pointer_variable_dec = STRUCT_POINTER_DEC.format(dataType=get_pointer_data_type(argument), variableName=var_name)
                pointer_variable_init = STRUCT_POINTER_INIT.format(variableName=var_name,value=arg_string, dataType=get_pointer_data_type(argument))
                arg_init += pointer_variable_dec + pointer_variable_init
                return arg_init, var_name
            else :
                var_name = get_next_variable()
                arg_init += STRUCT_DEC_INIT.format(structType=argument["type"], variableName=var_name, value=arg_string)
                return arg_init, var_name
    else :
        # Primitive argument.
        # Now, now. What are the primitive values in C ???
        if type(argument) is int :
            var_name = get_next_variable()
            arg_init += INT_DEC_INIT.format(variableName=var_name, value=argument)
            arg_string += var_name
        else :
            raise ValueError("Could not resolve the primitive data type")
    return arg_init, arg_string

# Generates a function call string for the given function name and given arguments.
def generate_function_call(function_name, arguments) :
    function_call_string = ""
    arguments_string = ""
    arguments_init_string = ""

    # Now we will add the arguments one by one.
    # There are 2 cases.
    # One that the argument is primitive.
    # Second that the argument is non-primitive (struct).
    for argument in arguments :
        # Returns the initialised arguments and the
        argument_init_string, argument_string = construct_argument(argument)
        arguments_string += argument_string + COMMA
        arguments_init_string += argument_init_string

    # We will add the function name, opening bracket, arguments, opening bracket.
    function_call_string += function_name + ROUND_BRACKET_OPEN + arguments_string[:-1] + ROUND_BRACKET_CLOSE

    return arguments_init_string, function_call_string

def construct_return_value(function_call_string, value) :
    var_name = get_next_variable()
    return_value_string = ""
    if not is_primitive(value) :
        return_value_string = STRUCT_DEC_INIT.format(structType=value["type"], variableName=var_name, value=function_call_string)
    else :
        if type(value) is int :
            return_value_string = INT_DEC_INIT.format(variableName=var_name, value=function_call_string)
        else :
            raise ValueError("Could not resolve the primitive data type")
    return var_name, return_value_string

def wrap_with_assert(return_variable, return_value) :
    assert_string = ""
    if not is_primitive(return_value) :
        # Not a primitive value.
        # We recurse until we find a leaf node and do assert on that.
        for key in return_value["value"] :
            assert_string += wrap_with_assert(return_variable + DOT + key, return_value["value"][key])
    else :
        if type(return_value) is int :
            assert_string = ASSERT.format(value1=return_variable, value2=return_value)
        else :
            raise ValueError("Could not resolve the primitive data type")
    return assert_string


def generate_single_test(test) :
    arguments_init_string, function_call_string = generate_function_call(test["function-name"], test["arguments"])
    return_var_name, return_value_string = construct_return_value(function_call_string, test["return-value"])
    arguments_init_string += return_value_string
    return arguments_init_string, wrap_with_assert(return_var_name, test["return-value"])

def generate_tests(test_cases) :
    test_cases_string = ""
    for test in test_cases :
        arg_init, assert_string = generate_single_test(test)
        test_cases_string += arg_init
        test_cases_string += assert_string
    return test_cases_string

def parse_input(input_file_name) :
    test = {}
    with open(input_file_name, "r") as input_file :
        test = json.load(input_file)
    return test

def generate_program(test) :
    headers = generate_header_files(test["includes"])
    body = generate_tests(test["test-cases"])
    with open(template, "r") as template_file :
        template_program = template_file.read()
        template_program = template_program.format(
            headerFiles=headers,
            programBody=body,
            openingBrace=OPEN_BRACE,
            closeingBrace=CLOSE_BRACE
        )
        return template_program

def write_program_to_file(program, file_name) :
    with open(file_name, "w") as program_file :
        program_file.write(program)

def driver():
    test = parse_input(suite)
    program = generate_program(test)
    location_to_write = suite.replace(".json", ".c")
    write_program_to_file(program, location_to_write)

if __name__ == "__main__" :
    driver()
