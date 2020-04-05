#include <stdio.h>

int main(void)
{
    int numbers[6] = {5, 8, 15, 23, 26, 30};
    
    for (int i = 0; i < 6; i++)
    {
        if (numbers[i] == 50)
        {
            printf("Found\n");
        }
    }
    printf("Not found\n");
}
