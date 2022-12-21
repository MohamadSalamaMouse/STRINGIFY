.MODEL SMALL
.DATA
MSG db "often  time time  in lIfE, What is easy to  do is not worth worth it.suRe,crashing on the  couch and watcHing the the newest// episode of your favorite show is A  pleasuRable exPerience.but it is bad   input and it it it will not not help you   adVance much in the rOAd to  success.",0
LEN equ  $ - MSG
.CODE
CAPITAL_SMALL PROC FAR
.STARTUP
    LEA si, MSG
    
    mov bx,0
    MOV AH,02H

Next:
    ; Make frist letter in paragraph capital letter
    CMP BX,0
    JNE B
        MOV DL,[SI+BX];LETTERS
        AND DL,11011111B
        INT 21H 
        INC BX
    B:
   
    ;MOV DL,[SI+BX];LETTERS
    CALL SMALL_LETTER
    INT 21H
     ;condition to know beginning of each sentence
    CMP DL,'.'
    JNE A
        CALL CAPS
    A:
  
  
    INC     bx
    CMP     bx, LEN
    JNE     Next
    
    
    .EXIT
CAPITAL_SMALL ENDP
      ;SMALL METHOD CONVERT CAPTIAL LETTER TO SMALL LETTER
    SMALL_LETTER PROC NEAR
        OR [si + bx],00100000B
        MOV     DL,[si + bx]
        RET
    SMALL_LETTER ENDP
     ;to make capital letter at the beginning of each sentence
    CAPS PROC NEAR
     INC     bx
     MOV DL,[SI+BX];LETTERS
     AND DL,11011111B
     INT 21H 
    RET 
    CAPS ENDP
    
END CAPITAL_SMALL