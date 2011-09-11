/* The project is licensed under GNU GPL v3. See $(PROJECT_ROOT)/doc/gpl.txt for more details.
 *
 * phOS Operating System
 * Copyright (C) 2009 Cristian Bidea
 */

#ifndef _KERNEL_HPP_
#define _KERNEL_HPP_

//---------------------------------------------------------------------------
//    Defines
//---------------------------------------------------------------------------
#define va_list __builtin_va_list
#define va_start(a, b) __builtin_va_start ((a), (b))
#define va_arg(a, b) __builtin_va_arg ((a), b)
#define va_end(a) __builtin_va_end ((a)) 
#define strcpy(a, b) __builtin_strcpy ((a), (b))

//---------------------------------------------------------------------------
//    Type definitions
//---------------------------------------------------------------------------
typedef unsigned long	u64;
typedef		 long	s64;
typedef unsigned int	u32;
typedef		 int	s32;
typedef unsigned short	u16;
typedef		 short  s16;
typedef unsigned char	u8;
typedef		 char	s8;

//---------------------------------------------------------------------------
//    Functions declaration
//---------------------------------------------------------------------------
void printk (s8* str, ...);

#endif // _KERNEL_HPP_
