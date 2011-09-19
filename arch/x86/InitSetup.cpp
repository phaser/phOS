/* The project is licensed under GNU GPL v3. See $(PROJECT_ROOT)/doc/gpl.txt for more details.
 *
 * phOS Operating System
 * Copyright (C) 2009 Cristian Bidea
 */

#include <phos/InitSetup.hpp>
#include <phos/Video.hpp>

#define IRQ0	0
#define IRQ1	1
#define IRQ2	2
#define IRQ3	3
#define IRQ4	4
#define IRQ5	5
#define IRQ6	6
#define IRQ7	7
#define IRQ8	8
#define IRQ9	9
#define IRQ10	10
#define IRQ11	11
#define IRQ12	12
#define IRQ13	13
#define IRQ14	14
#define IRQ15	15
#define IRQ16	16
#define IRQ17	17
#define IRQ18	18
#define IRQ19	19
#define IRQ20	20
#define IRQ21	21
#define IRQ22	22
#define IRQ23	23
#define IRQ24	24
#define IRQ25	25
#define IRQ26	26
#define IRQ27	27
#define IRQ28	28
#define IRQ29	29
#define IRQ30	30
#define IRQ31	31

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
//    PUBLIC class functions implementation
//---------------------------------------------------------------------------
void KernelInit::init_tables()
{
	init_gdt();
	init_idt();
}

void KernelInit::init_timer(u32 freq)
{
	//register_interrupt_handler(IRQ0, &timer_callback);
}

void KernelInit::CallIRQHandler(registers_t regs)
{
	if (irqHandlers[regs.int_no] != 0)
	{
		ISRHandlerCallback handler = irqHandlers[regs.int_no];
		handler(regs);
	}
}

//---------------------------------------------------------------------------
//    PRIVATE class functions implementation
//---------------------------------------------------------------------------
void KernelInit::init_gdt()
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

void KernelInit::init_idt()
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

	idt_set_entry(IRQ0,  (u32)isr0,  0x08, 0x8E);
	idt_set_entry(IRQ1,  (u32)isr1,  0x08, 0x8E);
	idt_set_entry(IRQ2,  (u32)isr2,  0x08, 0x8E);
	idt_set_entry(IRQ3,  (u32)isr3,  0x08, 0x8E);
	idt_set_entry(IRQ4,  (u32)isr4,  0x08, 0x8E);
	idt_set_entry(IRQ5,  (u32)isr5,  0x08, 0x8E);
	idt_set_entry(IRQ6,  (u32)isr6,  0x08, 0x8E);
	idt_set_entry(IRQ7,  (u32)isr7,  0x08, 0x8E);
	idt_set_entry(IRQ8,  (u32)isr8,  0x08, 0x8E);
	idt_set_entry(IRQ9,  (u32)isr9,  0x08, 0x8E);
	idt_set_entry(IRQ10, (u32)isr10, 0x08, 0x8E);
	idt_set_entry(IRQ11, (u32)isr11, 0x08, 0x8E);
	idt_set_entry(IRQ12, (u32)isr12, 0x08, 0x8E);
	idt_set_entry(IRQ13, (u32)isr13, 0x08, 0x8E);
	idt_set_entry(IRQ14, (u32)isr14, 0x08, 0x8E);
	idt_set_entry(IRQ15, (u32)isr15, 0x08, 0x8E);
	idt_set_entry(IRQ16, (u32)isr16, 0x08, 0x8E);
	idt_set_entry(IRQ17, (u32)isr17, 0x08, 0x8E);
	idt_set_entry(IRQ18, (u32)isr18, 0x08, 0x8E);
	idt_set_entry(IRQ19, (u32)isr19, 0x08, 0x8E);
	idt_set_entry(IRQ20, (u32)isr20, 0x08, 0x8E);
	idt_set_entry(IRQ21, (u32)isr21, 0x08, 0x8E);
	idt_set_entry(IRQ22, (u32)isr22, 0x08, 0x8E);
	idt_set_entry(IRQ23, (u32)isr23, 0x08, 0x8E);
	idt_set_entry(IRQ24, (u32)isr24, 0x08, 0x8E);
	idt_set_entry(IRQ25, (u32)isr25, 0x08, 0x8E);
	idt_set_entry(IRQ26, (u32)isr26, 0x08, 0x8E);
	idt_set_entry(IRQ27, (u32)isr27, 0x08, 0x8E);
	idt_set_entry(IRQ28, (u32)isr28, 0x08, 0x8E);
	idt_set_entry(IRQ29, (u32)isr29, 0x08, 0x8E);
	idt_set_entry(IRQ30, (u32)isr30, 0x08, 0x8E);
	idt_set_entry(IRQ31, (u32)isr31, 0x08, 0x8E);

	asm_init_idt((u32)&idt_p);
}

void KernelInit::RegisterInterruptHandler(u8 n, ISRHandlerCallback handler)
{
	irqHandlers[n] = handler;
}

//---------------------------------------------------------------------------
//    Local functions implementation
//---------------------------------------------------------------------------
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

static void idt_set_entry (s32 num, u32 base, u16 sel, u8 flags)
{
	idt[num].base_lo = base & 0xFFFF;
	idt[num].base_hi = (base >> 16) & 0xFFFF;

	idt[num].sel = sel;
	idt[num].always0 = 0;
	idt[num].flags = flags;
}


