#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEVEL 10
typedef unsigned char  bool;
#define true 1
#define false 0
typedef struct Node Node;

struct Node{
    int key;
    int value;
    Node *forward[1];  /*指向包含n个元素的数组*/
};

typedef struct skiplist skiplist;
struct skiplist{
    int level;
    Node *header;
};


/*每次对2取余，如果是1，上移， 如果是0，则在最低端增加即可*/
int randomLevel(){
    int k=0;
	while(rand()%2)
	    k++;
	printf("random is %d\n", k);
	k = k < MAX_LEVEL ? k : MAX_LEVEL;
	return k;
}

void printSL(skiplist *sl){
	Node *p, *q;
	int k=sl->level, i=0;
	for(i=k; i>=0; i--){
	    p = sl->header->forward[i];
		printf("level[%d]: ", i);
		while(p->forward[i] != NULL){
		   printf("%d -> ", p->value);
		   p = p->forward[i];
		}
		printf("%d\n", p->value);
	}
	printf("\n");
}


Node *create(int level, int key, int value){
    Node *node = (Node*)malloc(sizeof(Node) + level * sizeof(Node*));
	printf("Node: %x\n", node);
	node->key = key;
	node->value = value;
	return node;
}

skiplist *createSkipList(){
    int i=0;
    skiplist *sl = (skiplist*)malloc(sizeof(skiplist));
    sl->level = 0;
    sl->header = create(MAX_LEVEL, 0, 0);
    for(i=0; i<MAX_LEVEL; i++){
	   sl->header->forward[i] = NULL; /*虽然数组越界，由于申请的是连续内存，无所谓*/
    }
    return sl;
}

bool insert(skiplist* sl,int key,int value){  
    Node *update[MAX_LEVEL];  
    Node *p,*q;  
    p = sl->header;  
    int k = sl->level, i;  
	/*查找插入位置*/
    for(i = k ; i >=0 ; i --){  /*每一层遍历*/
        while(p->forward[i] != NULL && (p->forward[i]->key < key)){  
            p = p->forward[i];  
        }  
		/*设置update数组*/
        update[i] = p;  
    }  
    q = p->forward[0];  
    if(q && q->key == key){  
        return false;  
    }  
 

	/*随机生成一个层次*/
    k = randomLevel();  
    printf("NewLevel: %d, CurLevel: %d\n",k,sl->level);  
    if(k > sl->level){
	/*如果新生成的层次大于跳表的层次，则增加跳表的层次*/
        for(i = sl->level + 1 ; i <= k ; i ++)  
            update[i] = sl->header;  /*在update中将新增的层指向sl->header*/
        sl->level = k;  
    }  
  
/*生成层次个节点数组*/
    q = create(k,key,value);  
    for(i = 0 ; i <= k ; i ++){ 
		/*更新两个指针*/
        q->forward[i] = update[i]->forward[i];  
	printf("q->forward[%d]:%x\n",i,q->forward[i]);
        update[i]->forward[i] = q;  
    } 
/*
    for(i=0; i<=k ; i++){
        printf("%x\n",&q->forward[i]);
    }
    */
	/*已经插入完成*/
    printSL(sl);  
    return true;  
}  
  
bool delete(skiplist *sl,int key){  
    Node *update[MAX_LEVEL];  
    Node *p,*q;  
    p = sl->header;  
    int k = sl->level, i=0;  
    for(i = k ; i >=0 ; i --){  
        while(p->forward[i] != NULL && (p->forward[i]->key < key)){  
            p = p->forward[i];  
        }  
        update[i] = p;  
    }  
    q = p->forward[0];  
    if(q && q->key == key){  
        for(i = 0 ; i <= sl->level; i ++){  
            if(update[i]->forward[i] != q)  
                break;  
            update[i]->forward[i] = q->forward[i];  
        }  
        free(q);  
        for(i = sl->level ; i > 0 ; i --){  
            if(sl->header->forward[i] == NULL){  
                sl->level --;  
            }  
        }  
        return true;  
    }  
    else{  
        return false;  
    }  
}  
  
int search(skiplist *sl,int key){  
    Node *p,*q;  
    p = sl->header;  
    int k = sl->level, i=0;  
    for(i = k ; i >= 0 ; i --){  
        while((q = p->forward[i]) && q->key <= key){  
            if(q->key == key)  
                return q->value;  
            p = q;  
        }  
    }  
    return 0;  
} 


int main(){  
    int i=0;
    srand((int)time(0));  
    skiplist *sl=createSkipList(); 
    for(i=1;i<=1;i++)  
    {  
        bool a = insert(sl,i,i*3);  
    }  
    i=search(sl,10);  
    printSL(sl);  
    printf("i=%d\n",i);  
    bool b=delete(sl,10);  
    printSL(sl);  
    return 0;  
}  
