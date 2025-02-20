#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int countL(string text);
int countW(string text);
int countS(string text);

int main(void)
{
    // Ask the user for some text
    string text = get_string("Text: ");

    // Run the count method on the user input to count some metics
    int letters = countL(text);
    int words = countW(text);
    int sentences = countS(text);

    // Compute the Coleman-Liau index
    float L = ((float) letters / words) * 100;
    float S = ((float) sentences / words) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int rounded = round(index);

    // Print the grade level
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", rounded);
    }
}

// Function for counting letters
int countL(string text)
{
    // Creating the counter
    int counter = 0;

    // Counting the amount of letters
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            counter++;
        }
    }

    // Returning the output
    return counter;
}

// Function for counting words
int countW(string text)
{
    // Creating the counter
    int counter = 1;

    // Counting the amount of words
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == ' ')
        {
            counter++;
        }
    }

    // Returning the output
    return counter;
}

// Function for counting sentences
int countS(string text)
{
    // Creating the counter
    int counter = 0;

    // Counting the amount of sentences
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            counter++;
        }
    }

    // Returning the output
    return counter;
}
