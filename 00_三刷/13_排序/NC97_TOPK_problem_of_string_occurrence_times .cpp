/* NC97 字符串出现次数的TopK问题
 * 原题链接：https://www.nowcoder.com/practice/fd711bdfa0e840b381d7e1b82183b3ee?tpId=117&tqId=37809&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26pageSize%3D50%26search%3D97%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=undefined&tags=&title=97
 * */

// 方法一：sort函数（插入排序+快排）
class Solution {
public:
    /**
     * return topK string
     * @param strings string字符串vector strings
     * @param k int整型 the k
     * @return string字符串vector<vector<>>
     */
    static bool cmp(const pair<string, int>& p1, const pair<string, int>& p2) {
        return p1.second == p2.second ? p1.first < p2.first : p1.second > p2.second;
    }

    vector<vector<string> > topKstrings(vector<string>& strings, int k) {
        // write code here
        unordered_map<string, int> map;
        vector<pair<string, int>> vec;

        // 先统计各个字符串的出现次数
        for (auto& s : strings) map[s]++;
        // 数据类型转换umap-->vector
        for (auto [k, v] : map) vec.push_back({k, v});
        // 再进行排序
        sort(vec.begin(), vec.end(), cmp);

        // 统计前k元素
        vector<vector<string>> ans;
        for (int i = 0; i < k; i++) {
            vector<string> tmp = {vec[i].first, to_string(vec[i].second)};
            ans.push_back(tmp);
        }

        return ans;
    }
};

// 方法二：小根堆
class Solution {
public:
    /**
     * return topK string
     * @param strings string字符串vector strings
     * @param k int整型 the k
     * @return string字符串vector<vector<>>
     */
    // priority_queue的比较类
    struct que_cmp {
        bool operator() (const pair<string, int>& p1, const pair<string, int>& p2) {
            return cmp(p1, p2);
        }
    };// 结构体要加;

    static bool cmp (const pair<string, int>& p1, const pair<string, int>& p2) {
        return p1.second == p2.second ? p1.first < p2.first : p1.second > p2.second;
    }

    vector<vector<string> > topKstrings(vector<string>& strings, int k) {
        unordered_map<string, int> map;
        vector<pair<string, int>> vec;

        // 统计每个子串出现次数
        for (auto& s : strings) map[s]++;

        // 转存储到vector数组
        for (auto& [k, v] : map) vec.push_back({k, v});

        // 创建优先队列/小顶堆
        priority_queue<pair<string, int>, vector<pair<string, int>>, que_cmp> pque;
        for (auto& v : vec) {
            if (pque.size() < k) pque.push(v);
            else if (cmp(v, pque.top())) {
                pque.pop();
                pque.push(v);
            }
        }

        // 统计k个元素
        vector<vector<string>> ans;
        while (!pque.empty()) {
            pair<string, int> tmp = pque.top();
            pque.pop();
            ans.push_back({tmp.first, to_string(tmp.second)});
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};