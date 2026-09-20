class Solution 
{
public:
    int reverseDegree(string s) 
    {
        int sum = 0;
        for(int i = 0; i < s.size(); i++)
        {
            int temp = int(26 - (s[i] - 97)) * (i + 1);
            sum += temp;
        }
        return sum;
    }
};