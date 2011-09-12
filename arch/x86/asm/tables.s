; The project is licensed under GNU GPL v3. See $(PROJECT_ROOT)/doc/gpl.txt for more details.
; 
; phOS Operating System
; Copyright (C) 2009 Cristian Bidea

[GLOBAL asm_init_gdt]
[GLOBAL asm_init_idt]

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

asm_init_idt:
	mov eax, [esp+4]
	lidt [eax]
	ret
