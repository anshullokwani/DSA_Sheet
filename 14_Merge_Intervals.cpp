vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>>ans;
    int size=intervals.size();
    sort(intervals.begin(),intervals.end());
    vector<int>curr;
    curr=intervals[0];
    for(int i=1;i<size;i++)
    {
        if(curr[1]>=intervals[i][0])
        {
            curr[1]=max(curr[1],intervals[i][1]);
        }
        else
        {
            ans.push_back(curr);
            curr=intervals[i];
        }
    }
    ans.push_back(curr);
    return ans;
}