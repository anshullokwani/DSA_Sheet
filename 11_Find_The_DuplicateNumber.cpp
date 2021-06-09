int findDuplicate(vector<int>& nums) {
    int ans=1;
    int n=nums.size();
    for(int i=2;i<n;i++)
    {
        ans=ans^i;
    }
    for(int i=0;i<n;i++)
    {
        ans=ans^nums[i];
    }
    return ans;
}