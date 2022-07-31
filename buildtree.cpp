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

Node* buildtree(int preorder[], int inorder[], int st, int en){
    static int idx = 0;
    if(st>en){
        return NULL;
    }
    int curr = preorder[idx];
    idx++;
    struct Node* node = new Node(curr);
    if(st==en){
        return node;
    }
    int pos = search(inorder,st,en,curr);
    node->left = buildtree(preorder,inorder,st,pos-1);
    node->right = buildtree(preorder,inorder,pos+1,en);
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
    int preorder[] = {1,2,4,3,5};
    int inorder[] = {4,2,1,5,3};
    Node* root = buildtree(preorder,inorder,0,4);
    inorderprint(root);
    

}