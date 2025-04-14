#include <stdio.h>
#define MAX_STACK_SIZE 100

/*
* 2���� Stack�� �̿��� Queueó�� �۵��ϴ� �ڷᱸ���� ����
* �Է� ���� (stack_in): �����͸� ������� �� ����ϴ� ����
* ��� ���� (stack_out): �����͸� ���� �� ����ϴ� ����
*/

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} Stack;

// ���� �ʱ�ȭ �Լ�
void init_Stack(Stack* stack) {
	stack->top = -1;
}

// ���� ����ִ� �� Ȯ��
int is_empty(Stack* stack) { 
	return (stack->top == -1);
}

// ������ ���� á���� Ȯ��
int is_full(Stack* stack) { 
	return (stack->top == (MAX_STACK_SIZE - 1));
}

void push(Stack* stack,int value) {
	stack->data[++(stack->top)] = value;
}

int pop(Stack* stack) {
	return stack->data[(stack->top)--];
}

// Queue ����ü �����ϱ�
typedef struct {
	// ť�� �̷�� 2���� �������� �����ϱ�!
	Stack stack_in;  
	Stack stack_out; 
} Queue;

// ť �ʱ�ȭ�ϱ�
void init_Queue(Queue* queue) {
	init_Stack(&(queue->stack_in));
	init_Stack(&(queue->stack_out));
}

// ť�� ������ �߰��ϱ�
void enqueue(Queue* queue, int value) {
	if (is_full(&(queue->stack_in))) {// ť ���� á���� Ȯ���ϱ�
		printf("%d �Է� ����, �Է� ������ ����á���ϴ�.(= ť�� ���� á���ϴ�.)\n",value);
		return 0;
	}
	printf("%d �Է� ����\n", value);
	push(&(queue->stack_in), value); // �Է� �������� ������ �߰�
}

// ť���� ������ �����ϱ�
int dequeue(Queue* queue) {
	int save; 

	if (!is_empty(&(queue->stack_in)) && is_empty(&(queue->stack_out))) { // �Է� ���� �����ϰ�, ��� ������ ����ִ� ���
		while (!is_empty(&(queue->stack_in))) { 
			// �Է� ���ÿ� �ִ� ��� ���� ��� �������� �ű��
			save = pop(&(queue->stack_in));
			push(&(queue->stack_out), save);
		}
	}

	if (!is_empty(&(queue->stack_out))) { // ��� ���ÿ� ���� �����ϴ� ���
		printf("��ȯ�� : %d\n", pop(&(queue->stack_out)));
	}
	else { // ��� ���ÿ� ���� �������� �ʴ� ��� 
		// �Է� ������ ���� ��� �ű�� ������ ���Ʊ� ������
		// ���⼭�� ��� ������ ��� �Է� ���õ� ���ʿ� �ƹ� �͵� �����ٰ� ������ �� ����!
		printf("ť�� ��� �ֽ��ϴ�.");
		return 0;
	}
}


int main(void) {
	Queue queue;

	init_Queue(&queue);
	printf("10,20,30 enqueue �ϱ�\n");
	enqueue(&queue, 10);
	enqueue(&queue, 20);
	enqueue(&queue, 30);

	printf("\ndequeue 2�� ����\n");
	dequeue(&queue);
	dequeue(&queue);

	printf("\n40 enqueue �ϱ�\n");
	enqueue(&queue, 40);

	printf("\ndequeue 2�� ����\n");
	dequeue(&queue);
	dequeue(&queue);

	printf("\n����ִ� ���¿��� dequeue �����ϱ�\n");
	dequeue(&queue);
}

