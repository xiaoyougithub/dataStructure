#include<iostream>
using namespace std;
//创建二叉树
struct BinaryTreeNode{
	char data;
	BinaryTreeNode *leftChild,*rightChild;
};
void createBinaryTree(BinaryTreeNode *&rootNode){
	//创建二叉树的思路：先定义一个数据变量，确定是否对参数初始化或置为NULL
	// 递归先序创建二叉树
	char data;
	cout<<"input a data:";
	cin>>data;
	if(data=='#')rootNode=NULL;
	else{
		rootNode=new BinaryTreeNode;
		rootNode->data=data;
		createBinaryTree(rootNode->leftChild);
		createBinaryTree(rootNode->rightChild); 
	} 
}
void show(BinaryTreeNode *&rootNode){
	if(rootNode){
		cout<<rootNode->data;
		show(rootNode->leftChild);
		show(rootNode->rightChild);
	}
}
int main(){
	BinaryTreeNode *rootNode=new BinaryTreeNode;
	createBinaryTree(rootNode);
	show(rootNode);
	return 1;
}
