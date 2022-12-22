;include caps.inc 
include dups.inc
;include spaces.inc

.MODEL small

.DATA       

TEXT DB "often  time time  in lIfE, What  is easy easy to  do is not worth worth it. SuRe,crashing on the  couch!and watcHing the the newest, episode,of your favorite show is A  pleasuRable exPerience.",10,13,"$"
TEXT_LEN EQU  $ - TEXT
FINAL_OUTPUT DB 255 DUP('$')

.CODE 
 
    MAIN PROC FAR
        .STARTUP
        MOV AX, @DATA
        MOV ES, AX
        
        MOV BX, TEXT_LEN
        LEA SI, TEXT
        CALL SAVE_TEXT
        
        LEA DX, FINAL_OUTPUT
        CALL PRINT

            
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

