# Race01
A program that decodes all valid variations of an encrypted math expression.\
The program takes four arguments:\
• integer operands:operand1 and operand2\
• operationoperation\
• result of the math operation result\
Encoder must support four math operations: addition + , subtraction - , multiplication *  and division / . \
Operands and the result may consist of hidden digits marked by?character.\
One digit per one ? . The program must not print zeros if they are before afull number.\
The program finds out which digits are hidden by ? in order to maintain a mathematical expression valid. \
It outputs all valid variations (one per line).\
Valid expressions in output must be sorted in ascending order of operand1.\
Operands, operations, equal sign and the result in output are separated by a single space character.\
Error handling. The program prints errors to the standard error streamstderr:\
• if the number of arguments is not equal to 4, the program prints: usage: ./part_of_the_matrix [operand1] [operation] [operand2] [result]\
• in case of invalid operation the program prints: Invalid operation: <value>\
• in case of invalid operands the program prints: Invalid operand: <value>\
• in case of invalid operation the program prints: Invalid result: <value>

# In addition:
The program also implements calculations, when we have ? in operation. It find all necessary results and sort them in such order: + - * / .\
Also, the program supports ? in operands and result, but with some restrictions:\
it works, when we do not separate ? in operands or result, \
Correct e.g. : "1??3" "??9" "123?" "12?????3" etc.\
Incorrect e.g. : "?1?" "12??3?" "1?23??4?9" etc.
