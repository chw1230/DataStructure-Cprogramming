/* ���� ����
 ������ �ȵ� ����Ʈ �� ���� �տ� �ִ� ���� ������ �� ����Ʈ���� �� �ڸ� ã�� ����

 ���� : �������� �̵��� ����

 �ּ��� ��� : O(n) -> �̹� ���ĵ� ���
 �־��� ��� : 0(n^2) -> �������� ���ĵǾ� �ִ� ���
*/
#include <stdio.h>
#define MAX_SIZE 10
#define swap(x,y,t) ( (t) = (x) , (x) = (y), (y) = (t))

void print_list(int list[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

void insertion_sort(int list[], int n) {
    int key,j;
    for (int i = 1; i < n; i++) { 
        key = list[i]; // �ű���� �ϴ� ���� key�� �����صα�
        for (j = i - 1; j > -1 && list[j] > key; j--) {
            list[j + 1] = list[j];  // ���� ���������� �̵�
        }

        list[j + 1] = key; // �ݺ������� �������� j-- ������ �ϳ� �۾� ���Ƿ� +1 ���ֱ�! 
        print_list(list, n);
    }
}

int main(void)
{
    int i;
    int n = MAX_SIZE;
    int list[MAX_SIZE];
    srand(32323);
    for (i = 0; i < n; i++)      // ���� ���� �� ��� 
        list[i] = rand() % 100; // ���� �߻� ���� 0~99
    printf("���� ��: ");
    print_list(list, n);
    insertion_sort(list, n);                // �������� ȣ�� 
    printf("���� ��: ");
    print_list(list, n);
    return 0;
}

