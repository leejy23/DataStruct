#include <stdio.h>
#include <stdlib.h>


#define MAX_INDEX 100 // ��� ����.

typedef struct {  //stack ����ü�� �����Ѵ�.
    int data[MAX_INDEX]; // MAX_INDEX �� ũ�⸦ ���� ��� data �迭�� �����Ѵ�.
    int top; // data �迭�� ���� �ε����� ��Ÿ���� ��� top �� �����Ѵ�.
}stack;



int is_full(stack s) { //������ ����á�� "�˻�" �ϴ� �Լ�
    return (s.top == MAX_INDEX - 1); // top ������ 99�϶� 1�� ��ȯ�Ѵ�.(true ��ȯ)
}

int is_empty(stack s) { //������ ������� �˻��ϴ� �Լ�

    return (s.top == -1); //top ������ -1�϶� 1�� ��ȯ�Ѵ�.(true ��ȯ)
}

void push(stack* s, int input) { //���ÿ� ���� �ִ� �Լ�, �޾ƿ� input �� ���ÿ� �ִ� �Լ���.

    if (is_full(*s)) { //���� ������ ���� á����
        printf("������ ���� á��"); // �̰��� ����ϰ�
        exit(1); // ���α׷��� �����Ѵ�.
    }


    else {  //���� ������ ���� ���� �ʾ�����
        s->top += 1; // ���� top�� 1�� �����Ѵ�.
        s->data[s->top] = input; //data �迭�� ������ top index �� input �� �Ҵ��Ѵ�.

    }
}

void init(stack* s) { // ������ �ε��� ��ġ�� �ʱ�ȭ�ϴ� �Լ�, ������ �����Ǹ� ������ ȣ���ؾ���
    s->top = -1;
}

int peek(stack s) { //�迭�� ������������� �迭�� top index�� ���� ��ȯ�Ѵ�.
    //���������� push ���� ��ȯ�Ѵ�.

    if (is_empty(s)) { //���� ������ ������ִٸ�
        printf("������ �������!"); // �̰��� ����ϰ� 
        exit(1); // ���α׷� ����
    }
    else { // ���� ������ ������ִ°� �ƴ϶��
        return (s.data[s.top]); // data �迭�� top index�� ���� ��ȯ�Ѵ�.
    }
}

int pop(stack* s) { // data�迭�� top index �� -1 �� �ϰ� ����� top index�� ���� �Ѵ�.
    //���������� push ���� �����ϰ� ��ȯ�Ѵ�.

    if (is_empty(*s)) { //���� ������ ������ִٸ�
        printf("������ �������!");// �̰��� ����ϰ� 
        exit(1);// ���α׷� ����
    }
    else { // ���� ������ ������ִ°� �ƴ϶��
        s->top -= 1; //top������ -1�� ����
        return (s->data[s->top + 1]); // ��ȯ�� data�迭�� top���� +1 index�� ��ȯ�Ѵ�.
    }
}


int main() {

    stack st;
    init(&st);


    //����! ������ ����Ͽ� ���ڿ��� �������� ����ϱ�
    //�����ٶ󸶹ٻ� �� ��ٸ���ٳ��� �� ����ϱ�

    char korean[] = "abcdefg"; // �������� �̿��� �迭 ����

    for (int i = 0; korean[i] != NULL; i++) { //�迭 �ε����� ���� ��ŭ �۵��ϴ� for�� ����
        push(&st, korean[i]); //push�Լ� ȣ��(stack�� ���� �ϳ��� �־��ش�)
    }

    while (!is_empty(st)) { //���� stack�� ������� �ʴ´ٸ� ���� ����.
        
        printf("%c/>", pop(&st)); //pop�� �Լ��� return���� ���.
    }
    char* ptr = strchr(korean, '<');
    printf("�ּҰ� : %p\n", ptr);
}
