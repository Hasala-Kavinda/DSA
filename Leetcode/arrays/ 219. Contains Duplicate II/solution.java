
import java.util.HashSet;
import java.util.*;

class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Set<Integer> hashset = new HashSet<>();
        for (int i = 0; i < nums.length; i++) {
            if (hashset.contains(nums[i]))
                return true;
            hashset.add(nums[i]);

            if (hashset.size() > k)
                hashset.remove(nums[i - k]);
        }

        return false;

    }

    public static void main(String args[]) {

        Solution sol = new Solution();
        int[] nums = { 1, 2, 3, 1 };

        System.out.println("Output: " + sol.containsNearbyDuplicate(nums, 1));
    }
}