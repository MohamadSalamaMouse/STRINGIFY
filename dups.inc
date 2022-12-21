.MODEL SMALL
.STACK
.DATA 

	;Your data items 
	BUFFER DB 255 DUP ('$')
	CURRENT DB 255 DUP('$')
	CLEAN_TEXT DB 255 DUP(0)
	IDX DB 0

.CODE 
	
	;-----------------------------
	; Remove duplicate words
	; "Every Every thing is good, right right?" --> "Every thing is good, right?"
	REMOVE_DUP PROC 

		LEA SI, TEXT
		LEA IDX, CLEAN_TEXT
		CHECK:
			CMP BYTE PTR [SI], '$'
			JZ EXIT
			CALL GET_NEXT_WORD
			PUSH SI
			CALL COMPARE
			CMP DL, 1
			JZ NEXT
			
			; MOVE WORD TO CLEAN_TEXT
			
			NEXT:
				
				LEA DI, BUFFER
				CALL CLEAR_VAR
				CALL COPY_TO_BUFFER
				
				LEA DI, CURRENT
				CALL CLEAR_VAR
				
				POP SI
				; MOV NON-ALPHA CHARACTERS TO CLEAN AND INC SI
				ADD SI, 2
				
				JMP CHECK
					
		EXIT:
			RET
		
	REMOVE_DUP ENDP
	
	;-----------------------------------
	
	GET_NEXT_WORD PROC ; store the next word in CURRENT, expect to find the first character of the word in SI
		MOV DI, SI
		LEA BX, CURRENT
		CONT:
			CALL CHECK_ALPHA
			CMP DL, 1
			JNZ FINISH
			INC DI
			JMP CONT
			
		FINISH:
			CMP SI, DI
			JE DONE
			MOV AX, [SI]
			MOV [BX], AX
			INC SI
			INC BX
			JMP FINISH
			
		DONE:
			RET
	GET_NEXT_WORD ENDP
	
	;-----------------------------------
	
	CHECK_ALPHA PROC ;Check if the currnet char is alphabet, IF ALPHA --> DL = 1, OTHERWISE DL = 0
		MOV DL, 1
		CMP BYTE PTR [DI], 'A'
		JL NOT_FOUND
		CMP BYTE PTR [DI], 'Z'
		JLE TOEND
		
		CMP BYTE PTR [DI], 'a'
		JLE NOT_FOUND
		CMP BYTE PTR [DI], 'z'
		JLE TOEND
		
		NOT_FOUND:
			MOV DL, 0
			DEC DI

		TOEND:
			RET
			
	CHECK_ALPHA ENDP
	
	;-----------------------------------
	
	CLEAR_VAR PROC ; Clear variable -> Excpect to find the first character in DI

		MOV CX, 255
		CLR:
			MOV BYTE PTR [DI], '$'
			INC DI
			LOOP CLR

		RET
	CLEAR_VAR ENDP
	
	;-----------------------------------
	
	COMPARE PROC ; Compare CURRENT and BUFFER, IF EQUAL -> DL = 1, OTHERWISE, DL = 0
		MOV DL, 1
		LEA SI, CURRENT
		LEA DI, BUFFER
		MOV CX, 255
		COMP:
			MOV AL, [SI]
			CMP AL, [DI]
			JNE NOT_EQ
			INC SI
			INC DI
			LOOP COMP
		RET
			
		NOT_EQ:
		MOV DL, 0
			RET
			
	COMPARE ENDP
		
	;-----------------------------------
	
	COPY_TO_BUFFER PROC
		LEA SI, CURRENT
		LEA DI, BUFFER
		MOV CX, 255
		CLD
		REP MOVSB
		
		RET
	COPY_TO_BUFFER ENDP