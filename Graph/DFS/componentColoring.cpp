#include<bits/stdc++.h>
using namespace std;

#define LIM 100
#define pp push_back

vector<int>graph[LIM];
int visited[LIM];
int dist[LIM];
int colorNumber[LIM];

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
    for(auto v:graph[source])
    {
        if(visited[v]!=1)
        {
            dist[v]=dist[source]+1;
            colorNumber[v]=colorNumber[source];
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

    return 0;
}

/*
12 13
1 9
1 8
9 8

7 3
7 6
7 11
7 10
10 11
6 5
5 3
4 3
2 3
8 7


*/

