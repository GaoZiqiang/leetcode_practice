/* T3:无重复字符的最长子串 https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
 * 思路：https://app.yinxiang.com/Home.action?_sourcePage=kpFf1eZWmGfiMUD9T65RG_YvRLZ-1eYO3fqfqRu0fynRL_1nukNa4gH1t86pc1SP&__fp=PQ2S0ayPtXM3yWPvuidLz-TPR6I9Jhx8&login=true&username=gaoziqianghi%40163.com#n=fd8b5297-b384-4af5-adf9-22cf2af3e53a&s=s3&ses=4&sh=2&sds=5&
 *
 * */

int lengthOfLongestSubstring(string s) {
    int ans = 0;
    unordered_map<char, int> sm;
    int start = 0;
    for (int end = 0; end < s.size(); end++) {
        sm[s[end]]++;
        while (sm[s[end]] >1) {
            sm[s[start]]--;// i往后走一步，对应的sm值减一
            start++;
        }
        ans = max(ans, end - start + 1);
    }
    return ans;
}