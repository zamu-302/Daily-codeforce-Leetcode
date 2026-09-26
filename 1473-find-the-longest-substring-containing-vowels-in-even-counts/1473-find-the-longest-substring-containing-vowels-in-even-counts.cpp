class Solution {
public:
    int findTheLongestSubstring(string s) {
        std::unordered_map<uint32_t,int>seen;
        std::unordered_map<char,int> vowel_map{
            {'a',1<<0},{'e',1<<1},{'i',1<<2},{'o',1<<3},{'u',1<<4}
        };
        seen[0]=-1;
        uint32_t mask=0;
        int longest=0;
        for(int i=0;i<s.length();i++){
            mask^=vowel_map[s[i]];
            if(seen.count(mask)){
                longest=std::max(longest,i-seen[mask]);
            }
            else{
                seen[mask]=i;
            }
        }
        return longest;
    }
};