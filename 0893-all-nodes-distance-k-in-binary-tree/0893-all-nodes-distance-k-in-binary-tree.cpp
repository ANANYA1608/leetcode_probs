/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void par(TreeNode* root,unordered_map<TreeNode*, TreeNode*> &parent, TreeNode* target ){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left){
                parent[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        par(root,parent,target);
        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target]=true;
        int dis=0;
        while(!q.empty()){
            int s=q.size();
            if(dis++ ==k)break;
            for(int i=0;i<s;i++){
            TreeNode* curr= q.front();
            q.pop();
            if(curr->left && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left]=true;
            }
            if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right]=true;
            }
            if(parent[curr] && !vis[parent[curr]]){
                    q.push(parent[curr]);
                    vis[parent[curr]]=true;
            }
            }

        }
        vector<int> res;
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            res.push_back(curr->val);
        }
        return res;

    }
};