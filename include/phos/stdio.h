/** \file stdio.h
 *
 * Standard functions that are built into the compiler.
 */

#ifndef  STDIO_INC
#define  STDIO_INC

#define va_list __builtin_va_list
#define va_start(a, b) __builtin_va_start ((a), (b))
#define va_arg(a, b) __builtin_va_arg ((a), b)
#define va_end(a) __builtin_va_end ((a)) 
#define strcpy(a, b) __builtin_strcpy ((a), (b))

#endif   /* ----- #ifndef STDIO_INC  ----- */

