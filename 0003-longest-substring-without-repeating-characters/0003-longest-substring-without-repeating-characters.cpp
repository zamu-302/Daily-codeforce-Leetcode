class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()){
            return 0;
        }
        std::unordered_set<char> seen;
        int left=0;
        seen.insert(s[0]);
        int len=1;
        for(int right=1;right<s.length();right++){
            while(seen.contains(s[right])){
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[right]);
            len=std::max(right-left+1,len);
        }
        return len;

    }
};