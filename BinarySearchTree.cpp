#include <sstream>
#include <iostream>
#define INPUT_LEN 100
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node* parent;
};

class BST {
public:
    enum travOrder {
        InOrder,
        PreOrder,
        PostOrder
    };
    
    BST();
    void Insert(int insert);
    void Delete(int del);
    void Print(enum travOrder);
    void In_order(Node *n);
    void Pre_order(Node *n);
    void Post_order(Node *n);
    void transplant(Node *a, Node *b);
private:
    Node* root;
 	Node* max(Node *n);
    Node* min(Node *n);
    Node* succ(Node *n);
    Node* search(int n);
};

BST::BST() {
    root = NULL;
}

void BST::Insert(int insert) {
    Node* a = NULL;         //temp
    Node* b = root;         //root node
    Node* c = new Node();
    
    c->val = insert;
    while(b != NULL) {
        a = b;
        if (b->val > insert)
            b = b->left;
        else
            b = b->right;
    }
    c->parent = a;
    if (a == NULL)
        root = c;
    else if (insert < a->val)
        a->left = c;
    else
        a->right = c;
}

void BST::Delete(int del) {
    Node* x = search(del);
    Node* y;
    if (x->left == NULL)
        transplant(x, x->right);
    else if (x->right == NULL)
        transplant(x, x->left);
    else {
        y = min(x->right);
        if (y->parent != x) {
            transplant(y, y->right);
            y->right = x->right;
            y->right->parent = y;
        }
        transplant(x,y);
        y->left = x->left;
        y->left->parent = y;
    }
}

void BST::transplant(Node *a, Node *b) {
    if (a->parent == NULL)
        root = b;
    else if (a == a->parent->left)
        a->parent->left = b;
    else
        a->parent->right = b;
    if (b != NULL)
        b->parent = a->parent;
}

Node* BST::succ(Node *x) {
    Node* suc;
    if (x->right == NULL)
        return min(x->right);
    suc = x->parent;
    while (suc != NULL && x == x->right) {
        x = suc;
        suc = suc->parent;
    }
    return suc;
}


Node* BST::min(Node *x) {
    while (x->left != NULL)
        x = x->left;
    return x;
}

Node *BST::max(Node *x) {
    while (x-> right != NULL)
        x = x-> right;
    return x;
}

Node *BST::search(int n) {
    Node* x = root;
    while (x != NULL & n != x->val) {
        if (n < x->val)
            x = x->left;
        else
            x = x->right;
    }
    return x;
}

void BST::Print(travOrder ord) {
    if(ord == InOrder)
        In_order(root);
    else if(ord == PreOrder)
        Pre_order(root);
    else if(ord == PostOrder)
        Post_order(root);
}

void BST::Pre_order(Node *a) {
    if (a != NULL) {
        cout << a-> val << endl;
        Pre_order(a->left);
        Pre_order(a->right);
    }
}

void BST::Post_order(Node *b) {
    if (b != NULL) {
        Post_order(b->left);
        Post_order(b->right);
        cout << b->val << endl;
    }
}

void BST::In_order(Node *c) {
    if (c != NULL) {
        In_order(c->left);
        cout << c->val << endl;
        In_order (c-> right);
    }
}

int main(int argc,char **argv) {
    BST bst;
    int key;
    char line[INPUT_LEN];

    while (std::cin.getline(line,INPUT_LEN)) {
        string str(line);
        if (str.size() == 0)
            continue;
        if (str[0] == 'e')
            return 1;
	
        if (str[0] == 'o') {
            if (str.substr(0,3) == "oin")
                bst.Print(BST::InOrder);
            else if (str.substr(0,4) == "opre")
                bst.Print (BST::PreOrder);
            else if (str.substr(0,5) == "opost")
                bst.Print(BST::PostOrder);
        }
        else {
            stringstream convert_stm(str.substr(1,str.size()-1));
            if (!(convert_stm >> key))
                key = -1;
            if (str.substr(0,1) == "i")
                bst.Insert(key);
            else if (str.substr(0,1) == "d")
                bst.Delete(key);
        }
    }
    return 0;
}

