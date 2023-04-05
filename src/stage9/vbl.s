;Authours: Alexander Pham and Kushal Saini

            xdef        _vblISR
            xref        _vblReq

_vblISR:    movem.l     d0/a0,-(sp)
            jsr         _vblReq      
            movem.l     (sp)+,d0/a0
            rte


