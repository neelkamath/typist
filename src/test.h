typedef struct
{
    double accuracy, speed;
} result;

// Pauses program execution for <seconds> seconds after calling <puts()> with <msg>.
void display(char msg[], int seconds);

// Returns the user's typing speed in WPM after prompting them to enter a passage.
result test();

// Returns the number of seconds it took to input <chars> (<chars> has size <chars_size>).
double time_input(char chars[], int chars_size);