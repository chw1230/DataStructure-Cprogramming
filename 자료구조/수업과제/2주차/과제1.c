#include <stdio.h>
#include <stdlib.h>

// ���� 1) ���� �迭 ���� �Ҵ�

int main(void) {
	int N;
	printf("���� �迭 ũ�� �Է�: ");
	scanf("%d", &N);

	int* arr = (int*)malloc(sizeof(int) * (N+1));
	if (arr == NULL)
	{
		printf("�޸𸮰� �Ҵ���� �ʾҽ��ϴ�.\n");
		return 1;
	}
	for (int i = 0; i < N; i++)
	{
		arr[i] = i + 1;
	}

	printf("�迭 ����: ");
	for (int i = 0; i < N; i++)
	{
		printf("%d ",arr[i]);
	}
	free(arr);
	return 1;
}