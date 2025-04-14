#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

// Circular Queue

typedef int element;

typedef struct {
	int rear, front;
	element data[MAX_QUEUE_SIZE];
} QueueType;

// �ʱ�ȭ �Լ� 
void init_queue(QueueType* q) {
	q->rear = 0;
	q->front = 0;
}

// �������ִ� �� Ȯ���ϴ� �Լ�
int is_full(QueueType* q) {
	return q->front == (q->rear + 1) % MAX_QUEUE_SIZE;
}

// ��� �ִ��� Ȯ���ϴ� �Լ�
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

// ���� �Լ� enqueue
void enqueue(QueueType* q,int value) {
	if (is_full(q)) {
		printf("Queue�� �������ֽ��ϴ�.\n");
		exit(1);
	}

	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = value;
}

// ���� �Լ� dequeue
int dequeue(QueueType* q) {
	if (is_empty(q)) {
		printf("Queue�� ����ֽ��ϴ�.");
		exit(1);
	}

	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// ����ť ��� �Լ�
void queue_print(QueueType* q) {
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);

	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear) {
				break;
			}
		} while (i != q->front);
	}
	printf("\n");
}

int main(void) {
	QueueType queue;
	int element;

	init_queue(&queue);

	enqueue(&queue, 2);
	enqueue(&queue, 9);
	enqueue(&queue, 3);
	enqueue(&queue, 5);
	queue_print(&queue);
	

	element = dequeue(&queue);
	printf("�ų� ���� : %d\n", element);
	element = dequeue(&queue);
	printf("�ų� ���� : %d\n", element);
	queue_print(&queue);

	enqueue(&queue, 7);
	enqueue(&queue, 8);
	queue_print(&queue);

	element = dequeue(&queue);
	printf("�ų� ���� : %d\n", element);
	element = dequeue(&queue);
	printf("�ų� ���� : %d\n", element);
	queue_print(&queue);

	enqueue(&queue, 1);
	queue_print(&queue);

	
	return 0;
}