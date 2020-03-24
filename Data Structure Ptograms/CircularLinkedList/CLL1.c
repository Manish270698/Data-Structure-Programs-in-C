#include<stdio.h>
#includde<stdlib.h>
struct node{
int data;
struct node*next;
};
//Addition at top of linked list
void push(struct node* *head_ref,int info){
struct node* current=(struct node*)malloc(sizeof(struct node));
struct node* temp=*head_ref;
current->data=info;
current->next=*head_ref;

if(*head_ref==NULL)
    current->next=*head_ref;

    else{
        while(temp->next!=*head_ref)
            temp=temp->next;

        temp->next=current;
    }

    *head_ref=current;
}
}
//Traversing Circular Linked List
void traverse(struct node* first){

}
