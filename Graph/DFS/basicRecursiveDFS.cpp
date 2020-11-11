#include<bits/stdc++.h>
using namespace std;

#define LIM 100
#define pp push_back

vector<int>graph[LIM];
int visited[LIM];

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
        dfs(v);
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
    printGraph(node);

    cout<<"DFS TRAVERSAL: ";
    dfs(1);
    return 0;
}

/*
5 4
1 2
1 3
2 4
5 4

*/

