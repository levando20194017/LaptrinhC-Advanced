#include<iostream>
using namespace std;
typedef struct Node{
	int id;
	Node* left;
	Node* right;
};
Node* root;
Node* makeNode(int v){
	Node*p= new Node;
	p->id=v;
	p->right=NULL;
	p->left=NULL;
	return p;
	}
Node* find(Node* r, int v){
    if(r == NULL) return NULL;
    if(r->id == v) return r;
    Node* p = r->left;
    while(p != NULL){
        Node* q = find(p,v);
        if(q != NULL) return q;
        p = p->right;
    }
    return NULL;
}
void insert(int u, int v){
    // tao 1 nut co id = v, chen vao cuoi DS nut con cua nut co id = u
    Node* p = find(root,u);
    if(p == NULL) return;
    Node* tmp = p->left;
    if(tmp == NULL){
        p->left = makeNode(v); return;
    }
    while(tmp->right != NULL) tmp = tmp->right;
    tmp->right = makeNode(v);
}
void printTree(Node* r){
	if(r==NULL) return;
	cout<<r->id<<": ";
	Node*p=r->left;
	if(p==NULL) return;
	cout<<p->id<<" ";
	Node* pp=p->right;
	while(pp!=NULL){
		cout<<pp->id<<" ";
		pp=pp->right;
		}
		while(p!=NULL){
		cout<<endl;
		printTree(p);
		p=p->right;
		}
		return;
	}
void preOder(Node* r){
	if(r==NULL) return;
	cout<<r->id<<" ";
	Node*p=r->left;
	while(p!=NULL){
		preOder(p);
		p=p->right;
		}
	}
void InOder(Node* r){
	if(r==NULL) return;
	Node*p=r->left;
	InOder(p);
	cout<<r->id;
	if(p!=NULL) p=p->right;
	while(p!=NULL){
		InOder(p);
		p=p->right;
		}
	}
void LastOder(Node* r){
	if(r==NULL) return;
	Node*p=r->left;
	while(p!=NULL){
		LastOder(p);
		p=p->right;
		}
		cout<<r->id;
	}
int countleaves(Node*r){
	int s=0;
	if(r==NULL) return 0;
	Node*p=r->left;
	if(p==NULL) return 1;
	while(p!=NULL){
		s=s+countleaves(p);
		r=r->right;
		}
		return s;
	}
int heightNode(Node*r){
	int max=0;
	if(r==NULL) return 0;
	Node*p=r->left;
	while(p!=NULL){
		int h=heightNode(p);
		if(h>max) max=h;
		p=p->right;
		}
		return max+1;
	}
int deft(Node*r, int u, int d){
	if(r==NULL) return -1;
	if(r->id==u) return d;
	Node*p=r->left;
	while(p!=NULL){
		if(p->id==u) return d+1;
		int dr=deft(p,u,d+1);
		if(dr>-1) return dr;
		p=p->right;
		}
		return -1;
	}
int height(int v){
	//tra ve do cao cua nut v;
	Node*p= find(root,v);
	return heightNode(p);
	}
int depth(int v){
	return deft(root, v, 1);
	}
Node* parent(Node*r, Node*q){
	if(r==NULL) return NULL;
	Node*p=r->left;
	if(p==q) return r;
	while(p!=NULL){
		Node*pp=parent(p,q);
		if(pp!=NULL) return pp;
		p=p->right;
		}
		return NULL;
	}
int main(){
	root=makeNode(10);
	insert(10,3);
	insert(10,7);
	insert(10,5);
	insert(3,2);
	insert(3,1);
	insert(7,11);
	//preOder(root);
	printTree(root);
	return 0;
	}
