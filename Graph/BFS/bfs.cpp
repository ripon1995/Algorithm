#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int>adj[],int node1,int node2)
{
    adj[node1].push_back(node2);
    adj[node2].push_back(node1);
}

void BFS(vector<int>adj[],int node,vector<bool>&visited,vector<int>&prev)
{
    queue<int>q;
    q.push(node);
    visited[node]=true;
    while(!q.empty())
    {
        int f=q.front();
        q.pop();
        cout<<f<<" ";
        for(int i=0;i<adj[f].size();i++)
        {
            if(visited[adj[f][i]]==false)
            {
                q.push(adj[f][i]);
                visited[adj[f][i]]=true;
                prev[adj[f][i]]=f;
            }
        }
    }

}

void shortestPath(vector<int>adj[],vector<bool>visited,int source,int dest,vector<int>prev)
{
    if(visited[dest]==false)cout<<"No path"<<endl;
    else
    {
        vector<int>path;
        for(int i=dest;i!=-1;i=prev[i])path.push_back(i);

        reverse(path.begin(),path.end());
        cout<<"Path:  ";
        for(int i=0;i<path.size();i++) cout<<path[i]<<" ";
    }
    cout<<endl;
}




void bfsUtil(vector<int>adj[],int v)
{
    vector<bool>visited(v,false);
    vector<int>prev(v,-1);
    BFS(adj,6,visited,prev);
    /*for(int i=0;i<v;i++)
    {
        if(visited[i]==false)BFS(adj,i,visited);
    }*/

    shortestPath(adj,visited,6,3,prev);


}



int main()
{
    int v;
    v=7;
    vector<int>adj[v];
	addEdge(adj,6,4);
	addEdge(adj,4,5);
	addEdge(adj,4,3);
	addEdge(adj,5,1);
	addEdge(adj,5,2);
	addEdge(adj,1,2);
	addEdge(adj,2,3);


	bfsUtil(adj,v);
    return 0;
}
