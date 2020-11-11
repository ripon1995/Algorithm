#include<bits/stdc++.h>
using namespace std;

#define inf 10000000
#define LIM 10000

struct Node
{
    int u,cost;
    Node(){};
    Node(int temp_u,int temp_cost)
    {
        u=temp_u;
        cost=temp_cost;
    }
};


bool operator <(Node A,Node B)
{
    return A.cost>B.cost;
}

void addEdge(vector<int>graph[],vector<int>cost[],int node1,int node2,int costs)
{
    graph[node1].push_back(node2);
    graph[node2].push_back(node1);
    cost[node1].push_back(costs);
    cost[node2].push_back(costs);
}


void prims(vector<int>graph[],vector<int>cost[],int totalNode,int source)
{

    priority_queue<Node>pq;
    int key[totalNode+1];
    for(int i=0;i<=totalNode;i++)key[i]=inf;
    int parent[totalNode+1];
    memset(parent,0,sizeof(parent));

    bool inMST[totalNode+1];
    memset(inMST,false,sizeof(inMST));
    int ans=0;
    key[source]=0;
    pq.push(Node(source,0));

    while(!pq.empty())
    {

        int now=pq.top().u;
        int xxx=pq.top().cost;
        pq.pop();
        if(inMST[now]==false)ans+=xxx;
        inMST[now]=true;



        for(int i=0;i<graph[now].size();i++)
        {
            int v=graph[now][i];
            int c=cost[now][i];
            if(inMST[v]==false && c<key[v])
            {
                key[v]=c;
                parent[v]=now;
                pq.push(Node(v,key[v]));
            }


        }
    }

    cout<<endl<<endl;

     for (int i = 1; i <= totalNode; i++)
        printf("%d - %d \n", parent[i], i);
    cout<<"TotalCost: "<<ans<<endl;
}


int main()
{
    vector<int>graph[LIM],cost[LIM];
    int nodes,edges;
    cin>>nodes>>edges;
    for(int i=0;i<edges;i++)
    {
        int node1,node2,costs;///cost or weight
        cin>>node1>>node2>>costs;
        addEdge(graph,cost,node1,node2,costs);
    }
    vector<int>prev(nodes+1,-1);

    int source;
    cin>>source;
    prims(graph,cost,nodes,source);
    return 0;
}

/*

6 9
1 2 6
1 5 5
2 5 7
2 3 1
5 3 8
5 4 14
3 6 2
6 4 3
3 4 9
1
*/

