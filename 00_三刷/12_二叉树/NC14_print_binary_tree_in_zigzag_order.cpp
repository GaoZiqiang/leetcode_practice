/* NC14 按之字形顺序打印二叉树
 * 原题链接：https://www.nowcoder.com/practice/91b69814117f4e8097390d107d2efbe0?tpId=117&tqId=37722&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=undefined&tags=&title=
 * 参考题解：https://www.nowcoder.com/practice/91b69814117f4e8097390d107d2efbe0?tpId=117&tqId=37722&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=undefined&tags=&title=
 * */

#include <queue>
#include <vector>

using namespace std;

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        if (!pRoot) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> que;
        que.push(pRoot);
        int level = 0;

        while (!que.empty()) {
            vector<int> tmp;
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* top = que.front();
                que.pop();

                // 左右孩子入队(先左再右)
                if (top->left) que.push(top->left);
                if (top->right) que.push(top->right);

                // 打印输出top元素
                if (level % 2 == 0) {
                    // 从左到右
                    tmp.push_back(top->val);
                } else {
                    // 头插vector数组
                    tmp.insert(tmp.begin(), top->val);
                }
            }
            // 层数加1
            level++;
            ans.push_back(tmp);
        }
        return ans;
    }
};