#include <cs50.h>
#include <stdio.h>
#include <string.h>

int counter(char letter);
bool InArray(char element, char arr[], int n);
int main(void)
{
    string a = get_string("PLAYER 1\nInsert your word:\t");
    string b = get_string("PLAYER 2\nInsert your word:\t");
    string Players[2];
    Players[0] = a;
    Players[1] = b;

    int lens[2] = {strlen(Players[0]), strlen(Players[1])};
    int counters[2] = {0, 0};

    int i = 0;
    while (i < 2)
    {
        for (int j = 0; j < lens[i]; j++)
        {
            char x = Players[i][j];
            counters[i] += counter(x);
        }
        i++;
    }
    if (counters[0] == counters[1])
    {
        printf("Tie!\n");
    }

    else if (counters[0] < counters[1])
    {
        printf("Player 2 wins!\n");
    }
    else // if (counters[1] < counters[0])
    {
        printf("Player 1 wins!\n");
    }
}

int counter(char letter)
{
    int counter = 0;
    char letter1[10];
    letter1[0] = 'a';
    letter1[1] = 'e';
    letter1[2] = 'i';
    letter1[3] = 'l';
    letter1[4] = 'n';
    letter1[5] = 'o';
    letter1[6] = 'r';
    letter1[7] = 's';
    letter1[8] = 't';
    letter1[9] = 'u';

    char LETTER1[10];
    for (int i = 0; i < 10; i++)
    {
        LETTER1[i] = letter1[i] - 32;
    }

    char letter2[2];
    letter2[0] = 'd';
    letter2[1] = 'g';

    char LETTER2[2];
    for (int i = 0; i < 2; i++)
    {
        LETTER2[i] = letter2[i] - 32;
    }

    char letter3[4];
    letter3[0] = 'b';
    letter3[1] = 'c';
    letter3[2] = 'm';
    letter3[3] = 'p';
    char LETTER3[4];
    for (int i = 0; i < 4; i++)
    {
        LETTER3[i] = letter3[i] - 32;
    }

    char letter4[5];
    letter4[0] = 'f';
    letter4[1] = 'h';
    letter4[2] = 'v';
    letter4[3] = 'w';
    letter4[4] = 'y';
    char LETTER4[5];
    for (int i = 0; i < 5; i++)
    {
        LETTER4[i] = letter4[i] - 32;
    }

    char letter5 = 'k';
    char LETTER5 = 'K';

    char letter8[2];
    letter8[0] = 'j';
    letter8[0] = 'x';
    char LETTER8[2];
    for (int i = 0; i < 2; i++)
    {
        LETTER8[i] = letter8[i] - 32;
    }

    char letter10[2];
    letter10[0] = 'z';
    letter10[1] = 'q';
    char LETTER10[2];
    for (int i = 0; i < 2; i++)
    {
        LETTER10[i] = letter10[i] - 32;
    }

    // Starting of the real code

    if (InArray(letter, letter1, 10) == true || InArray(letter, LETTER1, 10) == true)
    {
        counter++;
    }

    else if (InArray(letter, letter2, 2) == true || InArray(letter, LETTER2, 2) == true)
    {
        counter += 2;
    }
    else if (InArray(letter, letter3, 4) == true || InArray(letter, LETTER3, 4) == true)
    {
        counter += 3;
    }
    else if (InArray(letter, letter4, 5) == true || InArray(letter, LETTER4, 5) == true)
    {
        counter += 4;
    }
    else if (letter == letter5 || letter == LETTER5)
    {
        counter += 5;
    }
    else if (InArray(letter, letter8, 2) == true || InArray(letter, LETTER8, 2) == true)
    {
        counter += 8;
    }
    else if (InArray(letter, letter10, 2) == true || InArray(letter, LETTER10, 2) == true)
    {
        counter += 10;
    }

    else
    {
        counter += 0;
    }

    return (counter);
}

bool InArray(char element, char arr[], int n)
{
    bool container = false;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element)
        {
            container = true;
            break;
        }
        else
        {
            container = false;
        }
    }
    return container;
}
