/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** put number
*/

void my_putchar(char c);

int calc_put_nbr(int nb)
{
    int i = 0;

    if (nb < 0) {
        nb = nb * - 1;
    }
    if (nb < 10) {
        my_putchar(nb + '0');
    } else {
        calc_put_nbr(nb / 10);
        i = nb % 10;
        my_putchar(i + '0');
    }
    return (0);
}

int my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        my_putchar('-');
        my_putchar('2');
        my_putchar('1');
        my_putchar('4');
        my_putchar('7');
        my_putchar('4');
        my_putchar('8');
        my_putchar('3');
        my_putchar('6');
        my_putchar('4');
        my_putchar('8');
        return (0);
    }
    if (nb < 0) {
        nb = nb * - 1;
        my_putchar('-');
    }
    calc_put_nbr(nb);
    return (0);
}
