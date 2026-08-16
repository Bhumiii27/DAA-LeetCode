/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0)
            return NULL;

        int rootValue = postorder.back();
        postorder.pop_back();

        TreeNode* root = new TreeNode(rootValue);

        int i=0;
        while(inorder[i]!=rootValue)
            i++;

        vector<int> rightIn(inorder.begin()+i+1, inorder.end());
        vector<int> leftIn(inorder.begin(), inorder.begin()+i);

        root->right = buildTree(rightIn, postorder);
        root->left = buildTree(leftIn, postorder);

        return root;        
    }
};