            xdef        _ikbdISR
            xref        _ikbdReq

_ikbdISR:   movem.l     d0/a0,-(sp)
            jsr         _ikbdReq      
            movem.l     (sp)+,d0/a0
            rte