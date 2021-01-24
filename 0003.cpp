class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //abcabcbb
        // a, ab, abc, bca, cab, abc, cb, b  
        // keep a pointer at the beginning of the substring
        // everytime we look at new letter, iterate through substring, look for duplicate
        int startIdx = 0;
        int curLen = 0;
        int maxLen = 0;
        
        for(int i=0; i<s.length(); i++) {
            int curIdx = i;
            cout << "i: " << i << endl;
            // start at beginning of substring, end at the current index
            for(int j = startIdx; j < curIdx; j++) {
                //if letter in substring == currentIndex, startIdx is letter after the one we're looking at
                if(s.at(j) == s.at(i)) {
                    cout << "comparing: " << s.at(j) << " + " << s.at(i) << endl;
                     startIdx = j+1; // exclude letter j from the substring, start at the next letter
                     curLen = i - startIdx; // length is now 1 element shorter
                 }
            }
            // increment substring length
            curLen++;
            
            maxLen = max(maxLen, curLen);
            
            cout << "current length: " << curLen << endl;
        }
        return maxLen;
    }
};