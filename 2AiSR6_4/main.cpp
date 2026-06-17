#include <iostream>
#define SIZE 10

    void menu(void) {
    printf("1. Enter the values into the array\n");
    printf("2. Display the content of the array\n");
    printf("3. Determine the minimum value\n");
    printf("4. Determine the maximum value\n");
    printf("5. Determine the average value\n");
    printf("0. EXIT\n");
    printf("Select an option:\n");
}

   void copyArray(int numbers[], int size, int copyofnumbers[]){
    for (int i=0; i<size;++i) {
           copyofnumbers[i]=numbers[i];
       }
}

    void printArray(int numbers[], int size){
        for(int i=0;i<size;i++) {
            printf("numbers[%d]=%d\n",i,numbers[i]);
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

    void printCopy(int copyofnumbers[], int size){
        for(int i=0;i<size-1;i++) {
            for (int j=0; j<size-i-1; j++) {
                if (copyofnumbers[j] > copyofnumbers[j+1]) {
                    int temp = copyofnumbers[j];
                    copyofnumbers[j] = copyofnumbers[j+1];
                    copyofnumbers[j+1] = temp;
                }
            }
        }
        for(int i=0;i<SIZE;i++) {
            printf("copyofnumbers[%d]=%d\n", i, copyofnumbers[i]);
        }
}

    float calculateMedian(int copyofnumbers[], int size){
        float median;
        if (size % 2 == 0) {
            median = float(copyofnumbers[size/2-1] + copyofnumbers[size/2]) / 2;
        } else {
            median = copyofnumbers[size/2];
        }
        return median;
}

int main() {
    printf("Simple arrays\n");
    int numbers[SIZE]={1, 2, 3, 40, -5, 6, 7, 8, 9, 10};
//    int copyofnumbers[SIZE];
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
             case 5:
                 printf("Determining the average value: %.2f\n", calculateAverage(numbers, SIZE));
                 break;
             default:
                 printf("Choose the right option...\n\n");
         }
     } while (option != 0);

     printf("The end!\n");
//    copyArray(numbers, SIZE, copyofnumbers);
//    printCopy(copyofnumbers, SIZE);
//    printf("Median: %.2f\n", calculateMedian(copyofnumbers, SIZE));

    return 0;
}
