class Solution {
public:
    int reverse(int x) {
                
        long long reversedInt = 0;        
        
        while(x != 0) {           
            reversedInt *= 10;
            reversedInt += x % 10;           
            x /= 10;            
        }
        
        if(reversedInt > INT_MAX || reversedInt < INT_MIN) {
            return 0;
        }
        
        return reversedInt;
    }
};