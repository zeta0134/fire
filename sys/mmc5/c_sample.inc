.proc _select_sample_bank
    .export _select_sample_bank
    .importzp samplebank

    ora #$80 ; add the PRG ROM flag
    sta samplebank
    
    sta $5116 ; mmc5 bank set to samplebank
    
    rts
.endproc ; _select_sample_bank
