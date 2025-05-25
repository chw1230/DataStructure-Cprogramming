//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAX_VERTICES 50
//int visited[MAX_VERTICES]; // �湮 ó���� ���� �迭
//
//typedef struct GraphNode {
//	int node; // ��尡 ���� ���� 
//	struct GraphNode* link; // �ٸ� ��带 ����ų ������ ����
//}GraphNode;
//
//typedef struct GraphType {
//	int nodeCnt; // ����� ������ ������ ����
//	GraphNode* adj_list[MAX_VERTICES];
//}GraphType;
//
//// �׷��� �ʱ�ȭ �Լ�
//void init(GraphType* g) {
//	g->nodeCnt = 0; // ����� ���� 0���� ����
//	for (int i = 0; i < MAX_VERTICES; i++) { // ����� �ִ밳�� ��ŭ �ݺ�
//		g->adj_list[i] = NULL; // ��� null�� ����Ű���� �ʱ�ȭ
//	}
//}
//
//// ��� ���� �Լ�
//void insert_node(GraphType* g, int v) {
//	if (((g->nodeCnt) + 1) > MAX_VERTICES) {
//		printf("����� ������ �ʰ� �Ͽ���");
//		return;
//	}
//	(g->nodeCnt)++; // ����� ���� �ø���
//}
//
//// ���� ���� �Լ�
//void insert_edge(GraphType* g, int u, int v) { // u->v , u�� v�� �����ϴ� ���� 
//	if (u >= g->nodeCnt || v >= g->nodeCnt) {
//		printf("��� ��ȣ ����");
//		return;
//	}
//
//	GraphNode* newNode = (GraphNode*)malloc(sizeof(GraphNode));
//	newNode->node = v;
//	newNode->link = g->adj_list[u];
//	g->adj_list[u] = newNode; // ���� �߰��� ��尡 ���� ������ ��ġ�� ���� (���Ƿ� ���� �� ��)
//}
//
//// ��� �Լ�
//void print_adj_list(GraphType* g) {
//	for (int i = 0; i < g->nodeCnt; i++) {
//		GraphNode* p = g->adj_list[i];
//
//		printf("���� %d�� ���� ����Ʈ", i);
//
//		while (p != NULL) {
//			printf("-> %d", p->node);
//			p = p->link;
//		}
//		printf("\n");
//	}
//}
//
//// ���� �켱 Ž��
//void dfs_list(GraphType* g, int v) {
//	GraphNode* w;
//	visited[v] = 1; // �湮 ó��
//	printf("���� %d -> ", v); // ���
//
//	for (w = g->adj_list[v]; w; w = w->link) {
//		if (!visited[w->node]) {
//			dfs_list(g, w->node);
//		}
//	}
//}
//
//int main(void) {
//	GraphType* g = (GraphType*)malloc(sizeof(GraphType));
//	init(g);
//
//	for (int i = 0; i < 4; i++) {
//		insert_node(g, i);
//	}
//
//	insert_edge(g, 0, 1);
//	insert_edge(g, 1, 0);
//	insert_edge(g, 0, 2);
//	insert_edge(g, 2, 0);
//	insert_edge(g, 0, 3);
//	insert_edge(g, 3, 0);
//	insert_edge(g, 1, 2);
//	insert_edge(g, 2, 1);
//	insert_edge(g, 2, 3);
//	insert_edge(g, 3, 2);
//	print_adj_list(g);
//
//	printf("���� �켱 Ž��_recursion\n");
//	dfs_list(g, 0);
//	free(g);
//	return 0;
//}
///*
//���� ���� 0�� ����� ��尡 1, 2, 3�̶�顦
//
//dfs_list(g, 0) ȣ��
//visited[0] = 1 �� ���
//������ 3 �湮 
//
//�� dfs_list(g, 3)
//visited[3] = 1 �� ���
//������ 2 �湮 
//
//�� dfs_list(g, 2)
//visited[2] = 1 �� ���
//������ 1 �湮 
//
//�� dfs_list(g, 1)
//visited[1] = 1 �� ���
//�� �̻� ���� 
//
//�� ��� ����
//*/