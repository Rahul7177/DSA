#include<bits/stdc++.h>
using namespace std;


void decimalToBinary(int n)
{
    stack<int> st;

    while(n>1)
    {
        st.push(n%2);
        n = n/2;
    }

    if(n==1)
    {
        st.push(1);
    }


    while(!st.empty())
    {
        cout << st.top()<<" ";
        st.pop();
    }

    cout<<endl;

}

void binaryToDecimal(string s)
{
    int i=0;
    int n = s.size()-1;

    int ans = 0;

    while(i<s.size() && n>=0)
    {
        ans= ans + (s[i] - '0') * pow(2,n);
        i++;
        n--;
    }

    cout<<ans<<endl;
}




int main(){
    
    decimalToBinary(13);
    binaryToDecimal("1101");
    return 0;
}