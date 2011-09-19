/* The project is licensed under GNU GPL v3. See $(PROJECT_ROOT)/doc/gpl.txt for more details.
 *
 * phOS Operating System
 * Copyright (C) 2009 Cristian Bidea
 */

#ifndef _INIT_SETUP_HPP_
#define _INIT_SETUP_HPP_

#include <phos/Kernel.hpp>

//---------------------------------------------------------------------------
//    Defines
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//    Structs and type definitions
//---------------------------------------------------------------------------
struct segment_descriptor_struct
{
	u16	limit;
	u16	basel;
	u8	basem;
	u8	type;
	u8	flags;
	u8	baseh;
} __attribute__ ((packed));

struct gdt_ptr_struct
{
	u16 	limit;
	u32 	base;
} __attribute__ ((packed));

struct idt_descriptor_struct
{
	u16 	base_lo;
	u16 	sel;
	u8 	always0;
	u8 	flags;
	u16 	base_hi;
} __attribute__ ((packed));

struct idt_ptr_struct
{
	u16 	limit;
	u32 	base;
} __attribute__ ((packed));

typedef struct registers {
	u32 ds;
	u32 edi, esi, ebp, esp, ebx, edx, ecx, eax;
	u32 int_no, err_code;
	u32 eip, cs, eflags, useresp, ss;
} registers_t;

typedef struct segment_descriptor_struct segment_descriptor;
typedef struct gdt_ptr_struct gdt_ptr;
typedef struct idt_descriptor_struct idt_descriptor;
typedef struct idt_ptr_struct idt_ptr;
typedef void (*ISRHandlerCallback)(registers_t);

//---------------------------------------------------------------------------
//    Class definitions
//---------------------------------------------------------------------------
class KernelInit
{
public:
	void init_tables();
	void init_timer(u32 freq);
	void CallIRQHandler(registers_t regs);
private:
	u32 tick;
	ISRHandlerCallback irqHandlers[256];

	void init_gdt();
	void init_idt();
	void RegisterInterruptHandler(u8 n, ISRHandlerCallback handler);
};

#endif // _INIT_SETUP_HPP_
