#include<iostream>
using namespace std;
struct LinkNode{
	int data;
	LinkNode *next;
};
struct Quene{
	LinkNode *front;
	LinkNode *rear;
};
void createQuene(Quene *&Q){
	Q->front=new LinkNode;
	Q->front->next=NULL;
	Q->rear=Q->front;
	int data;
	LinkNode *newLinkNode;
	while(1){
		cout<<"input a data:";
		cin>>data;
		if(data<0)break;
		newLinkNode=new LinkNode;
		newLinkNode->data=data;
		newLinkNode->next=NULL;
		Q->rear->next=newLinkNode;
		Q->rear=newLinkNode;
	}
}
void show(Quene *&Q){
	LinkNode *queneGuider=Q->front;
	for(;queneGuider;queneGuider=queneGuider->next){
		cout<<queneGuider->data<<endl;
	}
}
int main(){
	Quene *Q=new Quene;
	createQuene(Q);
	show(Q);
	return 1;
}
