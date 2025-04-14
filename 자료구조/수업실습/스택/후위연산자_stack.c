#include <stdio.h>

#define MAX_STACK_SIZE 100
typedef char element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} Stack;

void init_stack(Stack* s) {
	s->top = -1;
}

int is_empty(Stack* s) { // ���� ���� -1�� top�� ���ٸ� �迭�� ����ִ� ������! 
	return (s->top == -1);
}

int is_full(Stack* s) { // ������ �ִ� �迭�� top�� ���ٸ� ������ ���� �� ������!
	return (s->top == (MAX_STACK_SIZE - 1));
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

int eval(char exp[]) {
	int n1, n2;
	int len = strlen(exp);

	Stack s;
	init_stack(&s); // ���� �ʱ�ȭ 

	for (int i = 0; i < len; i++)
	{
		char ch = exp[i];
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/') { // ch�� �����ڰ� �ƴ� ������ ��� ���ÿ� ���� push�ϱ�!
			push(&s, ch - '0');
		}
		else
		{ // ch �������� ��� ���ÿ��� ����ϱ� ���� ���� 2���� ������ ���� ���� ���� ��� n1,n2�� �ֱ�  
			n1 = pop(&s);
			n2 = pop(&s);
			switch (ch) {
				case '+':
					push(&s, n1 + n2);
					break;
				case '-':
					// -�� ��� �Ի� ���� �����ϱ� ������ �������� �������� �� ���� �� ���� n2��! �׷��Ƿ� n2-n1 �����ϱ�!
					push(&s, n2 - n1);
					break;
				case '*':
					push(&s, n1 * n2);
					break;
				case '/':
					// /�� ��� �Ի� ���� �����ϱ� ������ �������� �������� �� ���� �� ���� n2��! �׷��Ƿ� n2/n1 �����ϱ�!
					push(&s, n2 / n1);
					break;
			}
		}
	}
	return pop(&s); // ������ �ϳ� �����ִ� ���� pop�� �̿��Ͽ� ��ȯ���ֱ�
}

int main(void) {
	int result;
	printf("����ǥ����� 82/3-32*+\n");
	result = eval("82/3-32*+");
	printf("������� %d\n", result);
	return 0;
}
