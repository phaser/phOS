/* The project is licensed under GNU GPL v3. See $(PROJECT_ROOT)/doc/gpl.txt for more details.
 *
 * phOS Operating System
 * Copyright (C) 2009 Cristian Bidea
 */

#include <phos/hw_tables.h>
#include <phos/kernel.h>

segment_descriptor gdt[5];
gdt_ptr gdt_p;

extern void asm_init_gdt (u32 ptr);
void gdt_set_entry (s32 num, u32 base, u32 limit, u8 access, u8 flags);

void init_gdt()
{
   gdt_set_entry(0, 0, 0, 0, 0);                // Null segment
   gdt_set_entry(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); // Code segment
   gdt_set_entry(2, 0, 0xFFFFFFFF, 0x92, 0xCF); // Data segment
   gdt_set_entry(3, 0, 0xFFFFFFFF, 0xFA, 0xCF); // User mode code segment
   gdt_set_entry(4, 0, 0xFFFFFFFF, 0xF2, 0xCF); // User mode data segment

   // set the ptr
   gdt_p.limit = sizeof (segment_descriptor) * 5 - 1;
   gdt_p.base = (u32)&gdt;

   asm_init_gdt ((u32)&gdt_p);
}

void gdt_set_entry (s32 num, u32 base, u32 limit, u8 access, u8 flags)
{
	gdt[num].limit	= limit & 0xFFFF;
	gdt[num].basel	= base & 0xFFFF;
	gdt[num].basem	= (base >> 16) & 0xFF;
	gdt[num].baseh	= (base >> 24) & 0xFF;

	gdt[num].type	= access;
	gdt[num].flags	= (limit >> 16) & 0xF;
	gdt[num].flags |= flags & 0xF0;
}

