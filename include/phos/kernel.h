/* The project is licensed under GNU GPL v3. See $(PROJECT_ROOT)/doc/gpl.txt for more details.
 *
 * phOS Operating System
 * Copyright (C) 2009 Cristian Bidea
 */

#ifndef _KERNEL_H_
#define _KERNEL_H_

typedef unsigned long	u64;
typedef		 long	s64;
typedef unsigned int	u32;
typedef		 int	s32;
typedef unsigned short	u16;
typedef		 short  s16;
typedef unsigned char	u8;
typedef		 char	s8;

void printk (s8* str, ...);

#endif
