// Satvik Choudhary
// 111601021

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Node is the element of the stack
struct Node{
    struct Node* next; // Pointer to the next element in stack
    char data; // data in the node
};

struct Stack{
    struct Node* top; // The top element of the stack
    int size; // Size of the stack
};

typedef struct Stack* stack; // typedef for shortening the name to a more convenient one.

stack createStack(); // manually allocates a new stack struct
void stackPush(stack* stk, char x); // Push a new element on top of the stack
char stackPop(stack* stk); // Popping an element from top of the stack
int stackIsEmpty(stack stk); // Checking if stack is empty
int stackSize(stack stk); // Returns stack size
void print(stack* stk); // Prints the elements in the stack using stackPop.
char stackTop(stack stk); // returns the top element of the stack.
void printv(stack stk){
	struct Node* temp = stk->top;
	printf(" Start - ");
	while(temp != NULL){
		printf("%c ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
int main(){
    stack stk = createStack(); // new element is created.
    char a[50], ans[50];
    scanf("%s", a);
    int i = 0;
    int pre[128];
    for(i = 0; i<128; i++) pre[i] = -1;
    pre['*'] = 10; pre['+'] = 5; pre['-'] = 5; pre['='] = 0;
    int assoc[128];
    assoc['+'] = assoc['-'] = assoc['*'] = 1; assoc['='] = 0;
    for(i =0; i<strlen(a); i++){
        if(a[i]>='0' && a[i] <='9') printf("%c", a[i]);
        else{
            if(stackIsEmpty(stk) || stackTop(stk) == '(') stackPush(&stk, a[i]);
            else if(a[i] == '(') stackPush(&stk, a[i]);
            else if(a[i] == ')') print(&stk);
            else if(pre[a[i]] > pre[stackTop(stk)]) stackPush(&stk, a[i]);
            else if(pre[a[i]] == pre[stackTop(stk)]){
                if(assoc[a[i]]) printf("%c", stackPop(&stk));
                stackPush(&stk, a[i]);
            }
            else{
            	while(!stackIsEmpty(stk) && pre[stackTop(stk)] != -1 && pre[a[i]] <= pre[stackTop(stk)]) printf("%c", stackPop(&stk));
				stackPush(&stk, a[i]);
			} 
            if(!stackIsEmpty(stk) && stackTop(stk) == ')') print(&stk);
            //printv(stk);
			//printf(" %d ", i);
        }
    }
    print(&stk);
    return 0;
}

void print(stack* stk){
    if(!stackIsEmpty(*stk) && stackTop(*stk) == ')') stackPop(stk);
    while(!stackIsEmpty(*stk) && stackTop(*stk) != '('){
        printf("%c", stackPop(stk));
    }
    if(!stackIsEmpty(*stk) && stackTop(*stk) == '(') stackPop(stk);
}
stack createStack(){
    stack new1 = (stack) malloc (sizeof(stack));
    new1->top = NULL;
    new1->size = 0;
    return new1;
}
void stackPush(stack* stk, char x){
    struct Node* new1 = (struct Node*) malloc (sizeof(struct Node*));
    new1->data = x;
    new1->next = (*stk)->top;
    (*stk)->top = new1;
    (*stk)->size += 1;
}
char stackPop(stack* stk){
    static char b; // Because returning outside of the function
    b = -1;
    if((*stk)->size == 0){
        printf("The stack is empty. Cannot pop!\n");
    }
    else {
        struct Node* temp = (*stk)->top;
        b = temp->data;
        (*stk)->top = (*stk)->top->next;
        (*stk)->size -= 1;
        free(temp);
    }
    return b;
}
int stackIsEmpty(stack stk){
    if(stk->size == 0) return 1;
    return 0;
}
int stackSize(stack stk){
    return stk->size;
}
char stackTop(stack stk){
    return stk->top->data;
}
