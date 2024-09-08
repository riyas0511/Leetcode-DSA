class Solution {
    public int reverse(int x) {
      
        int revNum = 0;
        
        while (x != 0) {
            int lastdig = x % 10;  // Get the last digit of x
            x = x / 10;  // Remove the last digit from x

            // Check for overflow before updating revNum
            if (revNum > Integer.MAX_VALUE / 10 || (revNum == Integer.MAX_VALUE / 10 && lastdig > 7)) {
                return 0;  // Overflow case for positive numbers
            }
            if (revNum < Integer.MIN_VALUE / 10 || (revNum == Integer.MIN_VALUE / 10 && lastdig < -8)) {
                return 0;  // Overflow case for negative numbers
            }

            // Update revNum with the last digit
            revNum = revNum * 10 + lastdig;
        }
        
        return revNum;
    }
}
