//双蛋问题
//100层楼，找到摔不碎蛋的临界层，总共两个蛋
//求最差情况下需要实验次数的下界
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<math.h>
#include<algorithm>


using namespace std;
int main(){
    vector<int> dp(101,0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 2;
    for(int i = 3;i <= 100;i++){
        int ans = i + 1;
        for(int j = 1;j < i;j++){
            int temp = 1 + max(j,dp[i-j-1]);
            ans = min(ans,temp);
        }
        dp[i] = ans;
        cout<<i<<" "<<dp[i]<<endl;
    }
    return 0;
}
