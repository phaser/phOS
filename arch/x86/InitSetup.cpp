/* The project is licensed under GNU GPL v3. See $(PROJECT_ROOT)/doc/gpl.txt for more details.
 *
 * phOS Operating System
 * Copyright (C) 2009 Cristian Bidea
 */

#include <phos/InitSetup.hpp>
#include <phos/Video.hpp>

//---------------------------------------------------------------------------
//    Local vars
//---------------------------------------------------------------------------

segment_descriptor gdt[5];
gdt_ptr gdt_p;
idt_descriptor idt[256];
idt_ptr idt_p;

//---------------------------------------------------------------------------
//    Extern defines
//---------------------------------------------------------------------------
extern "C" {
	extern void asm_init_gdt (u32 ptr);
	extern void asm_init_idt (u32 ptr);
	extern void isr0  ();
	extern void isr1  ();
	extern void isr2  ();
	extern void isr3  ();
	extern void isr4  ();
	extern void isr5  ();
	extern void isr6  ();
	extern void isr7  ();
	extern void isr8  ();
	extern void isr9  ();
	extern void isr10 ();
	extern void isr11 ();
	extern void isr12 ();
	extern void isr13 ();
	extern void isr14 ();
	extern void isr15 ();
	extern void isr16 ();
	extern void isr17 ();
	extern void isr18 ();
	extern void isr19 ();
	extern void isr20 ();
	extern void isr21 ();
	extern void isr22 ();
	extern void isr23 ();
	extern void isr24 ();
	extern void isr25 ();
	extern void isr26 ();
	extern void isr27 ();
	extern void isr28 ();
	extern void isr29 ();
	extern void isr30 ();
	extern void isr31 ();
}

//---------------------------------------------------------------------------
//    Forward function declarations
//---------------------------------------------------------------------------
static void idt_set_entry (s32 num, u32 base, u16 sel, u8 flags);
static void gdt_set_entry (s32 num, u32 base, u32 limit, u8 access, u8 flags);

//---------------------------------------------------------------------------
//    Functions implementation
//---------------------------------------------------------------------------
static void init_gdt()
{
	gdt_set_entry(0, 0,          0,    0,    0); // Null segment
	gdt_set_entry(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); // Code segment
	gdt_set_entry(2, 0, 0xFFFFFFFF, 0x92, 0xCF); // Data segment
	gdt_set_entry(3, 0, 0xFFFFFFFF, 0xFA, 0xCF); // User mode code segment
	gdt_set_entry(4, 0, 0xFFFFFFFF, 0xF2, 0xCF); // User mode data segment

	// set the ptr
	gdt_p.limit = sizeof (segment_descriptor) * 5 - 1;
	gdt_p.base = (u32)&gdt;

	asm_init_gdt ((u32)&gdt_p);
}

static void gdt_set_entry (s32 num, u32 base, u32 limit, u8 access, u8 flags)
{
	gdt[num].limit	= limit & 0xFFFF;
	gdt[num].basel	= base & 0xFFFF;
	gdt[num].basem	= (base >> 16) & 0xFF;
	gdt[num].baseh	= (base >> 24) & 0xFF;

	gdt[num].type	= access;
	gdt[num].flags	= (limit >> 16) & 0xF;
	gdt[num].flags |= flags & 0xF0;
}

static void init_idt()
{
	idt_p.limit = sizeof(idt_descriptor) * 256 - 1;
	idt_p.base = (u32)&idt;

	//__builtin_memset(&idt, 0, sizeof(idt_descriptor)*256);
	for (int i = 0; i < 256; i++)
	{
		idt[i].always0 = 0;
		idt[i].base_lo = 0;
		idt[i].base_hi = 0;
		idt[i].sel = 0;
		idt[i].flags = 0;
	}

	idt_set_entry( 0, (u32)isr0,  0x08, 0x8E);
	idt_set_entry( 1, (u32)isr1,  0x08, 0x8E);
	idt_set_entry( 2, (u32)isr2,  0x08, 0x8E);
	idt_set_entry( 3, (u32)isr3,  0x08, 0x8E);
	idt_set_entry( 4, (u32)isr4,  0x08, 0x8E);
	idt_set_entry( 5, (u32)isr5,  0x08, 0x8E);
	idt_set_entry( 6, (u32)isr6,  0x08, 0x8E);
	idt_set_entry( 7, (u32)isr7,  0x08, 0x8E);
	idt_set_entry( 8, (u32)isr8,  0x08, 0x8E);
	idt_set_entry( 9, (u32)isr9,  0x08, 0x8E);
	idt_set_entry(10, (u32)isr10, 0x08, 0x8E);
	idt_set_entry(11, (u32)isr11, 0x08, 0x8E);
	idt_set_entry(12, (u32)isr12, 0x08, 0x8E);
	idt_set_entry(13, (u32)isr13, 0x08, 0x8E);
	idt_set_entry(14, (u32)isr14, 0x08, 0x8E);
	idt_set_entry(15, (u32)isr15, 0x08, 0x8E);
	idt_set_entry(16, (u32)isr16, 0x08, 0x8E);
	idt_set_entry(17, (u32)isr17, 0x08, 0x8E);
	idt_set_entry(18, (u32)isr18, 0x08, 0x8E);
	idt_set_entry(19, (u32)isr19, 0x08, 0x8E);
	idt_set_entry(20, (u32)isr20, 0x08, 0x8E);
	idt_set_entry(21, (u32)isr21, 0x08, 0x8E);
	idt_set_entry(22, (u32)isr22, 0x08, 0x8E);
	idt_set_entry(23, (u32)isr23, 0x08, 0x8E);
	idt_set_entry(24, (u32)isr24, 0x08, 0x8E);
	idt_set_entry(25, (u32)isr25, 0x08, 0x8E);
	idt_set_entry(26, (u32)isr26, 0x08, 0x8E);
	idt_set_entry(27, (u32)isr27, 0x08, 0x8E);
	idt_set_entry(28, (u32)isr28, 0x08, 0x8E);
	idt_set_entry(29, (u32)isr29, 0x08, 0x8E);
	idt_set_entry(30, (u32)isr30, 0x08, 0x8E);
	idt_set_entry(31, (u32)isr31, 0x08, 0x8E);

	asm_init_idt((u32)&idt_p);
}

static void idt_set_entry (s32 num, u32 base, u16 sel, u8 flags)
{
	idt[num].base_lo = base & 0xFFFF;
	idt[num].base_hi = (base >> 16) & 0xFFFF;

	idt[num].sel = sel;
	idt[num].always0 = 0;
	idt[num].flags = flags;
}

static void isr_handler(registers_t regs)
{
	Video vid;
	vid.printk("received interrupt: %d\n", regs.int_no);
}

void init_tables()
{
	init_gdt();
	init_idt();
}
