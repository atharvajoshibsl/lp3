#include<bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    int freq;
    Node *left;
    Node *right;
    Node(char d,int f)
    {
        left=right=NULL;
        data=d;
        freq=f;
    }
};

struct compare{
    bool operator()(Node *a,Node *b){
        return (a->freq>b->freq);
    }
};

void printCodes(Node *root,string str)
{
    if(root==NULL)
    {
        return;
    }
    if(root->data!='$')
    {
        cout<<root->data<<": "<<str<<endl;
    }
    printCodes(root->left,str+"0");
    printCodes(root->right,str+"1");
}

void huffmanCode(char data[],int freq[],int n)
{
    Node *left,*right,*temp;

    priority_queue<Node*,vector<Node*>,compare> minHeap;

    for(int i=0;i<n;i++)
    {
        minHeap.push(new Node(data[i],freq[i]));
    }

    while(minHeap.size()!=1)
    {
        left=minHeap.top();
        minHeap.pop();
        right=minHeap.top();
        minHeap.pop();
        temp=new Node('$',left->freq+right->freq);
        temp->left=left;
        temp->right=right;
        minHeap.push(temp);
    }
    printCodes(minHeap.top(),"");
}

int main()
{
    char data[]={'a','b','c','d'};
    int freq[]={23,12,34,10};
    huffmanCode(data,freq,4);
    return 0;
}