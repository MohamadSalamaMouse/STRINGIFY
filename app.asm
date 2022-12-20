    ;include caps.inc 
    ;include dups.inc
    include spaces.inc
.model small
.data       
text DB "often time  time  in lIfE,What  is easy to   do is not  worth   worth it ",10,13,"$"
.code 
 
    MAIN PROC FAR
        .startup
        
        
        call REMOVE_SPACES
            
       .EXIT
       
    MAIN ENDP
END MAIN