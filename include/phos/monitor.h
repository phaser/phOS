#ifndef _MONITOR_H_
#define _MONITOR_H_

#include <phos/kernel.h>

/* Extern functions implemented in monitor.s */
extern void putc (u8 c);
extern void move ();
extern void scroll ();
extern void clrscr ();

void printk (u8* str, ...);
void monitor_write_dec (s32 c);
void monitor_write (const u8* str);
void monitor_write_hex (s32 c);

#endif
