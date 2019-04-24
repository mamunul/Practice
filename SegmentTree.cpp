//
//  SegmentTree.cpp
//  Practice
//
//  Created by New User on 24/4/19.
//  Copyright © 2019 Mamunul. All rights reserved.
//

#include "SegmentTree.hpp"



void buildSegmentTree(vector<int> &tree,vector<int> in,int node,int l,int r){
    
    if (l == r) {
        tree[node] = in[l-1];
        return;
    }
    
    buildSegmentTree(tree,in,node*2,l,(l+r)/2);
    buildSegmentTree(tree,in,node*2+1,(l+r)/2+1,r);
    
    tree[node] = min(tree[node*2], tree[node*2 +1]);
    
}
/*
 10
 2 4 3 1 6 7 8 9 1 7
 */
int querySegmentTree(vector<int> tree,int node,int ql,int qr, int l, int r){
    
    if (qr<l || ql>r) {
        return 100000;
    }
    
    if(r==l)
        return tree[node];
    
    int a1 = querySegmentTree(tree, node*2, ql, qr, l, (l+r)/2);
    int a2 = querySegmentTree(tree, node*2 +1, ql, qr, (l+r)/2 +1, r);
    
    return min(a1,a2);
    
}

void testSegmentTree(vector<int> v){
    
    //everything is in 1 based
    
    int nodeCount = 2 * pow(2,ceil(log2(v.size()))) + 1;
    
    vector<int> nodes(nodeCount,10000000);
    
    int treeStartIndex = 1;
    int treeEndIndex = int( v.size());
    int firstNode = 1;
    
    buildSegmentTree(nodes,v,firstNode,treeStartIndex,treeEndIndex);
    
    int queryLeft = 5;
    int queryRight = 6;
    
    cout << querySegmentTree(nodes, firstNode, queryLeft, queryRight, treeStartIndex, treeEndIndex) << endl;
}

void updateBIT(vector<int> &tree,int index,int value){
    
    for (;index<tree.size();index+=index&-index){
        tree[index]+=value;
    }
    
}

int queryBIT(vector<int> &tree,int index){
    
    int sum = 0;
    for (; index>0; index-=index&-index) {
        sum+=tree[index];
    }
    
    return sum;
}

void buildBinaryIndexedTree(vector<int> &tree,vector<int> in){
    
    
    for (int i = 0; i<in.size(); i++) {
        updateBIT(tree, i+1, in[i]);
    }
    
}

void testBinaryIndexedTree(vector<int> in){
    vector<int> bit(in.size()+1,0);
    buildBinaryIndexedTree(bit,in);
    
    
    int numberOfElements = 8;
    cout << queryBIT(bit, numberOfElements) << endl;
    numberOfElements = 3;
    cout << queryBIT(bit, numberOfElements) << endl;
}

int test_main(){
    
    int n;
    cin>> n;
    vector<int> v(n,0);
    
    for (int i = 0; i<n; i++) {
        cin>>v[i];
    }
    
    
    testBinaryIndexedTree(v);
    
    
        testSegmentTree(v);
    
    return 0;
}
