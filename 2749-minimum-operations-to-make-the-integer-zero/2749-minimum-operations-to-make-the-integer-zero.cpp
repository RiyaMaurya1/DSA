class Solution {
public:
    
    // Time complexity: O(1)
    // Space complexity: O(1)
        
        
    int makeTheIntegerZero(int num1, int num2) {
        // num1 = 2^i1 + num2 + 2^i2 + num2 + ............. + 2i^n + num2
        // num1 = k*num2 + 2^i1 + 2^i2 +..................+ 2^i;
        // num1- k*num2 = target;
        
        for(int k = 0 ;  k <= 60 ; k++){
            long long target = (long long) num1 - (long long)k*num2;
            bitset<64> bits(target);
            if(target >= 0 && bits.count() <= k && k <= target){
                return k;
            }
        }
        return -1;
    }
};


