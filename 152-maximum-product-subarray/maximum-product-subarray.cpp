class Solution 
{
public:
    int maxProduct(vector<int>& arr) 
    {
        long long mini = 1, maxi = 1;
        long long max_ans = LONG_LONG_MIN;
        long long min_ans = LONG_LONG_MAX;
        for (int i = 0; i < arr.size(); i++)
        {
            long long newMax = max({(long long)arr[i], arr[i] * maxi, arr[i] * mini});
            long long newMin = min({(long long)arr[i], arr[i] * maxi, arr[i] * mini});
            maxi = newMax;
            mini = newMin;
            max_ans = max(max_ans, maxi);
            min_ans = min(min_ans, mini);
        }
        return max_ans;
    }
};