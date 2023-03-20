                xdef        _clearG

base	        equ         64

_clearG:     	movem.l     d0-7/a0-6,-(sp)
                lea         blackFill,a0
                movem.l		(a0)+,d1-7/a1-6
		        movea.l		base(sp),a0
		        adda.l		#32000,a0
		        move.w		#560,d0
fillLoopGame:   movem.l		d1-7/a1-6,-(a0)
		        dbra		d0,fillLoopGame
		        movem.l		d1-5,-(a0)
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