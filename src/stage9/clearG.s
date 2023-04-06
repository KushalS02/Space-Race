;Authours: Alexander Pham and Kushal Saini

;Course: COMP 2659 - 001

;File name: clearG.s

;Instructor: Paul Pospisil
				
				xdef        _clearGame

base	        equ         64

_clearGame:     movem.l     d0-7/a0-6,-(sp)
                lea         blackFill,a0
                movem.l		(a0)+,d1-7/a1-6
	       		movea.l		base(sp),a0
	        	adda.l		#32000,a0
	        	move.w		#600,d0
				
fillLoopGame:   movem.l		d1-7/a1-6,-(a0)
	        	dbra		d0,fillLoopGame
	        	movem.l		d1-4,-(a0)
	        	movem.l		(sp)+,d0-7/a0-6
	        	rts

blackFill:      dc.l        $FFFFFFFF
                dc.l		$FFFFFFFF
	        	dc.l		$FFFFFFFF
	        	dc.l		$FFFFFFFF
	        	dc.l		$FFFFFFFF
	       		dc.l		$FFFFFFFF
	        	dc.l		$FFFFFFFF
	        	dc.l		$FFFFFFFF
	        	dc.l		$FFFFFFFF
	        	dc.l		$FFFFFFFF
	        	dc.l		$FFFFFFFF
	        	dc.l		$FFFFFFFF
	        	dc.l		$FFFFFFFF


