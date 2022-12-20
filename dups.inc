.model small
.data 

	;Your data items 
	
	hi_dups db "Hello from dups.inc",10,13,"$" ; Remove this

.code 

	TEST_PROC_DUPS PROC ; Remove this proc
	
		LEA DX, hi_dups
		MOV AH, 9 		
		INT 21h 		
		ret
	TEST_PROC_DUPS ENDP
	
	;-----------------------------
	; Remove duplicate words
	; "Every Every thing is good, right right?" --> "Every thing is good, right?"
	REMOVE_DUP PROC 

		;Your code
		ret
		
	REMOVE_DUP ENDP

