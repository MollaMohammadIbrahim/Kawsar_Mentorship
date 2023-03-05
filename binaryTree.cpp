
// This code implements binary search tree, preorder traversal, postorder traversal and inorder traversal
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;

    Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinaryTree{
    public:
    Node *root;
    BinaryTree(){
        root = nullptr;
    }

    void addNode(int data){
        Node *newNode = new Node(data);

        if(root == nullptr){
            root = newNode;
            return;
        }

        else{
            Node *parent, *focus;
            focus = root;
            while (true)
            {
                parent = focus;
                if(focus->data >= data){
                    focus = focus->left;
                    if(focus==nullptr){
                        parent->left = newNode;
                        return;
                    }
                }else{
                    focus = focus->right;
                    if(focus==nullptr){
                        parent->right = newNode;
                        return;
                    }
                }
            }
        }
    }

    

    void preOrderTraversal(Node *current){
        if(current == nullptr)return;
        cout<<current->data<<" ";
        preOrderTraversal(current->left);
        preOrderTraversal(current->right);
    }

     void inOrderTraversal(Node *current){
        if(current == nullptr)return;
        preOrderTraversal(current->left);
        cout<<current->data<<" ";
        preOrderTraversal(current->right);
    }

     void postOrderTraversal(Node *current){
        if(current == nullptr)return;
        preOrderTraversal(current->left);
        preOrderTraversal(current->right);
        cout<<current->data<<" ";
    }

    
};



int main(){
    vector<int> arr = {50,25,75,12,37,43,30};
    BinaryTree tree;

    for(int i=0; i<arr.size() ; i++){
       tree.addNode(arr[i]); 
    }
    tree.preOrderTraversal(tree.root);
    cout<<endl;
    tree.inOrderTraversal(tree.root);
    cout<<endl;
    tree.postOrderTraversal(tree.root);
    cout<<endl;
}