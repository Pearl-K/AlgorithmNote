#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100000;
int T;
char input[50][1001000];
char result[50][1001000];
char myAnswer[1001000];

typedef struct st{
    char alpha;
    struct st *next;
} NODE;

NODE HEAD[MAX];
NODE POOL[MAX];
int pcnt;

int tree[MAX*2];
int leafSize;
int start;
int idx = 1;

void showSegment(int size){
    for(int i=1; i <= size; i <<= 1){
        for(int j=i; j <= (i << 1)-1; j++){
            cout << tree[j] << "\n";
        }
    }
}

void insertNode(NODE *node, int headIdx, int insertIdx){
    NODE *curNode = &HEAD[headIdx];

    int curIdx = 1;
    while(true){
        if(insertIdx == curIdx){
            // 삽입하면서 포인터 변경하는 과정
            node -> next = curNode -> next;
            curNode -> next = node;

            return;
        }
    }
}

void deleteNode(int headIdx, int deleteIdx){
    NODE *curNode = &HEAD[headIdx];

    int curIdx = 1;
    while(true){
        if(deleteIdx == curIdx){
            curNode -> next = curNode->next->next;
            return;
        }

        curIdx++;
        curNode = curNode -> next;
    }

}

void update(int idx, int diff){
    idx += start;
    while(idx > 1){
        tree[idx] += diff;
        idx /= 2;
    }
}

void appendData(char data){
    NODE *node = &POOL[pcnt++];
    node -> alpha = data;

    update(idx, 1);

    node -> next = HEAD[idx].next;
    HEAD[idx].next = node;

    idx++;
}

void insertData(NODE *node, int idx){
    int treeIdx = 1;
    while(treeIdx < leafSize){
        if(idx <= tree[treeIdx << 1]) treeIdx <<= 1;
        else{
            idx -= tree[treeIdx << 1];
            treeIdx <<= 1;
            treeIdx++;
        }
    }

    insertNode(node, treeIdx-start, idx);
    update(treeIdx-start, 1);
}

void deleteData(int idx){
    int treeIdx = 1;
    while(treeIdx < leafSize){
        if(idx <= tree[treeIdx << 1]) treeIdx <<= 1;
        else{
            idx -= tree[treeIdx << 1];
            treeIdx <<= 1;
            treeIdx++;
        }
    }
    deleteNode(treeIdx-start, idx);
    update(treeIdx-start, -1);
}

void showData(int TC){
    int acnt = 0;
    for(int headIdx = 1; headIdx <= leafSize; headIdx++){
        for(NODE *p = HEAD[headIdx].next; p; p = p->next){
            myAnswer[acnt++] = p -> alpha;
        }
    }

    myAnswer[acnt]= 0;

    if(strcmp(myAnswer, result[TC]) == 0) cout << TC << "\n"; //pass
    else cout << TC << "\n"; //fail
}

int main(void){

    return 0;
}
