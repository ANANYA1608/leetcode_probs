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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<long, int> m;
        for(int i=0;i<inorder.size();i++){
        m[inorder[i]] = i;
        }
        TreeNode* root= buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1, m) ;
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, int prestart, int preend, vector<int>& inorder, int instart, int inend ,map<long, int>& m ){
        if(prestart>preend || instart>inend)
        return NULL;
        TreeNode* root=new TreeNode(preorder[prestart]);
        int inroot=m[root->val];
        int nums=inroot - instart;
        root->left= buildTree(preorder,prestart + 1, prestart + nums, inorder, instart, inroot -1, m);
        root->right=buildTree(preorder,prestart + nums +1, preend, inorder, inroot +1, inend, m);
        return root;
    }
};