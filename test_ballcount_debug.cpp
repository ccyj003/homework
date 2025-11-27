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

    //3개의 숫자를 입력
    int input[3];
    printf("Enter the first number: ");
    scanf("%d", &input[0]);

    printf("Enter the second number: ");
    scanf("%d", &input[1]);

    printf("Enter the third number: ");
    scanf("%d", &input[2]);

    printf("input : %d %d %d\n", input[0], input[1], input[2]) ;

    int strike_count = 0;
    int ball_count = 0 ;
    int out_count = 3 ;
    if( ball[0] == input[0] )       // strike count
    {
        strike_count = strike_count + 1 ;
        out_count = out_count - 1 ;
    }
    if( ball[0] == input[1] )     // ball count
    {
        ball_count = ball_count + 1 ;
        out_count = out_count - 1 ;
    }
    if( ball[0] == input[2] )     // ball count
    {
        ball_count = ball_count + 1 ;
        out_count = out_count - 1 ;
    }

    if( ball[0] == input[0] && ball[1] == input[1] && ball[2] == input[2] )
    {
	    printf("Home Run~\n") ;
    }
    else
    {
        printf("%d Strike, %d Ball, %d Out\n", strike_count, ball_count, out_count) ;
    }

    return 0;
}
