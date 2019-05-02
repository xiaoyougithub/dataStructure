#include<iostream>
#define MVNum 5
using namespace std;
//something wrong with the program,maybe is unproper use of pointer
struct AMGraph
{
	int arcnum,vexnum;
	char vexs[MVNum];
	int arcs[MVNum][MVNum];
};
int LocateVex(AMGraph *&G,char v)
{
	int i,j;
	for(i=0;i<MVNum,G->vexs[i]!=v;i++);
	return i;
}

void CreateUDAMGraph(AMGraph *&G)
{
	cout<<"arcnum:";
	cin>>G->arcnum;
	cout<<"input vexs:"<<endl;
	for(int i=0;i<MVNum;i++)
		cin>>G->vexs[i];
	cout<<endl;
	char v1,v2;
	int i,j;
	cout<<"create adjaency matrix:"<<endl;
	for(int m=0;m<MVNum;m++){
		for(int n=0;n<MVNum;n++){
			G->arcs[m][n]=888;
		}
	}
	for(int i=0;i<G->arcnum;i++)
	{
		cout<<"input v1&v2:";
		cin>>v1>>v2;
		i=LocateVex(G,v1);
		j=LocateVex(G,v2);
		G->arcs[i][j]=G->arcs[j][i]=1;
	}
}

void ShowUDAMGraph(AMGraph *&G)
{
	for(int i=0;i<MVNum;i++)
	{
		for(int j=0;j<MVNum;j++)
		cout<<G->arcs[i][j]<<" ";
		cout<<endl;
	 } 	
}
int main(){
	AMGraph *graph=new AMGraph;
	CreateUDAMGraph(graph);
	ShowUDAMGraph(graph);
} 
