class Solution 
{
public:
    template <class Pred>
    bool mapsEqual(const unordered_map<char, int>& a, const unordered_map<char, int>& b, Pred eq)
    {
        for (const auto& [k, v] : a) 
        {
            auto it = b.find(k);
            if (it == b.end() || !eq(v, it->second)) return false;
        }
        return true;
    }

    int countCharacters(vector<string>& words, string chars) 
    {
        unordered_map<char, int> freq;
        for(int i = 0; i < chars.size(); i++)
        {
            freq[chars[i]]++;
        }
        int ans = 0;
        for(int i = 0; i < words.size(); i++)
        {
            unordered_map<char, int> mp;
            for(int j = 0; j < words[i].size(); j++)
            {
                mp[words[i][j]]++;
            }
            if(mapsEqual(mp, freq, [](int x, int y) { return x <= y; }))
            {
                ans += words[i].size();
            }
        }
        return ans;
    }
};