; This file contains functions used for monitor output in text mode

_cx		dd	0
_cy		dd	0

[BITS 32]	; 32 bits instructions

[GLOBAL putc]
[GLOBAL move]
[GLOBAL scroll]

; void putc (int char)
; puts a character on the screen
putc:
	push ebp
	mov ebp, esp
	xor ecx, ecx	
	mov cl, [ebp+8]

	cmp cl, 0x8		; if backspace
	jne .tab
	dec word [_cx]
	jmp .exit
.tab:	cmp cl, 0x9		; if tab
	jne .cr
	mov eax, [_cx]
	add eax, 0x8
	and eax, eax
	mov [_cx], eax
	jmp .exit
.cr:	cmp cl, 0xD		; if carriage return
	jne .newline
	mov word [_cx], 0x0
	jmp .exit
.newline:
	cmp cl, 0xA		; if new line
	jne .write
	mov word [_cx], 0x0
	inc word [_cy]
	jmp .exit

.write:
	mov eax, [_cy]
	mov ebx, 0xA0
        mul ebx
	mov ebx, [_cx]
	shl ebx, 0x1
	add eax, ebx
	add eax, 0xB8000

	mov bl, cl
	mov bh, 0x0F
	mov [eax], bx

	inc word [_cx]	

.exit:
	cmp word [_cx], 0x50
	jl .rexit
	mov word [_cx], 0x0
	inc word [_cy]
	call scroll			; if it's necessary scroll the screen
.rexit:
	pop ebp
	ret

; void scroll()
; scrolls the screen one line
scroll:
	cmp word [_cy], 0x50
	jl .scrolle
	mov eax, 0xB8000
.memcpy:
	mov ecx, 0x50
	mov esi, eax			; source
	lea edi, [eax+0xA0]		; destination
	rep movsw
	cmp eax, 0xBB160
        jle .memcpy
	dec word [_cy]
	mov word [_cx], 0x0	
.scrolle:
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
	ret

