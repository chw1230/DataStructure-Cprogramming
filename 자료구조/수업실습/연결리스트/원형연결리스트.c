#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;
 
// ���� ���� ����Ʈ�� ó���� ����
ListNode* insert_first(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) { // ����Ʈ�� �ϳ��� ���� ���
		head = node; 
		node->link = head; // node�� ��ũ�� �ڱ� �ڽ��� ����Ű����
	}
	else {
		node->link = head->link; // ���� ���� ��尡 ������ head�� ���� ��带 ����Ű�����ϱ�
		head->link = node; // ���� head�� ���λ��� ��带 ����Ű���� �ٲٱ�
		
	}
	return head; //����� ��� �����͸� ��ȯ�Ѵ�.
}

// ���� ���� ����Ʈ�� ���� ����
ListNode* insert_last(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) { // ����Ʈ�� �ϳ��� ���� ���
		head = node;
		node->link = head; // node�� ��ũ�� �ڱ� �ڽ��� ����Ű����
	}
	else {
		node->link = head->link; // ���� ���� ��尡 ������ head�� ���� ��带 ����Ű�����ϱ�
		head->link = node; // ���� head�� ���λ��� ��带 ����Ű���� �ٲٱ�
		head = node; // ���������� �߰��� ��带 ��� ���� �ٲٱ�
	}
	return head; //����� ��� �����͸� ��ȯ�Ѵ�.
}

// ����Ʈ�� �׸� ���
void print_list(ListNode* head){

	ListNode* p;

	if (head == NULL) {
		return;
	}
	p = head->link; // ��� ��尡 ������ ��带 ����Ű���� �����Ͽ��� ������ p�� head -> link �� �ֱ�
	do {
		printf(" %d ", p->data);
		if (p != head) { // '->' �������ϴ� ���� �߰��ϱ�! �� ���������� ������ �ʰ� �ϵ���!
 			printf("->");
		}
		p = p->link;
	} while (p != head->link); // ó���� ������ �ּҷ� �ٽ� ���ƿ��� ������
}



// �׽�Ʈ ���α׷�
int main(void) {
	ListNode* head = NULL;

	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10);
	print_list(head);
	return 0;
}