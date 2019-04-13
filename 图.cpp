#include<iostream>
#include<string>
#include<queue>
#include<fstream>
using namespace std;	
#define vertexType string									//�������������ݵ����� 
#define maxVertexNumber 20 									//��󶥵�����  

//����ṹ 
typedef struct
{
	vertexType data;		//�������� 
	bool visited;			//�Ƿ񱻷���(����ʱʹ��) 
}Vertex;

typedef struct{
	Vertex vertex[maxVertexNumber];							//���� 
	int adjacencyMatrix[maxVertexNumber][maxVertexNumber];	//���ڽӾ��������ڶ�����Ϣ ��Ȩͼ0 1 ��ȨͼȨֵ 
	int vertexNumber;										//�������� 
	int arcNumber;											//������ 
}Graph;



int locateVertex(const Graph &G, vertexType v)		//��Χ�������� �޸ö��㷵��-1 
{
	for(int i = 0; i < G.vertexNumber; i++)
	{
		if(G.vertex[i].data == v)
		{
			return i;
		}
	}
	return -1;
}

void createGraph(Graph &G)	//��������ͼ 
{	
	cin>>G.vertexNumber>>G.arcNumber;	
	
	for(int i = 0; i < G.vertexNumber; i++)		//��ʼ��
	{
		G.vertex[i].visited = false;
		for(int j = 0; j < G.vertexNumber; j++)
		{
			G.adjacencyMatrix[i][j] = 0; 
		}
	}
	
	for(int i = 0; i < G.vertexNumber; i++)		//ÿ���������� 
	{
		cin >> G.vertex[i].data;
	}
	
	for(int i = 0; i < G.arcNumber; i++)
	{
		vertexType v1,v2;
		cin>>v1>>v2;
		int v1Location = locateVertex(G, v1);
		int v2Location = locateVertex(G, v2);
		if(v1Location != -1 && v2Location !=-1)
		{
			G.adjacencyMatrix[v1Location][v2Location] = G.adjacencyMatrix[v2Location][v1Location] = 1;     //����ͼ���ڽӾ��������Խ��߶Գ� 
		}
		else
		{
			cout<<"�޸ýڵ� ����������"<<endl;
			i--; 
		}
	}
	 
	
} 

void printAdjacencyMatrix(const Graph &G)
{
	for(int i = 0; i < G.vertexNumber; i++)
	{
		cout<< " " << G.vertex[i].data << " ";
	}
	
	cout<<endl;
	
	for(int i = 0; i < G.vertexNumber; i++)
	{	
		cout<< G.vertex[i].data <<" ";
		
		for(int j = 0; j < G.vertexNumber; j++)
		{
			cout<< G.adjacencyMatrix[i][j] << " ";
		}
		cout<<endl;
	}
} 

void visit(Vertex &v)
{
	cout<<"->"<<v.data;
}

void DFS(Graph &G, Vertex &v)		//����������� ���� 
{
	visit(v);
	v.visited = true;
	int location = locateVertex(G, v.data);
	for(int i = 0; i < G.vertexNumber; i++)			//�Ըö���ÿ���ڽӵ�ʹ��DFS 
	{
		if(G.adjacencyMatrix[location][i] && G.vertex[i].visited == false)
		{
			DFS(G, G.vertex[i]);
		}
	}
}

void BFS(Graph &G, Vertex &v)		//����������� ʹ�ö��� 
{
	for(int i = 0; i < G.vertexNumber; i++)		//��ʼ��visited
	{
		G.vertex[i].visited = false;

	}
	
	queue<Vertex> q;				//�������� ������ʼ������� 
	Vertex v1 = v;
	q.push(v1);
	v.visited = true;
	
	while(!q.empty())				//queue�ܿ� ���û������� ���в���ʹ�ø��Ƶ�v1 �޸�visitʹ��v 
	{

		v1 = q.front();
		visit(v1);
		int v1Location = locateVertex(G, v1.data);
		q.pop();
	
		for(int i = 0; i < G.vertexNumber; i++)		//���ö�����ڽӵ���� 
		{
			if(G.adjacencyMatrix[v1Location][i] && G.vertex[i].visited == false)
			{
				v1 = G.vertex[i];	
				q.push(v1);
				G.vertex[i].visited = true;			//��popʱ�޸�visited ��ͬһ�������֮ǰ��α����ڽӵ���� 
			}
		}
	}
} 

int main()
{
	Graph G;
	createGraph(G);
	//printAdjacencyMatrix(G);
	
	cout<<"DFS";
	DFS(G, G.vertex[0]);
	cout<<endl;
	
	cout<<"BFS";
	BFS(G, G.vertex[0]);
	cout<<endl;
	return 0; 
}

