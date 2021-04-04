#include <stdio.h>
#include <stdlib.h>
#include "vectors.h"

#define CHILDREN_INIT_CAPACITY 6
#define UNDEFINE -1
#define SUCCESS 0

typedef struct node node;

struct node{
    int data;
    int numChildren;
    int childrenCapacity;
    node **children;
};

node * newNode(int data){
    node *temp = NULL;
    temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->numChildren = 0;
    temp->childrenCapacity = CHILDREN_INIT_CAPACITY;
    temp->children = NULL;
    temp->children=(int **)malloc(sizeof(node *) * CHILDREN_INIT_CAPACITY);
}

int childrenResize(node *parent, int capacity){
    int status = UNDEFINE;
    if(parent){
        int **children = realloc(parent->children, sizeof(node *) * capacity);
        if(children){
            parent->children = children;
            parent->childrenCapacity=capacity;
            status = SUCCESS;
        }
    }

    return status;
}

int addChild(node *parent, node *child){
    int status = UNDEFINE;
    if(parent){
        if(parent->numChildren == parent->childrenCapacity){
            status = childrenResize(parent, parent->childrenCapacity * 2);
            if(status != UNDEFINE){
                parent->children[parent->numChildren++] = child;
            }
        } else {
            parent->children[parent->numChildren++] = child;
            status = SUCCESS;
        }
    }
    
    return status;
}



int main(int argc, char const *argv[])
{
    
    return 0;
}
