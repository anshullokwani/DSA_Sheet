#include<bits/stdc++.h>  
using namespace std; 
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;	cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
    	cin>>arr[i];
    }
    int one=0,two=0;
    while(two<n)
    {
    	if(arr[two]<0)
    	{
    		swap(arr[one],arr[two]);
    		one++;
    		two++;
    	}
    	else
    	{
    		two++;
    	}
    }
    for(int i=0;i<n;i++)
    {
    	cout<<arr[i]<<" ";
    }

}