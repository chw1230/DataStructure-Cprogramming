#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node * next;
} Node;

void AddNum(Node **head, Node **tail, int data) {
	if (*head != NULL) {  // head�� �����ϴ� ���
		(*tail) -> next = (Node*)malloc(sizeof(Node)); // �޸� �Ҵ�
		*tail = (*tail)->next; // ������ ��� �ֽ�ȭ
	}
	else { // head�� �ƹ� �͵� ���� ���� �ʴ� ���
		*head = (Node*)malloc(sizeof(Node)); 
		*tail = *head; // ������ ��� �ֽ�ȭ
	}
	(*tail)->data = data; // ������ ��忡�� data ����
	(*tail)->next = NULL; // ������ ����� next�� NULL�� �����ϸ� ���������� ��Ȯ��!
}


void main(void) {
	Node* head = NULL; // ��� ������ ù��° ��带 ����Ŵ
	Node* tail = NULL;
	Node* p;
	int data;
	int sum = 0;

	/*
	* Node�� ä��� �ݺ���
	*/
	while (1) {
		printf("���ڸ� �Է��Ͻÿ�(-1 �Է�->����): ");
		scanf("%d", &data);
		if (data == -1) break;

		AddNum(&head, &tail, data);
	}

	/*
	* Node�� data�� ����ϰ�, sum�� �����ϴ� �ݺ���
	*/
	p = head;
	while (p != NULL) {
		if (p != head) { // ó���� head�� �ּҰ� ������ '+' ��� x
			printf("+");
		}
		printf(" %d ", p->data);
		sum += p->data;
		p = p->next;
	}
	printf(" = %d", sum);

	/*
	*  Node�� �Ҵ��� �����ϴ� �ݺ���
	*/
	while (head != NULL) {
		p = head;
		head = head->next;  // head�� ���� ���� �Ѿ �ּ� �����صα�!
		free(p);
	}
	tail = head; // head�� NULL�� ��!, tail���� NULL ����
}
