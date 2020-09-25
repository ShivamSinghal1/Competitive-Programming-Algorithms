/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        unordered_set<int> st;
        int k=0,maxi=0;
        for(int i=0;i<size;i++){
            if(st.find(s[i])==st.end()){
                st.insert(s[i]);
                k++;
            }
            else{
                st.clear();
                st.insert(s[i]);
                maxi = max(maxi,k);
                k=1;
            }
        }
        maxi = max(maxi,k);
        return maxi;
    }
};
// @lc code=end

