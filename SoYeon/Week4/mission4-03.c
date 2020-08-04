#include <stdio.h>
#define NUM_OF_PEOPLE 7 

int timeOfPeople[NUM_OF_PEOPLE]={1, 2, 3, 4, 5, 6, 7};  //각 사람들이 다리를 건너는 시간. 다리를 건너기 전의 상태를 보여주는 배열
int afterBridge[NUM_OF_PEOPLE]={0, 0, 0, 0, 0, 0, 0}; //다리를 건넌 도착상태를 알려주는 배열
int totalTime=0;

void printArray(){      //함수 시작 전에 초기화되어 있는 배열 내용 출력
    printf("|");
    for(int i=0; i<NUM_OF_PEOPLE; i++) printf("%d ", timeOfPeople[i]);
    printf("|----------------|");
    for(int i=0; i<NUM_OF_PEOPLE; i++) printf("%d ", afterBridge[i]);
    printf("|\n");
}

void printBefore(){     //timeOfPeople 배열을 출력하는 함수. 
    printf("|");
    for(int i=0; i<NUM_OF_PEOPLE; i++) printf("%d ", timeOfPeople[i]);
    printf("|");
}

void printAfter(){      //afterBridge 배열을 출력하는 함수
    printf("|");
    for(int i=0; i<NUM_OF_PEOPLE; i++) printf("%d ", afterBridge[i]);
    printf("|\nTotal Time : %d\n", totalTime);
}

void returnBridge(int fast){                    // 한 사람이 다리를 건너는 함수 or 다리를 건넜다 돌아오는 함수
    totalTime += afterBridge[fast];            // 한 사람이 다리를 건너는 시간을 총 시간에 더하기
    timeOfPeople[fast] = afterBridge[fast];     // ex) 1, 2, 3 : {1, 2, 0} {0, 0, 3} -> {1, 2, 3} {0, 0, 3}
    afterBridge[fast] = 0;                      // ex) 1, 2, 3 : {1, 2, 0} {0, 0, 3} -> {1, 2, 3} {0, 0, 0}
    printBefore();
    printf("<-------%d-------", timeOfPeople[fast]);
    printAfter();
}

void crossBridge(int slow, int slower){         //두 사람이 다리를 건너는 함수. 둘이 다리를 건널 때는 느린 사람과 더 느린 사람이 존재하므로 변수 이름을 slow와 slower로 지정.
    totalTime += timeOfPeople[slower];          // 더 느린 사람의 시간을 총 걸린 시간에 더함
    afterBridge[slow] = timeOfPeople[slow];     //다리를 건너 반대편에 도착한 상태 표시. 
    afterBridge[slower] = timeOfPeople[slower]; //다리를 건너 반대편에 도착한 상태 표시  
    timeOfPeople[slow] = 0;                     //다리를 건넜으니 원래 배열의 원소는 0으로 초기화. 
    timeOfPeople[slower] = 0;                   //다리를 건넜으니 원래 배열의 원소는 0으로 초기화
    printBefore();
    printf("------%d %d------>", afterBridge[slow], afterBridge[slower]);
    printAfter();
}

void bridge(int numOfPeople){                   //다리를 건너는 전체 과정을 나타내는 함수
    if(numOfPeople == 1){                       //1명이 건널 때 = 다리를 건넜다가 다시 1명이 돌아올 때
        returnBridge(0);                        //배열의 인덱스로 사용되므로 1명이어도 인자로 0을 줌.
    }
    else if(numOfPeople == 2){                  //2명이 다리를 건너는 경우, 그냥 같이 건너면 됨.
        crossBridge(0, 1);                      
    }   
    else if(numOfPeople == 3){                  // 3명이 다리를 건너는 경우,  
        crossBridge(0, 1);                      // 1) 셋 중 빠른 2명이 먼너 건넘
        returnBridge(0);                        // 2) 먼저 건넌 2명 중 빠른 사람(셋 중 가장 빠른 사람)이 다시 다리를 건너옴
        crossBridge(0, 2);                      // 3) 가장 빠른 사람과 가장 느린 사람이 함께 다리를 건넘
    }
    else{                                           // 4명 이상이 다리를 건너는 경우
        crossBridge(0, 1);                          // 1) 첫번째로 빠른 사람과 두 번째로 빠른 사람이 다리를 건넘
        returnBridge(0);                            // 2) 그 중 첫번째로 빠른 사람이 다시 다리를 건너 돌아옴
        crossBridge(numOfPeople-2, numOfPeople-1);  // 3) 제일 느린 사람과 그 다음으로 느린 사람이 다리를 건넘
        returnBridge(1);                            // 4) 다리를 건넜던 두 번째로 빠른 사람이 다시 다리를 건너옴
        bridge(numOfPeople-2);                      // 5) 4번의 상태가 완료되면, 상황은 numOfPeople-2 수의 사람을 처음부터 옮기는 것과 동일해짐
    }
}

int main(void){

    printf("START TO CROSS BRIDGE\n");
    printArray();
    bridge(NUM_OF_PEOPLE);
}

