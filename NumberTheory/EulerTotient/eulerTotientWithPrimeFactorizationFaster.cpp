#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000
bool isComposite[MAX + 1];

void sieve(int N)
{
    isComposite[1] = 1;
    int sqn = sqrt(N) + 1;
    for(int i = 2; i <= sqn; i++)
    {
        if(isComposite[i] == 0)
        {
            for(int j = i * i; j <= N; j += i)
            {
                isComposite[j] = 1;
            }
        }
    }
    /*
    int prm_cnt = 0;
    for(int i = 1; i <= N; i++)
    {
        if(isComposite[i] == 0) prm_cnt++;
    }
    cout << prm_cnt << '\n';*/
}


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

int main()
{
    sieve(10000000);

    long long int num;
    while(scanf("%lld", &num))
    {
        if(num==0)break;
        printf("%lld\n", eulerTotientFormula(num));
    }

    return 0;
}

