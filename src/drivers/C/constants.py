NEW_LINE = "\n"
SEMI_COLON = ";"
COMMA = ","
DOT = "."
EQUAL = "="
STAR = "*"

INCLUDE = "#include \"{headerFileName}\""
ASSERT = "assert({value1} == {value2})" + SEMI_COLON + NEW_LINE

ROUND_BRACKET_OPEN = "("
ROUND_BRACKET_CLOSE = ")"

OPEN_BRACE = "{"
CLOSE_BRACE = "}"

INT_DEC_INIT = "int {variableName} = {value}" + SEMI_COLON + NEW_LINE
STRUCT_DEC_INIT = "struct {structType} {variableName} = {value}" + SEMI_COLON + NEW_LINE
PRIMITIVE_POINTER_DEC = "{dataType}* {variableName} = ({dataType}*) malloc(sizeof({dataType}))" + SEMI_COLON + NEW_LINE
STRUCT_POINTER_DEC = "struct {dataType}* {variableName} = (struct {dataType}*) malloc(sizeof(struct {dataType}))" + SEMI_COLON + NEW_LINE
STRUCT_POINTER_INIT = "*{variableName} = (struct {dataType}) {value}" + SEMI_COLON + NEW_LINE
