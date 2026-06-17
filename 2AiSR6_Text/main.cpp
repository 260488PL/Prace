#include <iostream>

void toLower(char *text) {
    while (*text) {
        if ('A' <= *text && *text <= 'Z') {
            *text += ('a' - 'A');
        }
        text++;
    }
}

void toUpper(char *text) {
    while(*text) {
        if ('a' <= *text && *text <= 'z') {
            *text -= ('a' - 'A');
        }
        text++;
    }
}

int textSize(char *text) {
    int size = 0;
    while(*text) {
        size++;
        text++;
    }
    return size;
}

void RemoveNewLine(char *text) {
	int i = 0;
        while (text[i] != '\0') {
            if (text[i] == '\n') {
                text[i] = '\0';
                break;
            }
            i++;
        }
}

int main() {
    char text[80];

    while (true) {
        printf("Enter text, if you want to end press enter: \n");
        fgets(text, 80, stdin);
        
		RemoveNewLine(text);     
        if (text[0] == '\0') break;

        printf("Normal: %s\n", text);
        toLower(text);
        printf("Lower:  %s\n", text); 
        toUpper(text);
        printf("Upper:  %s\n", text);
        printf("Size:   %d\n", textSize(text));
    }
    return 0;
}


//#include <iostream>
//
//    void toLower(char *text) {
//    while (*text) {
//        if ('A' <= *text && *text <= 'Z') {
//            *text += ('a' - 'A');
//        }
//        text++;
//    }
//}
//
//    void toUpper(char *text) {
//    while(*text) {
//        if ('a' <= *text && *text <= 'z') {
//            *text -= ('a' - 'A');
//        }
//        text++;
//    }
//}
//
//int textSize(char *text) {
//    int size = 0;
//    while(*text) {
//    size++;
//    text++;
//    }
//    return size;
//}
//
//int main() {
//    char text[] = "Ala ma kota.";
//    printf("%s\n", text);
//    toLower(text);
//    printf("%s\n", text);
//    printf("%d\n", textSize(text));
//    toUpper(text);
//    printf("%s\n", text);
//
//    return 0;
//}
