import java.math.BigInteger;

class Solution {
    public String addBinary(String a, String b) {
        BigInteger a1 = new BigInteger(a, 2); // Parse as binary
        BigInteger b1 = new BigInteger(b, 2); // Parse as binary

        // Perform binary addition
        while (!b1.equals(BigInteger.ZERO)) 
        {
            BigInteger sum = a1.xor(b1);           // XOR for addition
            BigInteger carry = a1.and(b1).shiftLeft(1); // AND and shift for carry
            a1 = sum;
            b1 = carry;
        }

        return a1.toString(2); // Convert result to binary string
    }
}