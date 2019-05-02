#include<iostream>
using namespace std;
//单链表的创建、查询、插入、更改和删除 
//创建一个结构体 
struct node{
	int data;
	node *next;
}; 
void creatLinkList(node *&head){//先取head的地址，再把地址转换为指向结构体地址的指针 
	node *p,*q;//p是用来接收head的指向node结构体地址的指针,也就是指向链表的。而q是用来接收循环生成新结点的结构体变量 
	p=head;
	int data;//data是创建新节点使用的变量
	while(1){
		cout<<"input a data:";
		cin>>data;
		if(data<0)break;
		q=new node;
		q->next=NULL;
		q->data=data;
		p->next=q;
		p=q;
	} 
}
void show(node *&head){//正向遍历链表 
	for(node *p=head->next;p;p=p->next){
		cout<<p->data<<endl;
	}
}
void deleteNode(node *&head,int data){//删除某个结点 
	node *q=head;
	for(node *p=head->next;p;p=p->next){
		if(p->data==data){
			q->next=p->next;
		}
		q=q->next;
	}
}
void insert(node *&head,int data){//在头节点的后面插入一个结点 
	node *insertedNode=new node;
	insertedNode->data=data;
	insertedNode->next=head->next;
	head->next=insertedNode;
} 
int main(){
	node *head=new node;
	creatLinkList(head);//创建一个链表 
	show(head); 
//	deleteNode(head,3);//测试删除一个结点 
//	show(head);
	insert(head,9);//测试插入一个结点 
	show(head);
}
