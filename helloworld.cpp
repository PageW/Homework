#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

#include<unordered_map>
using namespace std;
class Solution
{
public:
    vector<vector<int>> pairSums(vector<int> &nums, int target)
    {
        //count一波
        unordered_map<int, int> numCount;
        for (int num : nums)
            numCount[num]++;
        vector<vector<int>> res;
        if (target % 2 == 0)
        {
            if (numCount[target / 2] > 0)
            {
                for (int i = 0; i < numCount[target / 2] / 2; i++)
                    res.push_back(vector<int>{target / 2, target / 2});
                numCount[target / 2] = 0;
            }
        }
        cout << numCount[43] << " " << numCount[773] << endl;
        for (unordered_map<int, int>::iterator itr = numCount.begin(); itr != numCount.end(); itr++)
        {
            cout << itr->first << " " << itr->second << endl;
            if (itr->first <= target / 2)
            {
                for (int i = 0; i < min(itr->second, numCount[target - itr->first]); i++)
                    res.push_back(vector<int>{itr->first, target - itr->first});
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> nums{234, 361, 294, 297, 5, 522, 528, 291, 798, 249, 63, 907, 951, 86, 597, 91, 744, 483, 795, 991, 140, 587, 939, 338, 582, 118, 92, 43, 916, 984, 849, 62, 638, 965, 657, 515, 541, 591, 167, 827, 723, 649, 954, 325, 587, 443, 854, 575, 519, 6, 8, 109, 88, 237, 963, 550, 631, 820, 491, 868, 177, 145, 832, 980, 591, 506, 831, 288, 726, 382, 469, 314, 297, 676, 72, 383, 382, 822, 848, 626, 219, 994, 23, 773, 725, 121, 847, 90, 407, 788, 187, 426, 627, 433, 455, 717, 475, 333, 995, 208};
    vector<vector<int> > ans;
    ans = s.pairSums(nums,816);

    cout << ans.size() << endl;
    return 0;
}