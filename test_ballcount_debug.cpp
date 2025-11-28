#include <stdio.h>      // printf, scanf를 사용하기 위해서 헤더 추가
#include <stdlib.h>     // rand, srand를 사용하기 위해서 헤더 추가
#include <time.h>       // time 함수를 사용하기 위해서 헤더 추가

int main(void)      // 프로그램을 실행하는 main 함수
{                   // 메인함수의 시작
    int ball[3];            // 3개의 난수 저장 배열
    srand(time(NULL));      // 난수 초기화

    do {
        ball[0] = rand() % 10;      // 0~9까지의 난수를 생성하여 ball[0]에 저장
        ball[1] = rand() % 10;      // 0~9까지의 난수를 생성하여 ball[1]에 저장
        ball[2] = rand() % 10;      // 0~9까지의 난수를 생성하여 ball[2]에 저장
    } while (ball[0] == ball[1] || ball[0] == ball[2] || ball[1] == ball[2]);       // ball[0]과 ball[1]의 숫자가 같으면 다시 생성 || ball[0]과 ball[2]의 숫자가 같으면 다시 생성 || ball[1]과 ball[2]의 숫자가 같으면 다시 생성

    printf("baseball : %d %d %d\n", ball[0], ball[1], ball[2]);     // 생성된 난수 3개 출력

    int input[3];                           // 사용자가 입력할 숫자 3개를 저장할 배열 선언
    printf("Enter the first number: ");     // Enter the first number: 메시지 출력      
    scanf("%d", &input[0]);                 // 사용자가 입력한 첫번째 숫자를 input[0]에 저장

    printf("Enter the second number: ");    // Enter the first number: 메시지 출력
    scanf("%d", &input[1]);                 // 사용자가 입력한 첫번째 숫자를 input[1]에 저장

    printf("Enter the third number: ");     // Enter the first number: 메시지 출력
    scanf("%d", &input[2]);                 // 사용자가 입력한 첫번째 숫자를 input[2]에 저장

    printf("input : %d %d %d\n", input[0], input[1], input[2]) ;    // 사용자가 입력한 숫자 출력

    int strike_count = 0;           // 스트라이크 개수가 0이 되면 초기화하는 변수 선언
    int ball_count = 0 ;            // 볼 개수가 0이 되면 초기화하는 변수 선언 
    int out_count = 3 ;             // 아웃 개수가 3이 되면 초가화하는 변수 선언
    if( ball[0] == input[0] )       // ball[0]과 input[0]이 같은 경우 
    {
        strike_count = strike_count + 1 ;       // 스트라이크 개수는 1씩 증가
        out_count = out_count - 1 ;             // 아웃 개수는 1씩 감소
    }
    if( ball[0] == input[1] )           // ball[0]과 input[1]이 같은 경우
    {
        ball_count = ball_count + 1 ;   // 볼 개수는 1씩 증가
        out_count = out_count - 1 ;     // 아웃 개수는 1씩 감소
    }
    if( ball[0] == input[2] )           // ball[0]과 input[2]이 같은 경우
    {
        ball_count = ball_count + 1 ;   // 볼 개수는 1씩 증가
        out_count = out_count - 1 ;     // 아웃 개수는 1씩 감소
    }

    if( ball[0] == input[0] && ball[1] == input[1] && ball[2] == input[2] )     //  3자리 숫자가 자리까지 완전히 일치하는지 검사(조건이 하나라도 만족하지 못할 경우 거짓)
    {
	    printf("Home Run~\n") ;     // Home Run~ 메시지 출력
    }
    else    //if조건이 거짓일때
    {
        printf("%d Strike, %d Ball, %d Out\n", strike_count, ball_count, out_count) ;   // 스트라이크 개수, 볼 개수, 아웃 개수 출력
    }

    return 0;   // 프로그램 종료
}
