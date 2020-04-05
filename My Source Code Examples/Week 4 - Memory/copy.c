#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    // Get a string
    char *name = get_string("s: ");

    // Allocate memory for another string
    char *count = malloc(strlen(name) + 1);

    // Copy string into memory
    for (int i = 0, n = strlen(name); i <= n; i++)
    {
        count[i] = name[i];
    }
    // Capitalize copy
    count[0] = toupper(count[0]);

    // Print string
    printf("Name: %s\n", name);
    printf("Upper: %s\n", count);
}
