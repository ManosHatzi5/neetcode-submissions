class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Hash map storing: Key = number value, Value = index in 'nums'
        unordered_map<int, int> numMap;

        // Optimization for ML Systems / HPC:
        // Pre-allocate bucket storage to eliminate dynamic rehashing stalls
        numMap.reserve(nums.size());

        for (size_t i = 0; i < nums.size(); ++i) {
            int difference = target - nums[i];
            auto it = numMap.find(difference);
            if (it != numMap.end()) {
                return {it->second, (int)i};
            }
            numMap[nums[i]] = i;
        }
        return {};
    }
};