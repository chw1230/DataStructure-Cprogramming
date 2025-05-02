///*Ʈ�� �� ����� ����, ���� ���ϱ�*/
//
//#include <stdio.h>	
//#include <stdlib.h>
//#define MAX(a,b) ((a) > (b) ? (a) : (b))
//
//typedef struct TreeNode {
//	int data;
//	struct TreeNode* left, * right;
//} TreeNode;
//
//TreeNode n0 = { 0,NULL,NULL };
//TreeNode n1 = { 1, NULL, &n0 };
//TreeNode n2 = { 4, &n1, NULL };
//TreeNode n3 = { 16, NULL, NULL };
//TreeNode n7 = { 3, NULL, NULL };
//TreeNode n8 = { 100, NULL, NULL };
//TreeNode n4 = { 25, &n8, &n7 };
//TreeNode n5 = { 20, &n3, &n4 };
//TreeNode n6 = { 15, &n2, &n5 };
//TreeNode* root = &n6;
//
//// ����� ���� ���ϴ� �Լ�
//int getNodeCount(TreeNode* root) {
//	int cnt = 0;
//	if (root != NULL) {
//		cnt = 1 + getNodeCount(root->left) + getNodeCount(root->right);
//		// root �� NULL�� �ƴ� ��쿡�� 1�� ���ϵ��� �ؼ�  ����� ������ ���
//	}
//	return cnt;
//}
//
//// leaf ����� ���� ���ϴ� �Լ�
//int getLeafNodeCount(TreeNode* root) {
//	int cnt = 0;
//	if (root != NULL) { 
//		if (root->left == NULL && root->right == NULL) {
//			return 1; // �ڽ� ��尡 ��� NULL�̸� leaf ��� �̱� ������ 1�� ��ȯ
//		}
//		else {
//			cnt = getLeafNodeCount(root->left) + getLeafNodeCount(root->right);
//		}
//	}
//	// root �� NULL �̸� 0�� ��ȯ
//	return cnt;	
//}
//
//// Non leaf ����� ���� ���ϴ� �Լ�
//int getNonLeafNodeCount(TreeNode* root) {
//	int cnt = 0;
//	if (root != NULL) {
//		if (root->left != NULL || root->right != NULL) {
//			// �ڽ� ��尡 1�� �̻� ������ ���� ��尡 �ƴϱ� ������ �̿� ���� ������ ����
//			cnt = 1 + getNonLeafNodeCount(root->left) + getNonLeafNodeCount(root->right); 
//		}
//		else {
//			return 0;
//		}
//	}
//	return cnt;
//}
//
//// Ʈ���� ���̸� ���ϴ� �Լ�
//int getHeight(TreeNode* root) {
//	int height = 0;
//	if (root != NULL) {
//		height = 1 + MAX(getHeight(root->left), getHeight(root->right));
//	}
//	return height;
//}
//
//int main(void) {
//	printf("����� ���� ���ϱ� = %d\n", getNodeCount(root)); 
//	printf("Leaf ����� ���� ���ϱ� = %d\n", getLeafNodeCount(root));
//	printf("Non Leaf ����� ���� ���ϱ� = %d\n", getNonLeafNodeCount(root));
//	printf("Tree�� ���� ���ϱ� = %d\n", getHeight(root));
//	return 0;
//}