;include caps.inc 
;include dups.inc
include spaces.inc

.MODEL small

.DATA       

text DB "time  !time  in lIfE,What  is  easy to   do is not  worth worth?it ",10,13,"$"
RemoveSpaceOutput DB ? 
AddSpaceOutput DB ?
 

.CODE 
 
    MAIN PROC FAR
        .STARTUP
        
        ;call REMOVE_SPACES
        call ADD_SPACES

            
        .EXIT
       
    MAIN ENDP
    
END MAIN