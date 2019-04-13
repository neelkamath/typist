#include <stdio.h>

#include "accuracy.h"
#include "save.h"
#include "test.h"

char *file = "records.txt";

/* 
    Returns the option the user selected. 
    This will repeatedly prompt the user for an option until a valid one has been inputted.
*/
char get_option();

void print_records(int size, record records[size]);

// Prints the records in the file named <file>.
void display_records(char *file);

int main()
{
    while (1)
    {
        char option = get_option();
        puts("");
        switch (option)
        {
        case 's':
            puts("A professional typist types 50-80 WPM and an advanced typist types 120 WPM.");
            display_records(file);
            break;
        case 't':
            printf("Enter username (no spaces): ");
            record r;
            scanf("%s", r.name);
            result res = test();
            r.accuracy = res.accuracy;
            r.speed = res.speed;
            save_record(file, r);
            printf("Accuracy: %f%% Speed: %f WPM\n", r.accuracy, r.speed);
            break;
        case 'q':
            return 0;
        }
        puts("");
    }
}

char get_option()
{
    char option;
    while (!(option == 's' || option == 't' || option == 'q'))
    {
        printf("Enter \"s\" to view statistics, \"t\" to test your typing speed, or \"q\" to quit the program: ");
        while ((option = getchar()) == '\n' || option == EOF)
            /* Discard buffered input. */;
    }
    return option;
}

void print_records(int size, record records[size])
{
    int i;
    for (i = 0; i < size; i++)
        printf("Record %d - Username: %s Accuracy: %f%% Speed: %f WPM\n",
               i + 1,
               records[i].name,
               records[i].accuracy,
               records[i].speed);
}

void display_records(char *file)
{
    int size = count_records(file);
    record records[size];
    read_records(file, size, records);
    size == 0 ? puts("No records.") : print_records(size, records);
}
