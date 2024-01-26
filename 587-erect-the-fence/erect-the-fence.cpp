class Solution {
public:
    int getRotationAngle(vector<int> a, vector<int> b, vector<int> c){
        //(x2-x1)(y3-y1) - (y2-y1)(x3 - x1) cross product of ab and ac vector
        return ((b[0] - a[0]) * (c[1] - a[1])) - ((b[1] - a[1]) * (c[0] - a[0]));
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        //by using convex Hull algorithm
        if(trees.size() <= 3) return trees; // if less than equal to 3 then all need to include
        sort(trees.begin(), trees.end()); // sort them in lexo manner(according to order of x coordinates);
        vector<vector<int>> upperHull; //creating upper hull
        //pushing two points in upper hUll as 'a' and 'b';
        upperHull.push_back(trees[0]);
        upperHull.push_back(trees[1]);
        for(int i=2;i<trees.size();i++){ // considering it as 'c' start traversing from index 2
            int Uhs =upperHull.size();
            //slop / cross product should be greater than 0 counter clock wise angle remove b and add c
            while(upperHull.size() >= 2 && getRotationAngle(upperHull[Uhs - 2], upperHull[Uhs - 1], trees[i]) > 0){
                upperHull.pop_back();
                Uhs--;
            }
            upperHull.push_back(trees[i]);
        }
        vector<vector<int>> lowerHull; //creating lower hull
        //same steps for lower hull as upper hull but reversed array of trees
        lowerHull.push_back(trees[trees.size() - 1]);
        lowerHull.push_back(trees[trees.size() - 2]);
        for(int i=trees.size() - 3;i>=0;i--){
            int lhs = lowerHull.size();
            while(lowerHull.size() >= 2 && getRotationAngle(lowerHull[lhs - 2], lowerHull[lhs - 1], trees[i]) > 0){
                lowerHull.pop_back();
                lhs--;
            }
            lowerHull.push_back(trees[i]);
        }
        //now merge upperhull and lowerHUll using STL
        upperHull.insert(upperHull.end(), lowerHull.begin(), lowerHull.end());
        //now remove the duplicates from the merged upper hull
        sort(upperHull.begin(), upperHull.end());
        upperHull.erase(unique(upperHull.begin(), upperHull.end()), upperHull.end());
        return upperHull;
    }
};

