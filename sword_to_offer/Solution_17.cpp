#include <iostream>

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
private:
    bool isSame(TreeNode *p1, TreeNode *p2) {
        // 判断是否是p1的子树
        if (p2 == NULL) {
            return true;
        }
        if(p1 == NULL){
            return false;
        }

        if (p1->val == p2->val) { // 不为空
            return isSame(p1->left, p2->left) && isSame(p1->right, p2->right);
        }
        return false;
    }

public:
    bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2) {
        if (pRoot1 == NULL || pRoot2 == NULL) {
            // 空树不是任意子树
            return false;
        }
        return isSame(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
    }
};

int main(){
    TreeNode *p1 = new TreeNode(8);
    TreeNode *p2 = new TreeNode(8);
    p1->left = p2;
    TreeNode *p3 = new TreeNode(7);
    p1->right = p3;
    TreeNode *p4 = new TreeNode(9);
    p2->left = p4;
    TreeNode *p5 = new TreeNode(2);
    p2->right = p5;
    TreeNode *p6 = new TreeNode(4);
    p5->left = p6;
    TreeNode *p7 = new TreeNode(7);
    p5->right = p7;

    TreeNode *p8 = new TreeNode(8);
    TreeNode *p9 = new TreeNode(9);
    p8->left = p9;
    TreeNode *p10 = new TreeNode(2);
    p8->right = p10;

    Solution s;
    cout<< s.HasSubtree(p1,p8);
}