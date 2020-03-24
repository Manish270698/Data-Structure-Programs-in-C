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
//Floyd's Cycle finding algorithm
void detectLoop(struct node* head)
{
    struct node* fast_ptr=head, *slow_ptr=head;
    while(fast_ptr && fast_ptr->next && slow_ptr){
        slow_ptr=slow_ptr->next;
        fast_ptr=fast_ptr->next->next;
        if(slow_ptr==fast_ptr){
            printf("\nLoop");
            break;
        }
    }
    if(!(fast_ptr && fast_ptr->next && slow_ptr)){return;}
    //Length of loop
    int count=1;
    while(slow_ptr->next!=fast_ptr){
        count++;
        slow_ptr=slow_ptr->next;
    }
    printf("\nLength of loop=%d",count);
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
     append(&head,4);
     insert(head->next,8);
     printf("Current list is: ");
     print_list(head);
    head->next->next->next->next->next=head->next;
     detectLoop(head);
}
