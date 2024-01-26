class Solution {
private:
    const int mod=int(1e9+7);
    vector<pair<int,int>> dirs={{-1,0},{0,-1},{1,0},{0,1}};
    int dp[51][51][51];
    int f(int i,int j,int m,int n,int remMoves) {
        //base cases
        if(i==m || j==n || i==-1 || j==-1) return 1;
        if(remMoves==0) return 0;
        if(dp[i][j][remMoves]!=-1) return dp[i][j][remMoves];

        int ans=0;
        for(auto [dx,dy] :dirs) {
            ans+=f(i+dx,j+dy,m,n,remMoves-1);
            ans%=mod;
        }
        return dp[i][j][remMoves]=ans; 
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return f(startRow,startColumn,m,n,maxMove);
    }
};