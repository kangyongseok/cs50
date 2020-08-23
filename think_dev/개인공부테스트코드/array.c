#include <stdio.h>

char *get_string(char *text) {
    static char str[100];
    printf("%s", text);
    scanf("%s", str);
    return (char*)str;
}

int get_int(char *text) {
    int getInt;
    printf("%s", text);
    scanf("%i", &getInt);
    return getInt;
}

int main(void) {
    char *text = get_string("입력하시오.");
    printf("%s", text);
    return 0;
}