#include <phos/monitor.h>

int main (int argc, char** argv)
{
	move();
	printk ("hello\nworld\n%h\n%d\n%h\n", 100, 120, 0);
	return 0xABCDEF00;
}

