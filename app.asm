include caps.inc 
include dups.inc
include spaces.inc
include UI.inc
;include file.inc
.386
.MODEL small

.DATA       

TEXT DB "often time time  in lIfE, What  is eASy to  do is,not worTH worth it.suRe,crashing on on     on the  couch!And  WAtcHing the.the nEwest, episode,of your!fAVorite sHow!is A  pleasuRable?exPerience.",10,13,"$"
TEXT_LEN EQU  $ - TEXT
;-----------------------------------------------------
save_into_file DB "1-Save result into output file",10,13,"$"
Back_TO_Options DB"2-Go Back To Main Menu",10,13,"$"
ExitST DB "2-Exit the program",10,13,"$"
;-----------------------------------------------------
INPUTLINE DB "ENTER YOUR CHOOSE: ","$"
msg db 'Enter your string: $'
;-----------------------------------------------------
NEWLINE DB 10,13,"$"
;-----------------------------------------------------
BUFFER1 DB 255 DUP("$")

fname db "temp.txt",0
fhandle dw ?

fname_read db "input.TXT",0
fhandle_read dw ?

fname_output db "OUTPUT.TXT",0
fhandle_output dw ?
;-----------------------------------------------------
FINAL_OUTPUT DB 255 DUP('$')
;-----------------------------------------------------


.CODE 
 
    MAIN PROC FAR
        .STARTUP
        MOV AX, @DATA
        MOV ES, AX
        ;-----------------
        
        
        MOV BX, TEXT_LEN
        LEA SI, TEXT
        CALL SAVE_TEXT
        ;----------------------

         call load_function
         LEA DX,INPUTLINE
         CALL PRINT
            
         MOV AH,1
         INT 21H
         LEA DX, NEWLINE
         CALL PRINT
         
        CMP AL, '1'
        JE Rendering
        CMP AL, '2'
        JE loadingOPT_2
        CMP AL, '3'
        JE loadingOPT_3
        
         
                  
          loadingOPT_2:
          call FILEHANDLING
          jmp Rendering

                
          loadingOPT_3:
           mov ah,3dh
           lea dx,fname_read
           mov al,2
           int 21h
           mov fhandle_read ,ax 
        
          mov ah,3fh
          MOV DX,0000H
          lea dx,BUFFER1
          mov cx,255
          mov bx,fhandle_read
          int 21h 
          MOV DX,0000H
          LEA SI,BUFFER1
       
          MOV BX, 255
         CALL SAVE_TEXT 
         jmp Rendering
         
             ; close a file
             mov ah,3eh
             mov bx,fhandle_read
             int 21h

        
        ;----------------------
        
        Rendering :
            LEA DX, NEWLINE
            CALL PRINT 
            CALL WAKE_UP
            CALL OPTIONS
        
        GET_OPTION:
             LEA DX, NEWLINE
             CALL PRINT


            LEA DX,INPUTLINE
            CALL PRINT
            
            MOV AH,1
            INT 21H
            LEA DX, NEWLINE
            CALL PRINT

            
            CMP AL, '1'
            JE OPT_1
            CMP AL, '2'
            JE OPT_2
            CMP AL, '3'
            JE OPT_3
            CMP AL, '4'
            JE OPT_4
            CMP AL, '5'
            JE OPT_5
            
            OPT_1:
                LEA DX, L5
                CALL PRINT
                CALL CAPITAL_SMALL
                LEA DX, FINAL_OUTPUT
                CALL PRINT
                LEA DX, NEWLINE
                CALL PRINT
                JMP Continue_option
                
            OPT_2:
                LEA DX, L5
                CALL PRINT
                CALL ADD_SPACES
                CALL REMOVE_SPACES
                LEA DX, FINAL_OUTPUT
                CALL PRINT
                LEA DX, NEWLINE
                CALL PRINT
                JMP Continue_option
                
            OPT_3: 
                LEA DX, L5
                CALL PRINT
                CALL REMOVE_DUP
                LEA DX, FINAL_OUTPUT
                CALL PRINT
                 LEA DX, NEWLINE
                 CALL PRINT
                JMP Continue_option
                
            OPT_4:
                LEA DX, L5
                CALL PRINT
                CALL CAPITAL_SMALL
                CALL REMOVE_DUP
                CALL ADD_SPACES
                CALL REMOVE_SPACES
                LEA DX, FINAL_OUTPUT
                CALL PRINT
                LEA DX, NEWLINE;NEW LINE
                CALL PRINT
                JMP Continue_option
                
            OPT_5:
                JMP TERM    
                
        
        ;----------------------
        Continue_option:
            LEA DX,save_into_file
            call print
            LEA DX,Back_TO_Options
            call print
            LEA DX,ExitST
            call print
            
            LEA DX, NEWLINE
            CALL PRINT
        
            LEA DX,INPUTLINE
            CALL PRINT
                
            MOV AH,1
            INT 21H
            
            LEA DX, NEWLINE
             CALL PRINT
             CALL PRINT
             CALL PRINT





            CMP AL, '1'
            jz  store_files
            CMP AL, '2'
            jz  Rendering
            CMP AL, '3'
            JE TERM
           
            
       store_files:
       mov ah,3ch
       mov dx,OFFSET fname_output   
       mov cl,0
       int 21h
       mov fhandle_output,ax
       
       ;open an existing file
        mov ah,3dh
        lea dx,fname_output
        mov al,2
        int 21h
        mov fhandle_output ,ax 
        
    ;  how to write text in file 
       mov ah,40h
       mov bx,fhandle_output   
           
       LEA dx,FINAL_OUTPUT
       MOV CX,255
       int 21h
        
      jmp Rendering
         TERM:
        .EXIT
       
    MAIN ENDP
                
    ;-----------------------------------
    
    PRINT PROC ; Print the string found in DX
    
        MOV AH, 9
        INT 21H
        RET
        
    PRINT ENDP
  
    ;-----------------------------------
    
    SAVE_TEXT PROC ; Move text between two variables, Excpect to found the source variable in SI and the length to copy in BX
        
        LEA DI, FINAL_OUTPUT
        
        PUSH DI
        CALL CLEAR_VAR
        POP DI        

        MOV CX, BX
        CLD
        REP MOVSB
        
        RET
        
    SAVE_TEXT ENDP
    
    ;---------------------------------------
    
    
