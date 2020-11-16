#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <inttypes.h>

// Define terminal colors. 
#define RED  "\x1B[31m"
#define GRN  "\x1B[32m"
#define NRM  "\x1B[0m"

// Max amount of charathers
#define MAX_INPUT 50
// Max amount of words
#define N 9894

// True and false
#define TRUE 1
#define FALSE 0

// Array of char pointors (memoray addresses)
char *words[N];

// Statsitcs
int word_count = 0;
int correct_words = 0;

// Prototypes (functions)
int getInt(char *txt);
int load();
int testRanWord(int i);
int freeMem();

// Main function which get excuted when the pgrogams starts
int main()
{
    int num = 0;

    // Get intager
    while (num == FALSE)
    {
        num = getInt("How many words? ");
    }


    // Load words into memory
    int file_status = load();
    
    if (file_status == FALSE) return FALSE;

    // Save curent UTC timestamp 
    time_t start = time(NULL);

    // Promot a word an test num times
    for (int i = 0; i < num; i++) testRanWord(i);

    // Save curent UTC timestamp 
    time_t end = time(NULL);

    // Seconds difeance
    int secs = (int)(end - start);
    
    // Calculate the word par seconds
    double wps = (float)correct_words / (float)(secs / 60.0);

    // Print the resualts
    printf("Correct:  %iw\nTime:     %is\n%.0fw/min\n", correct_words, secs, wps);

    // Free Up memory
    freeMem();
}


// Get amount for words that will be tested
int getInt(char *txt)
{
    printf("%s", txt);

    char str[MAX_INPUT];
    
    // copy to the chars array
    scanf("%s", str);

    char *str_r;

    // parse intager (convert char to intager)
    int num = (int) strtol(str, &str_r, 10);

    // Check if string inludes more then ints
    if (*str_r != '\0') return FALSE;
    else return num;
}


// Load words to an array in memory
int load()
{
    // Save words file to memory
    FILE *f = fopen("./dicationary.txt", "r");
    if (f == NULL)
    {
        printf("Can't open the file");
        return FALSE;
    }

    char word[20];

    // Scan a word at the time until the end of file 
    // and save in word var
    while (fscanf(f, "%s", word) != EOF)
    {
        // Allocate memory 20 bytes
        char *mem = malloc(sizeof(char) * 20);
        if (mem == NULL)
        {
            fclose(f);
            freeMem();
            return printf("No memory");  
        }

        // Copy the a word to somewhere in the array
        strcpy(mem, word);
        words[word_count] = mem;
        word_count++;
    }

    // Remove file chunk from memory
    fclose(f);
    
    return TRUE;
}


// Test a random word
int testRanWord(int i)
{
    // Get random word between 1-10 000
    srand(time(NULL) + i);
    int ran = rand() % (N - 1);

    // Access a word using the random number
    printf("%s\n", words[ran]);

    // Get user input
    char name[MAX_INPUT];
    scanf("%s", name);

    // Compare both values
    if (strcmp(name, words[ran]) == 0)
    {
        printf("%sCorrect\n\n%s", GRN, NRM);
        ++correct_words;
    }
    else {
        printf("%sFalse\n\n%s", RED, NRM);
    }

    return TRUE;
}

// Free upp memory used by the application after is
// done executing
int freeMem()
{
    // Go throw every word and free it
    for (int i = 0; i < word_count; i++)
    {
        free(words[i]);
    }
    return FALSE;
}