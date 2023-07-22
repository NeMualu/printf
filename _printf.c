#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0;
    char c;
    char *s;

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++; // Move to the character after '%'
            switch (*format)
            {
            case 'c':
                c = va_arg(args, int);
                putchar(c);
                count++;
                break;
            case 's':
                s = va_arg(args, char *);
                while (*s != '\0')
                {
                    putchar(*s);
                    s++;
                    count++;
                }
                break;
            case '%':
                putchar('%');
                count++;
                break;
            default:
                // Unsupported conversion specifier, just print the '%'
                putchar('%');
                putchar(*format);
                count += 2;
                break;
            }
        }
        else
        {
            putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);

    return count;
}
