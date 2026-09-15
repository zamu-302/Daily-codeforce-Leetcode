class Solution {
public:
    int characterReplacement(string s, int k) {
        std::vector<int> freq(26,0);
        int left=0;
        int max_len=0;
        int max_freq=0;
        for(int right=0;right<s.length();right++){
            freq[s[right]-'A']+=1;
            max_freq=std::max(max_freq,freq[s[right]-'A']);
            while((right-left+1)-max_freq>k){
                freq[s[left]-'A']-=1;
                left++;
            }
            max_len=std::max(max_len,right-left+1);


        }
        return max_len;
    }
};