NEW_LINE = "\n"
SEMI_COLON = ";"
COMMA = ","
DOT = "."
EQUAL = "="
STAR = "*"
ARROW = "->"

INCLUDE = "#include \"{headerFileName}\""
ASSERT = "assert({value1} == {value2})" + SEMI_COLON + NEW_LINE

ROUND_BRACKET_OPEN = "("
ROUND_BRACKET_CLOSE = ")"

OPEN_BRACE = "{"
CLOSE_BRACE = "}"

# These are primitive data types and there can be modifiers built on top of these.
# Like short int, long int, unsigned long int etc.
PRIMITIVES = ["char", "int", "float", "double"]

PRIMITIVE_DEC_INIT = "{dataType} {variableName} = {value}" + SEMI_COLON + NEW_LINE
INT_DEC_INIT = "int {variableName} = {value}" + SEMI_COLON + NEW_LINE
STRUCT_DEC_INIT = "struct {structType} {variableName} = {value}" + SEMI_COLON + NEW_LINE

PRIMITIVE_POINTER_DEC = "{dataType}* {variableName} = ({dataType}*) malloc(sizeof({dataType}))" + SEMI_COLON + NEW_LINE
PRIMITIVE_POINTER_INIT = "*{variableName} = {value}" + SEMI_COLON + NEW_LINE

STRUCT_POINTER_DEC = "struct {dataType}* {variableName} = (struct {dataType}*) malloc(sizeof(struct {dataType}))" + SEMI_COLON + NEW_LINE
STRUCT_POINTER_INIT = "*{variableName} = (struct {dataType}) {value}" + SEMI_COLON + NEW_LINE

TEST_CASE_HEADER = NEW_LINE + "/* TEST CASE START : # {testCaseNumber} */" + NEW_LINE
TEST_CASE_FOOTER = "/* TEST CASE END : # {testCaseNumber} */" + NEW_LINE
