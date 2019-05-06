section .data

section .text                   
        
global  _doubleX, _tripleXPlus1, _seizeXPlus2, _pos_or_neg, _pair_or_impair
                                                
extern print_registers  


_doubleX:    
        mov eax, edi
        shl eax, 1
        ret

_tripleXPlus1:
        mov eax, edi
        shl eax, 1
        add eax, edi
        inc eax
        ret

_seizeXPlus2:
        mov eax, edi
        shl eax, 4 ;2^4 = 16
        sub eax, edi
        add eax, 2
        ret

_pos_or_neg:
        mov rax, 1
        shl rax, 63
        and rdi, rax
        jne neg
pos: 
        mov rax, 1
        ret
neg:
        mov rax, 0
        ret

_pair_or_impair: 
        and rdi, 1
        jz pair

pair:
        mov rax, 1
        ret

impair: 
        mov rax, 0
        ret

_start:
        mov rax, 1
        mov rbx, 0
        int 80h
