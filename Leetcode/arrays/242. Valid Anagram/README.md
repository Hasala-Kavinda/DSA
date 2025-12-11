# Contains Duplicate II

Problem: Given two strings `s` and `t`, return true if `t` is an anagram of `s`, and `false` otherwise.


## Examples

- Example 1:  
  - Input: `s = "anagram", t = "nagaram"`
  - Output: `true`

- Example 2
  - Input: `s = "rat", t = "car"`
  - Output: `false`

## Constraints
- 1 <= s.length, t.length <= 5 * 104
- s and t consist of lowercase English letters.

## Explanation / Approach
Created an array sized 26. if one word contains an letter, update its position by one in letters array.and if the other one contains
it subtract one form the array.Finally loop through the array and if one item is not zero return false.if all the items are 0s return true