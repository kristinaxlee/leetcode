/* 
    Time: O(n) - need to iterate through each letter in string (n) + hashmap lookup (1)
    Memory: O(n) - hashmap will be less than N when string has repeating letters
    
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int curLen = 0, maxLen = 0, startIdx = 0;
        
        unordered_map<char, int> letters; // store char and the most recent location the char was found
        
        // iterate through all characters
        for(int i = 0; i < s.length(); i++) {
            auto it = letters.find(s.at(i));
            
            // if we found the letter in the hash map, check and see if it's before our starting index
            if(it != letters.end()) {
                // if it's before beginning of substring, we're ok
                if(it->second < startIdx) {
                    curLen++;
                }
                // if it's in the substring, we have to start the substring at the index after this one
                else {
                    startIdx = it->second + 1;
                    curLen = i - startIdx + 1; // new length is the new start idx up to index i (if string starts at 2, ends at 3, then length is 2)
                }
                it->second = i; // the latest time we've now seen this index is now (i)
            }
            
            // if we haven't found the letter in the hashmap, add to letters map & increment curLen
            else {
                letters.insert({s.at(i), i});
                curLen++;
            }
            
            maxLen = max(curLen, maxLen);
        }
        
        return maxLen;
    }
};