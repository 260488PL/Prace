#include <iostream>
#include <cstring>

void usage(char *programName) {
    printf("Enter text, if you want to end press enter: \n");
}
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


int main(int argc, char* argv[]) {
    if (argc < 2) {
    usage(argv[0]);
    return 1;
    }
    char text[80];
    strncpy(text, argv[1], 79);
    text[79] = '\0';

    printf("Normal: %s\n", text);
    toLower(text);
    printf("Lower:  %s\n", text);
    toUpper(text);
    printf("Upper:  %s\n", text);
    printf("Size:   %d\n\n", textSize(text));

    return 0;
}
