#include <stdio.h>
#include <stdlib.h>

struct Stack{
	int size;
	int top;
	int *S;
	
};

void create(struct Stack *st)
{
	printf("Enter Size");
	scanf("%d",&st->size);
	st->top=-1;
	st->S=(int *)malloc(st->size*sizeof(int));
}

void Display(struct Stack st)
{
	int a=st.top;
	for(int i=0;i<=a;i++){
		printf("%d ",st.S[st.top]);
		st.top--;
	}
	printf("\n");
}

void push(struct Stack *st,int x){
	if(st->top==st->size-1)
	printf("Stack overflow\n");
	else{   
		    st->top++;
			  st->S[st->top]=x;    
			}
}

int pop(struct Stack *st){
	int x=-1;
	if(st->top==-1)
	printf("Stack Underflow\n");
	else{
		  	x=st->S[st->top];
				st->top--;
			}
	return x;
}

int peek(struct Stack st,int pos){
	int x=-1;
	if(st.top-pos+1<0)
	printf("Invalid Index \n");
	else{
		x=st.S[st.top-pos+1];
	}
	return x;
}

int isEmpty(struct Stack st){
	if(st.top==-1){
		return 1;
	}
	return 0;
}

int isFull(struct Stack st){
	return st.top==st.size-1;
}

int stackTop(struct Stack st){
	if(!isEmpty(st))
	return st.S[st.top];
	return -1;
}

int main(){
	struct Stack st;
	create(&st);
	push(&st,10);
	push(&st,20);
	push(&st,30);
	push(&st,40);
	printf("%d \n",peek(st,2));
	pop(&st);
	Display(st);
	printf("%d\n",pop(&st));
	printf("%d\n",pop(&st));
	printf("%d\n",pop(&st));
	printf("%d\n",pop(&st));
	Display(st);
	return 0;
	
}