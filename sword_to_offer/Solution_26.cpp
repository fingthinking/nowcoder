#include <iostream>
#include <stack>

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
    /**
     * 转化左子树
     * @param root
     * @param parent
     * @return 左节点
     */
    TreeNode *convertLeft(TreeNode *root, TreeNode *parent){
        if(root == NULL){
            return NULL;
        }
        // 左子树的右节点一定指向父节点,因此先计算右子树
        TreeNode *right = convertRight(root->right,root);
        if(right!=NULL){
            right->right = parent;
        }else{
            right
        }
        TreeNode *left = convertLeft(root->left,root);
        if(left != NULL){
            left->right = parent;
        }else{
            left = root;
        }


    }

    /**
     * 转化右子树
     * @param root
     * @param parent
     * @return 又节点
     */
    TreeNode *convertRight(TreeNode *root, TreeNode *parent){

    }

public:
    TreeNode *Convert(TreeNode *pRootOfTree) {

    }


};

int main() {
    TreeNode *one = new TreeNode(1);
    TreeNode *two = new TreeNode(2);
    TreeNode *three = new TreeNode(3);
    TreeNode *four = new TreeNode(4);
    TreeNode *five = new TreeNode(5);

    four->left = two;
    four->right = five;
    two->left = one;
    two->right = three;

    Solution s;
    TreeNode *conv = s.Convert(four);
    while (conv != NULL) {
        cout << conv->val << " ";
        conv = conv->right;
    }
}