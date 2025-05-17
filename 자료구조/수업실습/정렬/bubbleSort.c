/* ���� ����
������ 2���� ���� ���Ͽ� ������� �Ǿ� ����
������ ���� ��ȯ

 ���� : �������� �̵��� ����

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

void bubble_sort(int list[], int n) {
    int tmp;
    for (int i = 0; i < n-1; i++) { // �� �� �� ������ ���� ū ���� ���������� ���ĵ�

        for (int j = 0; j < n-1; j++) { // �յ��� ���� ���ϱ� �ٲٱ�
            if (list[j] > list[j + 1]) {
                swap(list[j], list[j + 1], tmp);
            }
        }
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
    bubble_sort(list, n);                // �������� ȣ�� 
    printf("���� ��: ");
    print_list(list, n);
    return 0;

}