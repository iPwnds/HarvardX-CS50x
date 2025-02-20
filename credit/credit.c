#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // asking the user for a card number and copying it for later
    long cardNumber = get_long("Number: ");
    long copyOfNumber = cardNumber;

    // initialising a few integer variables for later use
    int firstDigit = 0;
    int secondDigit = 0;
    int counter = 0;

    // getting the sum of the odd and the sum of the even numbers
    while (cardNumber > 0)
    {
        int number = cardNumber % 10;

        if (counter % 2 == 0)
        {
            firstDigit += number;
        }
        else
        {
            number *= 2;
            if (number > 9)
            {
                secondDigit += number - 9;
            }
            else
            {
                secondDigit += number;
            }
        }

        cardNumber /= 10;
        counter++;
    }

    // adding the even end odd numbers together to get the final number
    int finalNumber = firstDigit + secondDigit;

    // if the final number does not end in 0 then its a invalid card number
    if (finalNumber % 10 != 0)
    {
        printf("INVALID\n");
    }
    // if the final number ends in a 0 we start to check if the card number is a AMEX, MASTERCARD or
    // VISA
    else
    {
        while (copyOfNumber > 100)
        {
            copyOfNumber /= 10;
        }

        if (counter == 15 && (copyOfNumber == 34 || copyOfNumber == 37))
        {
            printf("AMEX\n");
        }
        else if (counter == 16 && (copyOfNumber >= 51 && copyOfNumber <= 55))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            copyOfNumber /= 10;
            if ((counter == 13 || counter == 16) && copyOfNumber == 4)
            {
                printf("VISA\n");
            }
            // if the card number properties does not match any of the previouse if statements its
            // an INVALID card number
            else
            {
                printf("INVALID\n");
            }
        }
    }
}
