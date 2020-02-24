/*
** EPITECH PROJECT, 2019
** my_getnbr_base.c
** File description:
** get a number in given base in decimal base
*/

int get_index(char nb, char const *base)
{
    int i = 0;

    for (i = 0; !(base[i] == '\0' || base[i] == nb); i++) {}
    return i;
}

int is_base(char nb, char const *base)
{
    for (int c = 0; base[c] != '\0'; c++) {
        if (base[c] == nb)
            return 1;
    }
    return 0;
}

int power(int nb, int power)
{
    int count = nb;

    if (power == 0)
        return 1;
    if (power == 1)
        return nb;
    for (; power > 1; power--)
        count *= nb;
    return count;
}

int base_to_deci(char *str_pos, char *base)
{
    int conversion = 0;
    int length_str = 0;
    int length_base = 0;
    int count = 0;

    for (length_str = 0; str_pos[length_str] != '\0'; length_str++) {}
    for (length_base = 0; base[length_base] != '\0'; length_base++) {}
    for (int c = 0; c < length_str; c++) {
        conversion = get_index(str_pos[c], base);
        conversion *= power(length_base, length_str - c - 1);
        count += conversion;
    }
    return count;
}

int my_getnbr_base(char const *str, char const *base)
{
    char *str_pos;
    int count = 0;
    int sign = 1;

    if (str[0] == '+' || str[0] == '-') {
        if (str[0] == '-')
            sign = -1;
        str_pos = &str[1];
    } else
        str_pos = str;
    for (int c = 0; str_pos[c] != '\0'; c++)
        if (!is_base(str_pos[c], base))
            return 0;
    count = base_to_deci(str_pos, base);
    if (sign < 0)
        count = - count;
    return count;
}
