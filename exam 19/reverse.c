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
    n = (int)strlen(str);
    s1 = (char*)malloc(sizeof(char) * n);
    strcpy(s1, str);
    init_stack();   //스택 초기화
    checkAnotherchar(s1, n);    //문자열에 공백, 구두점 등등 삭제 및 소문지화
    pushchar(s1);
    n = (int)strlen(s1);
    for (int i = 0; i < n; i++)
    {
        if(s1[i] != pop())
            return 0;
    }
    return 1;
}

void checkAnotherchar(char str[], int n) //문자열에서 대문자는 소문자로 바꿔주고 공백, 구두점 등등 삭제.
{
    char *s1;
    int j = 0;
    s1 = (char*)malloc(sizeof(char) * n);
    for(int i = 0; i < n; i++)
    {
        if(!isspace(*(str + i)) && *(str + i) != ',' && *(str + i) != '.' && *(str + i) != '\'')
        {
            *(s1 + j) = tolower(*(str + i));
            j = j + 1;
        }
    }
    strcpy(str, s1);
}

void pushchar(char str[])   //문자열에 있는 데이터를 push해주는 함수
{
    unsigned int len;
    len = (int)strlen(str);
    for (int i = 0; i < len; i++)
    {
        push(str[i]);
    }
}

void inputchar(char *str)   //문자열을 사용자로부터 받기
{
    printf("문장을 입력해주세요.\n");
    fgets(str, 100, stdin);
}
