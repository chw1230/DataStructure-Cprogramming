#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
	long id;
	char name[20];
	struct TreeNode* left, * right;
}TreeNode;

// ���ο� ����Ҵ�
TreeNode* new_node(long id, char* name) {
	TreeNode* tmp = (TreeNode*)malloc(sizeof(TreeNode));
	tmp->id = id;
	strcpy(tmp->name, name); // name���� �Է¹��� ����� �ּҸ� ���� ����
	tmp->left = tmp->right = NULL;

	return tmp;
}


// �л� ���� �߰�
TreeNode* insert_node(TreeNode* node, long id, char* name) {
	if (node == NULL) {
		return new_node(id, name);
	}

	if (id < node->id) {
		node->left = insert_node(node->left, id, name);
	}
	else if (id > node->id) {
		node->right = insert_node(node->right, id, name);
	}
	else {
		printf("�̹� �����ϴ� �й�, �߰� �Ұ���\n");
	}
	return node;
}

// ���� ��ȸ
void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);
		printf("�й�: %ld, �̸�: %s\n", root->id, root->name);
		inorder(root->right);
	}
}

// Ư�� id�� ���� ��� ã��
TreeNode* search_node(TreeNode* node, long id) {
	while (node) {
		if (id < node->id) {
			node = node->left;
		}
		else if (id > node->id) {
			node = node->right;
		}
		else {
			return node;
		}
	}
	return NULL;
}

// Ʈ������ ���� ���� id�� ���� ��带 ã�� �Լ�
TreeNode* min_value_node(TreeNode* node) {
	TreeNode* current = node;
	while (current->left != NULL) {
		current = current->left;
	}
	return current;
}

// �л� ���� ����
TreeNode* delete_node(TreeNode* root, long id) {
	if (root == NULL) {
		printf("������ �й��� �������� ����\n");
		return NULL;
	}

	if (id < root->id) {
		root->left = delete_node(root->left, id);
	}
	else if (id > root->id) {
		root->right = delete_node(root->right, id);
	}
	else {
		// 1. �ڽ��� ���� ��� (�ܸ� ���)
		if (root->left == NULL && root->right == NULL) {
			free(root);
			return NULL;
		}
		// 2. ���� �ڽ��� ���� ��� �� ������ �ڽ� ���� ��ü
		else if (root->left == NULL) {
			TreeNode* tmp = root->right;
			free(root);
			return tmp;
		}
		// 3. ������ �ڽ��� ���� ��� �� ���� �ڽ� ���� ��ü
		else if (root->right == NULL) {
			TreeNode* tmp = root->left;
			free(root);
			return tmp;
		}

		// 4. ���� �ڽ��� ��� �ִ� ���
		// ������ ����Ʈ������ ���� ���� ���� ������ ��带 ã�� ���� ��带 ��ü
		TreeNode* tmp = min_value_node(root->right);

		// ���� ����� �����͸� �İ� ����� ������ ����� (���� �ƴ�!)
		root->id = tmp->id;
		strcpy(root->name, tmp->name); // name��! �����
		root->right = delete_node(root->right, tmp->id); // �İ� ��带 ������ ����

	}
	return root;
}

int main() {
	TreeNode* root = NULL;

	while (1) {
		printf("\n=== �л� ���� �ý��� ===\n");
		printf("(1) �л� ���� �߰�\n");
		printf("(2) �л� ���� Ž��\n");
		printf("(3) �л� ���� ����\n");
		printf("(4) �л� ���� ��ü ���\n");
		printf("(0) ����\n");
		printf("����: ");
		int n;
		scanf("%d", &n);

		if (n == 0) {
			printf("���α׷��� ����Ǿ����ϴ�.\n");
			return 0;

		}
		else if (n == 1) {
			char name[20];
			long id;

			printf("�й� �Է�: ");
			scanf("%ld", &id);
			printf("�̸� �Է�: ");
			scanf("%s", name);

			root = insert_node(root, id, name);

		}
		else if (n == 2) {
			printf("=== �л� ���� Ž�� ===\n");
			long id;
			printf("ã�� �л��� �й� �Է�: ");
			scanf("%ld", &id);
			TreeNode* result = search_node(root, id);

			if (result) {
				printf("�˻� ��� | �й�: %ld, �̸�: %s\n", id, result->name);
			}
			else {
				printf("�ش� �й� �������� ����\n");
			}
		}
		else if (n == 3) {
			printf("=== �л� ���� ���� ===\n");
			long id;
			printf("������ �л��� �й� �Է�: ");
			scanf("%ld", &id);
			root = delete_node(root, id);
			printf("�۾� �Ϸ�\n");

		}
		else if (n == 4) {
			printf("=== �л� ���� ��ü ��� (��������) ===\n");
			inorder(root);
		}
		else {
			printf("�߸��� �Է��Դϴ�.\n");
		}
	}
}
