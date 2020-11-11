#include<iostream>
#include<algorithm>
using namespace std;

int gcd(int n,int m)
{
    return __gcd(n,m);
}

int eulerPhi(int number)
{
    int counter=0;
    for(int i=1;i<=number;i++)
    {
        if(gcd(i,number)==1)counter++;
    }
    return counter;
}

int main()
{
    int num;
    cin>>num;
    cout<<eulerPhi(num)<<endl;
    main();
    return 0;

}


