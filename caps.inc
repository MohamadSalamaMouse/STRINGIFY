.MODEL SMALL



.CODE
CAPITAL_SMALL PROC 


   ; CALL POINT
    LEA si, FINAL_OUTPUT
    mov bx,0
    MOV AH,02H

Next1:
    ; Make frist letter in paragraph capital letter
    
    CMP BX,0
    JNE B
        MOV DL,[SI+BX];LETTERS
        AND DL,11011111B
		MOV [SI+BX],DL
        ;--INT 21H 
        INC BX
    B:
   
    ;MOV DL,[SI+BX];LETTERS
    CALL SMALL_LETTER
  ;---  INT 21H
     ;condition to know beginning of each sentence
    CMP DL,'.'
    JNE A
        CALL CAPS
    A:
  
  
    INC     bx
    CMP     bx, TEXT_LEN
    JNE     Next1
   
  

      ;SMALL METHOD CONVERT CAPTIAL LETTER TO SMALL LETTER
      ;--------------------------------------------------
    SMALL_LETTER PROC NEAR
        OR [si + bx],00100000B
        MOV     DL,[si + bx]
        RET
    SMALL_LETTER ENDP
     ;to make capital letter at the beginning of each sentence
     ;------------------------------------------------------
    CAPS PROC NEAR
     INC     bx
     MOV DL,[SI+BX];LETTERS
     AND DL,11011111B
	 MOV [SI+BX],DL
    ;--- INT 21H 
    RET 
    CAPS ENDP
    ;move postion of pointer
    ;---------------------
    POINT PROC NEAR
      mov dh, 0
      mov dl, 0
      mov bh, 0
      mov ah, 2
      int 10h
      RET
      POINT ENDP

