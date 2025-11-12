.model small 
.stack 100h 
.code 
main proc 
 call multiply 
 mov ah, 4ch 
 int 21h 
main endp 

multiply proc 
 push ax 
 push bx 
 xor dx, dx

Repeat:
 test bx, 1
 jz end_if 
 add dx, ax 

end_if:
 shl ax, 1
 shr bx, 1

 jnz Repeat 
 pop bx 
 pop ax 
 ret 

 multiply endp 
  end main