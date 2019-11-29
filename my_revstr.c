/*
** EPITECH PROJECT, 2019
** disp
** File description:
** disp
*/

char *my_revstr(char *str)
{
   int i;
   int x = 0;
   char reve;

    for (i = 0; str[i] != '\0'; i++) {
      i--;
    }
    while (x < i) {
        reve = str[x];
        str[x] = str[i];
        str[i] = reve;
        i--;
        x++;
    }
    return(str);
}