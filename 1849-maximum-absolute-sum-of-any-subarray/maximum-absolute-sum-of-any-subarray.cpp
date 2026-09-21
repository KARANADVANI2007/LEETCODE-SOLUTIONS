class Solution 
{
public:
    long long kadane(vector<int> &arr)
    {
        long long curr = 0, ans = LONG_LONG_MIN;
        for (int i = 0; i < arr.size(); i++)
        {
            curr = max(curr + arr[i], (long long)arr[i]); // NOTE HERE IN MAX BOTH THE DATATYPES SHALL BE SAME
            // EITHER BOTH SHALL BE LONG LONG OR BOTH SHALL BE INT
            ans = max(ans, curr);
        }
        return ans;
    }

    long long kadane_for_min_1(vector<int> &arr)
    {
        long long curr = 0, ans = LONG_LONG_MAX;
        for (int i = 0; i < arr.size(); i++)
        {
            curr = min((long long)arr[i], curr + arr[i]);
            ans = min(ans, curr);
        }
        return ans;
    }

    int maxAbsoluteSum(vector<int>& nums) 
    {
        return max(kadane(nums), -kadane_for_min_1(nums));
    }
};