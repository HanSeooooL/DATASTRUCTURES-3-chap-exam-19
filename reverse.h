//
//  reverse.h
//  exam 19
//
//  Created by 한설 on 2023/04/12.
//

#define MAX_STACK_SIZE 100

typedef char Element;

extern Element data[MAX_STACK_SIZE];
extern int top;

void error(char msg[]);

//스택 ADTs
void init_stack(void);  //스택 초기화
int is_empty(void); //스택 공백 확인
int is_full(void);  //스택 포화 확인
int size(void); //스택 크기 확인
Element peek(void); //스택에서 가장 마지막에 있는 값 반환
Element pop(void);  //스택에서 가장 마지막에 있는 값 반환 및 삭제
void push(int a);   //스택에 값 기입
void print_stack(char msg[]);   //스택 출력

//문자열에 관련된 ADTs
void inputchar(char *str);  //문자열을 사용자로부터 받기
void pushchar(char str[]);  //문자열을 스택에 기입
int checkPalindrome(char str[]); //회문인지 확인
void checkAnotherchar(char *str, int n); //문자열에서 대문자는 소문자로 바꿔주고 공백, 구두점 등등 삭제.
