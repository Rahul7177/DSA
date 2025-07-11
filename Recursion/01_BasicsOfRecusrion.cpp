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


void reverseArray(int arr[],int s, int e)
{
    if(s>=e)
    {
        return;
    }

    swap(arr[s],arr[e]);

    return reverseArray(arr,s+1,e-1);
}


int main(){
    
    // printNumbers(10);
    // cout<<endl;

    // int fact = factorial(5);
    // int sumn = printSum(10);
    // cout<<"Sum is : "<<sumn<<endl;

    int arr[5] = {3,1,4,2,5};
    int start = 0;
    int end = 4;
    reverseArray(arr,start,end);
    for(auto i:arr)
    {
        cout<<i<<" ";
    }

    return 0;
}