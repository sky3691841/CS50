#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //do-while loop: request an integer from the user until it's valid
    int height, i, j, k;

    do
    {
        printf("Please enter a non-negative integer no greater than 23\n");
        height = get_int();
    }
    while (height > 23 || height < 0);

    //print the pyramid
    for (i = 0; i < height; i++)
    {
        //print left spaces
        for (j = 1; j < (height - i); j++)
        {
            printf(" ");
        }

        //print left hashes
        for (k = 0; k < (i + 1); k++)
        {
            printf("#");
        }

        //print middle space
        printf("  ");

        //print right hashes
        for (k = 0; k < (i + 1); k++)
        {
            printf("#");
        }

        //next line
        printf("\n");
    }
}
