#include <stdio.h>
#include <string.h>

int main(void) {
    char str1[13] = "Hello, world";
    char str2[6] = "abcde";

    // strcpy(str1, str2);
    // printf("%s\n", str1); // abcde
    // int length = sizeof(str1) / sizeof(char);
    // for (int i = 0; i < length; i++) {
    //     printf("%c", str1[i]); // abcde world
    // }
    strncpy(str1, str2, sizeof(str1) - 1);
    printf("%s\n", str1);
    // int length = sizeof(str1) / sizeof(char);
    for (int i = 0; i < 13; i++) {
        printf("%c", str1[i]);
    }

    memset(str1, 'a', 13 * sizeof(char));
    for (int i = 0; i < 13; i++) {
        printf("%c\n", str1[i]);
    }
