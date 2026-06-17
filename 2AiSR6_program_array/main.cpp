#include <iostream>
#define SIZE 10

void menu(void) {
    printf("1. Enter the values into the array\n");
    printf("2. Display the content of the array\n");
    printf("3. Determine the minimum value\n");
    printf("4. Determine the maximum value\n");
    printf("5. Determine the average value\n");
    printf("6. Save the file\n");
    printf("7. Restore the file\n");
    printf("0. EXIT\n");
    printf("Select an option:\n");
}


void printArray(int numbers[], int size){
    for(int i=0;i<size;i++) {
        printf("numbers[%d]=%d\n\n",i,numbers[i]);
    }
}

int findMaximum(int numbers[], int size){
    int max=numbers[0];
    for(int i=0;i<size;i++) {
        if(max<numbers[i]) {
            max=numbers[i];
        }
    }
    return max;
}

int findMinimum(int numbers[], int size){
    int min=numbers[0];
    for(int i=0;i<size;i++) {
        if(min>numbers[i]) {
            min=numbers[i];
        }
    }


    return min;
}

float calculateAverage(int numbers[], int size){
    int sum = 0;
    for(int i=0;i<size;i++) {
        sum+=numbers[i];
    }
    float average = (float) sum/size;
    return average;
}

void saveToFile(int numbers[], int size, const char *filename) {
    FILE *fptr = fopen(filename, "w");
    if (fptr == NULL) {
        printf("Error: Can't open file\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        fprintf(fptr, "%d\n", numbers[i]);
    }
    fclose(fptr);
}

void restoreFromFile(const char *filename) {
    FILE *fptr = fopen(filename, "r");
    char fileLine[100];
    if (fptr == NULL) {
        printf("Error: Can't open file\n\n");
        return;
    }
    while (fgets(fileLine, 100, fptr)) {
        printf("%s", fileLine);
    }
    fclose(fptr);
}

int main() {
    printf("Simple arrays\n");
    int numbers[SIZE]={1, 2, 3, 40, -5, 6, 7, 8, 9, 10};
    int option = 0;

    do {
        menu();
        scanf("%d", &option);

        switch (option) {
            case 0:
                break;
            case 1:
                printf("Entering values into the array\n\n");
                break;
            case 2:
                printArray(numbers, SIZE);
                break;
            case 3:
                printf("Determining the minimum value: %d\n", findMinimum(numbers, SIZE));
                break;
            case 4:
                printf("Determining the maximum value: %d\n", findMaximum(numbers, SIZE));
                break;
            case 5:
                printf("Determining the average value: %.2f\n", calculateAverage(numbers, SIZE));
                break;
            case 6:
                printf("Saving data to file\n");
                saveToFile(numbers, SIZE, "numbers.txt");
                printf("File saved\n\n");
                break;
            case 7:
                printf("Restoring data from file:\n");
                restoreFromFile("numbers.txt");
                printf("Data restored\n\n");
                break;
                default:
                printf("Choose the right option...\n\n");
        }
    } while (option != 0);

    printf("The end!\n");


    return 0;
}