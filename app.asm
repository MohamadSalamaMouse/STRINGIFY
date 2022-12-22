include caps.inc 
include dups.inc
include spaces.inc
include UI.inc

.MODEL small

.DATA       

TEXT DB "often  time time  in lIfE, What  is eASy to  do is,not worTH worth it.SuRe,crashing on on     on the  couch!And  WAtcHing the.the nEwest, episode,of your!fAVorite sHow!is A  pleasuRable?exPerience.",10,13,"$"
INPUTLINE DB "ENTER YOUR CHOOSE: ","$"
TEXT_LEN EQU  $ - TEXT
NEWLINE DB 10,13,"$"
FINAL_OUTPUT DB 255 DUP('$')

.CODE 
 
    MAIN PROC FAR
        .STARTUP
        MOV AX, @DATA
        MOV ES, AX
        
        MOV BX, TEXT_LEN
        LEA SI, TEXT
        CALL SAVE_TEXT
        
        ;----------------------
        CALL WAKE_UP
        
        GET_OPTION:
            CALL OPTIONS
            LEA DX,INPUTLINE
            CALL PRINT
            
            MOV AH,1
            INT 21H
            LEA DX, NEWLINE
            CALL PRINT
            CALL PRINT
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
            
                CALL CAPITAL_SMALL
                LEA DX, FINAL_OUTPUT
                CALL PRINT
                LEA DX, NEWLINE
                CALL PRINT
                JMP GET_OPTION
                
            OPT_2:
            
                CALL ADD_SPACES
                CALL REMOVE_SPACES
                LEA DX, FINAL_OUTPUT
                CALL PRINT
                LEA DX, NEWLINE
                CALL PRINT
                JMP GET_OPTION
                
            OPT_3: 
            
                CALL REMOVE_DUP
                LEA DX, FINAL_OUTPUT
                CALL PRINT
                 LEA DX, NEWLINE
                 CALL PRINT
                JMP GET_OPTION
                
            OPT_4:
            
                CALL CAPITAL_SMALL
                CALL REMOVE_DUP
                CALL ADD_SPACES
                CALL REMOVE_SPACES
                LEA DX, FINAL_OUTPUT
                CALL PRINT
                LEA DX, NEWLINE;NEW LINE
                CALL PRINT
                JMP GET_OPTION
                
            OPT_5:
            
                JMP TERM            
        
        ;----------------------
        
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

    
END MAIN

