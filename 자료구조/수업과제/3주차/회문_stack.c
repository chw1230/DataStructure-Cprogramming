#include <stdio.h>

/*
3���� ���� ȸ�� ���� ��� ȸ���̶� �յ� ��� �ʿ��� �о ���� �ܾ �ǹ�
ex> ��eye��, ��Madam, I��m Adam��, ��race car�����̴�. ���⼭ �������̳� �����̽�, ��ҹ��� ���� ����
������ �̿��Ͽ� �־��� ���ڿ��� ȸ������ �ƴ����� �����ϴ� ���α׷��� �ۼ�
*/

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
	} else {
		s->data[++(s->top)] = n;
	}
}

int pop(Stack* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		return;
	} else {
		return s->data[(s->top)--];
	}
}

int palindrome(char c[]) { // �ҹ��ڸ� �ִ� ������ �迭�� �ޱ�
	Stack s;
	init_stack(&s);

	int len = strlen(c);
	int i;
	// ���ÿ� �ֱ�
	for (i = 0; i < len/2; i++)
	{
		push(&s, c[i]);
	}

	if (len % 2) {
		// Ȧ���� ���
		for (i = 1; i <= len / 2; i++)
		{
			if (pop(&s) != c[len / 2 + i]) {
				return 0;
			}
		}
	} else {
		// ¦���� ���
		for (i = 0; i < len / 2; i++)
		{
			if (pop(&s) != c[len / 2 + i]) {
				return 0;
			}
		}
	}
	return 1;
}

int main(void) {
	char c[MAX_STACK_SIZE];
	fgets(c, MAX_STACK_SIZE, stdin);

	// ������ �迭�� �ҹ����̰�, ����� �ٸ� ���ڵ�(������ ��)�� ������ ���ڿ��� �����ϱ�
	int len = strlen(c);
	int cnt = 0;
	for (int i = 0; i < len; i++)
	{ // �ƽ�Ű �ڵ带 ���� ��
		if (('a' <= c[i]) && (c[i] <= 'z')) {
			c[cnt] = c[i];
			cnt++;
		} else if (('A' <= c[i]) && (c[i] <= 'Z')) {
			c[cnt] = c[i] + 32;
			cnt++;
		}
	}
	c[cnt] = '\0'; // �ʿ��� ��ҵ�θ� ������ �����ϰ� �������� ������ ���� �ǹ��ϴ� ��

	if (cnt == 0) { // �����̽��ٸ� ���� ��� + ���͸� �׳� �ٷ� ���� ��� -> ������
		printf("ȸ���� �ƴմϴ�.");
		return 0;
	}

	if (palindrome(c)) {
		printf("ȸ���Դϴ�.");
	} else {
		printf("ȸ���� �ƴմϴ�.");
	}
	return 0;
}