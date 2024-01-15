class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> lost_map; //key:palyer, value:count of losses
        for(int i=0;i<matches.size();i++){
            int loser=matches[i][1];
            lost_map[loser]++;
        }
        vector<int> notlost;
        vector<int> lostonce;
        for(int i=0;i<matches.size();i++){
            int winner= matches[i][0];
            int loser= matches[i][1];
            if(lost_map.find(winner) == lost_map.end()){
                notlost.push_back(winner);
                lost_map[winner]=2;
            }
            if(lost_map[loser]==1){
                lostonce.push_back(loser);
            }
        }
        sort(begin(notlost),end(notlost));
        sort(begin(lostonce),end(lostonce));
        return {notlost,lostonce};
    }
};