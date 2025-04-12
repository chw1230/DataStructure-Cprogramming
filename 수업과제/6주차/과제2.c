#include <stdio.h>
#include <stdlib.h>
/*
�ܼ����� ����Ʈ���� Ư���� �����Ͱ��� ���� ��带 
�����ϴ� �Լ��� �ۼ�
*/
typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

// ����Ʈ�� ���� �κп� �׸��� �����ϴ� �Լ�
ListNode* insert_first(ListNode* head, int value) {

	ListNode* p = (ListNode*)malloc(sizeof(ListNode));

	p->data = value; // p�� ���� �־��ֱ�

	// ���� ������ �߿���!!
	p->link = head; // p�� link�� head�� ����Ű�� ��带 ����Ű���� �ϱ�!
	head = p; // head�� p�� ����Ű�� ��带 ����Ű���� �ϱ�
	return head;
	// p�� �׳� ���ֵ� ����� ���������̴ϱ�
}


// ����Ʈ�� �湮�Ͽ� ��� �׸��� ����ϴ� �Լ�
void print_list(ListNode* head) {
	/* for ���� ���
	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%d ->", p->data);
	}
	*/

	// while �� ���
	ListNode* p = head;
	while (p != NULL) {
		printf("%d -> ", p->data);
		p = p->link;
	}
	printf("NULL\n");
}


ListNode* delete_node(ListNode* head, int value) {
	ListNode* p = head; 
	ListNode* removed; // ������ ��带 ���� ������ ����


	if (p == NULL) {
		printf("��尡 ����ֽ��ϴ�.");
		return NULL;
	}


	// ã�� ���� ù��° ��忡 ���� ��, �ƴ� ���� ����� �����ϱ�

	// ù ��° ��忡 ã�� ���� ���� ��
	if (p->data == value) {
		head = p->link;
		free(p);
		return head;
	}

	// �ƴ� ���
	while (p->link != NULL) {
		if (p->link->data == value) {
			removed = p->link; // ������ ���� ����
			p->link = p->link->link;
			free(removed);
			return head;
		}
		p = p->link;
	}

	if (p->link == NULL) {
		printf("ã�� ���� �������� �ʽ��ϴ�.\n");
	}
	return head;
}

// �׽�Ʈ ���α׷�
int main(void)
{
	int value;
	ListNode* head = NULL;
	head = insert_first(head, 10);
	head = insert_first(head, 13);
	head = insert_first(head, 8);
	head = insert_first(head, 33);
	head = insert_first(head, 21);
	print_list(head);
	printf("������ ���� �Է��Ͻÿ�: ");
	scanf_s("%d", &value);
	head = delete_node(head, value);
	print_list(head);
	return 0;
}