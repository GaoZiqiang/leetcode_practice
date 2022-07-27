/* BM92 最长无重复子数组
 * 原题链接：https://www.nowcoder.com/practice/b56799ebfd684fb394bd315e89324fb4?tpId=295&tqId=1008889&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj
 * 滑动窗口+unordered_map
 * */

class Solution {
public:
    /**
     *
     * @param arr int整型vector the array
     * @return int整型
     */
    int maxLength(vector<int>& arr) {
        // write code here
        int n = arr.size();
        unordered_map<int, int> map;

        int ans = 0;
        int left = 0, right = 0;

        for (; right < n; right++) {
            // 窗口右移 元素计数+1
            map[arr[right]]++;
            // 出现次数>1 窗口内有重复元素
            while (map[arr[right]] > 1) map[arr[left++]]--;// 窗口左移 同时计数-1
            ans = max(ans, right- left + 1);
        }

        return ans;
    }
};