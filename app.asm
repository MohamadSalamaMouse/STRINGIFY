;include caps.inc 
;include dups.inc
include spaces.inc

.MODEL small

.DATA       

text DB "time  !tIMe  in lIfE   ,What  is  ea    .sy to   do is not  worth      worth?it ",10,13,"$"
AddSpaceOutput DB ?
;RemoveSpaceOutput DB ? 

 

.CODE 
 
    MAIN PROC FAR
        .STARTUP
        
        ;call CAPITAL_SMALL
        call REMOVE_SPACES
        call ADD_SPACES



            
        .EXIT
       
    MAIN ENDP
    
END MAIN