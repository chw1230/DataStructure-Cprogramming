#include <stdio.h>
#include <stdlib.h>

// ���� 3) �ΰ��� ��带 �����ϱ�

typedef struct Node
{
	int data;
	struct Node* next;
} Node;

int main(void) {
	Node* ptr = (Node*)malloc(sizeof(Node) * 2);
	if (ptr == NULL) {
		printf("�޸𸮰� �Ҵ���� �ʾҽ��ϴ�.\n");
		return 1;
	}

	for (int i = 0; i < 2; i++)
	{
		(ptr + i)->data = 10 * (i + 1);
	}

	ptr->next = ptr + 1; // ù ��° ����� next�� �� ��° ��带 ����Ű���� ����!
	(ptr + 1)->next = NULL; // �� ��° ����� next�� NULL�� ����!

	printf("ù ��° ����� ������ ���: %d\n", ptr->data);
	printf("ù ��° ����� next�� �̿��Ͽ� �� ��° ����� ������ ���: %d", ptr->next->data);
	free(ptr);
	return 0;
}