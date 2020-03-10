/*
** EPITECH PROJECT, 2019
** set_list.c
** File description:
** set list
*/

#include <stdlib.h>
#include "my.h"

list_t *new_node(int nb)
{
    list_t *node = malloc(sizeof(list_t));

    if (node == NULL)
        return (NULL);
    if (nb < 0) {
        node->nb = -nb;
        node->sign = -1;
    } else {
        node->nb = nb;
        node->sign = 1;
    }
    node->prev = NULL;
    node->next = NULL;
    return (node);
}

void add_node_end_list(list_t **list, int nb)
{
    list_t *node = new_node(nb);
    list_t *tmp = *list;

    if (tmp == NULL) {
        tmp = node;
        tmp->next = tmp;
        tmp->prev = tmp;
        *list = tmp;
        return;
    }
    node->next = tmp->next;
    node->prev = tmp;
    tmp->next = node;
    tmp->next->next->prev = tmp->next;
    *list = tmp;
}

int get_size(unsigned int x, int len)
{
    int size = sizeof(int) * 8 - 1;

    for (; size >= 0 && GET_BIT(x, size) == 0; size--);
    size++;
    if (size > len)
        return (size);
    return (len);
}

list_t *set_list(int ac, char **av, int *len, int *status)
{
    list_t *list = NULL;
    int nb = 0;
    int stock = MIN;

    for (int i = 1; i < ac; i++) {
        nb = my_atoi(av[i]);
        if (nb < stock)
            (*status)++;
        add_node_end_list(&list, nb);
        *len = get_size(list->nb, *len);
        stock = nb;
        list = list->next;
    }
    list = list->next;
    return (list);
}
