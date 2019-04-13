#include<iostream>
#include<string>
#include<queue>
#include<fstream>
using namespace std;	
#define vertexType string									//顶点点所存放数据的类型 
#define maxVertexNumber 20 									//最大顶点数量  

//顶点结构 
typedef struct
{
	vertexType data;		//顶点数据 
	bool visited;			//是否被访问(遍历时使用) 
}Vertex;

typedef struct{
	Vertex vertex[maxVertexNumber];							//顶点 
	int adjacencyMatrix[maxVertexNumber][maxVertexNumber];	//用邻接矩阵存放相邻顶点信息 无权图0 1 带权图权值 
	int vertexNumber;										//顶点数量 
	int arcNumber;											//边数量 
}Graph;



int locateVertex(const Graph &G, vertexType v)		//范围顶点索引 无该顶点返回-1 
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

void createGraph(Graph &G)	//构造无向图 
{	
	cin>>G.vertexNumber>>G.arcNumber;	
	
	for(int i = 0; i < G.vertexNumber; i++)		//初始化
	{
		G.vertex[i].visited = false;
		for(int j = 0; j < G.vertexNumber; j++)
		{
			G.adjacencyMatrix[i][j] = 0; 
		}
	}
	
	for(int i = 0; i < G.vertexNumber; i++)		//每个顶点数据 
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
			G.adjacencyMatrix[v1Location][v2Location] = G.adjacencyMatrix[v2Location][v1Location] = 1;     //无向图的邻接矩阵沿主对角线对称 
		}
		else
		{
			cout<<"无该节点 请重新输入"<<endl;
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

void DFS(Graph &G, Vertex &v)		//深度优先搜索 回溯 
{
	visit(v);
	v.visited = true;
	int location = locateVertex(G, v.data);
	for(int i = 0; i < G.vertexNumber; i++)			//对该顶点每个邻接点使用DFS 
	{
		if(G.adjacencyMatrix[location][i] && G.vertex[i].visited == false)
		{
			DFS(G, G.vertex[i]);
		}
	}
}

void BFS(Graph &G, Vertex &v)		//广度有限搜索 使用队列 
{
	for(int i = 0; i < G.vertexNumber; i++)		//初始化visited
	{
		G.vertex[i].visited = false;

	}
	
	queue<Vertex> q;				//创建队列 并将起始顶点入队 
	Vertex v1 = v;
	q.push(v1);
	v.visited = true;
	
	while(!q.empty())				//queue很坑 引用会有问题 队列操作使用复制的v1 修改visit使用v 
	{

		v1 = q.front();
		visit(v1);
		int v1Location = locateVertex(G, v1.data);
		q.pop();
	
		for(int i = 0; i < G.vertexNumber; i++)		//将该顶点的邻接点入队 
		{
			if(G.adjacencyMatrix[v1Location][i] && G.vertex[i].visited == false)
			{
				v1 = G.vertex[i];	
				q.push(v1);
				G.vertex[i].visited = true;			//若pop时修改visited 则同一顶点会在之前多次被其邻接点入队 
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

