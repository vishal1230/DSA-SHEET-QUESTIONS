class Solution {
public:

    int maxi = 0;

    bool isUnique(string s){

        set<char> st;
        
        for(auto x : s){
            st.insert(x);
        }

        if(s.size() == st.size()){
            return true;
        }
        
        return false;
    }

    void solve(vector<string>& arr, int i, int n, string temp){

        // if we have got duplicate int our result then simply return
        if(isUnique(temp) == false){
            return;
        }

        // Base Condition
        if(i >= n){

            // update maxi
            int currSize = temp.size();
            maxi = max(maxi, currSize);

            return;
        }

        // Take present string
        solve(arr, i+1, n, temp + arr[i]);

        // Dont take present string
        solve(arr, i+1, n, temp);
    }

    int maxLength(vector<string>& arr) {
        
        int n = arr.size();
        solve(arr, 0, n, ""); // recursion

        return maxi;
    }
};