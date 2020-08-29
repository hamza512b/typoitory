#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// #include <sys/time.h>

char *words[9894];

int main()
{
    int num;
    printf("How many words? ");
    scanf("%i", &num);

    // struct timeval stop, start;
    // gettimeofday(&start, NULL);
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
        int ran = rand() % 9893;
        printf("%s\n", words[ran]);

        char name[50]; // Segemntation fault if is bigger then 50
        scanf("%s", name);

        if (strcmp(name, words[ran]) == 0)
        {
            printf("Correct\n\n");
            ++correct_words;
        }
        else {
            printf("False\n\n");
        }
    }

    // gettimeofday(&start, NULL);
    // double secs = (double)(stop.tv_usec - start.tv_usec) / 1000 + (double)(stop.tv_sec - start.tv_sec);
    // printf("%f\n", secs);

    time_t end;
    time(&end);
    int secs = (int)(end - start);
    printf("Correct:  %iw\nTime:     %is\n%.0fw/s\n", correct_words, secs, (float)correct_words / (float)(secs / 60.0));

    for (int j = 0; j < 9894; j++)
    {
        free(words[j]);
    }
}
