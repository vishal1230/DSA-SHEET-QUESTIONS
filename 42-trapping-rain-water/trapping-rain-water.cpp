class Solution {
public:
    int trap(vector<int>& height) {
        int l=0,r=height.size()-1, L_max=INT_MIN,R_max=INT_MIN, sum=0;
        while(l<r){
            L_max=max(L_max,height[l]);
            R_max=max(R_max,height[r]);
            sum+=(L_max<R_max)?L_max-height[l++]:R_max-height[r--]; 
        }
        return sum;
    }
};