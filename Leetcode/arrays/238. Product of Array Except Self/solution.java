import java.util.*;

class Solution {
    public int[] productExceptInself(int[] nums) {

        int[] results = new int[nums.length];

        int pre = 1, post = 1;

        for (int i = 0; i < results.length; i++) {
            results[i] = pre;
            pre = nums[i] * pre;
        }
        for (int i = results.length - 1; i >= 0; i--) {

            results[i] = results[i] * post;
            post = nums[i] * post;
        }
        return results;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] inputs = { 1, 2, 3, 4 };

        int[] answer = sol.productExceptInself(inputs);

        // System.out.println(answer);
        for (int i = 0; i < answer.length; i++) {
            System.out.println(answer[i]);

        }

        // Output: [[eat, tea, ate], [tan, nat], [bat]]
    }
}