/***************�ڶ������Ա�ϰ�ܽ�*************************************/
/*2.5�����������㷨��������ĳ�ʼ�����������ǰ�巨����巨�����������������������ɾ�������룩 
ѭ�����������㷨��ѭ������ĳ�ʼ�����������ǰ�巨����巨�����������������������ɾ�������룩
˫�����������㷨��˫��������ĳ�ʼ�����������ǰ�巨����巨�����������������������ɾ�������룩*/

/********************������*********************************************
#include<iostream>
using namespace std;
struct LinkNode                           //������Ķ��� 
{
	int data;
	LinkNode *next;
 } ;
 
 void CreateLink(LinkNode *&head)            //��巨���������㷨 
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
 
 void Show(LinkNode *head)							//���������㷨 
 {
 	for(LinkNode *p=head->next;p;p=p->next)
 	cout<<p->data;
 }
 
 void DeleteLinkNode(LinkNode *&head,int key)				//ɾ��ָ�������㷨 
 {
 	LinkNode *q=head;
 	for(LinkNode *p=head->next;p->next->next;p=p->next,q=q->next)
 	if(p->data==key) 
 	{
 		q->next=p->next;	
	 }
  } 
  
  void InSertLinkNode(LinkNode *&head,int key)					//��ָ�����������һ�������㷨 
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
 
 /********************˫������******************************************
 #include<iostream>
 using namespace std;
 struct LinkNode
 {
 	int data;
 	LinkNode *prior,*next;
  } ;
  void Create(LinkNode *&head,int n)                        //����˫������ 
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
  
  void NextShow(LinkNode *head)										//˫���������� 
  {
  	for(LinkNode *p=head->next;p!=head;p=p->next)
  	cout<<p->data<<endl;
	//cout<<head->prior->data;
  	
  }
  
  void InSert(LinkNode *&head,int key)								//˫������������ 
  {
  	LinkNode *p=new LinkNode;
  	p->data=key;
  	p->next=head;
  	p->prior=head->prior;
  	head->prior->next=p;
  	head->prior=p;
  }
  
  void Delete(LinkNode *&head,int key)								//˫������ɾ�������� 
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
  
  /*******************ѭ������**********************************************
  #include<iostream>
 using namespace std;
 struct LinkNode
 {
 	int data;
 	LinkNode *next;
  } ;
  
  void Create(LinkNode *&head,int n)						//����ѭ������ 
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
  
  void Show(LinkNode *head)										//����ѭ������ 
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
  
