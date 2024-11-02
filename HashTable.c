#include<stdio.h>
#include<stdlib.h>
#define NNODE 1<<20
#define ADDR_SIZE 8
#define ll long long
#define MOD
typedef struct node{
    int data;
    struct node *next;
}HASH;
int get_hash(ll x)
{

}
HASH **create_hash(){
    HASH **h = (HASH **)malloc(NNODE * ADDR_SIZE);
    for(int i=0; i<NNODE; i++){
        h[i] = (struct node *)malloc(sizeof(struct node));
        h[i]->next=NULL;
    }
    return h;
}
int insert_hash_table(HASH **h,int data){
    int key = 
}
int main(void){

}