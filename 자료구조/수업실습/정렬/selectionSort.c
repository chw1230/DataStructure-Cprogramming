/* ���� ����
 �� Ƚ�� -> O(n^2) => ���ܺ��⵵
 �̵� ȸ�� -> �ܺ� ������ ���� Ƚ���� ���� => 3(n-1)
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

void selection_sort(int list[], int n) {
    int tmp;
    for (int i = 0; i < n; i++) {
        int least = i; // i�� ���� ���� ���� �ε����� �ǹ��ϴ� ������ ����
        for (int j = i+1; j < n; j++) { // �ּҰ� ã��/ i���� �ε��� ����
            if (list[least] > list[j]) {
                least = j; // ���� ���� ���� �ε����� �ǹ��ϴ� ���� �ֽ�ȭ
            }
        }
        swap(list[least], list[i], tmp);
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
    selection_sort(list, n);                // �������� ȣ�� 
    printf("���� ��: ");
    print_list(list, n);
    return 0;
}

