
#include<bits/stdc++.h>
using namespace std;

#define LIM 10000
void addEdge(vector<int>adj[],vector<int>cost[],int node1,int node2,int costs)
{
    adj[node1].push_back(node2);
    adj[node2].push_back(node1);
    cost[node1].push_back(costs);
    cost[node2].push_back(costs);
}



void dfs(vector<int>adj[],vector<int>cost[],int nodes,int visited[],int source)
{
   stack<int>S;
   S.push(source);
   while(!S.empty())
   {
       int now=S.top();
       S.pop();

       if(!visited[now])
       {
           cout<<now<<" ";
           visited[now]=true;
       }

       for(int i=0;i<adj[now].size();i++)
       {
           if(!visited[adj[now][i]])S.push(adj[now][i]);
       }
   }
}


void printGraph(vector<int>adj[],int nodes)
{
    for(int i=0;i<nodes;i++)
    {
        cout<<i<<" ";
        for(int j=0;j<adj[i].size();j++)cout<<adj[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{

    int tc;
    cin>>tc;
    for(int t=1;t<=tc;t++)
    {
        vector<int> adj[LIM];
        vector<int>cost[LIM];
        int nodes,edges;


        cin>>nodes>>edges;
        int node1,node2,costs;
        int visited[nodes];
        memset(visited,0,sizeof(visited));
        for(int i=1;i<=edges;i++)
        {
            cin>>node1>>node2>>costs;
            addEdge(adj,cost,node1,node2,costs);
        }
        int source=0;
        dfs(adj,cost,nodes,visited,source);
        //printGraph(adj,nodes);
    }
	return 0;
}

/*
2
5 4
0 4 50
0 3 29
0 2 20
2 1 10


*/

