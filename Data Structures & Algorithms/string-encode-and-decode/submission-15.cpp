#include <string>
#include <vector>

class Solution {
public:
    static std::string encode(const std::vector<std::string>& strs) {
        std::string encodedStr;
        for (const std::string& str : strs) {
            encodedStr += std::to_string(str.size()) + '#' + str;
        }
        return encodedStr;
    }

    static std::vector<std::string> decode(const std::string& s) {
        std::vector<std::string> result;
        size_t i = 0;

        while (i < s.size()) {
            // 1. Locate the delimiter '#' starting from index i
            size_t hashPos = s.find('#', i);

            // 2. Extract and parse the length prefix
            int length = std::stoi(s.substr(i, hashPos - i));

            // 3. Slice exactly 'length' characters starting immediately after '#'
            result.push_back(s.substr(hashPos + 1, length));

            // 4. Advance the index directly to the start of the next length prefix
            i = hashPos + 1 + length;
        }

        return result;
    }
};