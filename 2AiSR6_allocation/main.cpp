#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, aSize;
    int *randNums = NULL;
    time_t t;

    double total = 0;
    int biggest, smallest;
    float average;
    int minRange;
    int maxRange;

    srand(time(&t));

    printf("Podaj dolny prog zakresu:\n");
    scanf("%d", &minRange);

    printf("Podaj gorny prog zakresu:\n");
    scanf("%d", &maxRange);
    if(minRange > maxRange){
        printf("Dolna granica nie moze byc wieksza od gornej\n");
        return 1;
    }

    int range = maxRange - minRange + 1;

    while (1)
    {
        printf("\nIle liczb chcesz zapisac? (Wpisz 0, aby zakonczyc):\n ");
        if (scanf("%d", &aSize) != 1) break;

        if (aSize == 0) {
            printf("Zamykanie programu\n");
            break;
        }

        int *temp = (int *) realloc(randNums, aSize * sizeof(int));

        if (!temp)
        {
            printf("Blad realokacji pamieci!\n");
            free(randNums);
            return 1;
        }
        randNums = temp;

        double total = 0;

        for (i = 0; i < aSize; i++)
        {
            randNums[i] = (rand() % range) + minRange;
            total += randNums[i];

            if (i == 0) {
                biggest = smallest = randNums[i];
            } else {
                if (randNums[i] > biggest) {
                    biggest = randNums[i];
                }
                if (randNums[i] < smallest) {
                    smallest = randNums[i];
                }
            }
        }

        float average = (float)total / aSize;

        printf("Najwieksza liczba: %d\n", biggest);
        printf("Najmniejsza liczba: %d\n", smallest);
        printf("Srednia: %.2f\n", average);


    }

    free(randNums);

    return 0;
}