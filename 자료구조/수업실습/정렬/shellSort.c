#include <stdio.h>

// gap��ŭ ������ �κ� ����Ʈ�鿡 ���� ���� ������ ����
void inc_insertion_sort(int list[], int first, int last, int gap) {
	int i, j, key;
	for (i = first + gap; i <= last; i += gap) {
		key = list[i];
		for (j = i - gap; j >= first && key < list[j]; j = j - gap) {
			list[j + gap] = list[j]; // ū ���� �������� ����
		}
		list[j + gap] = key; // key�� ������ ���� ���� �����ϱ�
	}
}

void shell_sort(int list[], int n) {
	int i, gap;
	for (gap = n / 2; gap > 0; gap /= 2) { // gap ���� ���̱�
		if ((gap % 2) == 0) 
			gap++;  // gap�� ¦���� ��� Ȧ���� ������ִ� �ڵ�

		for (i = 0; i < gap; i++) { // ���� �ε����� Ű������ �Լ� ȣ���ϱ� 
			inc_insertion_sort(list, i, n - 1, gap);
		}
			
	}
	for (int k = 0; k < n; k++) {
		printf("%d ", list[k]);
	}
	printf("\n");
}

int main() {
	int list[] = { 45, 23, 53, 12, 90, 17, 65, 30 };
	int n = sizeof(list) / sizeof(list[0]);

	printf("���� �� �迭: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");

	printf("���� �� �迭: ");
	shell_sort(list, n);

	return 0;
}
