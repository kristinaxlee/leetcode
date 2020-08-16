class Solution {
public:
    string addBinary(string a, string b) {
        int displacement = 1;

        string sum = "";
        int carry = 0;

        // zero fill the shorter string so that we don't have to worry about different lengths

        int length = max(a.length(), b.length());
        string a1 = string(length-a.length(), '0').append(a);
        string b1 = string(length-b.length(), '0').append(b);

        for(int i = length-1; i>=0; i--) {

            if(a1.at(i) == '0' && b1.at(i) == '0') {

                if(carry == 1) {
                    sum.insert(0, 1,'1');
                    carry = 0;
                }

                else {
                    sum.insert(0, 1,'0');
                }
            }

            else if(a1.at(i) == '1' && b1.at(i) == '1') {

                if(carry == 1) {
                    sum.insert(0, 1,'1');
                }

                else {
                    sum.insert(0, 1,'0');
                    carry = 1;
                }
            }

            else {
                if(carry == 1) {
                    sum.insert(0, 1,'0');
                    carry = 1;
                }

                else {
                    sum.insert(0, 1,'1');
                }
            }
        }

        if(carry == 1) {
            sum.insert(0, 1,'1');
        }

        return sum;

    }
};
