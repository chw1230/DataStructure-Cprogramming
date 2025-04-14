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

int check_matching(const char* c) { // �ּҸ� �Ѱ� ���� �� �ִ� char *c ����
	Stack s;
	init_stack(&s);
	int len = strlen(c);

	for (int i = 0; i < len; i++)
	{
		char ch = c[i];
		switch (ch) {
		case '[': case '{': case'(':
			// switch���� Ư¡ Ȱ���ϱ�
			push(&s, ch);
			break;
		}
		switch (ch) {
		case ']': case '}': case')':
			if (is_empty(&s)) {
				return 0; // ������ ��� �ִ� ��� ������ -> �� ���� ���� ��ȣ�� ������ �ʰ� ���� ��ȣ ���� ���� ��츦 �ǹ�!!
			}
			else
			{
				char save = pop(&s);
				if ((save == '[' && ch != ']') || (save == '{' && ch != '}') || (save == '(' && ch != ')')) {
					// �߸� ��Ī�Ǵ� ��츦 �ǹ��ϹǷ� ����
					return 0;
				}
			}
			break;
		}
	}

	// ���� ���� �� ���Ҵٸ�
	if (!is_empty(&s)) {
		return 0; // ������ ��� ���� ������ / 0�� ���и� �ǹ�
	}
	return 1;
}

int main(void) {
	char *p = "{ A[(i+1)]=0; }"; // p�� "���ڿ�"�� �ּҸ� ������ ����
	if (check_matching(p) == 1) 
		printf("%s ��ȣ�˻缺��\n", p);
	else
		printf("%s ��ȣ�˻����\n", p);
	return 0;
}