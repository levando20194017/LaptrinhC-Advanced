#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int value;
	Node* next;
}Node;
Node* head; 
void printlist(Node* p){
	while(p!=NULL){
		printf("%d", p->value);
		p=p->next;
		}
	}
Node* makeNode(int v){
	Node*q=(Node*)malloc(sizeof(Node));
	q->value=v;
	q->next=NULL;
	return q;
	}
Node* insertBeforrecursive(Node*h, int u, int v){
	if(h==NULL) return h;
	if(h->value==u){
		Node* q= makeNode(v);
		q->next=h;
		return q;
		}
	h->next=insertBeforrecursive(h->next,u,v);
	return h;
	}
Node* insertlast(Node*h, int v){
	Node*q=makeNode(v);
	Node*p=h;
	if(p==NULL) return q;
	while(p->next!=NULL){
		p=p->next;
		}
		p->next=q;
		return h;
	}
Node* freeList(Node*h){
	}
Node* insertafterrecursive(Node*h, int u, int v){
	if(h==NULL) return h;
	Node*p=h;
	if(p->value==u){
		Node*q=makeNode(v);
		q->next=p->next;
		p->next=q;
		return p;
		}
	h->next=insertafterrecursive(h->next,u,v);
	return h;
	}
Node* insertBefore(Node*h, int u, int v){
		Node*p=h;
	if(h==NULL) return h;
	if(h->value==u){
		Node*q=makeNode(v);
		q->next=h;
		return q;
		}
	 while(p->next->value != u){
        p = p->next;
		}
		if(p==NULL) return h;
		 Node* q = makeNode(v);
    q->next = p->next;
    p->next = q;
	return h;
	}
Node* remove(Node*h, int v){
	if (h == NULL) return h;
	if (h->value == v) 
	{
		h = h->next;
		return h;
	}
	Node* p = h;
	while (p->next != NULL)
	{
		if (p->next->value == v) break;
		p = p->next;
	}
	if (p->next != NULL)
	{
		p->next = p->next->next;
	}
	return h;
	}
Node* removerecursive(Node*h, int v){
	if(h==NULL) return h;
	Node*p=h;
	Node*pn;
	if(p->next->value==v){
		p->next=p->next->next;
		return p;
		}
	h->next=removerecursive(h->next,v);
	return h;
	}
int main(){
for(int v = 2; v <= 8; v++){
        head = insertlast(head,v);
    }
 //   head = insertBefore(head,5,6);
    printlist(head);
    head = removerecursive(head,5);
    printf("after remove: ");
    printlist(head);

    freeList(head);
	return 0;
	}
