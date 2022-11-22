#include <stdio.h>
#include <stdlib.h>


#define MAX_INDEX 100 // 상수 선언.

typedef struct {  //stack 구조체를 생성한다.
    int data[MAX_INDEX]; // MAX_INDEX 의 크기를 가진 멤버 data 배열을 선언한다.
    int top; // data 배열의 현재 인덱스를 나타내는 멤버 top 을 선언한다.
}stack;



int is_full(stack s) { //스택이 가득찼나 "검사" 하는 함수
    return (s.top == MAX_INDEX - 1); // top 변수가 99일때 1을 반환한다.(true 반환)
}

int is_empty(stack s) { //스택이 비워졌나 검사하는 함수

    return (s.top == -1); //top 변수가 -1일때 1을 반환한다.(true 반환)
}

void push(stack* s, int input) { //스택에 값을 넣는 함수, 받아온 input 을 스택에 넣는 함수다.

    if (is_full(*s)) { //만약 스택이 가득 찼으면
        printf("스택이 가득 찼음"); // 이것을 출력하고
        exit(1); // 프로그램을 종료한다.
    }


    else {  //만약 스택이 가득 차지 않았으면
        s->top += 1; // 변수 top은 1을 증가한다.
        s->data[s->top] = input; //data 배열에 증가한 top index 에 input 을 할당한다.

    }
}

void init(stack* s) { // 스택의 인덱스 위치를 초기화하는 함수, 스택이 생성되면 무조건 호출해야함
    s->top = -1;
}

int peek(stack s) { //배열이 비어있지않으면 배열의 top index의 값을 반환한다.
    //마지막으로 push 값을 반환한다.

    if (is_empty(s)) { //만약 스택이 비워져있다면
        printf("스택이 비어있음!"); // 이것을 출력하고 
        exit(1); // 프로그램 종료
    }
    else { // 만약 스택이 비워져있는게 아니라면
        return (s.data[s.top]); // data 배열의 top index의 값을 반환한다.
    }
}

int pop(stack* s) { // data배열의 top index 를 -1 을 하고 출력은 top index의 값을 한다.
    //마지막으로 push 값을 삭제하고 반환한다.

    if (is_empty(*s)) { //만약 스택이 비워져있다면
        printf("스택이 비어있음!");// 이것을 출력하고 
        exit(1);// 프로그램 종료
    }
    else { // 만약 스택이 비워져있는게 아니라면
        s->top -= 1; //top변수에 -1을 빼고
        return (s->data[s->top + 1]); // 반환은 data배열의 top변수 +1 index를 반환한다.
    }
}


int main() {

    stack st;
    init(&st);


    //문제! 스택을 사용하여 문자열을 역순으로 출력하기
    //가나다라마바사 를 사바마라다나가 로 출력하기

    char korean[] = "abcdefg"; // 역순으로 이용할 배열 선언

    for (int i = 0; korean[i] != NULL; i++) { //배열 인덱스의 범위 만큼 작동하는 for문 실행
        push(&st, korean[i]); //push함수 호출(stack과 값을 하나씩 넣어준다)
    }

    while (!is_empty(st)) { //만약 stack이 비어있지 않는다면 무한 수행.
        
        printf("%c/>", pop(&st)); //pop의 함수의 return값을 출력.
    }
    char* ptr = strchr(korean, '<');
    printf("주소값 : %p\n", ptr);
}
