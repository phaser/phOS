#ifndef _HW_TABLES_H_
#define _HW_TABLES_H_

#include <phos/kernel.h>

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

#endif
