#include<iostream>
using namespace std;

void sumOfTwoSquare(int num)
{
    int num1,num2;
    for(int i=0;i<=num;i++)
    {
        for(int j=i;j<=num;j++)
        {
            if((i*i)+(j*j)==num)
            {
                num1=i;
                num2=j;
            }
        }
    }
    cout<<"NUM1: "<<num1<<"NUM2: "<<num2<<endl;
}


int main()
{

    return 0;
}
