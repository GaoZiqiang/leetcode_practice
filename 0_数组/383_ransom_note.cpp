/* leetcode T383:赎金信
 * 原题链接：https://leetcode-cn.com/problems/ransom-note/
 * */

/* 方法一：数组哈希表法
 *
 * 算法思想：参考242.有效的字母异位词 https://leetcode-cn.com/problems/valid-anagram/
 *
 * 复杂度分析：
 * 时间复杂度：O(n)，
 * 空间复杂度：O(n)，数组。
 * */

bool canConstruct(string ransomNote, string magazine) {
    int chs[26] = {0};

    for (char c : magazine) {
        chs[c - 'a']++;
    }

    for (char c : ransomNote) {
        chs[c - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (chs[i] < 0) {
            return false;
        }
    }

    return true;
}

// 优化版
bool canConstruct(string ransomNote, string magazine) {
    int chs[26] = {0};

    for (char c : magazine) {
        chs[c - 'a']++;
    }

    for (char c : ransomNote) {
        chs[c - 'a']--;
        if (chs[c - 'a'] < 0) {
            return false;
        }
    }

    return true;
}