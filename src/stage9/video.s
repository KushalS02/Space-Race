;Authours: Alexander Pham and Kushal Saini

;Course: COMP 2659 - 001

;File name: VIDEO.S

;Instructor: Paul Pospisil

        xdef    _getVideoBase
        xdef    _setVideoBase
SCREEN	equ 	$FFFF8201
OFFSET 	equ 	8   

;Physbase
_getVideoBase:
        move.l  a0,-(sp)
        clr.l   d0
        lea     SCREEN,a0
        movep.w (a0),d0
        lsl.l   #8,d0   
        move.l  (sp)+,a0
        rts

;Setscreen
_setVideoBase:
        link    a6,#0
        movem.l d0/a0,-(sp)

        move.l  OFFSET(a6),d0
        lsr.l   #8,d0
        lea     SCREEN,a0      
        movep.w d0,0(a0)
        
        movem.l (sp)+,d0/a0    
        unlk    a6
        rts


