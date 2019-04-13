/*
    Each record is saved on an individual line in the file using the format <<username> <accuracy> <speed>>, where
    <username> has no spaces, and <accuracy> and <speed> are <double>s.
    For example:
        neel_kamath 96.3 85.7
        tharun 87.5 67.2
        pavan 50.5 5.6
*/

typedef struct
{
    char name[100];
    double accuracy, speed;
} record;

// Saves <r> to a file named <file>.
void save_record(char *file, record r);

// Stores records from the file named <file> to <records>.
void read_records(char *file, int size, record records[size]);

// Returns the number of records in the file named <file>.
int count_records(char *file);

// Returns a record from a line in the saved records, <line>.
record read_record(char line[]);
