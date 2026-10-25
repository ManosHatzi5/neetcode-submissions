class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> orderedMap;

        // we use const so we are safe if by mistake we try to modify the variable
        // we use auto for readability, nothing crazy, could js say string
        // we use & because we dont want to make a copy for no reason, we save memory with that
        for (const auto& str : strs) {
            string newString = str;
            sort(newString.begin(), newString.end());
            orderedMap[newString].push_back(str);
        }

        // we use std::move because the .push_back() function creates a copy of the parameter
        // but because the orderedmap will get deleted anyway, we just take the pointers
        // of the value-vector so we can save memory and time
        vector<vector<string>> result;
        for (auto& str : orderedMap) {
            result.push_back(std::move(str.second));
        }

        return result;
    }
};
