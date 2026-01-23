#include<bits/stdc++.h>
using namespace std;

struct Node{
    char ch;
    int freq;
    Node *left,*right;

    Node(char c,int f){
        ch=c;
        freq=f;
        left=right=NULL;
    }
};

struct Compare{
    bool operator()(Node* a,Node* b){
        return a->freq>b->freq;
    }
};

void generate(Node* root,string code,unordered_map<char,string>& mp){
    if(!root) return;

    if(!root->left && !root->right){
        mp[root->ch]=code;
        return;
    }

    generate(root->left,code+"0",mp);
    generate(root->right,code+"1",mp);
}

string decode(Node* root,string bits){
    string ans="";
    Node* cur=root;

    for(char b:bits){
        if(b=='0') cur=cur->left;
        else cur=cur->right;

        if(!cur->left && !cur->right){
            ans+=cur->ch;
            cur=root;
        }
    }
    return ans;
}

int main(){
    string s;
    cout<<"Enter string: ";
    getline(cin,s);

    unordered_map<char,int> freq;
    for(char c:s) freq[c]++;

    priority_queue<Node*,vector<Node*>,Compare> pq;

    for(auto p:freq)
        pq.push(new Node(p.first,p.second));

    while(pq.size()>1){
        Node* a=pq.top(); pq.pop();
        Node* b=pq.top(); pq.pop();

        Node* parent=new Node('#',a->freq+b->freq);
        parent->left=a;
        parent->right=b;

        pq.push(parent);
    }

    Node* root=pq.top();

    unordered_map<char,string> code;
    generate(root,"",code);

    string encoded="";
    for(char c:s)
        encoded+=code[c];

    string decoded=decode(root,encoded);

    cout<<"Encoded: "<<encoded<<"\n";
    cout<<"Decoded: "<<decoded<<"\n";
}
