#include<iostream>
using namespace std;
//������Ĵ�������ѯ�����롢���ĺ�ɾ�� 
//����һ���ṹ�� 
struct node{
	int data;
	node *next;
}; 
void creatLinkList(node *&head){//��ȡhead�ĵ�ַ���ٰѵ�ַת��Ϊָ��ṹ���ַ��ָ�� 
	node *p,*q;//p����������head��ָ��node�ṹ���ַ��ָ��,Ҳ����ָ������ġ���q����������ѭ�������½��Ľṹ����� 
	p=head;
	int data;//data�Ǵ����½ڵ�ʹ�õı���
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
void show(node *&head){//����������� 
	for(node *p=head->next;p;p=p->next){
		cout<<p->data<<endl;
	}
}
void deleteNode(node *&head,int data){//ɾ��ĳ����� 
	node *q=head;
	for(node *p=head->next;p;p=p->next){
		if(p->data==data){
			q->next=p->next;
		}
		q=q->next;
	}
}
void insert(node *&head,int data){//��ͷ�ڵ�ĺ������һ����� 
	node *insertedNode=new node;
	insertedNode->data=data;
	insertedNode->next=head->next;
	head->next=insertedNode;
} 
int main(){
	node *head=new node;
	creatLinkList(head);//����һ������ 
	show(head); 
//	deleteNode(head,3);//����ɾ��һ����� 
//	show(head);
	insert(head,9);//���Բ���һ����� 
	show(head);
}
