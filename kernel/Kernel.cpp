/* The project is licensed under GNU GPL v3. See $(PROJECT_ROOT)/doc/gpl.txt for more details.
 *
 * phOS Operating System
 * Copyright (C) 2009 Cristian Bidea
 */

#include <phos/InitSetup.hpp>
#include <phos/Video.hpp>

Video vid;

int main(void)
{
	vid.printk("Hello, world! %d", 10);
	init_tables();
	return 0xABCD0123;
}

