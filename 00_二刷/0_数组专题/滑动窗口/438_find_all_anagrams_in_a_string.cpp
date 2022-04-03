/* leetcode T438:Find All Anagrams in a String
 * 原题链接：https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/
 * */

/* 方法一：滑动窗口法
 *
 * 算法思想：
 * 两个指针维护滑动窗口之间各个元素出现的次数
 * 将其与基准字符串中各个元素的出现次数进行比较
 *
 * 时间复杂度：O(lp + (ls - lp)*26)：共需要比较ls-lp次，每次比较两个vector数组中的元素。
 * 空间复杂度：O(26)：数组。
 * */

vector<int> findAnagrams(string s, string p) {
    int ls = s.size(), lp = p.size();
    if (ls < lp)
        return {};
    vector<int> ans;
    vector<int> hashs(26);
    vector<int> hashp(26);
    for (int i = 0; i < lp; i++) {
        hashs[s[i] - 'a']++;
        hashp[s[i] - 'a']++;
    }
    if (hashs == hashp)
        ans.emplace_back(0);

    for (int i = 0; i < ls - lp; i++) {
        hashs[s[i] - 'a']--;
        hashs[s[i+lp] - 'a']++;
        if (hashs == hashp) {
            ans.emplace_back(i + 1);
        }
    }
    return ans;
}