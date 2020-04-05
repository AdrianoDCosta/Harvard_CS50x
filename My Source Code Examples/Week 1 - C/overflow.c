#include <stdio.h>
#include <unistd.h>

int main(void)
{
    for (int n = 1; ; n *= 2)
    {
        printf("%i\n", n);
        sleep(1);
    }
}
