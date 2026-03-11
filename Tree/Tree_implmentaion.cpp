#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

static int idx = -1;

Node* buildpreorder(const vector<int>& pre) {
    idx++;
    if (idx >= pre.size() || pre[idx] == -1)
        return NULL;

    Node* root = new Node(pre[idx]);
    root->left = buildpreorder(pre);
    root->right = buildpreorder(pre);
    return root;
}

void preordertraversal(Node* root){
    if(root == NULL){
        return;
    }
    cout<< root -> data << " " ;
    preordertraversal(root -> left);
    preordertraversal(root -> right);
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root -> left);
    cout << root -> data << ' ';
    inorder(root -> right);
}

void postorder(Node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<< root -> data << ' ';
}


void levelorder(Node* root){
    queue <Node*> q;
    q.push(root);
    while(q.size() > 0){
        Node* curr = q.front();
        q.pop();
        cout<< curr -> data << ' ';
        if(curr -> left != NULL){
            q.push(curr -> left);
        }
        if(curr -> right != NULL){
            q.push(curr -> right);
        }
    }
}

int sumofnode(Node* root){
    if(root == NULL){
        return 0;
    }
    int left = sumofnode(root -> left);
    int right = sumofnode(root -> right);
    int sum = 
}

int main() {
    vector<int> preorder = {1, 2, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* rootnode = buildpreorder(preorder);

    cout << "Root value: " << rootnode->data << endl;
    preordertraversal(rootnode);
    cout << endl;
    postorder(rootnode);
    cout << endl;
    inorder(rootnode);
    cout<< endl;
    levelorder(rootnode);

    return 0;
}
