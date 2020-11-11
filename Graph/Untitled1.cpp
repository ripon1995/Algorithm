#include<bits/stdc++.h>
using namespace std;

#define LIM 100
#define pp push_back
#define row 5
#define column 5
vector<int>graph[LIM];
int visited[LIM];
char nodeColor[LIM];
char color[5]={'R','P','G','Y','W'};



bool checkAvailableColor(int source,char c)
{
    for(auto v: graph[source])
    {
        if(visited[v]==1 && nodeColor[v]==c)return false;
    }
    return true;
}

void colorNode(int source)
{
    for(int i=0;i<5;i++)
    {
        if(checkAvailableColor(source,color[i]))
        {
            nodeColor[source]=color[i];
            //break;
            return;
        }
    }
}

void addEdge(int node1,int node2)
{
    graph[node1].pp(node2);
    graph[node2].pp(node1);
}

void dfs(int source)
{
    if(visited[source])return;
    visited[source]=1;
    cout<<source<<" ";
    colorNode(source);
    for(auto v:graph[source])
    {
        if(visited[v]!=1)
        {
            dfs(v);
        }
    }
}

void printGraph(int node)
{
    for(int i=1;i<=node;i++)
    {
        cout<<i<<" : ";
        for(auto v:graph[i])cout<<v<<" ";
        cout<<endl;
    }
}

///grid from here

int grid[row][column];
int visitedGrid[row][column];
int directionX[8]={-1,+1,0,0,-1,+1,-1,+1};
int directionY[8]={0,0,-1,+1,-1,+1,+1,-1};
int counter=1;

bool isValid(int x,int y)
{
    if((x>=0 && x<row) && (y>=0 && y<column)&& visitedGrid[x][y]==0)return true;
    return false;
}

void dfsGrid(int x,int y)
{
    if(!isValid(x,y))return;

    visitedGrid[x][y]=1;
    grid[x][y]=counter++;

    cout<<"Row : "<<x<<"\tColumn: "<<y<<endl;


    for(int i=0;i<8;i++)
    {
        int nextX=x+directionX[i];
        int nextY=y+directionY[i];

        if(isValid(nextX,nextY))
        {
            dfsGrid(nextX,nextY);
        }
    }
}


void printDfsGrid()
{
    cout<<"Dfs grid : "<<endl;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++) cout<<grid[i][j]<<" ";
        cout<<endl;
    }
}


int main()
{
    /*
    int node,edge;
    cin>>node>>edge;
    for(int i=1;i<=edge;i++)
    {
        int u,v;
        cin>>u>>v;
        addEdge(u,v);
    }
    //printGraph(node);

    cout<<"DFS TRAVERSAL: ";

    dfs(1);

    cout<<"Distance from source: ";
    for(int i=1;i<=node;i++)cout<<dist[i]<<" ";
    cout<<endl;

    int color=1;
    for(int i=1;i<=node;i++)
    {
        if(visited[i]==0)
        {
            colorNumber[i]=color++;
            dfs(i);
        }
    }
    cout<<endl;
    cout<<"Component colors are: ";///same color indicates the same component
    for(int i=1;i<=node;i++)cout<<colorNumber[i]<<" ";
    int source=1;
    dfs(source);
    for(int i=1;i<=node;i++)
    {
        if(visited[i]==0)dfs(i);
    }
    cout<<endl;
    //nodeColor[source]=color[0];
    cout<<"Nodes colors: ";
    for(int i=1;i<=node;i++)cout<<nodeColor[i]<<" ";
    cout<<endl;*/

    dfsGrid(1,1);
    printDfsGrid();

    return 0;



}

/*
5 3
1 2
2 4
1 3


*/
