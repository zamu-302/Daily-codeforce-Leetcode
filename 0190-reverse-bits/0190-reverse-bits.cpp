class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t num=0;
        while(n){
            uint32_t sq=__builtin_ctzll(n);
            num|=(1ULL<<(31-sq));
            n&=n-1;
        }
        return num;
    }
};