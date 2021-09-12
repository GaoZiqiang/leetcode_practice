/* leetcode T763:划分字母区间
 * 原题链接：https://leetcode-cn.com/problems/partition-labels/
 * */

#include <vector>
#include <string>

/* 方法一：贪心
 *
 * 算法思想：
 * 第一步得到每个字母的最大下标--转化为贪心问题；第二步划分字符片段。
 * 在得到每个字母最后一次出现的下标位置之后，可以使用贪心的方法将字符串划分为尽可能多的片段，
 * 具体做法如下。
 *
 * 1 从左到右遍历字符串,遍历的同时维护当前片段的开始下标start和结束下标end,初始时start=end=0;
 * 2 对于每个访问到的字母c，得到当前字母的最后一次出现的下标位置end_c,则当前片段的结束下标
 * 一定不会小于end_c,因此令end = max(end,end_c);
 * 3 当访问到下标end时,当前片段访问结束,当前片段的下标范围是[start,end],长度为end−start+1,
 * 将当前片段的长度添加到返回值,然后令start = end + 1,继续寻找下一个片段;
 * 4 重复上述过程,直到遍历完字符串。
 *
 * 每个片段尽可能短,则可保证字符串尽可能多。
 * 复杂度分析：
 * 时间复杂度：O(n)，n为字符串长度；
 * 空间复杂度：O(26)，last[26]数组存放26个字母的最大下标；
 * */

using namespace std;

vector<int> partitionLables(string s) {
    int len = s.size();// 字符串长度

    // 确定每个字母的最大下标
    int last[26];// 存放每个字母的最大下标
    for (int i = 0; i < len; i++)
        last[s[i] - 'a'] = i;// last[]逐渐更新，最后得到字母最大下标

    // 划分字符片段
    vector<int> partition;
    int start = 0, end = 0;
    for (int i = 0; i < len; i++) {
        end = max(end, last[s[i] - 'a']);
        if (i == end) {
            partition.push_back(end - start + 1);// 存放字符判断的长度
            start = end + 1;// 更新start，用于end - start + 1
        }
    }

    return partition;
}

int main() {
    string S = "ababcbacadefegdehijhklij";
    vector<int> partition = partitionLables(S);
    for (int i = 0; i < partition.size(); i++)
        printf("%d ", partition[i]);
}