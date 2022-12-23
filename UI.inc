.MODEL SMALL

.DATA 
SAVE_FILE_MSG   DB	"1- Save result into output file",10,13,"$"
MAIN_MENU_MSG   DB	"2- Go Back To Main Menu",10,13,"$"
EXIT_OPTION_MSG DB 	"3- Exit the program",10,13,"$"
GET_CHOICE_MSG  DB  "ENTER YOUR CHOICE: ","$"
GET_STRING_MSG  DB  "Enter your string: ",10,13,"$"
BEFORE_MSG		DB 	"Text before :", 10, 13, "$"
AFTER_MSG		DB 	"Text after :", 10, 13, "$"
SHOW_STRING_MSG DB  "Your current text is: ", 10, 13, "$"
FILE_SAVED_MSG  DB 	"The file has been saved sucessfully!", 10, 13, "$"
NEWLINE			DB  10,13,"$"
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

Ll6 DB  '            ||==================================================||',0ah,0dh,'$'
Ll7 DB  '            ||                                                  ||',0ah,0dh,'$'
Ll8 DB  '            ||    How to do you want to enter data ??           ||',0ah,0dh,'$'
Ll9 DB  '            ||                                                  ||',0ah,0dh,'$'
Ll10 DB '            ||    1 - Use data stored implicitly in program     ||',0ah,0dh,'$'
Ll11 DB '            ||    2 - Enter data manually through console       ||',0ah,0dh,'$'
Ll12 DB '            ||    3 - Load data from file                       ||',0ah,0dh,'$'
Ll13 DB '            ||                                                  ||',0ah,0dh,'$'
Ll14 DB '            ||----***********----***********----***********-----||',0ah,0dh,'$'

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
SPLITTER PROC
	LEA DX, NEWLINE
	CALL PRINT
	LEA DX, L5
	CALL PRINT
	LEA DX, NEWLINE
	CALL PRINT
	RET
SPLITTER ENDP
; -------------------------------
CLEAR_SCREEN PROC
	MOV AL, 3
	MOV AH, 0
	INT 10H
	RET
CLEAR_SCREEN ENDP
; -------------------------------
SHOW_TEXT_BEFORE PROC
	LEA DX, NEWLINE
	CALL PRINT
	LEA DX, BEFORE_MSG
	CALL PRINT
	LEA DX, FINAL_OUTPUT
	CALL PRINT
	CALL SPLITTER
	RET
	
SHOW_TEXT_BEFORE ENDP
; -------------------------------
SHOW_TEXT_AFTER PROC

	LEA DX, AFTER_MSG
	CALL PRINT
	LEA DX, FINAL_OUTPUT
	CALL PRINT
	CALL SPLITTER
	RET
	
SHOW_TEXT_AFTER ENDP
; -------------------------------
SHOW_CONTINUE_OPTIONS PROC
	LEA DX, NEWLINE
	CALL PRINT
	CALL PRINT
	CALL PRINT

	LEA DX,SAVE_FILE_MSG
	CALL PRINT
	CALL delay
	LEA DX,MAIN_MENU_MSG
	CALL PRINT
	CALL delay
	LEA DX,EXIT_OPTION_MSG
	CALL PRINT
	CALL delay

	LEA DX, NEWLINE
	CALL PRINT
	
	LEA DX,GET_CHOICE_MSG
	CALL PRINT
	RET
SHOW_CONTINUE_OPTIONS ENDP
; -------------------------------
load proc 

	LEA DX, Ll6
	CALL PRINT
	
		call delay
	
	LEA DX, Ll7
	CALL PRINT
	
		call delay
	
	LEA DX, Ll8
	CALL PRINT
	
		call delay
	
	LEA DX, Ll9
	CALL PRINT
	
		call delay
	
	LEA DX, Ll10
	CALL PRINT
	
		call delay
	
	LEA DX, Ll11
	CALL PRINT
	
		call delay
	
	LEA DX, Ll12
	CALL PRINT
	
		call delay
	
	LEA DX, Ll13
	CALL PRINT
	
		call delay
	
	LEA DX, Ll14
	CALL PRINT
	
		call delay
	LEA DX, NEWLINE
	CALL PRINT
	RET

load endp

; -------------------------------

OPTIONS PROC
	LEA DX, NEWLINE
	CALL PRINT

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
	
	LEA DX, NEWLINE
	CALL PRINT
	
	RET
OPTIONS ENDP

delay proc  near 
  mov cx, 1      ;HIGH WORD.
  mov dx, 0A120h ;LOW WORD.
  mov ah, 86h    ;WAIT.
  int 15h
  ret
delay endp  

START_PROG proc 
	call WAKE_UP
	call load
	ret
START_PROG endp

PRINT_SAVED_MSG PROC
	CALL CLEAR_SCREEN
	
	CALL SPLITTER
	LEA DX, FILE_SAVED_MSG
	CALL PRINT
	CALL SPLITTER
	RET
PRINT_SAVED_MSG ENDP