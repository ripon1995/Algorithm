#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#define MAX 100000



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

set<int> getPrimeFactorization(int n)
{
    set<int>ret;
    while(n!=1)
    {
        ret.insert(spf[n]);
        n=n/spf[n];
    }
    return ret;
}

int eulerTotientFormula(int n)
{
    primeFactorizationSeieve();
    set<int>v=getPrimeFactorization(n);
    set<int>::iterator it;
    int result=n;

    for(it=v.begin();it!=v.end();it++)
    {
        result=result-result/(*it);
    }
    return result;
}

int main()
{
    int num;
    cin>>num;
    cout<<eulerTotientFormula(num);
    return 0;

}
