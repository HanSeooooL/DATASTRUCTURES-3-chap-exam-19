//
//  main.c
//  exam 19
//
//  Created by 한설 on 2023/04/12.
//

#include <stdio.h>
#include <stdlib.h>
#include "reverse.h"

Element data[MAX_STACK_SIZE];
int top;

int main(int argc, const char * argv[]) {
    
    char str[50];
    inputchar(str);
    if (checkPalindrome(str))
        printf("입력하신 문장은 회문입니다.");
    else
        printf("입력하신 문장은 회문이 아닙니다.");
    return 0;
}

void error(char msg[])
{
    printf("%s\n", msg);
    exit(1);
}

//STACK ADTs
void init_stack(void) { top = -1; }
int is_empty(void) {return top == -1;}
int is_full(void) {return top == MAX_STACK_SIZE - 1;}
int size(void) {return top + 1;}

Element peek(void) {
    if (is_empty())
        error("스택 공백 에러");
    return data[top];
}

Element pop(void) {
    if(is_empty())
        error("스택 공백 에러");
    return data[top--];
}

void push(int a) {
    if (is_full())
        error("스택 포화 에러");
    data[++top] = a;
}

void print_stack(char msg[]) {
    int i;
    printf("%s[%d] = ", msg, size());
    for (i = 0; i < size(); i++)
        printf("%d ", data[i]);
    printf("\n");
}

