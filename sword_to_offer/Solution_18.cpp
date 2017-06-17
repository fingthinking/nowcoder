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
public:
    void Mirror(TreeNode *pRoot) {
        TreeNode *p;
        if(pRoot != NULL){
            p = pRoot->left;
            pRoot->left = pRoot->right;
            pRoot->right = p;
            Mirror(pRoot->left);
            Mirror(pRoot->right);
        }
    }
};