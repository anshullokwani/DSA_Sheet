int maxSubarraySum(int arr[], int n){
    int curr_max=0;
    int overall_max=-99999999;
    for(int i=0;i<n;i++)
    {
        curr_max+=arr[i];
        if(curr_max>overall_max)
        {
            overall_max=curr_max;
        }
        if(curr_max<0)
        {
            curr_max=0;
        }
    }
    return overall_max;
}