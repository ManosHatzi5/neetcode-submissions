class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;

        for (const int& num : nums) {
            freqMap[num]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);
        for (const auto& pair : freqMap) {
            bucket[pair.second].push_back(pair.first);
        }

          
        vector<int> result;
        // 1. Standard signed int for safe reverse iteration
        for (int i = nums.size(); i >= 0; --i) {
            
            // 2. Iterate through whatever numbers are sitting in this bucket
            for (int num : bucket[i]) {
                result.push_back(num);
                
                // 3. Stop the moment we have collected k elements
                if (result.size() == k) {
                    return result;
                }
            }
        }
        return result;



    }
};
