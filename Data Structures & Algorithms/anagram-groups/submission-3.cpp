class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> orderedMap;

        for (const auto& str : strs) {
            string newString = str;
            sort(newString.begin(), newString.end());
            orderedMap[newString].push_back(str);
        }

        vector<vector<string>> result;
        for (auto& str : orderedMap) {
            result.push_back(std::move(str.second));
        }

        return result;
    }
};
