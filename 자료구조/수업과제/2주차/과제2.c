#include <stdio.h>
#include <stdlib.h>

// ���� 2) ����ü�� �����Ҵ��� ���� ���

typedef struct student
{
	char name[50];
	int age;
	float grade;
} std;

int main(void) {
	int n;
	printf("������ �л� ���� �Է�: ");
	scanf("%d", &n);

	std* ptr = 0;
	ptr = (std*)malloc(sizeof(std) * n); // �л� �� ��ŭ �Ҵ��ϱ�! + ����ü�� �����Ҵ��� ���� ���!
	if (ptr == NULL) {
		printf("�޸𸮰� �Ҵ���� �ʾҽ��ϴ�.\n");
		return 1;
	}
	

	for (int i = 0; i < n; i++)
	{
			printf("�л� %d�� �̸� �Է�: ",i+1);
			scanf("%s", ptr[i].name);
			while (getchar() != '\n');

			printf("�л� %d�� ���� �Է�: ",i+1);
			scanf("%d",&ptr[i].age);
			while (getchar() != '\n');

			printf("�л� %d�� ���� �Է�: ",i+1);
			scanf("%f", &ptr[i].grade);
			while (getchar() != '\n');

	}

	printf("--- �л� ���� ��� ---");
	for (int i = 0; i < n; i++) {
			printf("\n�л� %d�� �̸� = %s, ���� = %d, ���� = %.1f",
				i+1,ptr[i].name, (ptr + i)->age, (ptr + i)->grade);
	}
	free(ptr);
	return 1;
}