#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
/* vertices = node = ���� / edge = ���� */

// ���� ��� �׷��� ǥ��
typedef struct GraphType {
	int nodeCnt; // ����� ������ ������ ����
	int adj_mtx[MAX_VERTICES][MAX_VERTICES];
}GraphType;

// �׷��� �ʱ�ȭ �Լ�
void init(GraphType* g) {
	g->nodeCnt = 0; // ����� ���� 0���� ����
	for (int i = 0; i < MAX_VERTICES; i++) { // ����� �ִ밳�� ��ŭ �ݺ�
		for (int j = 0; j < MAX_VERTICES; j++) {
			g->adj_mtx[i][j] = 0;
		}
	}
}

// ��� ���� �Լ�
void insert_node(GraphType* g, int v) {
	if (((g->nodeCnt) + 1) > MAX_VERTICES) {
		printf("����� ������ �ʰ� �Ͽ���");
		return;
	} 
	(g->nodeCnt)++; // ����� ���� �ø���
}

// ���� ���� �Լ�
void insert_edge(GraphType* g, int start, int end) {
	if (start >= g->nodeCnt || end >= g->nodeCnt) {
		printf("��� ��ȣ ����");
		return;
	}
	// ������ ���� �׷����� Ư¡ ���
	g->adj_mtx[start][end] = 1; 
	g->adj_mtx[end][start] = 1; 
}

// �׷��� ��� �Լ�
void print_adj_mtx(GraphType* g) {
	for (int i = 0; i < g->nodeCnt; i++) {
		for (int j = 0; j < g->nodeCnt; j++) {
			printf("%d ", g->adj_mtx[i][j]);
		}
		printf("\n");
	}
}

int main(void) {
	GraphType* g = (GraphType*)malloc(sizeof(GraphType));
	init(g); //�ʱ�ȭ

	for (int i = 0; i < 4; i++) { // ����� ���� ����
		insert_node(g, i);
	}

	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);
	printf("���� ��� ����� �׷��� ����");
	print_adj_mtx(g);

	free(g);
}