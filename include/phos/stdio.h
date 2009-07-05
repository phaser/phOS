/** \file stdio.h
 *
 * Standard functions that are built into the compiler.
 */

/*
 * phOS Operating System
 * Copyright (C) 2009  Cristian Bidea
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef  STDIO_INC
#define  STDIO_INC

#define va_list __builtin_va_list
#define va_start(a, b) __builtin_va_start ((a), (b))
#define va_arg(a, b) __builtin_va_arg ((a), b)
#define va_end(a) __builtin_va_end ((a)) 
#define strcpy(a, b) __builtin_strcpy ((a), (b))

#endif   /* ----- #ifndef STDIO_INC  ----- */

