class Solution {
public:
    long long wonderfulSubstrings(string word) {
        std::unordered_map<uint64_t,int>seen;
        std::unordered_map<char,uint64_t> freq{
            {'a',1<<1},
            {'b',1<<2},
            {'c',1<<3},
            {'d',1<<4},
            {'e',1<<5},
            {'f',1<<6},
            {'g',1<<7},
            {'h',1<<8},
            {'i',1<<9},
            {'j',1<<10}
        }; 
        seen[0]=1;
        uint64_t mask=0;
        long long ans=0;
        for(int i=0;i<word.size();i++){
            mask=mask^freq[word[i]];
            ans+=seen[mask];
            for(int b=1;b<11;b++){
                ans+=seen[mask^(1<<b)];
            }
            seen[mask]++;
        }
        return ans;

    }
};