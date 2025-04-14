#include <stdio.h>
#include <stdlib.h>

typedef struct student {
	char name[20];
	int kr;
	int en;
	int math;
	struct student* next;
} Student;

void AddStudent(Student **head, Student **tail,int cnt) {
	if (*head == NULL) {
		*head = (Student*)malloc(sizeof(Student));
		*tail = *head;
	}
	else {
		(*tail) -> next = (Student*)malloc(sizeof(Student));
		*tail = (*tail)->next;
	}

	printf("%d ��° �л� �̸� : ", cnt);
	scanf("%s", (*tail)->name);

	printf("���� ���� : ");
	scanf("%d", &((*tail)->kr));

	printf("���� ���� : ");
	scanf("%d", &((*tail)->en));

	printf("���� ���� : ");
	scanf("%d", &((*tail)->math));
	(*tail)->next = NULL;
}

void PrintStudent(Student** head, Student** tail, int cnt) {
	int* p;
	int i = 0;
	printf("\n-----------------------------------\n");
	printf(" �̸�  ���� ���� ���� ���� ���\n");
	printf("-----------------------------------");
	while (*head != NULL)
	{
		p = *head;
		int sum = (*head)->kr + (*head)->en + (*head)->math;
		printf("\n %s   %d   %d   %d   %d   %d", (*head)->name, (*head)->kr, (*head)->en, (*head)->math, sum,sum/3);
		*head = (*head)->next;
		free(p);
	}
	printf("\n");
}

int main(void) {
	Student* head = NULL;
	Student* tail = NULL;
	int cnt = 0;
	int n;
	while (1) {
		printf("\n[�޴�]");
		printf("\n1. ���� �Է�");
		printf("\n2. ���� Ȯ��");
		printf("\n3. ����");
		printf("\n��ȣ �Է��ϱ� : ");
		scanf("%d", &n);

		if (n == 1) {
			cnt++;
			AddStudent(&head, &tail,cnt);
		}
		else if (n == 2) {
			PrintStudent(&head, &tail, cnt);
		}
		else if (n == 3) {
			printf("���α׷��� �����");
			return 1;
		}
		else {
			printf("�߸��� �Է��Դϴ�.\n");
		}
	}
}