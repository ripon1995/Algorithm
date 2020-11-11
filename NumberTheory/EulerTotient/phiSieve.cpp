#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#define MAX 1000000

int phi[MAX+5];

void phiSeive(int n)
{
    for(int i=0;i<=n;i++)phi[i]=i;

    for(int i=2;i<=n;i++)
    {
        if(phi[i]==i)
        {
            for(int j=i;j<=n;j+=i)
            {
                phi[j]=phi[j]-(phi[j]/i);
            }
        }
    }
}

int main()
{
    phiSeive(30);
    for(int i=0;i<=30;i++)cout<<phi[i]<<" ";
    return 0;

}


