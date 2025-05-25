#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

typedef struct GraphNode {
    int node;
    struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
    int nodeCnt;
    GraphNode* adj_list[MAX_VERTICES];
} GraphType;

// �湮 �迭
int visited[MAX_VERTICES];

// ���� �ڷᱸ��
typedef struct Stack {
    int data[MAX_VERTICES];
    int top;
} Stack;

// ���� ���� �Լ���
void init_stack(Stack* s) {
    s->top = -1;
}

int is_empty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int item) {
    s->data[++(s->top)] = item;
}

int pop(Stack* s) {
    return s->data[(s->top)--];
}

int peek(Stack* s) {
    return s->data[s->top];
}

// �׷��� �ʱ�ȭ
void init(GraphType* g) {
    g->nodeCnt = 0;
    for (int i = 0; i < MAX_VERTICES; i++) {
        g->adj_list[i] = NULL;
    }
}

// ��� ����
void insert_node(GraphType* g, int v) {
    if (g->nodeCnt + 1 > MAX_VERTICES) {
        printf("��� �� �ʰ�!\n");
        return;
    }
    g->nodeCnt++;
}

// ���� ����
void insert_edge(GraphType* g, int u, int v) {
    GraphNode* newNode = (GraphNode*)malloc(sizeof(GraphNode));
    newNode->node = v;
    newNode->link = g->adj_list[u];
    g->adj_list[u] = newNode;
}

// ���� ����Ʈ ���
void print_adj_list(GraphType* g) {
    for (int i = 0; i < g->nodeCnt; i++) {
        GraphNode* p = g->adj_list[i];
        printf("���� %d�� ���� ����Ʈ", i);
        while (p != NULL) {
            printf(" -> %d", p->node);
            p = p->link;
        }
        printf("\n");
    }
}

// ���� ��� DFS
void dfs_stack(GraphType* g, int v) {
    Stack s;
    init_stack(&s);
    push(&s, v); // ���� ������ ���ÿ� push

    while (!is_empty(&s)) { // ������ �� ������ �ݺ�
        int current = pop(&s); // ���ÿ��� ���� ������
        if (!visited[current]) {
            visited[current] = 1; // �湮 ó��
            printf("���� %d -> ", current); // ���� ���

            // ���� ������ ������ ��� ������ ���ÿ� push
            // (���� ����Ʈ�̹Ƿ�, �ڿ� ���Ե� ������ ���� Ž���� �� DFS ���� ����)
            GraphNode* w = g->adj_list[current];
            while (w != NULL) {
                if (!visited[w->node]) {
                    push(&s, w->node); // �湮���� ���� ������ push
                }
                w = w->link; // ���� ���� �������� �̵�
            }
        }
    }
}


int main(void) {
    GraphType* g = (GraphType*)malloc(sizeof(GraphType));
    init(g);

    for (int i = 0; i < 4; i++) {
        insert_node(g, i);
    }

    insert_edge(g, 0, 1);
    insert_edge(g, 1, 0);
    insert_edge(g, 0, 2);
    insert_edge(g, 2, 0);
    insert_edge(g, 0, 3);
    insert_edge(g, 3, 0);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 1);
    insert_edge(g, 2, 3);
    insert_edge(g, 3, 2);
    print_adj_list(g);

    printf("���� �켱 Ž��_����\n");
    dfs_stack(g, 0);
    free(g);
    return 0;
}