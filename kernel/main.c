#include <phos/monitor.h>
#include <phos/hw_tables.h>

int main (int argc, char** argv)
{
	clrscr();
	move();
	printk ("hello\nworld\n%h\n%d\n%h", 100, 120, 0);
	init_gdt();
	return 0xABCDEF00;
}

