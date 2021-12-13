#include<bits/stdc++.h>  
using namespace std; 
long long ncr(int n, int r)
{
    long long ans=1;
    for(int i=1;i<=r;i++)
    {
        ans=ans*((n+1)-r)/r;
    }
    return ans;
}
int main() 
{
    cout<<ncr(4,3);
}