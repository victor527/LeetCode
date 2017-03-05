/* LeetCode Problem 101

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

*/

class Solution{
public:
    int height(TreeNode* root){
        if(root == NULL)
            return 0;
        return max(height(root->right), height(root->left))+1;
    }

    bool isBalanced(TreeNode* root){
        if(root == NULL)
            return true;
        int right = height(root -> right);
        int left = height(root -> left);
        return abs(right - left) <= 1 && isBalanced(root -> right) && isBalanced(root -> left);
    }
}
