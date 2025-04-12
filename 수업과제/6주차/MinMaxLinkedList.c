#include <stdio.h>
#include <stdlib.h>
/*
 �ܼ����� ����Ʈ�� ���ĵ��� ���� �������� ����Ʈ�� ����
 ����Ʈ���� �ִ밪�� �ּҰ��� ã�� ���α׷� �ۼ�
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

// ���� ����Ʈ���� �ּҰ��� �ִ��� ã�� �Լ�
void MinMaxfromList(ListNode* head) {
	ListNode* p = head;
	int max = head->data;
	int min = head->data;
	while (p != NULL) {
		if (max < p->data) {
			max = p->data;
		}
		else if (min > p->data) {
			min = p->data;
		}
		p = p->link;
	}
	printf("MAX = %d �̰�, min = %d �̴�.", max, min);
}


// �׽�Ʈ ���α׷�
int main(void)
{
	ListNode* head = NULL;
	head = insert_first(head, 10);
	head = insert_first(head, 13);
	head = insert_first(head, 8);
	head = insert_first(head, 33);
	head = insert_first(head, 21);
	print_list(head);
	MinMaxfromList(head);
	return 0;
}