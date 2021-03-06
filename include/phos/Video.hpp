/* The project is licensed under GNU GPL v3. See $(PROJECT_ROOT)/doc/gpl.txt for more details.
 *
 * phOS Operating System
 * Copyright (C) 2009 Cristian Bidea
 */

#ifndef VIDEO_HPP_
#define VIDEO_HPP_

#include <phos/Kernel.hpp>

extern "C" {

	/* Extern functions implemented in monitor.s */
	extern void putc (s8 c);
	extern void move ();
	extern void scroll ();
	extern void clrscr ();
}

class Video
{
public:
	Video ();
	~Video ();
	void printk (s8* format, ...);

private:
	unsigned short *videomem;
	unsigned int off;
	unsigned int pos;

	void write_dec (s32 c);
	void write (const s8* str);
	void write_hex (s32 c);
}; 

#endif // VIDEO_HPP_
