/*
** EPITECH PROJECT, 2019
** pushswap.c
** File description:
** pushswap
*/

#include <stdlib.h>
#include "my.h"

void my_pb(list_t **la, list_t **lb, int check)
{
    list_t *tmp = *la;

    if ((*la) == (*la)->next)
        check = 1;
    *la = (*la)->next;
    (*la)->prev = (*la)->prev->prev;
    (*la)->prev->next = *la;
    if ((*lb) == NULL) {
        tmp->next = tmp;
        tmp->prev = tmp;
        *lb = tmp;
    } else {
        tmp->next = *lb;
        tmp->prev = (*lb)->prev;
        (*lb)->prev->next = tmp;
        (*lb)->prev = tmp;
        *lb = tmp;
    }
    if (check == 1)
        (*la) = NULL;
}

void my_pa(list_t **la, list_t **lb, int check)
{
    list_t *tmp = *lb;

    if ((*lb) == (*lb)->next)
        check = 1;
    *lb = (*lb)->next;
    (*lb)->prev = (*lb)->prev->prev;
    (*lb)->prev->next = *lb;
    if ((*la) == NULL) {
        tmp->next = tmp;
        tmp->prev = tmp;
        *la = tmp;
    } else {
        tmp->next = *la;
        tmp->prev = (*la)->prev;
        (*la)->prev->next = tmp;
        (*la)->prev = tmp;
        *la = tmp;
    }
    if (check == 1)
        (*lb) = NULL;
}

void main_loop(list_t **la, list_t **lb, int i, int ac)
{
    for (int j = 1; j < ac; j++) {
        if (i != 0 || j != 1)
            my_putchar(' ');
        if (GET_BIT((*la)->nb, i) == 0) {
            my_pb(la, lb, 0);
            my_putstr("pb");
        } else {
            *la = (*la)->next;
            my_putstr("ra");
        }
    }
    while (*lb != NULL) {
        my_pa(la, lb, 0);
        my_putstr(" pa");
    }
}

void loop_neg(list_t **la, list_t **lb, int ac)
{
    int neg = 0;

    for (int j = 1; j < ac; j++) {
        if ((*la)->sign == -1)
            neg = 1;
        *la = (*la)->next;
    }
    if (neg == 0)
        return;
    for (int j = 1; j < ac; j++) {
        if ((*la)->sign == -1) {
            my_pb(la, lb, 0);
            my_putstr(" pb");
        } else {
            *la = (*la)->next;
            my_putstr(" ra");
        }
    }
}

int pushswap(int ac, char **av)
{
    int size = 0;
    int status = 0;
    list_t *la = set_list(ac, av, &size, &status);
    list_t *lb = NULL;

    if (status == 0)
        return (0);
    for (int i = 0; i < size; i++)
        main_loop(&la, &lb, i, ac);
    loop_neg(&la, &lb, ac);
    while (lb != NULL) {
        if (lb != lb->next) {
            lb = lb->prev;
            my_putstr(" rrb");
        }
        my_pa(&la, &lb, 0);
        my_putstr(" pa");
    }
    return (0);
}
