[GLOBAL asm_init_gdt]

asm_init_gdt:
	mov eax, [esp+4]
	lgdt	[eax]

	mov ax, 0x10		; offset into gdt 16
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax
	jmp 0x08:.flush		; make a far jump into the code segment to initialize cs
.flush:
	ret
