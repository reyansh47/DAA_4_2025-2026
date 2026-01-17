#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node{
public:
    int data;
    Node *left,*right;
    Node(int x){
        data=x;
        left=right=NULL;
    }
};

class Compare{
public:
    bool operator()(Node* a,Node* b){
        return a->data > b->data;
    }
};

class Solution{
public:
    void dfs(Node* root,string s,vector<string>& ans){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            ans.push_back(s);
            return;
        }
        dfs(root->left,s+"0",ans);
        dfs(root->right,s+"1",ans);
    }

    vector<string> huffman(string S,vector<int> f,int N){
        priority_queue<Node*,vector<Node*>,Compare> pq;

        for(int i=0;i<N;i++){
            pq.push(new Node(f[i]));
        }

        while(pq.size()>1){
            Node* a=pq.top(); pq.pop();
            Node* b=pq.top(); pq.pop();

            Node* c=new Node(a->data + b->data);
            c->left=a;
            c->right=b;

            pq.push(c);
        }

        vector<string> ans;
        dfs(pq.top(),"",ans);
        return ans;
    }
};

int main(){
    string S;
    cout<<"Enter string: ";
    cin>>S;

    vector<int> f(S.size());
    cout<<"Enter frequencies: ";
    for(int i=0;i<S.size();i++){
        cin>>f[i];
    }

    Solution obj;
    vector<string> ans=obj.huffman(S,f,S.size());

    cout<<"Huffman Codes: ";
    for(string x:ans) cout<<x<<" ";
    return 0;
}
