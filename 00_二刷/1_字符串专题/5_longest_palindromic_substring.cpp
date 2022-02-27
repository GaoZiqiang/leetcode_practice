/* T5:最长回文子串 https://leetcode-cn.com/problems/longest-palindromic-substring/
 * 思路：https://app.yinxiang.com/Home.action?_sourcePage=kpFf1eZWmGfiMUD9T65RG_YvRLZ-1eYO3fqfqRu0fynRL_1nukNa4gH1t86pc1SP&__fp=PQ2S0ayPtXM3yWPvuidLz-TPR6I9Jhx8&login=true&username=gaoziqianghi%40163.com#n=fd8b5297-b384-4af5-adf9-22cf2af3e53a&s=s3&ses=4&sh=2&sds=5&
 * 方法：中心扩散法O(n*n)、动态规划法
 * */

string longestPalindrome(string s) {
    int subLen = 0, start = 0;
    for (int i = 0; i < s.size(); i++) {
        int curMax = max(getSubPalindromeLen(s, i, i), getSubPalindromeLen(s, i, i+1));
        if (curMax > subLen) {
            subLen = curMax;
            start = i - (curMax + 1) / 2 + 1;
        }
    }

    return s.substr(start, subLen);
}

// 找回文子串
int getSubPalindromeLen(string s, int l, int r) {
    while (l >= 0 && r < s.size() && s[l] == s[r]) {
        l--, r++;
    }
    return r - 1 - l - 1 + 1;
}