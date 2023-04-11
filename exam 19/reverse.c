//
//  reverse.c
//  exam 19
//
//  Created by 한설 on 2023/04/12.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "reverse.h"


int checkPalindrome(char str[]) //회문인지 확인
{
    unsigned int n;
    char *s1;
    n = (int)strlen(str);   //str문자열의 길이 대입
    s1 = (char*)malloc(sizeof(char) * n);   //s1 메모리 할당
    strcpy(s1, str);    //s1에 str문자열 복사
    init_stack();   //스택 초기화
    checkAnotherchar(s1);    //문자열에 공백, 구두점 등등 삭제 및 소문지화
    pushchar(s1);   //s1문자열 스택에 push
    n = (int)strlen(s1);    //s1의 길이 대입
    for (int i = 0; i < n; i++)
    {
        if(s1[i] != pop())  //먄약 스택에서 pop된 값과 s1[i]의 값이 다를 경우
        {
            free(s1);   //메모리 반납
            return 0;   //거짓
        }
    }
    free(s1);   //메모리 반납
    return 1;   //참
}

void checkAnotherchar(char str[]) //문자열에서 대문자는 소문자로 바꿔주고 공백, 구두점 등등 삭제.
{
    char *s1;
    int j = 0, n;
    n = (int)strlen(str);   //str문자열의 길이 대입
    s1 = (char*)malloc(sizeof(char) * n);   //메모리 할당
    for(int i = 0; i < n; i++)
    {
        if(!isspace(*(str + i)) && *(str + i) != ',' && *(str + i) != '.' && *(str + i) != '\'')    //공백, 쉼표, 마침표, 작은따옴표를 제외하고
        {
            *(s1 + j) = tolower(*(str + i));    //대문자는 소문자로 바꿔 기입
            j = j + 1;
        }
    }
    strcpy(str, s1);    //str문자열에 s1 대입
    free(s1);   //메모리 반납
}

void pushchar(char str[])   //문자열에 있는 데이터를 push해주는 함수
{
    unsigned int len;
    len = (int)strlen(str); //str문자열의 길이 대입
    for (int i = 0; i < len; i++)   //문자열 순서에 맞춰 스택으로 push
    {
        push(str[i]);
    }
}

void inputchar(char *str)   //문자열을 사용자로부터 받기
{
    printf("문장을 입력해주세요.\n");
    fgets(str, 100, stdin);
}
