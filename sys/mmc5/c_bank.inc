.proc _farcall
    .export _farcall
    .import pusha, popa, callptr4
    .importzp prgbank, tmp4

    ;; store the current bank on the stack, switch to new bank

    ; push the current prg bank on the stack
    lda prgbank
    jsr pusha

    lda tmp4
    sta prgbank
    sta $5114 ; mmc5 bank set to prgbank

    ;; jump to wrapped call
    jsr callptr4

    ;; restore the previous prg bank and pop it  
   
    jsr popa
    sta prgbank
    sta $5114

    rts
.endproc ; _farcall
