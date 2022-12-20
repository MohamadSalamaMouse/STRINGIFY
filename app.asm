include caps.inc 
include dups.inc
include spaces.inc

.MODEL small

.DATA       

text DB "often time  time  in lIfE,What  is easy to   do is not  worth   worth it ",10,13,"$"

.CODE 
 
    MAIN PROC FAR
        .STARTUP
        
        
        call REMOVE_SPACES
            
       .EXIT
       
    MAIN ENDP
    
END MAIN