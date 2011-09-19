#include <phos/Video.hpp>

void* __dso_handle;

/**
 * Constructor.
 */
Video::Video()
{
	pos = 0;
	off = 0;
	videomem = (unsigned short*) 0xb8000;
}

/**
 * Destructor.
 */
Video::~Video()
{
}

/**
 * printk is a function similar to printf.
 *
 * @param format - the format of the text being printed and also you can use 
 *                 multiple switches:
 *<ul>
 *<li>%d - output an int value
 *<li>%h - output an int value into hex format
 *</ul>
 */
void Video::printk (s8* format, ...)
{
	va_list args;
	va_start (args, format);
	s8 *c = format;
	while (*c) {
		if (*c == '%') {
	 	 	 *c = '\0'; ++c;
			 write (format);
			 switch (*c) {
			 case ('d'):
	 	 	 	 write_dec (va_arg(args, s32));
				 break;
			 case ('h'):
	 	 	 	 write_hex (va_arg(args, s32));
				 break;
			 }

			 format = ++c;
		 } else
			 ++c;
	}

	write (format);

	va_end (args);
	move();
}

/**
 * Used to write an array of characters on the screen.
 * The scrolling of the screen is handled in the putc
 * assembly routine.
 */
void Video::write (const s8* str)
{
	while (*str != '\0')
	{
		putc (*str);
		str++;
	}
}

/**
 * Write an integer on the screen.
 * TODO: Handle the sign.
 */
void Video::write_dec (s32 c)
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

/**
 * Write an integer in hex format.
 */
void Video::write_hex (s32 c)
{
	 /* convert from base 10 to 16 */
         if (c == 0) {
		write ("0x");
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

	 write ("0x");
	 while (i >= 0)
		 putc (result[i--]);
}

