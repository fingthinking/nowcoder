#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    // 广度优先遍历
    vector<int> PrintFromTopToBottom(TreeNode *root) {
        // 通过队列实现二叉树的遍历
        vector<int> scan;
        queue<TreeNode *> que;
        if (root != NULL) {
            que.push(root);
            while (!que.empty()) {
                TreeNode *node = que.front();
                que.pop();
                scan.push_back(node->val);
                if (node->left != NULL) {
                    que.push(node->left);
                }
                if (node->right != NULL) {
                    que.push(node->right);
                }
            }
        }
        return scan;
    }
};

int main() {
    TreeNode *one = new TreeNode(1);
    TreeNode *sec_l = new TreeNode(2);
    TreeNode *sec_r = new TreeNode(3);
    TreeNode *thr_l = new TreeNode(4);
    TreeNode *thr_r = new TreeNode(5);
    one->left = sec_l;
    one->right = sec_r;
    sec_l->left = thr_l;
    sec_r->right = thr_r;
    Solution s;
    vector<int> vec = s.PrintFromTopToBottom(one);
    for(auto v = vec.cbegin(); v != vec.cend(); v++){
        cout<<*v<<" ";
    }
}