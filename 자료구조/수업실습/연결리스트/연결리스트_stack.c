#include <stdio.h>
#include <malloc.h>

typedef int element;

typedef struct {
	element data;
	struct StackNode* link;
} StackNode;

typedef struct {
	// ���Ḯ��Ʈ���� ���� ����
	StackNode *top;
} LinkedStackType;

// �ʱ�ȭ �Լ�
void init(LinkedStackType* s) {
	s->top = NULL;
}

// ���� ���� ���� �Լ�
int is_empty(LinkedStackType* s) {
	return (s->top == NULL);
}

// push ���� �Լ�
void push(LinkedStackType* s, element data) {
	StackNode* tmp = (StackNode*)malloc(sizeof(StackNode));
	tmp->data = data;
	tmp->link = s->top; // ���� �߰��� ��尡 ������ ������ ���� �����ִ� ��带 ����Ű�����ϱ�
	s->top = tmp; // �߰��� ���� top�� ����Ű�� ��� �������ֱ�
}

// pop ���� �Լ�
element pop(LinkedStackType* s) {
	if (is_empty(s)) {
		printf("������ �������\n");
		exit(1);
	}
	else {
		StackNode* tmp = s->top; // pop�� ���� tmp�� ����
		int save = tmp->data; // pop�� ����� ���� save�� ����, ��ȯ�� ���ؼ�
		s->top = s->top->link;
		free(tmp);
		return save;
	}
}

// ������ ������ �� ����ϴ� �Լ�
void print_stack(LinkedStackType* s) {
	for (StackNode* p = s->top; p != NULL; p = p->link) {
		/*if (p->link != NULL) {
			printf(" -> ");
		}*/
		printf("%d -> ", p->data);
	}
	printf("NULL\n");
}

int main(void) {
	LinkedStackType s;
	init(&s);
	push(&s, 1); print_stack(&s);
	push(&s, 2); print_stack(&s);
	push(&s, 3); print_stack(&s);
	int popData = 0;
	popData = pop(&s);
	printf("%d ���� : ", popData);
	print_stack(&s);
	popData = pop(&s); 
	printf("%d ���� : ", popData);
	print_stack(&s);
	popData = pop(&s); 
	printf("%d ���� : ", popData);
	print_stack(&s);
}