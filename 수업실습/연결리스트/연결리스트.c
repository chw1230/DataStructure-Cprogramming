#include <stdio.h>
#include <stdlib.h>

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

// ����Ʈ�� �߰� �κп� �׸��� �����ϴ� �Լ�
ListNode* insert(ListNode* head,ListNode*pre, int value) {

	ListNode* p = (ListNode*)malloc(sizeof(ListNode));

	p->data = value;

	// ���� �߿�
	p->link = pre->link;
	pre->link = p;

	return head; // ��� ���� �����ϵ��� ��带 ��ȯ���ִ� ��!
}

// ����Ʈ�� ù ��° �׸��� �����ϴ� �Լ�
ListNode* delete_first(ListNode * head) {
	ListNode* removed;

	if (head == NULL) {
		return NULL;
	}

	removed = head; // �Ҵ� ������ ���� ����
	head = removed->link;
	free(removed);
	// ���࿡ �ϳ��� �����ͷ� ǥ���ؾ� �Ѵٸ� head = head -> link;
    return head;
}

// ����Ʈ�� �߰� �׸��� �����ϴ� �Լ�
ListNode* delete_pre(ListNode* head, ListNode* pre)
{
	ListNode* removed; 
	removed = pre->link; 
	pre->link = removed->link; // ���� ����� ���� ��带 ����Ű�� �ϱ�
	free(removed); 
	return head;
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

// Ư���� ���� Ž���ϴ� �Լ�
ListNode* search_list(ListNode* head, element x) {
	// ������ ��� ������ null ��ȯ

	ListNode* p = head;
	while (p != NULL) {
		if (p->data == x) {
			return p;
		}
		p = p->link;
	}
	return p;
}

// 2���� ����Ʈ�� ���ϴ� �Լ�
ListNode* cooncat_linkedList(ListNode* head1, ListNode* head2) {
	// head1�� head2 �����ϱ�

	// head1 �� null �̸� head2 ��ȯ
	if (head1 == NULL) {
		return head2;
	}
	else if (head2 == NULL) {
		return head1;
	}
	else {
		ListNode* p = head1;
		
		// head1�� ���� ã��
		while (p->link != NULL) {
			p = p->link;
		}
		p->link = head2;
	}
	return head1;
}

int main(void) {
	ListNode* head = NULL;


	for (int i = 0; i < 5; i++) {
		head = insert_first(head, i*10);
		print_list(head);
	}

	/*head = insert_first(head, 500);
	print_list(head);*/

	int find = 500;
	if (search_list(head, find) != NULL)
		printf("����Ʈ���� %d�� ã�ҽ��ϴ�.\n",find);
	else
		printf("����Ʈ���� %d�� ã�� ���߽��ϴ�.\n",find);

	/*
	for (int i = 0; i < 5; i++) {
		head = delete_first(head);
		print_list(head);
	}
	*/


	ListNode* head2 = NULL;
	ListNode* combined_head = NULL;

	for (int i = 0; i < 3; i++) {
		head2 = insert_first(head2, i + 3);
	}
	print_list(head2);

	combined_head = cooncat_linkedList(head, head2);
	print_list(combined_head);

	return 0;
}

