# Contains Duplicate II

Problem: Given an array of strings strs, group the anagrams together. You can return the answer in any order.


## Examples

- Example 1:  
  - Input: `strs = ["eat","tea","tan","ate","nat","bat"]`
  - Output: `[["bat"],["nat","tan"],["ate","eat","tea"]]`


## Constraints
- 1 <= strs.length <= 104
- 0 <= strs[i].length <= 100
- strs[i] consists of lowercase English letters.

## Explanation / Approach
Created an array sized 26. if one word contains an letter, update its position by one in letters array.And then add that to the hashmap with key 
generated with StringBuilder.then try to do the same for the other strings and make the hashmap and return it.