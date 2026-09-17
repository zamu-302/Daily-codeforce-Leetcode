class Solution {
public:
    bool isValid(string s) {
        std::unordered_map<char,char> hash{{'}','{'},{')','('},{']','['}};
        std::vector<char> arr;
        for(int i=0;i<s.length();i++){
            if(s[i]=='}'|| s[i]==']' || s[i]==')'){
                if(arr.empty()){return false;}
                char val=arr.back();
                arr.pop_back();
                if(val!=hash[s[i]]){
                    return false;
                }
                continue;
            }
            arr.emplace_back(s[i]);
        }
        if(arr.empty()){
            return true;
        }
        return false;
    }
};