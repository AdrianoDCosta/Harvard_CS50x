#include <string.h>
#include <stdio.h>

int main(void)
{
    char *n  = "ADRIANO";

    printf("The character %c corresponds to the Address %p\n", n[0], &n[0]);
    printf("The character %c corresponds to the Address %p\n", n[1], &n[1]);
    printf("The character %c corresponds to the Address %p\n", n[2], &n[2]);
    printf("The character %c corresponds to the Address %p\n", n[3], &n[3]);
    printf("The character %c corresponds to the Address %p\n", n[4], &n[4]);
    printf("The character %c corresponds to the Address %p\n", n[5], &n[5]);
    printf("The character %c corresponds to the Address %p\n", n[6], &n[6]);
}
