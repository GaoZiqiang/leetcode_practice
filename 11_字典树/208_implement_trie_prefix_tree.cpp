/* leetcode T208: 实现 Trie (前缀树)
 * 原题链接：https://leetcode-cn.com/problems/implement-trie-prefix-tree/
 * */

/* 方法一：字典树
 *
 * 算法思想：参考https://leetcode-cn.com/problems/implement-trie-prefix-tree/solution/trie-tree-de-shi-xian-gua-he-chu-xue-zhe-by-huwt/
 *
 * 关键点：
 * 关键在于多叉树的理解
 *
 * 复杂度分析：
 * 时间复杂度：O(|S|)，插入或查询的字符串的长度，
 * 空间复杂度：O(|T|*26)，|T|为所有插入字符串的长度之和。
 * */

class Trie {
private:
    bool isEnd;
    Trie* next[26];

public:
    Trie() {
        isEnd = false;
        memset(next, 0, sizeof(next));
    }

    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            if (node->next[c-'a'] == nullptr) node->next[c-'a'] = new Trie();
            node = node->next[c-'a'];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        Trie* node = this;
        for (char c : word) {
            node = node->next[c-'a'];
            if (node == nullptr) return false;
        }
        return node->isEnd;
    }

    bool startsWith(string prefix) {
        Trie* node = this;
        for (char c : prefix) {
            node = node->next[c-'a'];
            if (node == nullptr) return false;
        }
        return true;
    }
};