FILEHANDLING PROC 
     ;create  anew file
       mov ah,3ch
        mov dx,OFFSET fname   
        mov cl,0
        int 21h
       mov fhandle,ax

        
        

       ;open an existing file
        mov ah,3dh
        lea dx,fname
        mov al,2
        int 21h
        mov fhandle ,ax 
        
        ;----------------
       CALL  ReadFromScreen
        ;-------------
      ;  how to write text in file 
       mov ah,40h
       mov bx,fhandle   
           
       LEA dx,BUFFER1
       MOV CX,255
       int 21h
        ;------------
        
      ;how to read text from a file
      mov ah,3fh
      MOV DX,0000H
      lea dx,BUFFER1
      mov cx,255
      mov bx,fhandle
      int 21h 
      MOV DX,0000H
      
      LEA SI,BUFFER1
      MOV BX, 255
      CALL SAVE_TEXT
      

        
     
     RET
      FILEHANDLING ENDP
      
       ReadFromScreen PROC
         lea dx,msg
         mov ah,09h
         int 21h
         MOV DX,0000H
         mov si,0
         mov cx,0
      again:
        mov ah,01h
        int 21h
        cmp al,13
   
       je exit2
       mov BUFFER1[si],al
       inc si
       inc cx
       jmp again   
       exit2:
         
     
     RET
     ReadFromScreen ENDP
     



    
END MAIN

