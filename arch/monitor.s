; This file contains functions used for monitor output in text mode

_cx		dd	10
_cy		dd	10
_video_addr	dd	0xB8000		; the text mode video address

[BITS 32]	; 32 bits instructions

[GLOBAL putc]
[GLOBAL move]


putc:
	push ebp
	mov esp, ebp
	sub esp, 0x40  ; 64 kb of local stack space

	mov eax, [_cy]
	mov ebx, 0x50
        mul ebx
	add eax, [_cx]
	mov ebx, eax

	mov eax, [_video_addr]
	add eax, ebx
	mov word [eax], 0x5000

	inc word [_cx]	
	leave
	ret

; void move ()
; it moves the cursor to _cx, _cy coordinates
move:
	mov eax, [_cy]		;
	mov ebx, 0x50		; _cy * 80 + _cx
	mul ebx			;
	add eax, [_cx]		;
	mov ebx, eax
	mov eax, 0x0F
	mov dx, 0x3D4
	out dx, al
	mov eax, ebx
	mov dx, 0x3D5
	out dx, al
	mov ebx, eax
	mov eax, 0x0E
	mov dx, 0x3D4
	out dx, al
	mov eax, ebx
	shr eax, 0x08
	mov dx, 0x3D5
	out dx, al
	leave
	ret

