#include<bits/stdc++.h>
using namespace std;

#define LIM 100
#define pp push_back

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

int main()
{
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

    int source=1;
    dfs(source);
    for(int i=1;i<=node;i++)if(visited[i]==0)dfs(i);
    cout<<endl;
    cout<<"Nodes colors: ";
    for(int i=1;i<=node;i++)cout<<nodeColor[i]<<" ";
    cout<<endl;

    return 0;
}

/*
5 3
1 2
2 4
1 3


*/

