/*
** EPITECH PROJECT, 2019
** test_my_pushswap.c
** File description:
** test pushswap
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void redirect_stdout(void)
{
    cr_redirect_stdout();
}

Test(pushswap, test_one, .init = redirect_stdout)
{
    char *av[3] = {"./pushswap", "42", "21"};

    pushswap(3, av);
    cr_assert_stdout_eq_str(
        "pb ra pa ra pb pa ra pb pa ra pb pa ra pb pa ra pb pa");
}

Test(pushswap, test_two, .init = redirect_stdout)
{
    char *av[3] = {"./pushswap", "42", "-21"};

    pushswap(3, av);
    cr_assert_stdout_eq_str(
        "pb ra pa ra pb pa ra pb pa ra pb pa ra pb pa ra pb pa pb ra pa");
}

Test(pushswap, test_three)
{
    char *av[3] = {"./pushswap", "2", "2"};

    cr_assert_eq(pushswap(3, av), 0);
}

Test(pushswap, test_four, .init = redirect_stdout)
{
    char *av[4] = {"./pushswap", "-21", "0", "-21"};

    pushswap(4, av);
    cr_assert_stdout_eq_str("ra pb ra pa pb pb pb pa pa "
        "pa pb ra ra pa pb pb pb pa pa pa pb ra ra pa ra pb pb rrb pa pa");
}
