#pragma GCC optimize("fast-math","no-stack-protector")
class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {

    std::unordered_map<std::string,int> hash;
    for(const auto&p:positive_feedback){
        hash[p]=3;
    }
    for(const auto&n:negative_feedback){
        hash[n]--;
    }
     std::vector<std::pair<int, int>> scores;
        for (int i = 0; i < report.size(); i++) {
            int score = 0;
            std::istringstream iss(report[i]);
            std::string word;
            while (iss >> word) {
                auto it = hash.find(word);
                if (it != hash.end()) score += it->second;
            }
            scores.push_back({-score, student_id[i]});
        }

        std::sort(scores.begin(), scores.end());

        std::vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(scores[i].second);
        }
        return res;

        
    }
};