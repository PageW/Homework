//面试题08.13 堆箱子
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int pileBox(vector<vector<int>>& box) {
        //排序
        sort(box.begin(),box.end(),[](const vector<int>& a,const vector<int>& b){return a[0] < b[0];});
        vector<int> dp(box.size(),0);
        dp[0] = box[0][2];//dp[i]存以第i个箱子为结束的最大高度，第i个箱子必须有
        int ans = dp[0];
        for(int i = 0;i < box.size();i++){
            int maxh = 0;
            for(int j = 0;j < i;j++){
                if(box[j][0] < box[i][0] && box[j][1] < box[i][1] && box[j][2] < box[i][2])
                    maxh = max(maxh,dp[j]);
            dp[i] = maxh + box[i][2];
            ans = max(ans,dp[i]);
            }
        }
        return ans;
    }
};