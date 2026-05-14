Preorder Traversal

// duyet tien thu tu (goc, trai, phai)
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    
    if (root == nullptr) return res;

    stack<TreeNode*> s;
    s.push(root);
    
    while (!s.empty()) {
        TreeNode* cur = s.top();
        s.pop();
        
        res.push_back(cur->data);
        
        // lifo -> day con ben phai vao truoc de lay ra cuoi cung
        if (cur->right != nullptr) {
            s.push(cur->right);
        }
        if (cur->left != nullptr) {
            s.push(cur->left);
        }
    }
    
    return res;
}
