#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Initializing some int values for later use
    int amount, i, j;
    int bricks = 1;

    // Ask the user for a int that is between 1 and 8, otherwise ask again
    do
    {
        amount = get_int("Height: ");
    }
    while (amount < 1 || amount > 8);

    // Creating the space variable for correct spacing
    int space = amount;

    // For loops to create the right hight of pyramid
    for (i = 0; i < amount; i++)
    {
        for (j = 1; j < space; j++)
        {
            printf(" ");
        }

        for (j = 0; j < bricks; j++)
        {
            printf("#");
        }
        printf("  ");

        for (j = 0; j < bricks; j++)
        {
            printf("#");
        }
        printf("\n");
        bricks++;
        space--;
    }
}
