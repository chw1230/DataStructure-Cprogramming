#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	int data[MAX_QUEUE_SIZE];
	int rear, front;
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

// ���� �ڿ� �����ϴ� �Լ� add_rear (= enqueue)
void add_rear(QueueType* q, int value) {
	if (is_full(q)) {
		printf("���� �������ֽ��ϴ�.\n");
		exit(1);
	}

	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = value;
}

// ���� �տ��� �����ϴ� �Լ� delete_front (=dequeue)
int delete_front(QueueType* q) {
	if (is_empty(q)) {
		printf("���� ����ֽ��ϴ�.");
		exit(1);
	}

	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// ���� �տ� �����ϴ� �Լ� add_front
void add_front(QueueType* q,int value) {
	if (is_full(q)) {
		printf("���� ����á���ϴ�.");
		exit(1);
	}

	q->data[q->front] = value; // ���� �ְ�
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; // �ݽð� �������� �̵�
	// �� front���� 1�� ���� MAX�� ���ұ�? -> -1 ���� : front�� �ڸ� �� �ð�� �̵� , + MAX ���� : �ε��� 0���� MAX-1�� �̵��ϴ� ��츦 ���ؼ�
	// �� % MAX�� �ұ�? -> �ε����� 1�� ��� -1 �ϸ� 0 ���⿡ +MAX�ϸ� 5�ε� 5�ε����� ���� MAX�� ������ 0�� ��ġ ��Ű�� ���ؼ� ������ ���ڵ��� 5���� ������ ���� ��ġ��� �����ϸ��!
}

// ���� �ڿ� ���� �����ϴ� �Լ� delete_rear 
int delete_rear(QueueType* q) {
	if (is_empty(q)) {
		printf("���� ���ֽ��ϴ�.");
		exit(1);
	}
	int save = q->rear; // rear�� ���� �ٲ�� ���� �����صα�
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	// �� rear���� 1�� ���� MAX�� ���ұ�? -> -1 ���� : rear�� �ڸ� �� �ð�� �̵� , + MAX ���� : �ε��� 0���� MAX-1�� �̵��ϴ� ��츦 ���ؼ�
	// �� % MAX�� �ұ�? -> �ε����� 1�� ��� -1 �ϸ� 0 ���⿡ +MAX�ϸ� 5�ε� 5�ε����� ���� MAX�� ������ 0�� ��ġ ��Ű�� ���ؼ� ������ ���ڵ��� 5���� ������ ���� ��ġ��� �����ϸ��!
	return q->data[save];
}

// ���� ���� ���� Ȯ�θ� �ϴ� �Լ�
int get_front(QueueType* q) {
	if (is_empty(q)) {
		printf(" ���� ��������Դϴ�");
		exit(1);
	}
	return q->data[(q->front+1)%MAX_QUEUE_SIZE]; // front�ε������� �ƹ����� ���� �׷��Ƿ� front + 1�� ����
	// ������ MAX�� ������? -> front�� MAX - 1�� ��쿡 �׳� + 1�� �ϸ� ���ص� �迭�� �Ѿ������
}

// ���� ���� ���� Ȯ�θ� �ϴ� �Լ�
int get_rear(QueueType* q) {
	if (is_empty(q)) {
		printf(" ���� ��������Դϴ�");
		exit(1);
	}
	return q->data[q->rear];
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
	QueueType d1;
	int element;

	init_queue(&d1);

	add_rear(&d1, 2);
	add_rear(&d1, 9);
	add_rear(&d1, 3);
	add_rear(&d1, 5);
	queue_print(&d1);

	element = delete_front(&d1);
	printf("�ų� ���� : %d\n", element);
	element = delete_front(&d1);
	printf("�ų� ���� : %d\n", element);
	queue_print(&d1);

	add_rear(&d1, 7);
	add_rear(&d1, 8);
	queue_print(&d1);

	element = delete_front(&d1);
	printf("�ų� ���� : %d\n", element);
	element = delete_front(&d1);
	printf("�ų� ���� : %d\n", element);
	queue_print(&d1);

	add_rear(&d1, 1);
	queue_print(&d1);
	
	printf("----------------------------------\n");
	QueueType d2;
	init_queue(&d2);

	add_front(&d2, 2);
	add_front(&d2, 9);
	add_front(&d2, 3);
	add_front(&d2, 5);
	queue_print(&d2);

	element = delete_rear(&d2);
	printf("�ų� ���� : %d\n", element);
	element = delete_rear(&d2);
	printf("�ų� ���� : %d\n", element);
	queue_print(&d2);

	add_front(&d2, 7);
	add_front(&d2, 8);
	queue_print(&d2);

	element = delete_rear(&d2);
	printf("�ų� ���� : %d\n", element);
	element = delete_rear(&d2);
	printf("�ų� ���� : %d\n", element);
	queue_print(&d2);

	add_front(&d2, 1);
	queue_print(&d2);

	return 0;
}