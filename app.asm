include caps.inc
include dups.inc
include spaces.inc
include UI.inc
include files.inc
.386
.MODEL small

.DATA       
;-----------------------------------------------------
TEXT DB "often time time  in lIfE, What  is eASy to  do is,not worTH worth it.suRe,crashing on on     on the  couch!And  WAtcHing the.the nEwest, episode,of your!fAVorite sHow!is A  pleasuRable?exPerience.",10,13,"$"
TEXT_LEN EQU  $ - TEXT
;-----------------------------------------------------
FINAL_OUTPUT DB 255 DUP('$')
;-----------------------------------------------------

.CODE 
 
    MAIN PROC FAR
        .STARTUP
        MOV AX, @DATA
        MOV ES, AX

        ;----------------------
        ; Get the required choice of loading the text
        CALL    START_PROG
        LEA DX, GET_CHOICE_MSG
        CALL    PRINT
        
        MOV AH, 1
        INT 21H
        
        ;----------------------
        ; Check the user choice
        CMP AL, '1'
        JE loadingOPT_1
        CMP AL, '2'
        JE loadingOPT_2
        CMP AL, '3'
        JE loadingOPT_3

        loadingOPT_1:               ; Use the data stored in program
            MOV BX, TEXT_LEN
            LEA SI, TEXT
            CALL    SAVE_TEXT
            JMP Rendering

        loadingOPT_2:
            LEA DX, NEWLINE
            CALL PRINT
            CALL SPLITTER
            CALL FILEHANDLING
            JMP  Rendering


        loadingOPT_3:
            CALL READ_DATA_FROM_FILE


        ;----------------------

        Rendering :
            CALL CLEAR_SCREEN
            
            LEA DX, SHOW_STRING_MSG
            CALL    PRINT
            
            LEA DX, FINAL_OUTPUT
            CALL    PRINT
            
            CALL    OPTIONS

        GET_OPTION:
            LEA DX,GET_CHOICE_MSG
            CALL PRINT

            MOV AH,1
            INT 21H
            

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
            CALL CLEAR_SCREEN
            CALL SHOW_TEXT_BEFORE
            
            CALL CAPITAL_SMALL
            
            CALL SHOW_TEXT_AFTER
            
            JMP Continue_option

        OPT_2:
            CALL CLEAR_SCREEN
            CALL SHOW_TEXT_BEFORE
            
            CALL ADD_SPACES
            CALL REMOVE_SPACES
            
            CALL SHOW_TEXT_AFTER
            
            JMP Continue_option

        OPT_3:
            CALL CLEAR_SCREEN 
            CALL SHOW_TEXT_BEFORE
            
            CALL REMOVE_DUP
            
            CALL SHOW_TEXT_AFTER
            JMP Continue_option

        OPT_4:
            CALL CLEAR_SCREEN
            CALL SHOW_TEXT_BEFORE
            
            CALL CAPITAL_SMALL
            CALL REMOVE_DUP
            CALL ADD_SPACES
            CALL REMOVE_SPACES
            
            CALL SHOW_TEXT_AFTER
            JMP Continue_option

        OPT_5:
            JMP TERM    


        ;----------------------
        Continue_option:
            CALL SHOW_CONTINUE_OPTIONS

            MOV AH,1
            INT 21H

            CMP AL, '1'
            JE  store_files
            CMP AL, '2'
            JE  Rendering
            CMP AL, '3'
            JE  TERM

        store_files:

            CALL SAVE_FILE_ON_DISK
            CALL PRINT_SAVED_MSG
            
            JMP Continue_option
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
    
     
END MAIN

