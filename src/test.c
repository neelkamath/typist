#include <stdio.h>
#include <string.h>
#include <time.h>

#include "accuracy.h"
#include "test.h"
#include "util.h"

void display(char msg[], int seconds)
{
    puts(msg);
    clock_t start = clock();
    while ((clock() - start) / CLOCKS_PER_SEC != seconds)
        ;
}

result test()
{
    display("Enter at least a part of the following passage.", 2);
    char *expected = "Once upon a time, there was a boy named Nix. Nix was a good boy. Nix was such a "
                     "good boy that the Oxford dictionary changed their definition of \"good\" from \"to "
                     "be desired or approved of\" to \"Nix\". One day, Nix was walking down a very long "
                     "and boring road. The road was very long. It was also very boring. Nix didn't like "
                     "long and boring roads, because they were long. He also didn't like them because they "
                     "were boring. But Nix continued walking down the long and boring road, because he was "
                     "a good boy. This made Webster's dictionary update their definition of \"great\" to "
                     "\"Nix walking down a long and boring road\", so that they were more competitive in the "
                     "highly competitive industry of making dictionaries.";
    puts(expected);
    int size = 1000;
    char entered[size];
    fgets(entered, size, stdin); // Clear input buffer.
    double minutes = time_input(entered, size) / 60.0;
    double words = strlen(entered) / 5.0;
    double accuracy = get_accuracy(expected, entered);
    double speed = words / minutes;
    result res = {accuracy, speed};
    return res;
}

double time_input(char chars[], int chars_size)
{
    struct timespec start, finish;
    clock_gettime(CLOCK_MONOTONIC, &start);
    fgets(chars, chars_size, stdin);
    clock_gettime(CLOCK_MONOTONIC, &finish);
    chars = strtok(chars, "\n");
    double s = finish.tv_sec - start.tv_sec, ns = (finish.tv_nsec - start.tv_nsec) / 1.0e9;
    return s + ns;
}
