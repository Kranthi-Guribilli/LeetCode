class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len=0;
        for(int i=0;i<s.size();i++){
            unordered_map<char,int> mp;
            for(int j=i;j<s.size();j++){
                if(mp.find(s[j])==mp.end()){
                    max_len=max(max_len,j-i+1);
                    mp[s[j]]=j;
                }
                else break;
            }
        }
        return max_len;
    }
};