class Solution {
public:
    bool validPalindromeSub(string s) {
        int start = 0, end = s.length()-1;
        while(start < end) {
            if(s.at(start) != s.at(end)) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int start = 0, end = s.length()-1;
        
        while(start < end) {
            if(s.at(start) != s.at(end)) {
                int length = end-start;
                if(validPalindromeSub(s.substr(start, length)) || validPalindromeSub(s.substr(start+1, length))) {
                    return true;   
                }
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};