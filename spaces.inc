.model small
.data 
	beforeR DB 'text before removing spaces was: ',10,13,'$'  
	afterR DB 'text after removing spaces was: ',10,13,'$' 
	beforeD DB 'text before adding spaces was: ',10,13,'$'  
	afterD DB 'text after adding spaces was: ',10,13,'$'  	
.code



;--------------------------------------------------------------------------
;1- Remove extra white spaces from the whole text
; "Every   thing is	 good,  right?" --> "Every thing is good, right?"

	REMOVE_SPACES PROC far
	
		LEA DX , beforeR	
		mov ah , 09
		int 21h
	
	    LEA DX , text   
		mov ah , 09
        int 21h

		;mov   ax,SEG text
		;mov   ds,ax
		;mov   es,ax
		;mov   si,OFFSET text
		;mov   di,si
		;mov   bx,si

		;source
		mov   ax,SEG text
		mov   ds,ax
		mov   si,OFFSET text
		;destination
		mov   ax,SEG text
		mov   es,ax
		mov   di,OFFSET text
		mov   bx,di
		
		; ds:si = source pointer to read char by char
		; es:di = destination pointer to write modified string
		; bx = text pointer for compare during second phase
		
	xor   cx,cx  ; cx = 0, counts spaces to copy
	copyLoop:
		lodsb   ; 		inc si 	then	mov al , ds:[si]
		cmp   al,'$'
		je    terminate1
		cmp   al,' '
		jne   noSpace
		jcxz  copyLoop  ; no more spaces allowed to copy, skip
		; copy the space
		dec   cx        ; --allowed
		stosb           ; es:[di++] = al
		jmp   copyLoop

	noSpace:
		mov   cx,1      ; one space can be copied next time
		stosb           ; copy the not-space char
		jmp   copyLoop

	terminate1:
		cmp   di,bx
		je    emptyStringResult
		
		;dec   di
		;cmp   BYTE PTR [di],' '
		;je    removeTrailingSpaces
		;inc   di        ; not-space found, write '#' after it
	emptyStringResult:
		stosb           ; write the '#' at final position
	
		
		LEA DX , afterR	
		mov ah , 09
		int 21h
		
		LEA DX , text	
		mov ah , 09
		int 21h
		
		ret
		
	REMOVE_SPACES ENDP

;--------------------------------------------------------------------------
;2- Add white space after punctuations [',', '.', '!', '?']
;"Every,thing.is good?right." --> "Every, thing. is good? right."

	 ADD_SPACES PROC far
	 
	 	LEA DX , beforeD	
		mov ah , 09
		int 21h
		
		LEA DX , text	
		mov ah , 09
		int 21h
		
		LEA SI, text ; Initialize SI to point to the start of the string
		LEA DI, AddSpaceOutput ; Initialize DI to point to the start of the output
		
	loopp:	
		MOV AL, [SI] ; Get the character from string 1
		
		CMP AL, ',' ; Check if the character is a comma
		JE ADDSPACE ; If it is, jump to adding a space
		CMP AL, '!' ; Check if the character is a comma
		JE ADDSPACE ; If it is! jump to adding a space
		CMP AL, '?' ; Check if the character is a comma
		JE ADDSPACE ; If it is? jump to adding a space
		CMP AL, '.' ; Check if the character is a comma
		JE ADDSPACE ; If it is. jump to adding a space
		
		MOV [DI], AL ; If not, copy the character to the output
		INC SI ; Increment SI to point to the next character
		INC DI ; Increment DI to point to the next character
		CMP AL , '$'
		JE terminate2
		
		JMP LOOPp ; Jump back to the start of the loop
		
	ADDSPACE:
		MOV [DI], AL ; Copy the comma to the output
		INC DI ; Increment DI to point to the next character
		MOV [DI], ' ' ; Add a space to the output
		INC DI ; Increment DI to point to the next character
		INC SI ; Increment SI to point to the next character
		JMP LOOPp ; Jump back to the start of the loop
		
	terminate2:	
	
		LEA DX , afterD	
		mov ah , 09
		int 21h
		
		LEA DX , AddSpaceOutput	
		mov ah , 09
		int 21h
		
	ret
	
	
	ADD_SPACES ENDP
