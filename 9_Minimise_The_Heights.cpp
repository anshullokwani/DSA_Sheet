int getMinDiff(int arr[], int n, int k) {
    sort(arr,arr+n);
    int mn=99999999,mx=-99999999;
    int ans=99999999;
    for(int i=1;i<n;i++)
    {
        mx=max(arr[i-1]+k,arr[n-1]-k);
        if(arr[i]-k<0)
        {
            continue;
        }
        mn=min(arr[i]-k,arr[0]+k);
        ans=min(ans,abs(mx-mn));
    }
    return min(ans,abs(arr[0]-arr[n-1]));
}