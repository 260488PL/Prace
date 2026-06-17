#include <iostream>
#include <cstring>

void usage(char *programName) {
    printf("Usage: %s number1 operation number2\n", programName);
    printf("Available operations:\n");
    printf("\tadd\n");
    printf("\tsub\n");
    printf("\tmul\n");
    printf("\tdiv\n");
    printf("\tmod\n");
}

int main(int argc, char* argv[]) {

    int number1 = 0;
    int number2 = 0;
    int result = 0;

    if (argc == 4) {
        number1 = atoi(argv[1]);
        number2 = atoi(argv[3]);

        if (!strcmp("add", argv[2])) {
            result = number1 + number2;
            printf("%d + %d = %d\n", number1, number2, result);
            return 0;
        }
        else if (!strcmp("sub", argv[2])) {
            result = number1 - number2;
            printf("%d - %d = %d\n", number1, number2, result);
            return 0;
        }
        else if (!strcmp("mul", argv[2])) {
            result = number1 * number2;
            printf("%d * %d = %d\n", number1, number2, result);
            return 0;
        }
        else if (!strcmp("div", argv[2])) {
            if (number2 == 0) {
                printf("Error: division by 0\n");
                return 1;
            }
            printf("%d / %d = %.2f\n", number1, number2, (float) number1 / number2);
            return 0;
        }
        else if (!strcmp("mod", argv[2])) {
            if (number2 == 0) {
                printf("Error: division by 0\n");
                return 1;
            }
            result = number1 % number2;
            printf("%d %% %d = %d\n", number1, number2, result);
            return 0;
        }
        usage(argv[0]);
    }
    return 0;
}