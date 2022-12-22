.MODEL SMALL
.STACK
.DATA 

	;Your data items 
	BUFFER DB 255 DUP ('$')
	CURRENT DB 255 DUP('$')
	CLEAN_TEXT DB 255 DUP('$')
	IDX DW 0

.CODE 
	
	;-----------------------------
	; Remove duplicate words
	; "Every Every thing is good, right right?" --> "Every thing is good, right?"
	REMOVE_DUP PROC 

		LEA SI, FINAL_OUTPUT
		CHECK:
			CMP BYTE PTR [SI], '$'
			JZ EXIT
			CALL GET_NEXT_WORD
			PUSH SI
			CALL COMPARE
			CMP DL, 1
			JZ NEXT
			
			; MOVE WORD TO CLEAN_TEXT
			CALL MOVE_TO_CLEAN

			NEXT:
				
				LEA DI, BUFFER
				CALL CLEAR_VAR
				CALL COPY_TO_BUFFER
				
				LEA DI, CURRENT
				CALL CLEAR_VAR
				
				POP SI
				; MOV NON-ALPHA CHARACTERS TO CLEAN AND INC SI
				CALL MOVE_NON_ALPHA
				
				JMP CHECK
					
		EXIT:
			LEA SI, CLEAN_TEXT
			MOV BX, 255
			CALL SAVE_TEXT
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
			MOV AL, [SI]
			MOV [BX], AL
			INC SI
			INC BX
			JMP FINISH
			
		DONE:
			DEC SI
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
		
	;-----------------------------------
	
	MOVE_TO_CLEAN PROC
		LEA DI, CURRENT
	
		CONTINUE:
			MOV BX, IDX
			CALL CHECK_ALPHA
			CMP DL, 1
			JNZ ISDONE
			MOV AL, [DI]
			MOV CLEAN_TEXT[BX], AL
			INC IDX
			INC DI
			
			JMP CONTINUE
		
		ISDONE:
			RET
	MOVE_TO_CLEAN ENDP
		
	;-----------------------------------
	
	MOVE_NON_ALPHA PROC
		INC SI
		CHECKING:
			CMP BYTE PTR [SI], '$'
			JZ GOEXIT
			MOV BX, IDX
			MOV DI, SI
			CALL CHECK_ALPHA
			CMP DL, 1
			JZ GOEXIT
			MOV AL, [SI]
			MOV CLEAN_TEXT[BX], AL
			INC IDX
			INC SI
			JMP CHECKING
		
		GOEXIT:
			RET
	MOVE_NON_ALPHA ENDP