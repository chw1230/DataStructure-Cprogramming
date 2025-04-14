
#include <stdio.h>

#define MAX_STACK_SIZE 100
typedef int element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} Stack;

void init_stack(Stack * s) {
	s->top = -1;
}

int is_empty(Stack* s) { // ���� ���� -1�� top�� ���ٸ� �迭�� ����ִ� ������! 
	return (s->top == -1);
}

int is_full(Stack* s) { // ������ �ִ� �迭�� top�� ���ٸ� ������ ���� �� ������!
	return (s->top == (MAX_STACK_SIZE -1));
}

void push(Stack* s, int n) {
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else {
		s->data[++(s->top)] = n;
	}
}

int pop(Stack* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		return;
	}
	else {
		return s->data[(s->top)--];
	}
}

int main(void) {
	Stack s;

	init_stack(&s); // ���� �ʱ�ȭ

	push(&s, 1);
	push(&s, 2);
	push(&s, 3);

	printf("%d\n",pop(&s));
	printf("%d\n",pop(&s));
	printf("%d",pop(&s));
}
