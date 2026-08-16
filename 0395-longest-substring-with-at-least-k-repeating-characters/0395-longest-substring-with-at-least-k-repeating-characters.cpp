class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.size() < k)
            return 0;
        vector<int> cnt(26,0);
        for(char c : s)
            cnt[c-'a']++;
        for(int i=0;i<s.size();i++) {
            if(cnt[s[i]-'a'] < k) {
                int left = longestSubstring(s.substr(0,i), k);
                int right = longestSubstring(s.substr(i+1), k);
                return max(left,right);
            }
        }
        return s.size();
    }
};