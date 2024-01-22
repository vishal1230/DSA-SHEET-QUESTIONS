class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        int missing=-1;
        int duplicate=-1;
        for(int i=0;i<n;i++){
            if(nums[abs(nums[i])-1]<0){
                duplicate=abs(nums[i]);
            }else{
                nums[abs(nums[i])-1] *= (-1);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                missing=(i+1);
                break;
            }
        }
        return {duplicate,missing};
    }
};