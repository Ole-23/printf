#include <unistd.h>

/**
 * _putchar - Custom putchar function
 * @c: Character to be written
 * Return: The number of characters written
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}
