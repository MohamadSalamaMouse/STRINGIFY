include caps.inc 
;include dups.inc
include spaces.inc

.MODEL small

.DATA       

text DB "time  !tIMe  in lIfE   ,What  is  ea    .sy to   do is not  worth      worth?it ",'$'
HELLO_LEN equ  $ - text
TIT DB 'Natural-Language-Processing ',10,13,'$'
;PROCESSING1 DB 'beginning of the sentence is a capital letter and the rest of the sentence is lowercase: ',10,13,'$'  
 
AddSpaceOutput DB ?
;RemoveSpaceOutput DB ? 

 

.CODE 
 
    MAIN PROC FAR
        .STARTUP
        LEA DX,TIT
        CALL PRINT
        ;LEA DX,PROCESSING1
       ;CALL PRINT
        call CAPITAL_SMALL
        call REMOVE_SPACES
        call ADD_SPACES
       

            
        .EXIT
       
    MAIN ENDP
    ;------------Print function
    PRINT PROC NEAR
    MOV AH,09H
    INT 21H
    RET
    PRINT ENDP
    
END MAIN