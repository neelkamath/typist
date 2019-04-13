#include <string.h>

#include "accuracy.h"

double get_accuracy(char expected[], char actual[])
{
    int expected_size = count_words(expected), actual_size = count_words(actual), correct = 0, i;
    char expected_words[expected_size][1000], actual_words[actual_size][1000];
    split(expected, expected_size, expected_words);
    split(actual, actual_size, actual_words);
    for (i = 0; i < actual_size; i++)
        if (strcmp(expected_words[i], actual_words[i]) == 0)
            correct++;
    return ((double)correct / (double)actual_size) * 100.0;
}

int count_words(char *str)
{
    if (strlen(str) == 0)
        return 0;
    int words = 1, i;
    for (i = 0; i < strlen(str); i++)
        if (str[i] == ' ')
            words++;
    return words;
}

void split(char *str, int size, char words[size][1000])
{
    int i, index = 0, char_index = 0;
    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == ' ')
        {
            words[index][char_index] = '\0';
            index++;
            char_index = 0;
            continue;
        }
        words[index][char_index++] = str[i];
    }
    words[index][char_index] = '\0';
}