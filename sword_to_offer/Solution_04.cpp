#include <iostream>
#include <vector>

using namespace std;

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        // 根据二叉树的前序和中序重建二叉树
        // 递归实现
        if (pre.size() < 1) {
            return NULL;
        }
        int root = pre[0];
        TreeNode *head = new TreeNode(root);
        vector<int> left_p;
        vector<int> left_r;
        vector<int>::const_iterator iter = vin.cbegin();
        int i = 1;    // pre的指针
        while (*iter != root) {
            left_r.push_back(*iter);
            left_p.push_back(pre[i++]);
            iter++;
        }
        head->left = reConstructBinaryTree(left_p, left_r);
        iter++;
        vector<int> right_p;
        vector<int> right_r;
        while (iter != vin.cend()) {
            right_p.push_back(pre[i++]);
            right_r.push_back(*iter);
            iter++;
        }
        head->right = reConstructBinaryTree(right_p, right_r);
        return head;
    }
};
