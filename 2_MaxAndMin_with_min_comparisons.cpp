#include<bits/stdc++.h>  
using namespace std; 
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;  cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }  
    int mx,mn;
    if(n%2==0)
    {
        mx=max(arr[0],arr[1]);
        mn=min(arr[0],arr[1]);
        for(int i=0;i<n-1;i+=2)
        {
            if(arr[i]>=arr[i+1])
            {
                mx=max(mx,arr[i]);
                mn=min(mn,arr[i+1]);
            }
            else
            {
                mx=max(mx,arr[i+1]);
                mn=min(mn,arr[i]);
            }
        }
    }
    else
    {
        mx=arr[0];
        mn=arr[0];
        for(int i=1;i<n-1;i+=2)
        {
            if(arr[i]>=arr[i+1])
            {
                mx=max(mx,arr[i]);
                mn=min(mn,arr[i+1]);
            }
            else
            {
                mx=max(mx,arr[i+1]);
                mn=min(mn,arr[i]);
            }
        }
    }
    
    cout<<"mx="<<mx<<endl<<"mn="<<mn;
}