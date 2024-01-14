class Solution {
public:
void genpar(vector<string>& ans,string curr, int open ,int closed,int n){
    if(curr.size()==2*n){
        ans.push_back(curr);
        return;
    }
    if(open<n){
        genpar(ans,curr+'(',open+1,closed,n);
    }
    if(closed<open){
        genpar(ans,curr+')',open,closed+1,n);
    }
}
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        genpar(ans,"",0,0,n);
        return ans;
    }
};