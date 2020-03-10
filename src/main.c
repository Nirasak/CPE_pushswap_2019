/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main
*/

#include <stdbool.h>
#include "my.h"

bool is_alpha(char c)
{
    if (c == '-' || (c >= '0' && c <= '9'))
        return (true);
    return (false);
}

bool check_error(int ac, char **av)
{
    int j = 0;

    if (ac == 1)
        return (false);
    for (int i = 1; i < ac; i++) {
        j = 0;
        while (av[i][j] != '\0' && is_alpha(av[i][j]) == true)
            j++;
        if (is_alpha(av[i][j]) == false && av[i][j] != '\0')
            return (false);
    }
    return (true);
}

int main(int ac, char **av)
{
    if (check_error(ac, av) == false)
        return (84);
    pushswap(ac, av);
    my_putchar('\n');
    return (0);
}
