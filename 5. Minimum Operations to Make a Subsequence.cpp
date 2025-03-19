class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> indexMap;
        for (int i = 0; i < target.size(); i++) 
            indexMap[target[i]] = i;

        vector<int> indices;
        for (int a : arr) 
            if (indexMap.count(a)) 
                indices.push_back(indexMap[a]);

        return target.size() - longestIncreasingSubsequence(indices);
    }
private:
    int longestIncreasingSubsequence(vector<int>& nums) {
        vector<int> lis;
        for (int num : nums) {
            auto it = lower_bound(lis.begin(), lis.end(), num);
            if (it == lis.end()) lis.push_back(num);
            else *it = num;
        }
        return lis.size();
    }
};
