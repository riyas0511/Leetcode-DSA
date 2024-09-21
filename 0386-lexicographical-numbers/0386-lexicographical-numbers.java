class Solution {
    public List<Integer> lexicalOrder(int n) {
         // Create a list to store the result of numbers in lexicographical order
        List<Integer> result = new ArrayList<>();
        
        // Start with the first number in lexicographical order which is 1
        int current = 1;
        
        // Loop n times since we want n numbers in lexicographical order
        for (int i = 0; i < n; i++) {
            // Add the current number to the result list
            result.add(current);
            
            // Try to go "deeper" by multiplying the current number by 10 (e.g., 1 -> 10 -> 100)
            if (current * 10 <= n) {
                current *= 10;
            } 
            // If we can't go deeper (current * 10 exceeds n), we try to move to the next sibling
            else {
                // If the current number has reached or exceeded n, we move back up by dividing by 10
                if (current >= n) current /= 10;

                // Increment the current number to move to the next number in lexicographical order
                current++;

                // If the current number ends in 0 after increment (like 20, 30, etc.), we need to adjust it
                // For lexicographical order, skip numbers that end in 0 by dividing by 10
                while (current % 10 == 0) {
                    current /= 10;  // This will "move up" the tree (e.g., 20 -> 2, 30 -> 3)
                }
            }
        }
        
        // Return the result list containing the numbers in lexicographical order
        return result;
    }
}
