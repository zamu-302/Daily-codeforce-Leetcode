class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()){
            return false;
        }
        std::vector<int>arr(26,0);
        std::vector<int>arr2(26,0);
        for(const auto& c: s1){
            arr[c-'a']+=1;
        }
        for(int i=0;i<s1.length();i++){
            arr2[s2[i]-'a']++;
        }
        if(arr==arr2){
            return true;
        }
        
        for(int right=s1.length();right<s2.length();right++){
            arr2[s2[right-s1.length()]-'a']-=1;
            arr2[s2[right]-'a']+=1;
            if(arr==arr2){
                return true;
            }
        }
        return false;

        
        
    }
};