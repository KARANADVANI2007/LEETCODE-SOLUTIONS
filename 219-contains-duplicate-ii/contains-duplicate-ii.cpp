class Solution 
{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        // for(int i = 0; i < nums.size(); i++)
        // {
        //     for(int j = i + 1; j < nums.size(); j++)
        //     {
        //         if(nums[i] == nums[j] && abs(i - j) <= k)
        //         {
        //             return true;
        //         }
        //     }
        // }
        // return false;



        // THIS APPROACH IS MORE OPTIMAL BUT WE CAN STILL OPTIMISE SPACE
        // unordered_map<int, int> mp;
        // for(int i = 0; i < nums.size(); i++)
        // {
        //     if(mp.find(nums[i]) != mp.end())
        //     {
        //         if(abs(i - mp[nums[i]]) <= k)
        //         {
        //             return true;
        //         }
        //         mp[nums[i]] = i;
        //     }
        //     else
        //     {
        //         mp.insert({nums[i], i});
        //     }
        // }
        // return false;


        unordered_set<int> window;
        for (int i = 0; i < nums.size(); i++) 
        {
            if (window.count(nums[i])) return true;
            window.insert(nums[i]);
            if (window.size() > k) 
                window.erase(nums[i - k]);
        }
        return false;
    }
};