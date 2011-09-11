/* The project is licensed under GNU GPL v3. See $(PROJECT_ROOT)/doc/gpl.txt for more details.
 *
 * phOS Operating System
 * Copyright (C) 2009 Cristian Bidea
 */

#ifndef _INIT_SETUP_HPP_
#define _INIT_SETUP_HPP_

#include <phos/Kernel.hpp>

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
	u16 limit;
	u32 base;
} __attribute__ ((packed));

typedef struct segment_descriptor_struct segment_descriptor;
typedef struct gdt_ptr_struct gdt_ptr;

void init_gdt();

#endif // _INIT_SETUP_HPP_
