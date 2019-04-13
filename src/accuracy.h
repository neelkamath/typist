/*
    This returns the accuracy of a user-entered passage in terms of percentage.
    <expected> is the orignal passage which was to be typed. <actual> is the passage which was entered by the user.
*/
double get_accuracy(char expected[], char actual[]);

/*
    Returns the number of words in str.
    For example, count_words("Nix was a good boy.") = 5, count_words("hi") = 1, count_words("") = 0.
    Caveat: Multiple consecutive spaces aren't taken into account (i.e., count_words("Nix	was") = 3 instead of 2).
*/
int count_words(char *str);

/*
    Splits str into words (size is the number of words).
    For example, split("Nix was a good boy.") makes words become ["Nix", "was", "a", "good", "boy."].
    Caveats: 
        Multiple consecutive spaces are considered as multiple words (i.e., split("Nix	was") makes words
        become ["Nix", "", "was"] instead of ["Nix", "was"]).
        The maximum size of a word has been hardcoded to 1000.
*/
void split(char *str, int size, char words[size][1000]);