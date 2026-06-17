#include <iostream>
#define SIZE 10

int main() {
    printf("Arrays\n");
    int numbers[SIZE]={1, 2, 3, 40, -5, 6, 7, 8, 9, 10};
    int copyofnumbers[SIZE];

//    for (int i=0; i<SIZE;++i) {
//        copyofnumbers[i]=numbers[i];
//    }

    for (int i=0; i<SIZE;++i) {
        *(copyofnumbers + i)=*(numbers + i);
    }

//    for(int i=0;i<SIZE;i++) {
//        printf("numbers[%d]=%d\n",i,numbers[i]);
//    }
//    int max=numbers[0];
//    for(int i=0;i<SIZE;i++) {
//        if(max<numbers[i]) {
//            max=numbers[i];
//        }
//    }

    for(int i=0;i<SIZE;i++) {
        printf("*(numbers + %d)=%d\n",i,*(numbers + i));
    }
    int max=*numbers;
    for(int i=0;i<SIZE;i++) {
        if(max<*(numbers + i)) {
            max=*(numbers + i);
        }
    }
    printf("Max number: %d\n", max);

//    int min=numbers[0];
//    for(int i=0;i<SIZE;i++) {
//        if(min>numbers[i]) {
//            min=numbers[i];
//        }
//    }

    int min=*numbers;
    for(int i=0;i<SIZE;i++) {
        if(min>*(numbers + i)) {
            min=*(numbers + i);
        }
    }
    printf("Min number: %d\n", min);

//    int sum = 0;
//    for(int i=0;i<SIZE;i++) {
//        sum+=numbers[i];
//    }

    int sum = 0;
    for(int i=0;i<SIZE;i++) {
        sum+=*(numbers + i);
    }
    printf("Sum: %d\n", sum);
    float average = (float) sum/SIZE;
    printf("Average: %.2f\n", average);

    //sortowanie
//    for(int i=0;i<SIZE-1;i++) {
//        for (int j=0; j<SIZE-i-1; j++) {
//            if (copyofnumbers[j] > copyofnumbers[j+1]) {
//                int temp = copyofnumbers[j];
//                copyofnumbers[j] = copyofnumbers[j+1];
//                copyofnumbers[j+1] = temp;
//            }
//        }
//    }
    for(int i=0;i<SIZE-1;i++) {
        for (int j=0; j<SIZE-i-1; j++) {
            if (*(copyofnumbers + j) > *(copyofnumbers + j+1)) {
                int temp = *(copyofnumbers + j);
                *(copyofnumbers + j) = *(copyofnumbers + j+1);
                *(copyofnumbers + j+1) = temp;
            }
        }
    }

    //mediana
    float median;
    if (SIZE % 2 == 0) {
        median = float(copyofnumbers[SIZE/2-1] + copyofnumbers[SIZE/2]) / 2;
    } else {
        median = copyofnumbers[SIZE/2];
    }
    printf("Median: %.2f\n", median);

    return 0;
}
