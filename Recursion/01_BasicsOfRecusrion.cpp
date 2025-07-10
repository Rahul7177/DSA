#include<iostream>
using namespace std;


void printNumbers(int n)
{
    if(n==1)
    {
        cout<<n<<" ";
        return;
    }

    cout<<n<<" ";
    printNumbers(n-1);

    return;
}

int printSum(int n)
{
    if(n == 0)
    {
        return 0;
    }
   
    return n+printSum(n-1);
}

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}



int main(){
    
    // printNumbers(10);
    // cout<<endl;

    // int fact = factorial(5);
    int sumn = printSum(10);
    cout<<"Sum is : "<<sumn<<endl;


    return 0;
}