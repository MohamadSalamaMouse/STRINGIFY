.model small
.data 

	 before DB 'text before removing extra spaces was: ',10,13,'$'  
	 after DB 'text after removing extra spaces was: ',10,13,'$'  

.code 


	;1- Remove extra white spaces from the whole text
	; "Every   thing is	 good,  right?" --> "Every thing is good, right?"
	REMOVE_SPACES PROC far
	
		LEA DX , before	
		mov ah , 09
		int 21h
	
	    LEA DX , text   
		mov ah , 09
        int 21h


	
		mov   ax,SEG text
		mov   ds,ax
		mov   es,ax
		mov   si,OFFSET text
		mov   di,si
		mov   bx,si
		; ds:si = source pointer to read char by char
		; es:di = destination pointer to write modified string
		; bx = text pointer for compare during second phase
		xor   cx,cx  ; cx = 0, counts spaces to copy

	copyLoop:
		lodsb           ; al = ds:[si++]
		cmp   al,'#'
		je    removeTrailingSpaces
		cmp   al,' '
		jne   notSpace
		jcxz  copyLoop  ; no more spaces allowed to copy, skip
		; copy the space
		dec   cx        ; --allowed
		stosb           ; es:[di++] = al
		jmp   copyLoop

	notSpace:
		mov   cx,1      ; one space can be copied next time
		stosb           ; copy the not-space char
		jmp   copyLoop

	removeTrailingSpaces:
		cmp   di,bx
		je    emptyStringResult
		dec   di
		cmp   BYTE PTR [di],' '
		je    removeTrailingSpaces
		inc   di        ; not-space found, write '#' after it
	emptyStringResult:
		stosb           ; write the '#' at final position
		
		LEA DX , after	
		mov ah , 09
		int 21h
		
		LEA DX , text	
		mov ah , 09
		int 21h
		
		ret
		
	REMOVE_SPACES ENDP


	;2- Add white space after punctuations [',', '.', '!', '?']
	; "Every,thing.is good?right." --> "Every, thing. is good? right."

	; ADD_SPACES PROC far

		;Your code
	;	ret
		
	; ADD_SPACES ENDP





