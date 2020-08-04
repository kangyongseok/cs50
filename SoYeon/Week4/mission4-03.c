#include <stdio.h>
#define NUM_OF_PEOPLE 7 

int timeOfPeople[NUM_OF_PEOPLE]={1, 2, 3, 4, 5, 6, 7};  //�� ������� �ٸ��� �ǳʴ� �ð�. �ٸ��� �ǳʱ� ���� ���¸� �����ִ� �迭
int afterBridge[NUM_OF_PEOPLE]={0, 0, 0, 0, 0, 0, 0}; //�ٸ��� �ǳ� �������¸� �˷��ִ� �迭
int totalTime=0;

void printArray(){      //�Լ� ���� ���� �ʱ�ȭ�Ǿ� �ִ� �迭 ���� ���
    printf("|");
    for(int i=0; i<NUM_OF_PEOPLE; i++) printf("%d ", timeOfPeople[i]);
    printf("|----------------|");
    for(int i=0; i<NUM_OF_PEOPLE; i++) printf("%d ", afterBridge[i]);
    printf("|\n");
}

void printBefore(){     //timeOfPeople �迭�� ����ϴ� �Լ�. 
    printf("|");
    for(int i=0; i<NUM_OF_PEOPLE; i++) printf("%d ", timeOfPeople[i]);
    printf("|");
}

void printAfter(){      //afterBridge �迭�� ����ϴ� �Լ�
    printf("|");
    for(int i=0; i<NUM_OF_PEOPLE; i++) printf("%d ", afterBridge[i]);
    printf("|\nTotal Time : %d\n", totalTime);
}

void returnBridge(int fast){                    // �� ����� �ٸ��� �ǳʴ� �Լ� or �ٸ��� �ǳԴ� ���ƿ��� �Լ�
    totalTime += afterBridge[fast];            // �� ����� �ٸ��� �ǳʴ� �ð��� �� �ð��� ���ϱ�
    timeOfPeople[fast] = afterBridge[fast];     // ex) 1, 2, 3 : {1, 2, 0} {0, 0, 3} -> {1, 2, 3} {0, 0, 3}
    afterBridge[fast] = 0;                      // ex) 1, 2, 3 : {1, 2, 0} {0, 0, 3} -> {1, 2, 3} {0, 0, 0}
    printBefore();
    printf("<-------%d-------", timeOfPeople[fast]);
    printAfter();
}

void crossBridge(int slow, int slower){         //�� ����� �ٸ��� �ǳʴ� �Լ�. ���� �ٸ��� �ǳ� ���� ���� ����� �� ���� ����� �����ϹǷ� ���� �̸��� slow�� slower�� ����.
    totalTime += timeOfPeople[slower];          // �� ���� ����� �ð��� �� �ɸ� �ð��� ����
    afterBridge[slow] = timeOfPeople[slow];     //�ٸ��� �ǳ� �ݴ��� ������ ���� ǥ��. 
    afterBridge[slower] = timeOfPeople[slower]; //�ٸ��� �ǳ� �ݴ��� ������ ���� ǥ��  
    timeOfPeople[slow] = 0;                     //�ٸ��� �ǳ����� ���� �迭�� ���Ҵ� 0���� �ʱ�ȭ. 
    timeOfPeople[slower] = 0;                   //�ٸ��� �ǳ����� ���� �迭�� ���Ҵ� 0���� �ʱ�ȭ
    printBefore();
    printf("------%d %d------>", afterBridge[slow], afterBridge[slower]);
    printAfter();
}

void bridge(int numOfPeople){                   //�ٸ��� �ǳʴ� ��ü ������ ��Ÿ���� �Լ�
    if(numOfPeople == 1){                       //1���� �ǳ� �� = �ٸ��� �ǳԴٰ� �ٽ� 1���� ���ƿ� ��
        returnBridge(0);                        //�迭�� �ε����� ���ǹǷ� 1���̾ ���ڷ� 0�� ��.
    }
    else if(numOfPeople == 2){                  //2���� �ٸ��� �ǳʴ� ���, �׳� ���� �ǳʸ� ��.
        crossBridge(0, 1);                      
    }   
    else if(numOfPeople == 3){                  // 3���� �ٸ��� �ǳʴ� ���,  
        crossBridge(0, 1);                      // 1) �� �� ���� 2���� �ճ� �ǳ�
        returnBridge(0);                        // 2) ���� �ǳ� 2�� �� ���� ���(�� �� ���� ���� ���)�� �ٽ� �ٸ��� �ǳʿ�
        crossBridge(0, 2);                      // 3) ���� ���� ����� ���� ���� ����� �Բ� �ٸ��� �ǳ�
    }
    else{                                           // 4�� �̻��� �ٸ��� �ǳʴ� ���
        crossBridge(0, 1);                          // 1) ù��°�� ���� ����� �� ��°�� ���� ����� �ٸ��� �ǳ�
        returnBridge(0);                            // 2) �� �� ù��°�� ���� ����� �ٽ� �ٸ��� �ǳ� ���ƿ�
        crossBridge(numOfPeople-2, numOfPeople-1);  // 3) ���� ���� ����� �� �������� ���� ����� �ٸ��� �ǳ�
        returnBridge(1);                            // 4) �ٸ��� �ǳԴ� �� ��°�� ���� ����� �ٽ� �ٸ��� �ǳʿ�
        bridge(numOfPeople-2);                      // 5) 4���� ���°� �Ϸ�Ǹ�, ��Ȳ�� numOfPeople-2 ���� ����� ó������ �ű�� �Ͱ� ��������
    }
}

int main(void){

    printf("START TO CROSS BRIDGE\n");
    printArray();
    bridge(NUM_OF_PEOPLE);
}

