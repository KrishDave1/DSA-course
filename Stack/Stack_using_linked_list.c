#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int data;
    struct stack *next;
}stu;

void push(stu **head,int x){
    stu *t=(stu*)(malloc(sizeof(stu)));
    if (t==NULL){
        printf("Stack overflow\n");
    }
    else{
        t->data=x;
        t->next=*head;
        *head=t;
    }
}

int pop(stu **head){
    stu *t=(stu*)(malloc(sizeof(stu)));
    int x=-1;
    if (*head==NULL){
        printf("Empty stack\n");
    }
    else{
        t=*head;
        *head=t->next;
        x=t->data;
        free(t);
    }
    return x;
}

void Display(stu *head){
    stu *t=head;
    while(t!=NULL){
        printf("%d ",t->data);
        t=t->next;
    }
    printf("\n");
}

int peek(stu *head,int index){
    stu *t=head;
    if (head==NULL){
        return -1;
    }
    else{
        for(int i=0;i<index-1 && t!=NULL;i++){
            t=t->next;
        }
        if (t!=NULL){
            return t->data;
        }
        else{
            return -1;
        }
    }
}
int main(){
    stu *head=NULL;
    push(&head,10);
    push(&head,20);
    push(&head,30);
    push(&head,40);
    push(&head,50);
    Display(head);
    printf("%d \n",peek(head,3));
    printf("%d \n",pop(&head));
    printf("%d \n",pop(&head));
    printf("%d \n",pop(&head));
    Display(head);
    printf("%d \n",pop(&head));    
    printf("%d \n",pop(&head));    
    printf("%d \n",pop(&head));
    Display(head);

}