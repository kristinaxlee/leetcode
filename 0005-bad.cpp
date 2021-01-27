class Solution {
public:
    
    string longest = "";
    
    bool isPalindrome(string s) {
        for(int i=0; i < s.length()/2; i++) {
            if(s.at(i) != s.at(s.length()-i-1)) {
                return false;
            }
        }
        return true;
    }
    
    void findPalindrome(string s, int startIdx) {
        string sub = "";
        for(int i=s.length()-1; i > startIdx; i--) {
            // if we find a matching letter, check and see if it's a palindrome
            
            if(s.at(i) == s.at(startIdx)) {
                // look and see if there's a palindrome or not
                sub = s.substr(startIdx, i-startIdx+1);
                if(isPalindrome(sub)) {
                    // if it's longer than the current longest palindrome, replace it
                    if(sub.length() > longest.length()) {
                        longest = sub;
                    }
                    return;
                }
            }
        } 
    }
    
    string longestPalindrome(string s) {
        
        longest = s.at(0);
        
        for(int i=0; i<s.length(); i++) {
            findPalindrome(s, i);
        }    
        
        return longest;
    }
};