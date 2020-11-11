#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000
//bool isComposite[MAX + 1];

int phi[MAX+1];
int isPermutation[MAX+1];

bool perMutationCheck(int a,int b)
{
    int pos=a;
    string digitsA,digitsB;
    while(a!=0 && b!=0)
    {
        digitsA.push_back((a%10)+'0');
        a/=10;
        digitsB.push_back(b%10+'0');
        b/=10;
    }
    sort(digitsA.begin(),digitsA.end());
    sort(digitsB.begin(),digitsB.end());
    //if(digitsA==digitsB)isPermutation[pos]=1;
    if(digitsA==digitsB)return true;
    return false;
}

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
                //perMutationCheck(j,phi[j]);
            }
        }
    }
}

/*
long long int eulerTotientFormula(long long int n)
{
    long long int res=n;
    for(int i=2;i*i<=n;i++)
    {
        if(isComposite[i]==0)
        {
            if(n%i==0)
            {
                while(n%i==0)n/=i;
                res-=res/i;
            }
        }
    }
    if(n>1)res-=res/n;
    return res;
}
*/
int main()
{
    phiSeive(MAX);
    int tc;
    scanf("%d", &tc);
    while(tc--)
    {
        int num;
        int m=-1;
        scanf("%d", &num);
        for(int i=2;i<=num;i++)
        {
            cout<<i<<" "<<phi[i]<<endl;
            if(perMutationCheck(i,phi[i]))
            {
                m=max(m,i);
            }
        }
        if(m==-1)printf("No solution.\n");
        else printf("%d\n", m);
        printf("\n\n\n");
    }

    return 0;
}
