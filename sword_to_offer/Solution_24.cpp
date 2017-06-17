#include <iostream>
#include <vector>

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
    vector<vector<int>> vec;
    vector<int> mv;
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root != NULL){
            mv.push_back(root->val);
            // 找到了
            if(root->val == expectNumber && root->left == NULL && root->right == NULL){
                vec.push_back(vector<int>{mv});
            }

            // 小于,则去子树中找
            if(root->val < expectNumber){
                FindPath(root->left, expectNumber-root->val);
                FindPath(root->right, expectNumber-root->val);
            }
            mv.pop_back();
        }
        return vec;
    }
};