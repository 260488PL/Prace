#include <iostream>

int main() {
    printf("Simple calc\n");

    while (true) {
        int number1 = 0;
                int *ptrNumber1 = &number1;
        printf("Enter number 1: ");
        scanf("%d", ptrNumber1);
        if (ptrNumber1 == 0) {
            break;
        }
        int number2 = 0;
        int *ptrNumber2 = &number2;
        printf("Enter number 2: ");
        scanf("%d", ptrNumber2);
        if (ptrNumber2 == 0) {
            break;
        }
        printf("%d + %d = %d\n", *ptrNumber1, *ptrNumber2, *ptrNumber1 + *ptrNumber2);
        printf("%d - %d = %d\n", *ptrNumber1, *ptrNumber2, *ptrNumber1 - *ptrNumber2);
        printf("%d * %d = %d\n", *ptrNumber1, *ptrNumber2, *ptrNumber1 * *ptrNumber2);
        printf("%d / %d = %d\n", *ptrNumber1, *ptrNumber2, *ptrNumber1 / *ptrNumber2);
        printf("%d modulo %d = %d\n", *ptrNumber1, *ptrNumber2, *ptrNumber1 % *ptrNumber2);
    }
    return 0;
}