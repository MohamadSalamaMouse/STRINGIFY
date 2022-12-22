.MODEL SMALL

.DATA 

L1 DB  '            ||----***********----***********----***********-----|| ',0ah,0dh,'$'
L2 DB  '            ||                                                  ||',0ah,0dh,'$'
L3 DB  '            ||                  < STRINGIFY >                   ||',0ah,0dh,'$'
L4 DB  '            ||                                                  ||',0ah,0dh,'$'
L5 DB  '            ||==================================================||',0ah,0dh,'$'
L6 DB  '            ||==================================================||',0ah,0dh,'$'
L7 DB  '            ||                                                  ||',0ah,0dh,'$'
L8 DB  '            ||    1 - Correct paragraph capitalization          ||',0ah,0dh,'$'
L9 DB  '            ||    2 - Correct paragraph whitespaces             ||',0ah,0dh,'$'
L10 DB '            ||    3 - Remove successive duplicate words         ||',0ah,0dh,'$'
L11 DB '            ||    4 - Execute all operations above              ||',0ah,0dh,'$'
L12 DB '            ||    5 - Exit the program                          ||',0ah,0dh,'$'
L13 DB '            ||                                                  ||',0ah,0dh,'$'
L14 DB '            ||----***********----***********----***********-----||',0ah,0dh,'$'

.CODE 

WAKE_UP PROC

	LEA DX, L1
	CALL PRINT
	
	call delay
	
	LEA DX, L2
	CALL PRINT
	
	call delay
	
	LEA DX, L3
	CALL PRINT
	
	call delay
	
	LEA DX, L4
	CALL PRINT
	
	call delay
	
	LEA DX, L5
	CALL PRINT
	
	call delay
	
	RET
WAKE_UP ENDP

; -------------------------------

OPTIONS PROC
	LEA DX, L6
	CALL PRINT
	
		call delay
	
	LEA DX, L7
	CALL PRINT
	
		call delay
	
	LEA DX, L8
	CALL PRINT
	
		call delay
	
	LEA DX, L9
	CALL PRINT
	
		call delay
	
	LEA DX, L10
	CALL PRINT
	
		call delay
	
	LEA DX, L11
	CALL PRINT
	
		call delay
	
	LEA DX, L12
	CALL PRINT
	
		call delay
	
	LEA DX, L13
	CALL PRINT
	
		call delay
	
	LEA DX, L14
	CALL PRINT
	
		call delay
	
	RET
OPTIONS ENDP

delay proc  near 
  mov cx, 1      ;HIGH WORD.
  mov dx, 0A120h ;LOW WORD.
  mov ah, 86h    ;WAIT.
  int 15h
  ret
delay endp  

