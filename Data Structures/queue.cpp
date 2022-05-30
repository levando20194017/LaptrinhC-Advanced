#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	Node* next;
	int id;
};
Node* head;
Node* makeNode(int v){
	Node*p=(Node*)malloc(sizeof(Node));
	p->id=v;
	p->next=NULL;
	return p;
	}
Node* push(Node*h,int v){
	if(h==NULL){
		h=makeNode(v);
		return h;
		}
	Node*p=h;
	while(p->next!=NULL){ p=p->next;}
	Node*q=makeNode(v);
	p->next=q;
	return h;
	}
Node* pop(){
	if(head==NULL) return NULL;
	printf("%d", head->id);
	head=head->next;
	return head;
	}
int size(){
	if(head==NULL) return 0;
	int s=1;
	Node*h=head;
	while(h->next!=NULL){
		s=s+1;
		h=h->next;
		}
		return s;
	}
int main(){
	for(int i=0;i<5;i++){
		head=push(head,i);
		}
		pop();
		pop();
			pop();
		pop();
		pop();
		printf("%d",size());
	return 0;
	}
