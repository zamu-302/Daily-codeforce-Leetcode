class Solution {
public:
    bool isPalindrome(string s) {
        int left=0;
        int right=s.length();
        while(left<right){
            if(!std::isalnum(s[left])){
                left++;
                continue;
            }
            if(!std::isalnum(s[right])){
                right--;
                continue;
            }
            if(std::tolower(s[left])!=std::tolower(s[right])){
                return false;
            }
            left++;
            right--;
        }
        return true;
        
    }
};