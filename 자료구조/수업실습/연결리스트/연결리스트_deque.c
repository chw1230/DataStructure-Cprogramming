#include <stdio.h>
#include <stdio.h>
#include <malloc.h>

typedef int element;

typedef struct {
	element data;
	struct DequeueNode* link;
}DequeueNode;

typedef struct {
	DequeueNode* rear;
	DequeueNode* front;
}LinkedDequeueType;

// �ʱ�ȭ �Լ�
void init(LinkedDequeueType* d) {
	d->rear = NULL;
	d->front = NULL;
}

// ����ִ��� ���� Ȯ�� �Լ�
int is_empty(LinkedDequeueType* d) {
	return ((d->front == NULL) && (d->rear == NULL));
}

// �ڿ��� �߰�
void add_rear(LinkedDequeueType* d, element data) {
	DequeueNode* tmp = (DequeueNode*)malloc(sizeof(DequeueNode));
	tmp->data = data;
	tmp->link = NULL;

	if (is_empty(d)) {
		d->front = tmp;
		d->rear = tmp;
	}
	else {
		d->rear->link = tmp;
		d->rear = tmp;
	}
}

// �տ��� ����
int delete_front(LinkedDequeueType* d) {
	DequeueNode* tmp = d->front;
	if (is_empty(d)) {
		printf("ť�� ����ֽ��ϴ�.");
		exit(1);
	}
	else {
		element data = tmp->data;
		d->front = tmp->link;
		if (d->front == NULL) {
			d->rear = NULL;
		}
		free(tmp);
		return data;
	}
}

// �տ��� �߰�
void add_front(LinkedDequeueType* d, element data) {
	DequeueNode* tmp = (DequeueNode*)malloc(sizeof(DequeueNode));
	tmp->data = data;
	tmp->link = NULL;

	if (is_empty(d)) {
		d->front = NULL;
		d->rear = NULL;
	}
	else {
		tmp->link = d->front->link;
		d->front = tmp;
	}
}

// �ڿ��� ����
int delete_rear(LinkedDequeueType* d) {
	DequeueNode* tmp = d->front;
	if (is_empty(d)) {
		printf("dequeue�� ��� �ֽ��ϴ�. ���� �Ұ���");
		exit(1);
	}
	else {
		int data;
		DequeueNode* current = d->front;
		DequeueNode* pre = NULL;


		while (current -> link != NULL) { // ������ �̵�
			pre = current;
			current = current->link;
		}
		
		data = current->data;
		if (pre == NULL) {
			// ��尡 �ϳ����� ���
			d->front = d->rear = NULL;
		}
		else {
			pre->link = NULL;
			d->rear = pre;
		}

		free(current);
		return data;
	}
}

// ��� �Լ�
void print_deque(LinkedDequeueType* d) {
	DequeueNode* p = d->front;
	printf("[FRONT] ");
	while (p != NULL) {
		printf(" %d ", p->data);
		p = p->link;
	}
	printf(" [REAR]\n");
}

// �׽�Ʈ main �Լ�
int main(void) {
	LinkedDequeueType dq;
	init(&dq);

	add_front(&dq, 10);
	add_front(&dq, 20);
	add_rear(&dq, 30);
	add_rear(&dq, 40);
	print_deque(&dq);  // ����: 20 10 30 40

	printf("�� ����: %d\n", delete_front(&dq));  // 20
	printf("�� ����: %d\n", delete_rear(&dq));   // 40
	print_deque(&dq);  // ����: 10 30

	return 0;
}