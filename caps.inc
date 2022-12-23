.MODEL SMALL
.DATA

FLAG DW 1

.CODE

CAPITAL_SMALL PROC 

	LEA DI, FINAL_OUTPUT
	mov FLAG , 1

	Next1:
		CMP BYTE PTR [DI], '$' ; Return from function if the end of string
		JZ Z
		
		CALL CHECK_ALPHA	
		CMP DL, 1
		JZ B				; If the current char is alpha, jmp to check it
		
		CALL CHECK_DOT		; Check if the current char is dot, if so, it sets FLAG, clear it otherwise
		JMP A
		
		B:
			CMP FLAG, 1		
			JE TO_CAPITAL	; If the last char was dot, then make the current char capital, small otherwise
			TO_SMALL:
				CALL SMALL_LETTER
				JMP A
			TO_CAPITAL:
				CALL CAPITAL_LETTER
				MOV FLAG, 0
				
		A:	  
			INC DI
			JMP Next1
			
		Z:
			RET
			
CAPITAL_SMALL ENDP  


;--------------------------------------------------

SMALL_LETTER PROC ; Converting letter to small

	OR BYTE PTR [DI],00100000B
	RET
	
SMALL_LETTER ENDP

;------------------------------------------------------

CAPITAL_LETTER PROC ; Converting letter to capital

	AND BYTE PTR [DI],11011111B
	RET
	
CAPITAL_LETTER ENDP

;------------------------------------------------------

CHECK_DOT PROC	; if current char is dot, Set the FLAG variable to 1, 0 otherwise
	CMP FLAG, 1
	JE ISDOT
	
	MOV FLAG, 1
	CMP BYTE PTR [DI], '.'
	JE ISDOT
	MOV FLAG, 0
	
	ISDOT:
		RET
CHECK_DOT ENDP
