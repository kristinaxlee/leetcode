class Solution {
public:

  int expandFromCenter(string s, int left, int right) {
    int l = left, r = right;
    
    // while we're still in bounds and the two letters equal eachother, increment positions
    while(l >= 0 && r < s.length() && s.at(l) == s.at(r)) {
        l--;
        r++;
    }
    
    return r - l - 1;
  }
  
  string longestPalindrome(string s) {
      
    string longest = "";
    int length = 0, left = 0, right = 0, x1, x2;
    
    for(int i=0; i < s.length(); i++) {
      x1 = expandFromCenter(s, i, i);
      x2 = expandFromCenter(s, i, i+1);
      
      int length = max(x1,x2);

      if(length > longest.length()) {
          right = i - (length-1)/2;
          //left = i + ceil(length/2);    since C++ substr(startIdx, length), we don't need left index
          longest = s.substr(right, length);
      }
    }
    
    return longest;
  }
};