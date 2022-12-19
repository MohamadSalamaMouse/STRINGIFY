data SEGMENT
    
    TEXT DB "How do you balance the two halves of your self?the priest and the soldier?",10,13, "The light and the darkness.",10,13,"It was not a question he should've asked, not a possibility he should've considered, but it was done and now he waited. Because he needed the answer.$"
    include caps.inc
    include dups.inc
    include spaces.inc
   
    
data ENDS

code SEGMENT
    
    ASSUME CS:code, DS:data
    MOV AX,data
    MOV DS,AX
    
    MAIN PROC FAR
    
        
        .EXIT
        
    MAIN ENDP
        
code ENDS

END MAIN