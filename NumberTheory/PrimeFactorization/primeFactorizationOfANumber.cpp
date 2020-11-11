#include<bits/stdc++.h>
using namespace std;
void primeFactorization(int n)
{
    vector<int>st;
    while(n%2==0)
    {
        st.push_back(2);
        n/=2;
    }
    int num=sqrt(n);
    for(int i=3;i<=num;i+=2)
    {
        while(n%i==0)
        {
            st.push_back(i);
            n/=i;

        }
    }
    if(n>2)st.push_back(n);
    for(int i=0;i<st.size();i++)cout<<st[i]<<" ";
    cout<<endl;
}

int main()
{
    primeFactorization(300);
    return 0;
}
