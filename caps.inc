.model small
.data 

	;Your data items
	
	hi_caps db "Hello from caps.inc",10,13,"$" ; Remove this
	
.code 
	
	TEST_PROC_CAPS PROC ; Remove this proc
	
		LEA DX, hi_caps
		MOV AH, 9 		
		INT 21h 		
		ret
	TEST_PROC_CAPS ENDP
	
	;-----------------------------

	; Capitalize the first character of every line
	; "every thing. is good. Right?" --> "Every thing. Is good. Right?"
	CAPITALIZE PROC

		;Your code
		ret
		
	CAPITALIZE ENDP

	;-----------------------------

	; Lower case the rest of the sentence
	; "EVEry tHing IS goOD, right?" --> "Every thing is good, right?"
	LOWER PROC

		;Your code
		ret
		
	LOWER ENDP