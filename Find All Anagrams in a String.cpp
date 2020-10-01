#define pb push_back
class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        vector<int> ans, s_cnt(26,0), p_cnt(26,0);
        if(s.size() < p.size())
            return ans;
        
        for(int i=0;i<p.size();i++)
        {
            s_cnt[s[i]-'a']++, p_cnt[p[i]-'a']++;
        }
        
        int left = 0, right = p.size()-1;
        
        while(right < s.size())
        {
            if(s_cnt == p_cnt)
                ans.pb(left);
            
            s_cnt[s[left]-'a']--;
            right++;
            
            if(right != s.size())
            s_cnt[s[right]-'a']++;
           
            left++;
        }
        
        return ans;
    }
        
    
};