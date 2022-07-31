#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int search(int inorder[], int st, int en, int val){
    for(int i=st;i<=en;i++){
        if(inorder[i]==val){
            return i;
        }
    }
    return -1;
}

Node* buildtree(int inorder[], int postorder[], int st, int en){
    if(st>en){
        return NULL;
    }
    static int idx = en;
    int curr = postorder[idx];
    idx--;
     Node* node = new Node(curr);
    if(st==en){
        return node;
    }
    int pos = search(inorder,st,en,curr);
    node->right = buildtree(inorder,postorder,pos+1,en);
    node->left = buildtree(inorder,postorder,st,pos-1);
    return node;

}

void inorderprint(struct Node* root){
    if(root==NULL){
        return;
    }
    inorderprint(root->left);
    cout<<root->data<<" ";
    inorderprint(root->right);
}


int main(){
    int inorder[] = {4,2,1,5,3};
    int postorder[] = {4,2,5,3,1};
    Node* root =  buildtree(inorder,postorder,0,4);
    inorderprint(root);
    
}