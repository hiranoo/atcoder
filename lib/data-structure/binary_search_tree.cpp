#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <bitset>
#define rep(i, s, t) for(int i = (s); i <= (t); i++)
#define repd(i, s, t) for(int i = (s); i >= (t); i--)
using namespace std;

struct node {
    int val;
    node *lch, *rch;
};

node* insert(node* p, int x){
    if(p == NULL){
        node* q = new node;
        q->val = x;
        q->lch = q->rch = NULL;
        return q;
    }else{
        if(x < p->val) p->lch = insert(p->lch, x);
        else p->rch = insert(p->rch, x);
        return p;
    }
}

bool find(node* p, int x){
    if(p == NULL) return false;
    else{
        if(x < p->lch) return find(p->lch, x);
        else if(x > p->lch) return find(p->rch, x);
        else return true;
    }
}

node* remove(node* p, int x){
    if(p == NULL) return NULL;
    else if(x < p->val) p->lch = remove(p->lch, x);
    else if(x > p->val) p->rch = remove(p->rch, x);
    else if(p->lch == NULL) {
        node* q = p->rch;
        delete p;
        return q;
    } 
    else if(p->lch->rch == NULL){
        node* q = p->lch;
        q->rch = p->rch;
        delete p;
        return q;
    }
    else {
        node* q;
        for(q = p->lch; q->rch->rch != NULL; q = q->lch);
        node* r = q->rch;
        q->rch = r->lch;
        r->lch = p->lch;
        r->rch = p->rch;
        delete p;
        return r;
    }
    return p;
}