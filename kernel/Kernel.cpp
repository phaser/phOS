/* The project is licensed under GNU GPL v3. See $(PROJECT_ROOT)/doc/gpl.txt for more details.
 *
 * phOS Operating System
 * Copyright (C) 2009 Cristian Bidea
 */

#include <phos/InitSetup.hpp>
#include <phos/Video.hpp>

Video vid;
KernelInit kinit;

int main(void)
{
	vid.printk("Hello, world! %d", 10);
	kinit.init_tables();
	kinit.init_timer(100);
	while(1){}
	return 0xABCD0123;
}

extern "C" {
	void isr_handler(registers_t regs)
	{
		Video vid;
		vid.printk("received interrupt: %d\n", regs.int_no);
		kinit.CallIRQHandler(regs);
	}
}
