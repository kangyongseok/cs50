/*
출근하기 가장 빠른 방법
1. 출근방법
- 자차
- 버스
- 지하철
- 택시
- 도보
- 혼합

2. 대중교통이용시
- 어디서탑승
- 어디서 하차
- 환승여부

if (자차이용시) {

}

if (대중교통이용시) {
    switch(대중교통 종류) {
        case 버스:
        case 택시:
        case 지하철:
    }
}

함수
네비게이션 검색함수
만약 자차 < 대중교통
    자차이용
자차 >= 대중교통
    대중교통 이용
*/

/*
출근할때
1. 자차가 빠른지 대중교통이 빠른지 검색한다.
2. 자차가 빠르면 자차이용
3. 대중교통이 빠르면 대중교통이용
*/

/*
#include <stdio.h>

void use_public_transit();

int main(void) {
    int my_car_time = getGoToWorkTime(myCar); // 자차이용시 걸리는 시간
    int transport_time = getGoToWorkTime(publicTransport); // 대중교통이용시 걸리는 시간

    if (my_car_time < transport_time) {
        printf("자차이용");
        use_my_car();
    } else {
        printf("대중교통 이용");
        use_public_transit();
    }
}

void use_public_transit() {
    집앞버스정류장에서 가장 가까운 지하철역으로 가는 버스를 잡아탄다.
    move(bus);
    지하철역에 도착하면 을지로3가로 가서 2호선으로 환승한다.
    move(transfer);
    move(subway);
    구의역에 도착하면 2번출구로 나간다.
    도보로 회사까지 이동
    move(walking);
}


*/