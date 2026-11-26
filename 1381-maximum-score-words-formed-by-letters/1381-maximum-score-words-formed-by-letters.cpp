class Solution {
public:
    std::unordered_map<char,int>scores;
    std::unordered_map<char,int>count;
    int best=0;
    int n;
    void dfs(vector<string>& words,int gain,int start){
        for(int i=start;i<words.size();i++){
            bool ok=true;
            for(auto c:words[i]){
                if(--count[c]<0){
                    ok=false;
                }
                gain+=scores[c];
            }
            if(ok){ 
                best=std::max(best,gain);
                dfs(words,gain,i+1);
            }
            for(auto c:words[i]){
            ++count[c];
            gain-=scores[c];
            }
        }
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        n=words.size();
        for(int i=0;i<letters.size();i++){
            if(!scores.contains(letters[i])){
                scores[letters[i]]=score[letters[i]-'a'];
            }
            count[letters[i]]++;
        }

        dfs(words,0,0);
        return best;
        

    }
};