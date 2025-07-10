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


int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}




int main(){
    
    // printNumbers(10);
    // cout<<endl;

    int fact = factorial(5);
    cout<<"Factorial : "<<fact<<endl;


    return 0;
}