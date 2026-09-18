class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::vector<int> idx(speed.size());
        iota(idx.begin(),idx.end(),0);
        sort(idx.begin(),idx.end(),[&](int i,int j) {return position[i]<position[j];});
        
        
        int carfleet=0;
        float slowest=0;
        for(int i=position.size()-1;i>-1;i--){
            float time=float(target-position[idx[i]])/speed[idx[i]];
            if(time>slowest){
                carfleet+=1;
                slowest=time;
            }

        }
       
        return carfleet;
        
        
    }
};