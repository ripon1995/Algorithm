#include<bits/stdc++.h>
using namespace std;

#define LIM 100
#define pp push_back
#define row 5
#define column 5

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
    printDfsGrid();
    dfsGrid(1,1);
    printDfsGrid();

    return 0;



}

