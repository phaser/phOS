/* The project is licensed under GNU GPL v3. See $(PROJECT_ROOT)/doc/gpl.txt for more details.
 *
 * phOS Operating System
 * Copyright (C) 2009 Cristian Bidea
 */

#include <phos/Video.hpp>
extern "C" {
	#include <phos/hw_tables.h>
}

Video vid;

int main(void)
{
	vid.printk("Hello, world! %d", 10);
	init_gdt();
	return 0xABCD0123;
}

