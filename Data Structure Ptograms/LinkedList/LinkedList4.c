#include<stdio.h>
#include<stdlib.h>
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
//Middle element of a linked list
//Method-1
int Mid1(struct node* head){
    int len=0;
    struct node* current=head;
    while(current!=NULL){
        current=current->next;
        len++;
    }
    current=head;
    for(int i=1;i<=len/2;i++){
        current=current->next;
    }
    return current->data;

}
//Method-2
int Mid2(struct node* head){
    struct node* current=head,*middle=head;
    if(head!=NULL){
   while(current!=NULL && current->next!=NULL){
        current=current->next->next;
        middle=middle->next;
    }
    return middle->data;
}
}
//Method-3
int Mid3(struct node* head){
    int len=0;
    struct node* current=head;
    while(current!=NULL){
        current=current->next;
        len++;
    }
    current=head;
    for(int i=0;i<len;i++){
        if(i%2==0)
            continue;
        current=current->next;
    }
    return current->data;
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
     printf("\nMiddle element=%d",Mid1(head));
      printf("\nMiddle element=%d",Mid2(head));
       printf("\nMiddle element=%d",Mid3(head));
}





