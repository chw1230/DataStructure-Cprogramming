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

// ť ����
typedef struct {
    int queue[MAX_VERTICES];
    int front, rear;
} Queue;

int visited[MAX_VERTICES]; // �湮 ���� ���� �迭

// �׷��� �ʱ�ȭ
void init(GraphType* g) {
    g->nodeCnt = 0;
    for (int i = 0; i < MAX_VERTICES; i++) {
        g->adj_list[i] = NULL;
        visited[i] = 0; // �湮 �迭�� �ʱ�ȭ
    }
}

// ��� �߰�
void insert_node(GraphType* g, int v) {
    if ((g->nodeCnt + 1) > MAX_VERTICES) {
        printf("��� ���� �ʰ�\n");
        return;
    }
    g->nodeCnt++;
}

// ���� �߰�
void insert_edge(GraphType* g, int u, int v) {
    if (u >= g->nodeCnt || v >= g->nodeCnt) {
        printf("��� ��ȣ ����\n");
        return;
    }

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

// ť �Լ�
void init_queue(Queue* q) {
    q->front = q->rear = 0;
}

int is_empty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, int item) {
    if ((q->rear + 1) % MAX_VERTICES == q->front) {
        printf("Queue Overflow\n");
        exit(1);
    }
    q->rear = (q->rear + 1) % MAX_VERTICES;
    q->queue[q->rear] = item;
}

int dequeue(Queue* q) {
    if (is_empty(q)) {
        printf("Queue Underflow\n");
        exit(1);
    }
    q->front = (q->front + 1) % MAX_VERTICES;
    return q->queue[q->front];
}

// BFS ����
void bfs(GraphType* g, int start) {
    Queue q;
    init_queue(&q);

    visited[start] = 1;
    printf("�湮: %d\n", start);
    enqueue(&q, start);

    while (!is_empty(&q)) {
        int v = dequeue(&q);
        GraphNode* p = g->adj_list[v];

        while (p != NULL) {
            int w = p->node;
            if (!visited[w]) {
                visited[w] = 1;
                printf("�湮: %d\n", w);
                enqueue(&q, w);
            }
            p = p->link;
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

    printf("\n===== BFS Ž�� ��� =====\n");
    bfs(g, 0); // 0�� �������� BFS ����

    // �޸� ����
    for (int i = 0; i < g->nodeCnt; i++) {
        GraphNode* p = g->adj_list[i];
        while (p != NULL) {
            GraphNode* tmp = p;
            p = p->link;
            free(tmp);
        }
    }
    free(g);
    return 0;
}
