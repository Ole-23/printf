#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 * @...: Additional arguments
 * Return: Number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int char_count = 0;

    va_start(args, format);

    while (format && *format)
    {
        if (*format != '%')
        {
            write(1, format, 1);
            char_count++;
        }
        else if (*format == '%' && *(format + 1) != '\0')
        {
            format++; // Move to the character after '%'
            if (*format == 'c')
            {
                // Handle %c
                char c = va_arg(args, int);
                write(1, &c, 1);
                char_count++;
            }
            else if (*format == 's')
            {
                // Handle %s
                char *str = va_arg(args, char *);
                write(1, str, _strlen(str));
                char_count += _strlen(str);
            }
            else if (*format == '%')
            {
                // Handle %%
                write(1, "%", 1);
                char_count++;
            }
        }

        format++; // Move to the next character in the format string
    }

    va_end(args);

    return char_count;
}
