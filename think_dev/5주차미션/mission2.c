#include <stdio.h>
#include <string.h>

char str1[13] = "Hello, world";
char str2[6] = "abcde";

void strncpyPlay(void);
void strcpyPlay(void);
void memsetPLay(void);
void memmovePlay(void);
void memcmpPlay(void);

int main(void) {

    strcpyPlay();
    strncpyPlay();
    memsetPLay();
    memmovePlay();
    memcmpPlay();
}

void strncpyPlay(void) {
    strncpy(str1, str2, sizeof(str1) - 1);
    printf("%s\n", str1);
    for (int i = 0; i < 13; i++) {
        printf("%c", str1[i]);
    }
    printf("\n");
}

void strcpyPlay(void) {
    strcpy(str1, str2);
    printf("%s\n", str1); // abcde
    int length = sizeof(str1) / sizeof(char);
    for (int i = 0; i < length; i++) {
        printf("%c", str1[i]); // abcde world
    }
    printf("\n");
}

void memsetPLay(void) {
     memset(str1, 'a', 13 * sizeof(char));
    for (int i = 0; i < 13; i++) {
        printf("%c", str1[i]);
    }
    printf("\n");
}

void memmovePlay(void) {
    int arr[5] = {1, 2, 3, 4, 5};
    memmove(arr, arr + 1, sizeof(int) * 3);
    for (int i = 0; i < 5; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

void memcmpPlay(void) {
    int arr1[5] = {1, 2, 3, 4, 5};
    // int arr2[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {6, 7, 8, 9, 10};
    int result = memcmp(arr1, arr2, sizeof(int));
    printf("%d\n", result);    
    printf("\n");
}