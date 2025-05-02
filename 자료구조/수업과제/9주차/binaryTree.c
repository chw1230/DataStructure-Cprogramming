#include <stdio.h>	
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

TreeNode n0 = { 0,NULL,NULL };
TreeNode n1 = { 1, NULL, &n0 };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n7 = { 3, NULL, NULL };
TreeNode n8 = { 100, NULL, NULL };
TreeNode n4 = { 25, &n8, &n7 };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6;

// Non leaf ����� ���� ���ϴ� �Լ�(��ܸ� ��� ���� count)
int getNonLeafNodeCount(TreeNode* root) {
	int cnt = 0;
	if (root != NULL) {
		if (root->left != NULL || root->right != NULL) {
			// �ڽ� ��尡 1�� �̻� ������ ���� ��尡 �ƴϱ� ������ �̿� ���� ������ ����
			cnt = 1 + getNonLeafNodeCount(root->left) + getNonLeafNodeCount(root->right);
		}
		else {
			return 0;
		}
	}
	return cnt;
}

//  �� �˻��ϱ�
/* ���� Ʈ������ Ư�� ���� ���� ��带 ��������� ã�� ��ȯ�ϴ� �Լ�
��带 ã���� �ش� ����� �����͸� ��ȯ, ������ NULL�� ��ȯ */
TreeNode* search(TreeNode* node, int value) {
	if (node == NULL) {
		return NULL;
	}

	if (node->data == value) {
		return node; // ���� ��忡�� �� ã��
	}

	// �������� ã��
	TreeNode* p = search(node->left, value);
	if (p != NULL) { 
		// p�� NULL �̶�� ������ ã�� ���� ������ ��, 
		// NULL �ƴϸ� (node->left)����� data�� value�� ��ġ�ϴ� ��!
		return p;
	}

	// �������� ã��
	return search(node->right, value);

	// ��带 ��ȯ�ϴ� ���� ������ data�� value�� ���� ��� �ۿ� ����
	// ������ ��쿡�� NULL�� ��ȯ
}

int main(void) {
	printf("Non Leaf ����� ���� ���ϱ� = %d\n", getNonLeafNodeCount(root));

	int n;
	TreeNode* p;
	printf("ã�� ���� �Է��Ͻÿ�: ");
	scanf("%d", &n);
	if ( (p = search(root, n)) != NULL) {
		printf("�Է��� �� %d(��)�� Ʈ���� �����մϴ�.\n", p->data);
	}
	else {
		printf("�Է��� ���� Ʈ���� �������� �ʽ��ϴ�.");
	}
	return 0;
}