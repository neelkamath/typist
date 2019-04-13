#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "save.h"

void save_record(char *file, record r)
{
    FILE *f = fopen(file, "a");
    fprintf(f, "%s %f %f\n", r.name, r.accuracy, r.speed);
    fclose(f);
}

void read_records(char *file, int size, record records[size])
{
    FILE *f = fopen(file, "r");
    if (f != NULL)
    {
        int len = 100;
        char line[len];
        int i;
        for (i = 0; i < size; i++)
            records[i] = read_record(fgets(line, len, f));
    }
    fclose(f);
}

int count_records(char *file)
{
    int size = 0, len = 100;
    char line[len];
    FILE *f = fopen(file, "r");
    while (f != NULL && fgets(line, len, f) != NULL)
        size++;
    fclose(f);
    return size;
}

record read_record(char line[])
{
    record r;
    strcpy(r.name, strtok(line, " "));
    r.accuracy = atof(strtok(NULL, " "));
    r.speed = atof(strtok(NULL, " "));
    return r;
}