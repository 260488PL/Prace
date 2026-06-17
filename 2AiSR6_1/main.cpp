#include <iostream>
#define SIZE 10

int main() {
    printf("Arrays\n");
    int numbers[SIZE]={1, 2, 3, 40, -5, 6, 7, 8, 9, 10};

    //sortowanie
    for(int i=0;i<SIZE-1;i++) {
        for (int j=0; j<SIZE-i-1; j++) {
            if (numbers[j] > numbers[j+1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = temp;
            }
        }
    }
    for(int i=0;i<SIZE;i++) {
        printf("numbers[%d]=%d\n",i,numbers[i]);
    }
    int max=numbers[0];
    for(int i=0;i<SIZE;i++) {
        if(max<numbers[i]) {
            max=numbers[i];
        }
    }
    printf("Max number: %d\n", max);

    int min=numbers[0];
    for(int i=0;i<SIZE;i++) {
        if(min>numbers[i]) {
            min=numbers[i];
        }
    }
    printf("Min number: %d\n", min);

    int sum = 0;
    for(int i=0;i<SIZE;i++) {
        sum+=numbers[i];
    }
    printf("Sum: %d\n", sum);
    float average = (float) sum/SIZE;
    printf("Average: %.2f\n", average);


    //mediana
    float median;
    if (SIZE % 2 == 0) {
        median = float(numbers[SIZE/2-1] + numbers[SIZE/2]) / 2;
    } else {
        median = numbers[SIZE/2];
    }
    printf("Median: %.2f\n", median);

    return 0;
}
/*int main() {
    printf("Simple calc\n");

    while (true) {
        int number1 = 0
        printf("Enter number 1: ");
        scanf("%d", &number1);
        if (number1 == 0) {
            break;
        }
        int number2 = 0
        printf("Enter number 2: ");
        scanf("%d", &number2);
        if (number2 == 0) {
            break;
        }
        printf("%d + %d = %d\n", number1, number2, number1 + number2);
        printf("%d - %d = %d\n", number1, number2, number1 - number2);
        printf("%d * %d = %d\n", number1, number2, number1 * number2);
        printf("%d / %d = %d\n", number1, number2, number1 / number2);
        printf("%d modulo %d = %d\n", number1, number2, number1 % number2);
    }
    return 0;
}*/