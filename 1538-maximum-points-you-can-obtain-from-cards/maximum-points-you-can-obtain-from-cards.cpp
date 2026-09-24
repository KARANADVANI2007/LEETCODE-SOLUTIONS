class Solution 
{
public:
    // IN THIS QUESTION WE ARE CHOOSING ELEMENTS EITHER FROM RIGHT OR FROM LEFT
    // SO THE LEFTOVER IS A SUBARRAY SO THE QUESTION NOW BECOMES
    // FIND THE MINIMUM SUM(AS WE HAVE TO MAXIMIZE THE SCORE) SUBARRAY OF SIZE N - K(AS WE HAVE TO PICK K CARDS)
    int maxScore(vector<int>& arr, int k) 
    {
        int n = arr.size();
        int ans = INT_MAX;
        int sum = 0;
        int total = 0;
        int size = n - k;
        for(int i = 0; i < n; i++)
        {
            sum += arr[i];
            total += arr[i];
            if(i >= size)
            {
                sum -= arr[i - size];
            }
            if(i >= size - 1)
            {
                ans = min(ans, sum);
            }
        }
        return total - ans;
    }
};
