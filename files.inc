.MODEL SMALL

.DATA 

BUFFER1 DB 255 DUP("$")

fname db "temp.txt",0
fhandle dw ?

fname_read db "input.TXT",0
fhandle_read dw ?

fname_output db "OUTPUT.TXT",0
fhandle_output dw ?

.CODE 
FILEHANDLING PROC 
    ;create  anew file
    MOV AH,3ch
    LEA DX, fname   
    MOV CL,0
    INT 21h
    MOV fhandle,AX

    ;open an existing file
    MOV AH,3dh
    LEA DX,fname
    MOV AL,2
    INT 21h
    MOV fhandle ,AX 

    ;----------------
    CALL  ReadFromScreen
    ;-------------
    ;  how to write text in file 
    MOV AH,40h
    MOV BX,fhandle   

    LEA DX,BUFFER1
    MOV CX,255
    INT 21h
    ;------------

    ;how to read text from a file
    MOV AH,3fh
    MOV DX,0000H
    LEA DX,BUFFER1
    MOV CX,255
    MOV BX,fhandle
    INT 21h 
    MOV DX,0000H

    LEA SI,BUFFER1
    MOV BX, 255
    CALL SAVE_TEXT

    RET
FILEHANDLING ENDP
      
ReadFromScreen PROC
    LEA DX,GET_STRING_MSG
    MOV AH,09h
    INT 21h
    MOV DX,0000H
    MOV SI,0
    MOV CX,0
    
    again:
        MOV AH,01h
        INT 21h
        CMP AL,13

        JE exit2
        MOV BUFFER1[SI],AL
        INC SI
        INC CX
        JMP again
    
    exit2:
        RET
ReadFromScreen ENDP

READ_DATA_FROM_FILE PROC
	MOV AH, 3dh
	LEA DX, fname_read
	MOV AL, 2
	INT 21H
	MOV fhandle_read ,AX 

	MOV AH,3FH
	MOV DX,0000H
	LEA DX,BUFFER1
	MOV CX,255
	MOV BX,fhandle_read
	INT 21H
	MOV DX,0000H
	LEA SI,BUFFER1

	MOV BX, 255
	CALL SAVE_TEXT 

READ_DATA_FROM_FILE ENDP

SAVE_FILE_ON_DISK PROC
	MOV AH,3CH
	LEA DX, fname_output   
	MOV CL,0
	INT 21h
	MOV fhandle_output,AX

	;open an existing file
	MOV AH,3dh
	LEA DX,fname_output
	MOV AL,2
	INT 21h
	MOV fhandle_output ,AX 

	;  how to write text in file 
	MOV AH,40h
	MOV BX,fhandle_output   

	LEA DX,FINAL_OUTPUT
	MOV CX,255
	INT 21h
	RET
SAVE_FILE_ON_DISK ENDP
