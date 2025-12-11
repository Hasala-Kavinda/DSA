class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length())
            return false;

        int[] letters = new int[26];

        for (int i = 0; i < s.length(); i++) {
            letters[s.charAt(i) - 'a']++;
            letters[t.charAt(i) - 'a']--;
        }

        for (int i : letters) {
            if (i != 0) {
                return false;
            }
        }
        return true;

    }

    public static void main(String args[]) {

        Solution sol = new Solution();

        String a = "\"anagram\"";
        String b = "\"nagaram\"";

        System.out.println("Output: " + sol.isAnagram(a, b));
    }
}