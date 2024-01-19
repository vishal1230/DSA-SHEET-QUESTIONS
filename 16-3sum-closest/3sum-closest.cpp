class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int closest_sum=100000;
        sort(begin(nums),end(nums));
        for(int k=0;k<=n-3;k++){
            int i=k+1;
            int j=n-1;
            int sum=0;
            while(i<j){
                sum=nums[k]+nums[i]+nums[j];
                if(abs(target-sum)< abs(target-closest_sum))
                closest_sum=sum;
                if(sum<target){
                    i++;
                }
                else{
                    j--;
                }

            }
        }
        return closest_sum;
    }
};