#include <stdio.h>

float average(int length, int array[]);

int main(void) {
    // before
    // int score1 = 71;
    // int score2 = 72;
    // int score3 = 33;
    // printf("Average : %i\n", (score1 + score2 + score3) / 3);

    // after
    int n;
    printf("Number of scores: ");
    scanf("%i", &n);

    int scores[n];
    for(int i = 0; i < n; i++) {
        // scores[i];
        printf("Score %i: ", i + 1);
        scanf("%i", &scores[i]);
    }
    printf("Average: %.1f\n", average(n, scores));
}

float average(int length, int array[]) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += array[i];
    }
    return (float) sum / (float) length;
}