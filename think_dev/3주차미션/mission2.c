#include <stdio.h>
#define SIZE 500000

int main(int arge, char*argv[]) {
    int n;
    int nSum;
    int sum;

    // scanf 는 \n 즉 엔터가 나오기 전까지있는 숫자와 문자를 출력한다 해당 파일들은 각각 10, 100... 등의 숫자가 있고 바로 엔터가 있기때문에 n에는 자동으로 각 파일의 엔터전에있는 첫번째 숫자값이 자동으로 들어온다.
    scanf("%d", &n);

    // 1부터 N의 숫자중 K가 빠진 배열
    int partArr[SIZE]; // SIZE 만큼의 메모리 영역을 할당
    int lengthOfPartArr = n-1; // 받아온 각 첫번째 숫자보다 -1 된 숫자를 저장

    // 1 부터 N 까지의 정상적인 숫자의 합
    for (int j = 0; j <= n; j++) {
        nSum += j;
    }

    // 1 부터 N-1 까지의 숫자의 합
    for(int i=0; i < lengthOfPartArr; i++){
        // scanf 는 엔터를 만나기전까지의 데이터를 리턴하지만 띄어쓰기가 있어도 똑같이 동작함
        // 띄어쓰기를 만날때마다 partArr[i] 배열에 값을 하나씩 저장
        scanf("%d", &partArr[i]);
        sum += partArr[i];
    }

    // 1 부터 N 까지의 숫자를 더한 총 값에서 N-1 의 숫자를 더한값을 빼면 빠진값을 구할 수 있음
    printf("K = %d", nSum - sum);


    // TODO: n과 partArr를 이용하여, K를 구하라
    return 0;
}