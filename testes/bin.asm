section    		DATA
dois: CONST 2;numero2
OLD_DATA: space
new_DATA: SPACE
TMP_DATA: SPACE
SECTION TEXT;comentario1
INPUT old_data
load OLD_DATA
L1: DIV DOIS;comentario2
STORE  new_data;comentario3
mult  DOIS;comentario4
store TMP_DATA
LOAD OLD_DATA
SUB tmp_DATA;comentario5
STORE     TMP_data;comentario6
output    TMP_DATA

copy NEW_DATA,OLD_DATA
LOAD OLD_DATA
JMPP L1

stop