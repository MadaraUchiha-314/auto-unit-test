from constants import *

# We have to extend this function when we want to support type-casting as our auto-inference will fail.
def is_primitive(value) :
    try :
        _ = value["type"]
        # This means that its either forced cast or a pointer to a primitive type.
        # These are all the cases that I can think of right now.
        if value["type"].split()[-1][:-1] in PRIMITIVES :
            return True
    except :
        return True
    return False

def get_primitive_type_from_json(value) :
    try :
        return value["type"]
    except :
        return None

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

def get_primitive_data_type(data) :
    if type(data) is int :
        return "int", data
    elif type(data) is unicode and len(data) == 1 :
        # C supports only char as the primitive data type
        return "char", "\'{data}\'".format(data=data)
    elif type(data) is float :
        # Both float and double can be cast to double
        return "double", data
    else :
        return None, data

# It returns a tuple of (is_primitive, is_pointer, data_type, value)
def get_value_details(value) :
    try :
        # There are many cases here :
        # Can be a struct, pointer to struct or pointer to primitive.
        _ = value["type"]
        if is_pointer(value) :
            if is_primitive(value) :
                _, data = get_primitive_data_type(value["value"])
                return True, True, get_pointer_data_type(value), data
            else :
                return False, True, get_pointer_data_type(value), value["value"]
        else :
            if is_primitive(value) :
                data_type, data = get_primitive_data_type(value["value"])
                return True, False, data_type, data
            else :
                return False, False, value["type"], value["value"]
    except :
        # This means that its a primitive non-pointer data type
        data_type, data = get_primitive_data_type(value)
        return True, False, data_type, data
