/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** task02
*/

#include <stdarg.h>

#ifndef MY
    #define MY

void my_putchar(char c);
char *my_strstr(char *str, char const *to_find);
int my_isneg(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_put_nbr(int nb);
int my_strncmp(char const *s1, char const *s2, int n);
void my_swap(int *a, int *b);
char *my_strupcase(char *str);
void my_putstr(char const *str);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
char *my_strcapitalize(char *str);
int my_getnbr(char const *str);
int my_str_isalpha(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isnum(char const *str);
int my_compute_power_rec(int nb, int power);
int my_str_islower(char const *str);
int my_compute_square_root(int nb);
int my_str_isupper(char const *str);
int my_is_prime(int nb);
int my_str_isprintable(char const *str);
int my_find_prime_sup(int nb);
int my_showstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_showmem(char const *str, int size);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_show_word_array(char *const *tab);
int my_printf(const char *format, ...);
void switch_case2(char const *format, va_list arg, int i);
void switchcase_modulo(const char *format, va_list arg, int i);
void switchcase_tag(const char *format, int arg, int i);
void s_flags(char *str);
char *change_base(int nb, char *base);
char *fs_open_file(char *filepath);
void fs_cat_x_bytes(char const * filepath, int x);
void fs_print_first_line(char const *filepath);
float **scaling_fac(float **co, char **argv, int i);
void usageh(void);
float **multiplication(float **co, float **co2);
float **translation_vec(float **co, char **argv, int i);
float **co_initialize(void);
float **initialize_xy(float x, float y);
void print_co(float **co);
void print_xy(float **co, char **argv);
float **mult_end(float **co, float **co2);
void architect(char **argv, int argc);
float **rotation(float **co, char **argv, int i);
float **reflection(float **co, char **argv, int i);
int nb_words(char *str, char delim);
void fill_word_array(char **res, char delim, char *str);
char **str_to_word_array(char *str, char delim);
int my_arraylen(char **str);
int my_intarraylen(int **array);
int my_intlen(int nb);
void fill_res(char *res, int i, char *str);
int same_str(char *str, char const *to_find, int i);
int str_cap(int j, int i, char *str, char *res);
int same_len(int size_s1, int size_s2, char const *s2, char const *s1);

#endif //MY
