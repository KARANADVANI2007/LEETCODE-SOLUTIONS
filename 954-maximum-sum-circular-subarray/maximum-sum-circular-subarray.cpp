class Solution 
{
public:
    long long max_sum(vector<int> &arr)
    {
        long long curr = 0, ans = LONG_LONG_MIN;
        for(int i = 0; i < arr.size(); i++)
        {
            curr = max((long long)arr[i], curr + arr[i]);
            ans = max(curr, ans);
        }
        return ans;
    }

    long long min_sum(vector<int> &arr)
    {
        long long curr = 0, ans = LONG_LONG_MAX;
        for(int i = 0; i < arr.size(); i++)
        {
            curr = min((long long)arr[i], curr + arr[i]);
            ans = min(curr, ans);
        }
        return ans;
    }

    int maxSubarraySumCircular(vector<int>& nums) 
    {
        int maxi = max_sum(nums);
        int mini = min_sum(nums);
        bool allnegative = false;
        int sum = 0;
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < 0)
            {
                cnt++;
            }
            sum += nums[i];
        }
        if(cnt == nums.size())
        {
            allnegative = true;
        }
        cout << maxi << " " << mini << " " << sum;
        if(allnegative)
        {
            return maxi;
        }
        else
        {
            return max(maxi, sum - mini);
        }
    }
};
