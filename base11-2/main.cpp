//
//  main.cpp
//  base11-2
//
//  Created by suchao on 6/3/18.
//  Copyright © 2018 cs.nju. All rights reserved.
//

#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

void insert(node *&head, node *&p){
    bool flag = false;
    for(node *tmp = head; tmp!=NULL && !flag; tmp=tmp->next){
        if(tmp->data == p->data){
            flag = true;
        }
    }
    
    if(!flag){
        p->next = head;
        head = p;
    }
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "input:\n";
    node *head = NULL;
    
    int tmp;
    cin >> tmp;
    while(tmp != -1){
        node *p = new node;
        p->data = tmp;
        
        insert(head,p);
        cin >> tmp;
    }

    cout << "input k:\n";
    int k;
    cin >> k;
    int l=0;
    for(node *p=head; p != NULL; p=p->next){
        l++;
    }
    
    
    if(k >= l){
        cout << "wrong." << endl;
    }else{
        node *q=head;
        for(int i=0; i<l-k-1; i++){
            q = q->next;
        }
        cout << q->data << endl;
    }
    
    return 0;
}
