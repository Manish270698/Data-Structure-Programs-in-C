#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
struct node{
int data;
struct node *next;
};
//insert at top
void push(struct node* *head_ref,int info){
    struct node* temp= (struct node*)malloc(sizeof(struct node));
    temp->data=info;
    temp->next=*head_ref;
    *head_ref=temp;
    return;
}
//insert at end
void append(struct node* *head_ref,int info){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=info;
    temp->next=NULL;
    struct node* last=*head_ref;
    if(*head_ref==NULL){
        *head_ref=temp;
        return;
    }
    while(last->next!=NULL){
        last=last->next;
    }
    last->next=temp;
    return;
}
//insert at middle
void insert(struct node* prev_node, int info){
    if(prev_node==NULL){
            printf("prev_node can't be null/n");
            return;
        }
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=info;
    temp->next=prev_node->next;
    prev_node->next=temp;
    return;
}
//searching a node iterative
bool searchIterative(struct node* head,int key){
    struct node* current=head;
    while(current!=NULL){
        if(current->data==key){
           return true;
           }
        current=current->next;
    }
    return false;
}
//searching a node recursive
bool searchRecursive(struct node* head, int key){
    if(head==NULL){
        return false;
    }
    if(head->data==key){
        return true;
    }

     return searchRecursive(head->next,key);
}
//Get nth node in a linked list
int getNth(struct node* head,int key){
    if(head==NULL){
        printf("Empty list");
    }
    struct node* current=head;
    while(key>1 && current!=NULL){
        current=current->next;
        key--;
    }
    if(current !=NULL){
    return current->data;
    }
    else
        assert(0);

}
//nth node recursive
int getNthRec(struct node* head, int key){
    int count=1;

    if(count==key)
        return head->data;

    return getNthRec(head->next,key-1);
}
//Nth node from end using length
void NthnodefromEnd1(struct node* head,int key){
    int len=0;
    struct node* current=head;
    while(current!=NULL){
        len++;
        current=current->next;
    }
    if(key>len){
        return;
    }
    current=head;
    for(int i=1;i<len-key+1;i++){
        current=current->next;
    }
    printf("\n%d",current->data);
}
//Nth node from end using pointers
void NthnodefromEndP(struct node* head,int key){
    int len=0;
    struct node* main=head,*reference=head;
    while(main!=NULL){
        len++;
        main=main->next;
    }
    if(key>len){return;}
    main=head;

    for(int i=1;i<=key;i++){
        reference=reference->next;
    }
    while(reference!=NULL){
        reference=reference->next;
        main=main->next;
    }
    printf("\n%d",main->data);

}
void print_list(struct node* head)
{
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
}
void main(){
    struct node* head=NULL;
     append(&head,6);
     push(&head,7);
     push(&head,1);
     push(&head,5);
     append(&head,4);
     insert(head->next,8);
     printf("Current list is: ");
     print_list(head);
     searchIterative(head, 8)?printf("\nYes"):printf("\nNo");
      searchRecursive(head, 5)?printf("\nYes"):printf("\nNo");
      printf("\n%d",getNth(head,1));
      printf("\n%d",getNthRec(head,2));
      NthnodefromEnd1(head,2);
      NthnodefromEndP(head,1);
}

