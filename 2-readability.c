#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int arac = 0;
int number_words = 100;
bool Letter(char element);
bool Separator(char element);
char End_sentence[3] = {'.', '!', '?'};

bool InArray(char element, char arr[], int n);

int main(void)
{
    string text = get_string("Insert you text:\n");
    int len = strlen(text);
    float letters = 0.0;
    float words = 1.0;
    float phrases = 0.0;

    for (int i = 0; i < len; i++)
    {
        if (Letter(text[i]) == true)
        {
            letters++;
        }
        else if (text[i] == ' ')
        {
            words++;
        }
        else if (Separator(text[i]) == true && Separator(text[i - 1]) == false)
        {
            phrases++;
        }
    }

    float L = letters / words * number_words;
    float S = phrases / words * number_words;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int INDEX = round(index);

    if (INDEX < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (INDEX >= 16)
    {
        printf("Grade %d", 16);
        printf("+\n");
    }
    else
    {
        for (int i = 2; i < 16; i++)
        {
            if (INDEX == i)
            {
                printf("Grade %d\n", INDEX);
            }
        }
    }
}

bool Letter(char element)
{
    bool uppercase = (element >= 'a') && (element <= 'z');
    bool lowercase = (element >= 'A') && (element <= 'Z');
    if (uppercase == true || lowercase == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Separator(char element)
{
    bool A;
    for (int i = 0; i < 3; i++)
    {
        if (element == End_sentence[i])
        {
            A = true;
            break;
        }
        else
        {
            A = false;
        }
    }
    return A;
}
