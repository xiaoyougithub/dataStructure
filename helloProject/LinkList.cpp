/***************第二章线性表复习总结*************************************/
/*2.5单链表的相关算法（单链表的初始化；单链表的前插法、后插法创建；遍历单链表；单链表的删除、插入） 
循环链表的相关算法（循环链表的初始化；单链表的前插法、后插法创建；遍历单链表；单链表的删除、插入）
双向链表的相关算法（双链表链表的初始化；单链表的前插法、后插法创建；遍历单链表；单链表的删除、插入）*/

/********************单链表*********************************************
#include<iostream>
using namespace std;
struct LinkNode                           //链表结点的定义 
{
	int data;
	LinkNode *next;
 } ;
 
 void CreateLink(LinkNode *&head)            //后插法创建链表算法 
 {
 	LinkNode *p,*q=head;
 	int data;
 	while(1)
 	{
 		cin>>data;
 		if(data<0)break;
 		p=new LinkNode;
 		p->data=data;
 		p->next=NULL;
 		q->next=p;
 		q=p;
	}
 }
 
 void Show(LinkNode *head)							//遍历链表算法 
 {
 	for(LinkNode *p=head->next;p;p=p->next)
 	cout<<p->data;
 }
 
 void DeleteLinkNode(LinkNode *&head,int key)				//删除指定结点的算法 
 {
 	LinkNode *q=head;
 	for(LinkNode *p=head->next;p->next->next;p=p->next,q=q->next)
 	if(p->data==key) 
 	{
 		q->next=p->next;	
	 }
  } 
  
  void InSertLinkNode(LinkNode *&head,int key)					//在指定结点后面插入一个结点的算法 
  {
  	LinkNode *q=head,*p=new LinkNode;
  	p->data=key;
  	while(q->next!=NULL)
  	{
  		q=q->next;
	  }
	  q->next=p;
	  p->next=NULL;	
  }
 
 int main()
 {
 	LinkNode *head=new LinkNode;
 	head->next=NULL;
 	CreateLink(head);
 	Show(head);
 	DeleteLinkNode(head,5);
 	Show(head);
 	InSertLinkNode(head,9);
 	Show(head);
 	return 0;
 	
 }
 ******************************************************************/
 
 /********************双向链表******************************************
 #include<iostream>
 using namespace std;
 struct LinkNode
 {
 	int data;
 	LinkNode *prior,*next;
  } ;
  void Create(LinkNode *&head,int n)                        //创建双向链表 
  {
  	LinkNode *p,*q=head;
  	int data;
  	for(int i=0;i<n;i++)
  	{
  		cin>>data;
  		p=new LinkNode;
  		p->data=data;
  		q->next=p;
  		p->prior=q;
  		q=p;
	  }
	  head->prior=p;
	  p->next=head;
  }
  
  void NextShow(LinkNode *head)										//双向链表后遍历 
  {
  	for(LinkNode *p=head->next;p!=head;p=p->next)
  	cout<<p->data<<endl;
	//cout<<head->prior->data;
  	
  }
  
  void InSert(LinkNode *&head,int key)								//双向链表插入操作 
  {
  	LinkNode *p=new LinkNode;
  	p->data=key;
  	p->next=head;
  	p->prior=head->prior;
  	head->prior->next=p;
  	head->prior=p;
  }
  
  void Delete(LinkNode *&head,int key)								//双向链表删除结点操作 
  {
  	LinkNode *p=head->next;
  	for(p;p!=head;p=p->next)
  	if(p->data==key)
  	{
  		p->next->prior=p->prior;
		p->prior->next=p->next;	
	}	
  }
  
  int main()
  {
  	LinkNode *head=new LinkNode;
  	Create(head,5);
  	NextShow(head);
  	InSert(head,8);
  	cout<<endl;
  	NextShow(head);
  	Delete(head,3);
  	NextShow(head);
  	return 0;
  }
  ************************************************************************/
  
  /*******************循环链表**********************************************
  #include<iostream>
 using namespace std;
 struct LinkNode
 {
 	int data;
 	LinkNode *next;
  } ;
  
  void Create(LinkNode *&head,int n)						//创建循环链表 
  {
  	LinkNode *p,*q=head;
  	int data;
  	for(int i=0;i<n;i++)
  	{
  		p=new LinkNode;
  		cin>>data;
  		p->data=data;
  		q->next=p;
  		p->next=NULL;
  		q=p;
	  }
	  p->next=head;
  }
  
  void Show(LinkNode *head)										//遍历循环链表 
  {
  	LinkNode *p=head->next;
  	for(p;p!=head;p=p->next)
  	cout<<p->data<<endl;	
  }
  
  int main()
  {
  	LinkNode *head=new LinkNode;
  	Create(head,5);
  	Show(head);
  	return 0;
  }
  *************************************************************************/ 
  
