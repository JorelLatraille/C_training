#include <stdio.h>
#include <stdlib.h>

#define LEN 4

typedef struct node_t
{
    void *val;
    struct node *next;
}node;

int main() {
    /* This won't change, or we would lose the list in memory */
    node *root;       
    /* This will point to each node as it traverses the list */
    node *walk;  

    root = malloc( sizeof(struct node) );  
    int init = 12;
    root->val = &init;
    walk = root;

    void **list = (void **)malloc(LEN * sizeof(void *));

    int *p1;
    int first = 1;
    p1 = &first;
    long *p2;
    long second = 42;
    p2 = &second;
    char *p3;
    char third = 'i';
    p3 = &third;
    double *p4;
    double fourth = 5.0;
    p4 = &fourth;

    // list[0] = &first;
    // list[1] = &second;
    // list[2] = &third;
    // list[3] = &fourth;

    // for (int count=0; count<LEN; count++){
    //     walk->next = malloc( sizeof(struct node) );
    //     walk = walk->next;
    //     walk->val = *list[count];
    // }

    for (int count=0; count<LEN; count++){
        walk->next = malloc( sizeof(struct node) );
        walk = walk->next;
        if (count == 0){
            walk->val = &first;
        }
        if (count == 1){
            walk->val = &second;
        }
        if (count == 2){
            walk->val = &third;
        }
        if (count == 3){
            walk->val = &fourth;
        }
        
    }

    walk = walk->next;
    walk->val = &init;
    walk = root;

    // while ( walk->next != NULL ) {
    //     printf( "Pointer: %p\n", walk->val );
    //     printf("Value: %d\n", (int)sizeof(*walk->val) );
    //     walk = walk->next;
    // }

    for (int count=0; count<=LEN; count++){
        printf( "Pointer: %p\n", walk->val );
        if (count == 0 | count == 1){
            int val;
            val = *walk->val;
            printf("Value: %d\n", val);
        }
        walk = walk->next;
    }    

    return 0;
}