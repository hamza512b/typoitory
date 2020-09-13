#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <inttypes.h>

// Define terminal colors. 
#define RED  "\x1B[31m"
#define GRN  "\x1B[32m"
#define NRM  "\x1B[0m"

#define MAX_INPUT 50 // TODO segemntation fault if is bigger
#define N 9894

char *words[N];
int correct_words = 0;

// Prototypes
int getInt(char *txt);
int load();
int testRanWord(int i);
int freeMem();


int main()
{
    int num = 0;

    // Get intager
    while (num == 0)
    {
        num = getInt("How many words? ");
    }


    // Load words into memory
    load();
    
    // Save curent UTC seconds 
    time_t start = time(NULL);

    for (int i = 0; i < num; i++)
    {
        testRanWord(i);
    }

    // Save curent UTC seconds 
    time_t end = time(NULL);

    // Seconds difeance
    int secs = (int)(end - start);
    
    // Calculate the word par seconds
    double wps = (float)correct_words / (float)(secs / 60.0);

    printf("Correct:  %iw\nTime:     %is\n%.0fw/min\n", correct_words, secs, wps);

    // Clear up memory
    freeMem();
}


// Get a intenger 
int getInt(char *txt)
{
    printf("%s", txt);

    char str[MAX_INPUT];
    scanf("%s", str);
    char *str_r;

    // Convert to intager
    int num = (int) strtol(str, &str_r, 10);

    // Check if string inludes more then ints
    if (*str_r != '\0')
        return 0;

    return num;
}


// Load words to an array
int load()
{
    // Opent the  file
    FILE *f = fopen("./dicationary.txt", "r");
    if (f == NULL)
    {
        printf("Can't open the file");
        return 1;
    }

    char word[20];
    int i = 0;
     
    // Scan a word at the time until the end of file 
    // and save in word var
    while (fscanf(f, "%s", word) != EOF)
    {
        // Allocate memory 20 bytes
        char *mem = malloc(sizeof(char) * 20);
        if (mem == NULL)
            return printf("No memory");

        // Copy the 
        strcpy(mem, word);
        words[i] = mem;
        i++;
    }
    return 0;
}


// Test a word
int testRanWord(int i)
{
    // Get random word between 1-10 000
    srand(time(NULL) + i);
    int ran = rand() % (N - 1);

    // Access a word using random number
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

    return 0;
}

// Free upp memory used by the application after is
// done executing
int freeMem()
{
    // Go throw every word and free it
    for (int i = 0; i < N; i++)
    {
        free(words[i]);
    }
    return 0;
}