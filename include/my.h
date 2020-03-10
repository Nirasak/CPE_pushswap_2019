/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#define GET_BIT(x, i) (x & (1u << i) ? 1 : 0)

#define MIN -2147483648

typedef struct list
{
    int sign;
    int nb;
    struct list *next;
    struct list *prev;
} list_t;

int pushswap(int ac, char **av);
list_t *set_list(int ac, char **av, int *len, int *status);
int my_atoi(char *av);
void my_putstr(char const *str);
void my_putchar(char c);

#endif
