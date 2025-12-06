#include <stdio.h>      // printf, scanf를 사용하기 위해서 헤더 추가
#include <stdlib.h>     // rand, srand를 사용하기 위해서 헤더 추가
#include <time.h>       // time 함수를 사용하기 위해서 헤더 추가

int main(void)      // 프로그램을 실행하는 main 함수
{                   // 메인함수의 시작
    int ball[3];            // 3개의 난수 저장 배열
    srand(time(NULL));      // 난수 초기화
    
    do {    // 중복 없는 3자리 난수 생성
        ball[0] = rand() % 10;      // 0~9까지의 난수를 생성하여 ball[0]에 저장
        ball[1] = rand() % 10;      // 0~9까지의 난수를 생성하여 ball[1]에 저장
        ball[2] = rand() % 10;      // 0~9까지의 난수를 생성하여 ball[2]에 저장
    } while (ball[0] == ball[1] || ball[0] == ball[2] || ball[1] == ball[2]);   // ball[0]과 ball[1]의 숫자가 같으면 다시 생성 || ball[0]과 ball[2]의 숫자가 같으면 다시 생성 || ball[1]과 ball[2]의 숫자가 같으면 다시 생성

    int input[3];               // 사용자가 입력할 숫자 3개를 저장할 배열 선언
    int strike_count = 0 ;      // 스트라이크 개수가 0이 되면 초기화하는 변수 선언
    int ball_count = 0 ;        // 볼 개수가 0이 되면 초기화하는 변수 선언
    int out_count = 0;          // 아웃 개수가 0이 되면 초가화하는 변수 선언
    int try_count = 0;          // 시도 횟수가 0이 되면 초기화하는 변수 선언

    clock_t start, end;     // 시작 시간과 끝 시간을 기록할 변수
    start = clock();        // 게임 시작 시간 기록

    while (1) {     // 정답을 맞출 때까지 무한루프 실행
        printf("\n숫자 3개를 입력하세요 (공백으로 구분): ");        // 숫자 3개를 입력하세요 메시지 출력
        scanf("%d %d %d", &input[0], &input[1], &input[2]);     // 사용자가 입력한 숫자를 input[0], input[1], input[2]에 저장

        strike_count = 0;   // 스트라이크 수 초기화
        ball_count = 0;     // 볼 수 초기화

        // strike, ball 판정
        for (int i = 0; i < 3; i++) {       // 3개의 입력 숫자를 검사하는 for문 시작
            if (input[i] == ball[i]) {      // 사용자가 입력한 숫자와 난수가 같으면 스트라이크
                strike_count++;
            } else if (input[i] == ball[(i+1)%3] || input[i] == ball[(i+2)%3]) {    // 숫자는 맞고 위치가 다르면 볼
                ball_count++;
            }   // else if문 끝
        }   // for문 끝

        out_count = 3 - (strike_count + ball_count);    // 스트라이크와 볼이 아닌 나며지는 아웃
        
        try_count++;    // 시도 횟수 증가

        if (strike_count == 3) {    // 3스트라이크는 정답 맞춤
            end = clock();  // 게임 종료 시간 기록            
            double elapsed_sec = (double)(end - start) / CLOCKS_PER_SEC;    // 게임이 시작해서 끝날 때까지의 시간을 초 단위로 계산
            printf("Home Run! %d번 만에 맞췄습니다!\n", try_count);     // 시도 횟수를 계산해서 Home Run! (시도 횟수)번 만에 맞췄습니다! 메시지 출력
            printf("%f 초 시간이 걸렸습니다.\n", elapsed_sec);      // (걸린 시간)초 시간이 걸렸습니다. 메시지 출력
            break;      // 정답을 맞추면 while문 종료
        } else {    // 3스트라이크가 아닐 경우
            printf("%d Strike, %d Ball, %d Out\n", strike_count, ball_count, out_count);    // 스트라이크 개수, 볼 개수, 아웃 개수 출력
        }   // else문 종료
    }   // while(1)문 종료
    return 0;   // 프로그램 종료
}   // 메인함수의 끝
