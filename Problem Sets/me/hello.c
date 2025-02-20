#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string answer = get_string("What's your name? "); // Asks the user for a string input
    printf("hello, %s\n", answer); // Prints "hello, " + the user input (string answer)
}
