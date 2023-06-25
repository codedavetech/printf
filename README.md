A custom _printf function implementation

The _printf function is a custom implementation of the standard C library function printf. It allows you to format and output text to the console or other output streams.

This program implements a custom printf function that supports the following conversion specifiers:

**%c** : prints a single character
**%s** : prints a null-terminated string
**%d**, %i, %u, %o, %x, %X : prints a signed/unsigned integer in decimal, octal, or hexadecimal format
**%p** : prints a pointer address
**%S** : prints a string with non-printable characters represented in the format \xXX (where XX is the ASCII code value in hexadecimal, always two characters in uppercase)
The program also supports the following flag characters:

**0** : left-pads the output with zeros instead of spaces
**#** : left-justifies the output within the given field width
**+** : always prints the sign of a signed number (+ or -)
**space** : prints a space before a positive number (overrides the + flag)
The program also supports the following length modifiers:

**h** : short (for integers)
**l** : long (for integers)
In addition, the program supports the following custom conversion specifiers:

**%r** : prints the reversed string
**%R** : prints the rot13'ed string
The maximum field width that can be specified is 1024 characters. This buffer size is used to minimize the number of calls to the write function.

This project is a collaboration between:
*#  Chibuikem David*
*#  Mohamed Abdi*
