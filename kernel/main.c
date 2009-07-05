#include <phos/monitor.h>

int main (int argc, char** argv)
{
	clrscr();
	move();
	printk ("hello\nworld\n%h\n%d\n%h", 100, 120, 0);
	return 0xABCDEF00;
}

