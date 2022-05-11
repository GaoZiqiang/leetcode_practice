/* leetcode T455:分发饼干
 * 原题链接：https://leetcode-cn.com/problems/assign-cookies/
 * */

#include <vector>
#include <algorithm>
#include <stdio.h>

/* 方法一：排序 + 贪心
 *
 * 算法思想：
 * 核心思想：先满足胃口最小的孩子，且用最小的饼干
 * 为了尽可能满足最多数量的孩子，从贪心的角度考虑，应该按照孩子的胃口从小到大的顺序依次满足每个孩子，
 * 且对于每个孩子，应该选择可以满足这个孩子的胃口且尺寸最小的饼干。
 *
 * 因为饥饿度最小的孩子最容易吃饱,所以我们先考虑这个孩子。为了尽量使得剩下的饼干可
 * 以满足饥饿度更大的孩子,所以我们应该把大于等于这个孩子饥饿度的、且大小最小的饼干给这
 * 个孩子。满足了这个孩子之后,我们采取同样的策略,考虑剩下孩子里饥饿度最小的孩子,直到
 * 没有满足条件的饼干存在。
 *
 * 简而言之,这里的贪心策略是,给剩余孩子里最小饥饿度的孩子分配最小的能饱腹的饼干。
 * 至于具体实现,因为我们需要获得大小关系,一个便捷的方法就是把孩子和饼干分别排序。
 * 这样我们就可以从饥饿度最小的孩子和大小最小的饼干出发,计算有多少个对子可以满足条件。
 *
 * 复杂度分析：
 * 时间复杂度：O(mlogm+nlogn)，两数组排序的时间复杂度分别为O(mlogm)和O(nlogn)，
 * 遍历数组的复杂度O(m+n)-->总的时间复杂度为O(mlogm+nlogn)；
 * 空间复杂度：O(logm+logn)，主要为排序的空间开销；
 * */

using namespace std;

int findContentChildren(vector<int> & children, vector<int> & cookies) {
    sort(children.begin(), children.end());
    sort(cookies.begin(), cookies.end());

    int child = 0, cookie = 0;
    while (child < children.size() && cookie < cookies.size()) {
        if (cookies[cookie] >= children[child]) ++child;
        ++cookie;
    }

    return child;
}

/*我的实现*/
int findContentChildren2(vector<int> kids, vector<int> cookies) {
    sort(kids.begin(),kids.end());
    sort(cookies.begin(),cookies.end());

    int kids_size = kids.size(), cookies_size = cookies.size();
    int i = 0, j = 0;

    // 易错点：如果不加&& j < cookies_size，
    // 当while (j < cookies_size)完成时，i就不再++了，此时while(i<kids_size)就会陷入死循环
    while (i < kids_size && j < cookies_size) {
        while (j < cookies_size) {
            if (cookies[j] >= kids[i]) {
                i++;
                j++;// j的下一次循环从当前j的j+1开始，不必从0开始-->整个算法只需要遍历kids_size+cookies_size次
                break;
            }
            j++;
        }
    }

    return i;
}


// 解法三
int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end()), sort(s.begin(), s.end());

    int m = g.size(), n = s.size();
    int ans = 0;

    for (int i = 0, j = 0; i < m && j < n; i++, j++) {
        while (j < n && g[i] > s[j]) j++;// 找第一个比g[i]大的s[j]
        if (j < n) ans++;
    }

    return ans;
}

int main() {
    vector<int> children = {1,2};
    vector<int> cookies = {1,2,3};
    int num = findContentChildren2(children, cookies);
    printf("num: %d\n",num);
}