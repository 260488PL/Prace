#include <iostream>
#define SIZE 10

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
    printf("Arrays\n");
    int numbers[SIZE]={1, 2, 3, 40, -5, 6, 7, 8, 9, 10};
    int copyofnumbers[SIZE];
    
    copyArray(numbers, SIZE, copyofnumbers);

    printArray(numbers, SIZE);

    printf("Max number: %d\n", findMaximum(numbers, SIZE));

    printf("Min number: %d\n", findMinimum(numbers, SIZE));

    printf("Average: %.2f\n", calculateAverage(numbers, SIZE));

    printCopy(copyofnumbers, SIZE);

    printf("Median: %.2f\n", calculateMedian(copyofnumbers, SIZE));

    return 0;
}
