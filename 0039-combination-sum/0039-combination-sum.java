class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        findCombination(0, candidates, target, ans, new ArrayList<>());
        return ans;
    }

    // Recursive function to find all combinations that sum to target
    static void findCombination(int ind, int[] candidates, int target, List<List<Integer>> ans, List<Integer> ds) {
        // Base case: if we have processed all elements
        if (ind == candidates.length) {
            if (target == 0) {
                ans.add(new ArrayList<>(ds)); // Add a copy of the current list to the result
            }
            return;
        }
        
        // Pick the element if it's less than or equal to the remaining target
        if (candidates[ind] <= target) {
            ds.add(candidates[ind]);
            findCombination(ind, candidates, target - candidates[ind], ans, ds); // Explore with reduced target
            ds.remove(ds.size() - 1); // Backtrack
        }
        
        // Don't pick the element, move to the next index
        findCombination(ind + 1, candidates, target, ans, ds);
    }
}
