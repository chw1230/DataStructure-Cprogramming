#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char title[20];
	char name[20];
	int page;
} manager;

int main(void) {
	manager* ptr = (manager*)malloc(sizeof(manager) * 3);

	printf("���� ���� �Է�\n");
	for (int i = 0; i < 3; i++)
	{
		printf("%d��° å ���� �Է�\n",i+1);
		printf("����: ");
		scanf("%s", (ptr+i)->name);
		printf("����: ");
		scanf("%s", (ptr + i)->title);
		printf("������ ��: ");
		scanf("%d", &((ptr + i)->page));
	}

	printf("\n���� ���� ���\n");
	for (int i = 0; i < 3; i++)
	{
		printf("%d��° å ���� ���\n",i+1);
		printf("����: %s\n", (ptr + i)->name);
		printf("����: %s\n", (ptr + i)->title);
		printf("������ ��:%d\n", (ptr + i)->page);
	}
	free(ptr);
}