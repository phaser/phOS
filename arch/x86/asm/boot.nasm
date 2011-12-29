;    phOS kernel
;    Copyright (C) 2009  Cristian Bidea (cbidea at acm dot org)
;
;    This program is free software: you can redistribute it and/or modify
;    it under the terms of the GNU General Public License as published by
;    the Free Software Foundation, either version 3 of the License, or
;    (at your option) any later version.
;
;    This program is distributed in the hope that it will be useful,
;    but WITHOUT ANY WARRANTY; without even the implied warranty of
;    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;    GNU General Public License for more details.
;
;    You should have received a copy of the GNU General Public License
;    along with this program.  If not, see <http://www.gnu.org/licenses/>.
;

; Definitions

MAGIC			equ	0x1BADB002
FLAG_MEMINFO		equ	1<<0
FLAG_BOOT_DEV		equ	1<<1

MBOOT_FLAGS		equ	FLAG_MEMINFO | FLAG_BOOT_DEV
MBOOT_CHECKSUM		equ	-(MAGIC + MBOOT_FLAGS)	; checksum + values must be 0	

[BITS 32]

[EXTERN code]
[EXTERN bss]
[EXTERN end]
[EXTERN main]
[EXTERN _main]
[EXTERN _atexit]

multiboot:
	dd	MAGIC
	dd	MBOOT_FLAGS
	dd	MBOOT_CHECKSUM
	dd	multiboot
	dd	code
	dd	bss
	dd	end
	dd	start

[GLOBAL start]
[EXTERN main]

start:
	push ebx	; pass the address of the multiboot structure

	cli		; disable interrupts
	call _main
	call main
	call _atexit
	jmp $
