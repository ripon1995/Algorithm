#include<bits/stdc++.h>
using namespace std;
#define LIM 100
#define PP push_back

vector<int>graph[LIM];
vector<int>visited[LIM];

void edgeConnection(int node1,int node2)
{
    graph[node1].PP(node2);
    graph[node2].PP(node1);
}

void graphPrintUsingAuto(int node)
{
    for(int i=1;i<=node;i++)
    {
        cout<<i<<" : ";
        for(auto v : graph[i]) cout<<v<<" ";
        cout<<endl;
    }
}

void graphPrint(int node)
{
    cout<<"Full graph: "<<endl;
    for(int i=1;i<=node;i++)
    {
        cout<<i<<" ";
        for(int j=0;j<graph[i].size();j++)cout<<graph[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl<<endl;
}

int main()
{

    int node,edge;
    scanf("%d %d", &node,&edge);
    int u,v;
    for(int i=1;i<=edge;i++)
    {
        scanf("%d %d", &u,&v);
        edgeConnection(u,v);
    }

    graphPrint(node);
    graphPrintUsingAuto(node);

    return 0;
}


