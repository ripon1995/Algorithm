#include<bits/stdc++.h>
#define lli long long int

#define LIM 10000000
using namespace std;

bool myFunction(lli num)
{
    map<lli,lli>mp;
    for(lli i=0;i*i<=num;i++)
    {
        mp[i*i]=1;
        if(mp.find(num-(i*i))!=mp.end())return true;
    }
    return false;
}


bool fermatsNumber(lli value)
{
    if(value==1 || value==2)return true;
    int remainder=value%4;
    if(remainder==1)return true;
    return false;
}

void almostPrime(lli num)
{
    vector<lli>st;
    int counter=0;
    while(num%2==0)
    {
        num=num/2;
        if(counter==0)st.push_back(2);
        counter++;
    }
    for(lli i=3;i<=num;i+=2)
    {
        counter=0;
        while(num%i==0)
        {
            num=num/i;
            if(counter==0)st.push_back(i);
            counter++;
        }
    }
    if(st.size()==1)printf("-1\n");
    else printf("%lld\n", st[st.size()-1]);
}

bool isComposite[LIM+1];
void seiveBasic(lli value)
{
    isComposite[1]=1;
    for(int i=2;i*i<=value;i++)///first loop for prime
    {
        if(isComposite[i]==0)
        {
            for(int j=i*i;j<=value;j+=i)isComposite[j]=1;///second loop for marking composite
        }
    }
    int counter=0;
    for(int i=1;i<=value;i++)
    {
        if(isComposite[i]==0)counter++;//cout<<i<<"\t";
    }
    cout<<counter<<endl;
}

void ch(int value)
{
    vector<int>v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    for(auto i : v)
    {
        cout<<i<<endl;
    }
}

lli divisiorCounter(lli num)
{
    int mul=1;
    int counter=0;
    while(num%2==0)
    {
        num=num/2;
        counter++;
    }
    mul=mul*(counter+1);
    for(lli i=3;i<=num;i+=2)
    {
        counter=0;
        while(num%i==0)
        {
            num=num/i;
            counter++;
        }
        mul=mul*(counter+1);
    }
    return mul;

}


int gcdCalculate(lli a,lli b)
{
    int res;
    for(int i=1;i<=a;i++)
    {
        if(a%i==0 && b%i==0)res=i;
    }
    return res;
}

void commonDivisor(lli a,lli b)
{
    lli gcd=gcdCalculate(a,b);
    printf("%lld\n", divisiorCounter(gcd));
}


int main()
{
    int tc;
    scanf("%d", &tc);
    for(int i=1;i<=tc;i++)
    {
        lli num1,num2;
        scanf("%lld %lld", &num1,&num2);
        if(num1>num2)swap(num1,num2);
        commonDivisor(num1,num2);
    }

    return 0;


}
