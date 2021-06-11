int maxProfit(vector<int>& prices) {
        int mx=0,mxprofit=0;
        for(int i=prices.size()-1;i>=0;i--)
        {
            mx=max(mx,prices[i]);
            mxprofit=max(mxprofit,abs(mx-prices[i]));
        }
        return mxprofit;
    }