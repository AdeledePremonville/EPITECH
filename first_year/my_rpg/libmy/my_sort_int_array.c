/*
** EPITECH PROJECT, 2021
** my_sort_int_array.c
** File description:
** sort array of integer in ascending order
*/

#include "../include/my.h"

void swap_smallest_nb(int *array, int size, int nb_case_to_swap)
{
    int save_nb_to_swap = 2147483647;
    int save_counter = 0;

    for (int i = nb_case_to_swap; i < size; i++) {
        if (save_nb_to_swap > array[i]) {
            save_nb_to_swap = array[i];
            save_counter = i;
        }
    }
    array[save_counter] = array[nb_case_to_swap];
    array[nb_case_to_swap] = save_nb_to_swap;
}

void my_sort_int_array(int *array, int size)
{
    int nb_case_to_swap = 0;

    for (int i = 0; i < size; i++) {
        swap_smallest_nb(array, size, nb_case_to_swap);
        nb_case_to_swap++;
    }
}
