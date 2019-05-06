section .data

section .text                   
        
global  _mult2
                                                
extern print_registers  

_mult2 : 
	mov eax, edi
    shl eax, 1
    ret