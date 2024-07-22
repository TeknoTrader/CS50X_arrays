#include <cs50.h>
#include <stdio.h>
#include <string.h>

char encrypt(char element, string Key);
char decrypt(char element, string Key); // This function was NOT USED in this code, but can be used to decrypt the messages sent with this code using the Key

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("ERROR 0: There must be 1 argument in the prompt!\n");
        return 1;
    }

    string Key = argv[1];

    if (strlen(Key) != 26) // Less than 26 letters
    {
        printf("Error 1: The string must contain 26 DIFFERENT LETTERS:\n");
        return 1;
    }

    for (int i = 0; i < 26; i++)
    {
        int counter = 0;
        for (int y = 0; y < 26; y++)
        {
            bool uppercase = Key[i] >= 65 && Key[i] <= 90;
            bool lowercase = Key[i] >= 97 && Key[i] <= 122;
            if (y != i && Key[i] == Key[y]) // letters repeated
            {
                printf("Error2: The string must contain 26 DIFFERENT LETTERS:\n");
                return 1;
            }

            if (uppercase == false && lowercase == false) // if there are not alphabetic charachters
            {
                printf("Error 3: The string must contain 26 DIFFERENT LETTERS:\n");
                return 1;
            }
        }
    }

    string word = get_string("plaintext:");
    char words[strlen(word)];
    for (int i = 0; i < strlen(word); i++)
    {
        words[i] = word[i];
    }

    printf("ciphertext:");
    for (int i = 0; i < strlen(word); i++)
    {
        bool lowercase = words[i] >= 'a' && words[i] <= 'z';
        bool uppercase = words[i] >= 'A' && words[i] <= 'Z';

        if (uppercase == false && lowercase == false)
        {
            printf("%c", word[i]);
        }
        else
        {
            char w = word[i];
            bool lowercase1 = encrypt(w, Key) >= 'a' && encrypt(w, Key) <= 'z';
            bool uppercase1 = encrypt(w, Key) >= 'A' && encrypt(w, Key) <= 'Z';
            if (lowercase == true)
            {
                if (lowercase1 == true)
                {
                    printf("%c", encrypt(w, Key));
                }
                else if (uppercase1 == true)
                {
                    char solution = encrypt(w, Key) + 32;
                    printf("%c", solution);
                }
            }
            else if (uppercase == true)
            {
                if (uppercase1 == true)
                {
                    printf("%c", encrypt(w, Key));
                }
                else if (lowercase1 == true)
                {
                    char solution = encrypt(w, Key) - 32;
                    printf("%c", solution);
                }
            }
        }
    }
    printf("\n");
}

char encrypt(char element, string Key)
{
    int number = element;
    int ret = 0;
    bool lowercase = element >= 'A' && element <= 'Z';
    bool uppercase = element >= 'a' && element <= 'z';

    if (lowercase)
     {
        ret = element - 'A';
     }
     else if (uppercase)
     {
        ret = element - 'a';
     }

    char result = Key[ret];
    return result;
}

char decrypt(char element, string Key) // do NOT let the "non-letters" go to this function!
{
    int number = element;
    int ret;
    bool lowercase = element >= 65 && element <= 90;
    bool uppercase = element >= 97 && element <= 122;
    for (int i = 0; i < 26; i++)
    {
        if (number == Key[i])
        {
            ret = i;
            break;
        }
    }

    char result;
    if (lowercase == true)
    {
        result = 65 + ret;
    }

    else
    {
        result = 97 + ret;
    }
    return result;
}
