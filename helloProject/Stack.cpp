#include<iostream>
using namespace std;
struct stackNode{
	int data;
	stackNode *bottom;
}; 
void createStack(stackNode *&stackTopNode){//����һ��ջ�����㴴��һ����ջ 
	stackNode *newNode;
	int data;
	while(1){
		cout<<"input a data:";
		cin>>data;
		if(data<0) break;
		newNode=new stackNode;
		newNode->data=data;
		newNode->bottom=stackTopNode;
		stackTopNode=newNode;
	}
}
void show(stackNode *&stackTopNode){//����ջ
	for(stackNode *p=stackTopNode;p;p=p->bottom){
		cout<<p->data<<endl;
	}
}
void popTopNode(stackNode *&stackTopNode){//�����������ջ���㣬ʵ���ϲ�δ�ı�ջ 
	stackNode *p=stackTopNode;
	cout<<"the top node's value is:"<<p->data<<endl;
	p=p->bottom;
}
void pushATopNode(){
	//easy!!!
} 
int main(){
	stackNode *stackTopNode=new stackNode;
	stackTopNode->bottom=NULL;
	createStack(stackTopNode);
	show(stackTopNode); 
	popTopNode(stackTopNode);
	show(stackTopNode);
}
