#include<iostream>
#include<vector>
#include<string>
using namespace std;

const int a_s = 26;   // Alphabet Size

struct TrieNode{
    TrieNode* children[a_s];
    bool isEndofWord;
};

class Trie{
    TrieNode * root;
    public:
        Trie(){
            root = new TrieNode();
        }
        TrieNode* getNode(){
            TrieNode * node = new TrieNode;
            node->isEndofWord = false;
            return node;
        }
        void insert(string str){
            TrieNode * node = root;
            for(int i=0; i<str.size(); i++){
                int index = str[i]-'a';
                if(node->children[index] == NULL){
                    node->children[index] = getNode();
                }
                node = node->children[index];
            }
            node->isEndofWord = true;
        }
        bool isEmpty(TrieNode* node){
            for(int i=0; i<a_s; i++){
                if(node->children[i] != NULL) return false;
            }
            return true;
        }
        
        bool search(string str){
            if(root == NULL)    return false;
            TrieNode* node = root;
            for(int i=0; i<str.size(); i++){
                int index = str[i]-'a';
                if(node->children[index]==NULL) return false;
                else    node = node->children[index];
            }
            return (node->isEndofWord);
        }
        TrieNode* del(TrieNode* node, string key, int kindex){
            
            if(index == key.size()){
                if(node->isEndofWord)   node->EndofWord = false;
                if(isEmpty(node)){
                    delete(node);
                    node = NULL;
                }
                return node;
            }
            int index = key[kindex]-'a';
            node->children[index] = del(node->children[index], key, kindex+1);
            if((node->isEndofWord == false)  && (isEmpty(node))){
                delete(node);
                node = NULL;
            }
            return node;
        }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    return 0;
}
