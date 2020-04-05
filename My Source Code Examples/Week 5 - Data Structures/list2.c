#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // malloc is being asked for 3 times the size of an int
    int *list = malloc(4 * sizeof(int));
    if (list == NULL)
    {
        return 1;
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    int *tmp = realloc(list, 4 * sizeof(int));
    if (tmp == NULL)
    {
        return 1;
    }

    list = tmp;

    tmp[3] = 4;

    // copy intergers from old array into new array
    for (int i = 0; i < 3; i++)
    {
        tmp[i] = list[i];
    }
    // store at location 3, 0 index, which means it's the fourth location, another value, number 4.
    tmp[3] = 4;

    free(list);

    list = tmp;

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }
}
