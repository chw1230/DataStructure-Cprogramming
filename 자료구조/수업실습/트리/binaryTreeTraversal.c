//#include <stdio.h>	
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
//// pdf 41��
//
//// ���� ��ȸ
//void inorder(TreeNode* root) {
//	if (root) {
//		inorder(root->left);
//		printf("[%d] ", root->data);
//		inorder(root->right);
//	}
//}
//
//// ���� ��ȸ
//void preorder(TreeNode* root) {
//	if (root){
//		printf("[%d] ",root->data);
//		preorder(root->left);
//		preorder(root->right);
//	}
//}
//
//// ���� ��ȸ 
//void postorder(TreeNode* root) {
//	if (root) {
//		postorder(root->left);
//		postorder(root->right);
//		printf("[%d] ", root->data);
//	}
//}
//
//int main(void) {
//	// �ڼ� ���� ��Ʈ ���� �湮
//	printf("���� ��ȸ="); // VLR V(root) -> L(left) -> R(right)
//	preorder(root);
//	printf("\n");
//
//	// ���� �ڼ�, ��Ʈ, ���� �ڼ� �� �湮
//	printf("���� ��ȸ="); // LVR L(left) -> V(root) -> R(right)
//	inorder(root);
//	printf("\n");
//	
//	// ��Ʈ ���� �ڼ� ���� �湮
//	printf("���� ��ȸ="); // LRVL(left) -> R(right) -> V(root)
//	postorder(root);
//	printf("\n");
//	return 0;
//}