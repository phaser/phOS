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
