import java.util.*;

class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        if (strs.length == 0)
            return new ArrayList<>();

        Map<String, List<String>> ansMap = new HashMap<>();
        int[] count = new int[26];

        for (String str : strs) {
            Arrays.fill(count, 0);

            for (char c : str.toCharArray()) {
                count[c - 'a']++;
            }

            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < 26; i++) {
                sb.append('#');
                sb.append(count[i]);
            }

            String key = sb.toString();

            // System.out.println(key);
            if (!ansMap.containsKey(key)) {
                ansMap.put(key, new ArrayList<>());
            }
            ansMap.get(key).add(str);
        }

        return new ArrayList<>(ansMap.values());
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        String[] input = { "eat", "tea", "tan", "ate", "nat", "bat" };
        List<List<String>> result = sol.groupAnagrams(input);
        System.out.println(result);
        // Output: [[eat, tea, ate], [tan, nat], [bat]]
    }
}