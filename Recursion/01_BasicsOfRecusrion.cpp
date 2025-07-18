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

int sumArray(int s,int n, int arr[])
{
    if(s > n)
    {
        return 0;
    }


    // cout<<arr[s]<<" ";
    int sum = arr[s]+ sumArray(s+1,n,arr);

    return sum;
}


string reverseString(string str){


}

int main(){
    
    // printNumbers(10);
    // cout<<endl;

    // int fact = factorial(5);
    // int sumn = printSum(10);
    // cout<<"Sum is : "<<sumn<<endl;

    // int arr[5] = {3,1,4,2,5};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // int ans = sumArray(0,4,arr);
    // cout<<"Sum of Array is : "<<ans<<endl;


    // int start = 0;
    // int end = 4;
    // reverseArray(arr,start,end);
    // for(auto i:arr)
    // {
    //     cout<<i<<" ";
    // }


    string str = "Heelo World !!";
    cout<<"OG String : "<<str<<endl;
    int len = str.length();
    string rev = reverseString(str);
    cout<<"Rev String : "<<rev<<endl;
    return 0;
}