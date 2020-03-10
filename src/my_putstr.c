/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** my_putstr
*/

#include <unistd.h>
#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char const *str)
{
    int len = 0;

    for (; str[len] != '\0'; len++);
    write(1, str, len);
}
