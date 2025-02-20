#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int score(string word);

int main(void)
{
    // Gettings the players words
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    // Calculating the score of each player in the function score
    int score1 = score(player1);
    int score2 = score(player2);

    // Printing the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int score(string word)
{
    // Initializing score
    int score = 0;

    // Takes the word to break it down into pieces and calculates the score
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if (isupper(word[i]))
        {
            score += points[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += points[word[i] - 'a'];
        }
    }

    // Returning the score
    return score;
}
