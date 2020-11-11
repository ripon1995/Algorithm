#include<bits/stdc++.h>
#include<cstdio>

#define lli long long int
using namespace std;
///this is O(n^2) solution
///brute force
void sumOfTwoSquare(long long int num)
{
    long long int num1=1,num2=-1;
    for(long long int i=0;i*i<=num;i++)
    {
        for(long long int j=i;j*j<=num;j++)
        {
            if((i*i)+(j*j)==num)
            {
                num1=i;
                num2=j;
            }
        }
    }
    if(num1!=-1 && num2!=-1)cout<<"NUM1: "<<num1<<"\tNUM2: "<<num2<<endl;
    else cout<<"Impossible"<<endl;
}


///this is O(sqrt(n)) solution

void sumOfTwoSquare2(long long int num)
{
    lli num1=-1,num2=-1;
    map<lli , lli> mp;
    for(lli i=0;i*i<=num;i++)
    {
        mp[i*i]=1;
        if(mp.find(num-i*i)!=mp.end())
        {
            num1=i;
            num2=sqrt(num-(i*i));
        }
    }
    if(num1!=-1 && num2!=-1)cout<<"NUM1: "<<num1<<"\tNUM2: "<<num2<<endl;
    else cout<<"Impossible"<<endl;

}

int main()
{
    long long int value;
    scanf("%lld", &value);
    //sumOfTwoSquare(value);
    sumOfTwoSquare2(value);
    main();
    return 0;
}

