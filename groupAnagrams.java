import java.util.*;
import java.io.*;
import java.math.*;

// https://leetcode.com/problems/group-anagrams/description/

/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
*/

class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        /*
         * -- get string from array of strings -- sort the string -> key -- if that key
         * is present in map, add string to that key -- if key is not present, create
         * new key and add the word
         */
        HashMap<String, ArrayList<String>> map = new HashMap<>();
        // List<List<String>> anagrams = new ArrayList<List<String>>();
        for (String s : strs) {
            char[] s_arr = s.toCharArray();
            Arrays.sort(s_arr);
            String s_key = new String(s_arr);
            if (map.containsKey(s_key)) {
                map.get(s_key).add(s);
            } else {
                ArrayList<String> li = new ArrayList<String>();
                li.add(s);
                map.put(s_key, li);
            }
        }
        return new ArrayList<List<String>>(map.values());
        // for(Map.Entry<String, ArrayList<String>> e : map.entrySet()) {
        // anagrams.add(e.getValue());
        // }
        // return anagrams;
    }
}

public class groupAnagrams {
    public static void main(String[] args) {
        Solution sln = new Solution();
        List<List<String>> li = sln.groupAnagrams(
                new String[] { "tna", "tar", "eat", "tea", "tan", "ate", "nat", "rat", "bat, tab", "eta" });
        System.out.println(li);
    }
}