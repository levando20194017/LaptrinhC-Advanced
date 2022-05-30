#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int key;
    Node* next;
    Node* prev;

    Node(int k){
        //printf("contructor of Node\n ");
        key = k; next = NULL; prev = NULL;
    }
};

typedef struct DoubleLinkedList{
    Node* first;
    Node* last;

    DoubleLinkedList(){
        printf("constructor\n");
        first = NULL; last = NULL;
    }
    void addLast(int k){
        Node* p = new Node(k);//(Node*)malloc(sizeof(Node));
        if(first == NULL && last == NULL){
            first = p; last = p; return;
        }
        last->next = p;
        p->prev = last;
        last = p;
    }
    void addFirst(int k){
        Node* p = new Node(k);
        if(first == NULL && last == NULL){
            first = p; last = p; return;
        }
        p->next = first;
        first->prev = p;
        first = p;
    }
    void insertAfter(int k, int k1){
        // tao 1 nut co key = k, chen vao sau nut co key = k1

    }
    void insertBefore(int k, int k1){
        // tao 1 nut co key = k, chen vao truoc nut co key = k1
    }
    void insertAtPosition(int k, int index){
        // tao 1 nut co key = k, chen vao vi tri thu index (tu trai qua phai)
        Node* p = first;
        int i = 1;
        while(i < index && p != NULL){
                p = p->next;
                i++;
        }
        if(i < index - 1){
            return;
        }
        Node* q = new Node(k);
        if(p == first){
            q->next = p;
            p->prev = q;
            first = q;
        }else if(p == NULL){
            // chen vao vi tri cuoi cung cua DS
            q->prev = last;
            last->next = q;
            last = q;
        }else{
            q->next = p;
            q->prev = p->prev;
            p->prev->next = q;
            p->prev = q;
        }
    }
    void remove(int k){
        Node* p = first;
        while(p != NULL){
            if(p->key == k) break;
            p = p->next;
        }
        if(p == NULL) return;
        if(p == first){
                first = p->next;
                first->prev = NULL;
                free(p);
                if(first == NULL) last = NULL;
        }else if(p == last){
                last = p->prev;
                last->next = NULL;
                free(p);
                if(last == NULL) first = NULL;
        }else{
                p->prev->next = p->next;
                p->next->prev = p->prev;
                free(p);
        }
    }
    void printLeft2Right(){
        Node* p;
        for(p = first; p != NULL; p = p->next){
            printf("%d ",p->key);
        }
        printf("\n");
    }
    void printRight2Left(){
        Node* p;
        for(p = last; p != NULL; p = p->prev){
            printf("%d ",p->key);
        }
        printf("\n");
    }
    void freeList(){
        Node* p = first;
        while(p != NULL){
            Node* np = p->next;
            free(p);
            p = np;
        }
    }
};
int main(){
    Node* p;
    printf("size of p = %d, size of Node = %d\n",sizeof(p),sizeof(Node));

    DoubleLinkedList L;
    for(int i = 1; i <= 10; i++){
        L.addLast(i);
    }
    L.insertAtPosition(11,1000);

    L.printLeft2Right();
    L.printRight2Left();

    L.freeList();
}
