int getPairsCount(int arr[], int n, int k) {
        unordered_map<int,int>m;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(m[arr[i]]>0)
                cnt=cnt+m[arr[i]];
            m[k-arr[i]]++;

        }
        return cnt;
    }