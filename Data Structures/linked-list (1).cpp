#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    Node* next;
}Node;

Node* head;

void printList(Node* h){
    Node* p = h;
    while(p != NULL){
        printf("%d ",p->value);
        p = p->next;
    }
}
Node* makeNode(int v){
    Node*q = (Node*)malloc(sizeof(Node));// xin OS cap phat BN
    q->value = v;
    q->next = NULL;
    return q;
}
Node* insertLast(Node* h, int v){
    // them node co gia tri bang v vao cuoi DS co con tro dau la h
    Node* q = makeNode(v);
    Node* p = h;
    if(h == NULL){
        return q;
    }
    while(p->next != NULL){
        p = p->next;
    }
    p->next = q;
    return h;
}
Node* insertBeforeRecursive(Node* h, int v, int u){
    if(h==NULL) return h;
    if(h->value == u){
        Node* q= makeNode(v);
        q->next = h;
        return q;
    }
    h->next = insertBeforeRecursive(h->next,v,u);
    return h;
}
void freeList(Node* h){
    // TODO
}
Node * insertBefore(Node* h, int v, int u){
    // tao moi 1 phan tu co value = v, chen vao truoc phan tu co value = u
    // trong DS co con tro dau la h
    // tra ve con tro den dau DS thu duoc
    Node* p = h;
    if(h == NULL) return h;
    if(h->value == u){
        Node* q = makeNode(v);
        q->next = h;
        return q;
    }
    while(p->next != NULL){
        if(p->next->value == u) break;
        p = p->next;
    }
    if(p->next == NULL){
        return h;
    }
    Node* q = makeNode(v);
    q->next = p->next;
    p->next = q;
    return h;
}
Node* remove(Node* h, int u){
    // loai bo phan tu co value = u ra khoi DS con tro dau la h
    // tra ve con tro den dau DS thu duoc
    if(h == NULL) return h;
    if(h->value == u){
        Node* tmp = h->next;
        free(h);
        return tmp;
    }
    Node* p = h;
    while(p->next != NULL){
        if(p->next->value == u) break;
        p = p->next;
    }
    if(p->next == NULL) return h;
    Node* tmp = p->next;
    p->next = p->next->next;
    free(tmp);
    return h;
}
Node* removeRecursive(Node* h, int u){
    if(h == NULL) return h;
    if(h->value == u){
        Node* tmp = h->next;
        free(h);
        return tmp;
    }
    h->next = removeRecursive(h->next,u);
    return h;
}
int main(){
    for(int v = 1; v <= 5; v++){
        head = insertLast(head,v);
    }
    head = insertBeforeRecursive(head,6,5);
    printList(head);
    head = removeRecursive(head,5);
    printf("after remove: ");
    printList(head);

    freeList(head);
}
