class Solution {
public:
    int cntrows(set<int>& selected, vector<vector<int>>& matrix) 
    {
        int coveredRows = 0;
        
        for (int i = 0; i < matrix.size(); i++) 
        {
            bool covered = true;               
            for (int j = 0; j < matrix[0].size(); j++) 
            {
                if (matrix[i][j] == 1 && selected.find(j) == selected.end()) 
                {
                    covered = false;
                    break;
                }
            }
            if (covered) coveredRows++;
        }
        
        return coveredRows;
    }

    int mxrows(int idx, vector<vector<int>>& matrix, int num, int cnt, set<int>& selected) 
    {
        if (cnt == num) 
        {
            return cntrows(selected, matrix);
        }
        if (idx >= matrix[0].size()) 
        {
            return 0;
        }
        
        selected.insert(idx);
        int pick = mxrows(idx + 1, matrix, num, cnt + 1, selected);
        selected.erase(idx);
        int notpick = mxrows(idx + 1, matrix, num, cnt, selected);
        
        return max(pick, notpick);
    }
    
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        set<int> selected;
        return mxrows(0, matrix, numSelect, 0, selected);
    }
};
