    SECTION DATA 
DOIS: CONST 2 
OLD_DATA:        SPACE;Comentário 1
NEW_DATA: space
TMP_DATA: SPACE
;Comentário 2
SECtION TEXT
INPUT       OLD_DATA

 
    
load old_data 

L1:   

L2: DIV DOIS
STORE                         NEW_DATA
  MULT DOIS
STORE TMP_DATA
LOAD OLD_DATA
SUB TMP_DATA
STORE TMP_DATA
OUTPUT TMP_DATA
COPY NEW_DATA,OLD_DATA
LOAD OLD_DATA
JMPP L1
STOP
;Comentário 3
;


;Comentário 4