class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;

        for (const auto& num : nums) {
            freqMap[num]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);
        for (const auto& pairs : freqMap){
            bucket[pairs.second].push_back(pairs.first);
        }

        vector<int> result;
        for (int i=nums.size(); i>=0; --i){
            
            for (const auto& num : bucket[i]){
                result.push_back(num);
                if (result.size() == k){
                    return result;
                }
            }

        }
        return result;







    }
};
