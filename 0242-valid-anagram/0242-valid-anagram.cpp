class Solution {
public:
    bool isAnagram(string s, string t) {
     if(s.length()!=t.length()){
        return false;
     }
     std::unordered_map<char,int> words;
     for(int i=0;i<s.length();i++){
        words[s[i]]+=1;
     }
     for(int i=0;i<t.length();i++){
        words[t[i]]-=1;
        if(words[t[i]]<0){
            return false;
        }
     }
     return true;


    }
};