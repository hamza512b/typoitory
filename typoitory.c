#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <inttypes.h>
#include <errno.h>

#define RED  "\x1B[31m"
#define GRN  "\x1B[32m"
#define NRM  "\x1B[0m"

#define MAX_INPUT 50 // TODO egemntation fault if is bigger
#define N 9894

char *words[N];

// Prototypes
int getInt(char *txt);

int main()
{
    int num = 0;

    while (num == 0)
    {
        num = getInt("How many words? ");
    }

    time_t start;
    time(&start);

    FILE *f = fopen("./dicationary", "r");
    if (f == NULL)
        return printf("Can't open the file");
    char word[20];
    int i = 0;

    while (fscanf(f, "%s", word) != EOF)
    {
        char *mem = malloc(sizeof(char) * 20);
        if (mem == NULL)
            return printf("No memory");

        strcpy(mem, word);
        words[i] = mem;
        i++;
    }

    int correct_words = 0;

    for (int i = 0; i < num; i++)
    {
        srand(time(NULL) + i);
        int ran = rand() % (N - 1);
        printf("%s\n", words[ran]);

        char name[MAX_INPUT];
        scanf("%s", name);

        if (strcmp(name, words[ran]) == 0)
        {
            printf("%sCorrect\n\n%s", GRN, NRM);
            ++correct_words;
        }
        else {
            printf("%sFalse\n\n%s", RED, NRM);
        }
    }

    time_t end;
    time(&end);
    int secs = (int)(end - start);
    printf("Correct:  %iw\nTime:     %is\n%.0fw/s\n", correct_words, secs, (float)correct_words / (float)(secs / 60.0));

    for (int j = 0; j < 10000; j++)
    {
        free(words[j]);
    }
}


int getInt(char *txt)
{
    printf("%s", txt);

    char str[MAX_INPUT];
    scanf("%s", str);
    char *str_r;

    if (str == NULL)
        return 0;

    int num = (int) strtol(str, &str_r, 10);

    if (*str_r != '\0')
        return 0;

    return num;
}
