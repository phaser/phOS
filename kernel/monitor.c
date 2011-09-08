#include <phos/monitor.h>
#include <phos/stdio.h>
#include <phos/kernel.h>

void printk (u8* format, ...)
{
	va_list args;
	va_start (args, format);
	u8 *c = format;
	while (*c) {
		if (*c == '%') {
	 	 	 *c = '\0'; ++c;
			 monitor_write (format);
			 switch (*c) {
			 case ('d'):
	 	 	 	 monitor_write_dec (va_arg(args, s32));
				 break;
			 case ('h'):
	 	 	 	 monitor_write_hex (va_arg(args, s32));
				 break;
			 }

			 format = ++c;
		 } else
			 ++c;
	}

	monitor_write (format);

	va_end (args);
	move();
}

void monitor_write (const u8* str)
{
	while (*str != '\0')
	{
		putc (*str);
		str++;
	}
}

void monitor_write_dec (s32 c)
{
       	 u8 result[11];
	 s16 i = -1;

	 while (c > 0) {
		 result[++i] = c % 10;
		 result[i] += 0x30; /* Make it an ascii character */
		 c /= 10;
	 }

	 /* writing the result on the screen in the correct order */
	 while (i >= 0) {
		putc (result[i--]);
	 }
}

void monitor_write_hex (s32 c)
{
	 /* convert from base 10 to 16 */
         if (c == 0) {
		monitor_write ("0x");
                putc (0x30);
                return;
         }

	 s8 result[11];
	 s16 i = -1;
	 while (c > 0) {
	 	 result [++i] = c % 16;
		 result [i] += (result[i] < 10 ? 0x30 : 0x37);
		 c /= 16;
	 }

	 monitor_write ("0x");
	 while (i >= 0)
		 putc (result[i--]);
}

