#include<iostream>
using namespace std;
//����������
struct BinaryTreeNode{
	char data;
	BinaryTreeNode *leftChild,*rightChild;
};
void createBinaryTree(BinaryTreeNode *&rootNode){
	//������������˼·���ȶ���һ�����ݱ�����ȷ���Ƿ�Բ�����ʼ������ΪNULL
	// �ݹ����򴴽�������
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
