#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct Node{
	int value;
	Node* next;
};
Node* head;
Node* makeNode(int v){
	Node*q=(Node*)malloc(sizeof(Node));
	q->value=v;
	q->next=NULL;
	return q;
}
Node* insertLast(Node*h, int v){
	Node*q= makeNode(v);
	Node*p=h;
	if(h==NULL){ return q;}
	
	while(p->next!=NULL){
		p=p->next;
	}
	p->next=q;
	return h;
}

void print(Node* h){
	Node*p=h;
	if(h==NULL) return;
	while(p!=NULL){
		cout<<p->value;
		p=p->next;
	}
}
Node* insertBefore(Node*h, int u, int v){
	Node*q=makeNode(v);
	Node*p=h;
	if(h==NULL){ return NULL;}
	if(h->value==u){
		q->next=h;
		return 	q;
		}
	if(p->next==NULL){
		return h;
		}
	while(p->next!=NULL){
		if(p->next->value==u) break;
		p=p->next;
		}
	q->next=p->next;
	p->next=q;
	return h;
	}
Node* insertBeforerecursive(Node*h, int u, int v){
	Node*q= makeNode(v);
	if(h==NULL){
		return h;
		}
	if(h->value==u){
		q->next=h;
		return q;
		}
	if(h->next->value==u){
		Node*p=h;
		q->next=p->next;
		p->next=q;
		return p;
		}
	h->next=insertBeforerecursive(h->next,u,v);
	return h;
	}
Node* remove(Node*h, int u){
	if(h==NULL){
		return h;
		}
	if(h->value==u){
		h=h->next;
		return h;
		}
	Node*p=h;
	while(p->next!=NULL){
		if(p->next->value==u) break;
		p=p->next;
		}
		if(p->next==NULL) return h;
		p->next=p->next->next;
		return h;
	}
Node* removerecursive(Node*h, int u){
	if(h==NULL) return h;
	if(h->value==u){
		h=h->next;
		return h;
	}
	Node*p=h;
	while(p->next!=NULL){
		if(p->next->value==u) break;
		p=p->next;
		}
		if(p->next==NULL) return h;
		p->next=p->next->next;
		h->next=removerecursive(h->next, u);
		return h;
		}
//Node* insertLastrecursive(Node*h, int v){
//	Node*q=makeNode(v);
//	Node*p=h;
//	if(p->next==NULL){
//		p->next=q;
//		return p;
//		}
//	insertLastrecursive(h->next, v);
//	}
int main(){
	for(int v=1;v<5;v++){
		head=insertLast(head, v);
		}
		insertBeforerecursive(head,4,6);
		removerecursive(head,0);
	print(head);
	return 0;
}

