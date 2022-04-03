/* leetcode T242:有效的字母异位词
 * 原题链接：https://leetcode-cn.com/problems/valid-anagram/
 * */

/* 方法一：暴力遍历法
 *
 * 算法思想：
 * 关键点：
 * 1 字符转换为int数字 c - 'a'
 * 2 用普通数组记录每个字符出现的次数-->不需要用麻烦的map
 * 3 第一次对数组进行加+，第二次对数组进行减-
 *
 * 复杂度分析：
 * 时间复杂度：O(n)
 * 空间复杂度：O(26/1)，数组。
 * */

bool isAnagram(string s, string t) {
    int record[26] = {0};

    // 计数
    for (auto& x : s)
        record[x - 'a']++;
    for (auto& x : t)
        record[x - 'a']--;// 巧妙的方法

    for (int i = 0; i < 26; i++)
        if (record[i] != 0)
            return false;

    return true;
}