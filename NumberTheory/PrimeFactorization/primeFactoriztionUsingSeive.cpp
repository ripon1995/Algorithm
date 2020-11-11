#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000
int spf[MAX+5];
void primeFactorizationSeieve()
{
    for(int i=2;i<MAX;i++)
    {
        if(i%2==0)spf[i]=2;
        else spf[i]=i;
    }
    for(int i=3;i*i<MAX;i++)
    {
        if(spf[i]==i)
        {
            for(int j=i*i;j<MAX;j+=i)
            {
                if(spf[j]==j)
                {
                    spf[j]=i;
                }
            }
        }
    }
}

vector<int> getPrimeFactorization(int n)
{
    vector<int>ret;
    while(n!=1)
    {
        ret.push_back(spf[n]);
        n=n/spf[n];
    }
    return ret;
}


int main()
{
    primeFactorizationSeieve();
    vector<int>v=getPrimeFactorization(12246);
    for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
    return 0;
}
