/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
      string serialize(TreeNode *root)
{
    if(!root) return "";

    string s = "";

    queue<TreeNode*> q;

    q.push(root);

    while(!q.empty()){
        TreeNode* node = q.front();

        q.pop();

        if(node){
            s += to_string(node -> val) + ',';
            q.push(node -> left);
            q.push(node -> right);
        }
        else{
            s += "null,";
        }
    }
    cout<<s<<endl;
    return s;
}

// Decodes your encoded data to tree.
TreeNode *deserialize(string data)
{
    if(data.size() == 0) return NULL;

    vector<string>nodes;

    string temp;

    for(int i = 0; i < data.length(); i++){
        if(data[i] != ','){
            temp.push_back(data[i]);
        }
        else{
            nodes.push_back(temp);
            temp.clear();
        }
    }
    if(temp.length() != 0) nodes.push_back(temp);

   TreeNode* root = new TreeNode(stoi(nodes[0]));

   queue<TreeNode*> q;

   q.push(root);

   int i = 1;

   while(!q.empty()){
    TreeNode* curr = q.front();

    q.pop();

    if(nodes[i] != "null"){
        TreeNode* leftroot = new TreeNode(stoi(nodes[i]));

        curr -> left = leftroot;

        q.push(leftroot);
        i++;
    }
    else{
        i++;
    }
    if(nodes[i] != "null"){
        TreeNode* rightroot = new TreeNode(stoi(nodes[i]));

        curr -> right = rightroot;

        q.push(rightroot);
        i++;
    }
    else{
        i++;
    }
   }
   return root;

}
};



// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));