#include<bits/stdc++.h>
#include<iostream>

using namespace std;

// Implementing The Trie Data Structure + String
// Trie operations: insertion, search, and removal with time complexity
// INSERTION: O(L) where L is the length of the word
// SEARCH: O(L) where L is the length of the word
// REMOVAL: O(L) where L is the length of the word
// used for solving string problems with space optimization 

// Trie class 
class TrieNode {
public:
   char data; // character data elemenet 
   TrieNode* children[26]; // array of pointers to children nodes
    bool isTerminal; // last node declared as end of word

    TrieNode(char ch){
        data = ch;
        isTerminal = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr; // initialize all children to nullptr
        }
    }

    // removal operation in trie

};


class Trie {
public:
    TrieNode* root;
    // define the constructor
    Trie() {
        root = new TrieNode('\0'); // root node initialized with null character
    }

    void inserUtil(TrieNode* root, string word){
        // base case 
        if(word.size() == 0 ){
            root->isTerminal = true;
            return; 
        }

        int index = word[0] - 'A'; 
        TrieNode* child;
        
        // present
        if(root->children[index] != NULL){
            // if the char is present then move to the child node
            child = root->children[index];
        } else {
            // absent
            // if the char is not present then create a new node containing the char at word[0]
            child = new TrieNode(word[0]);
            // connect the child node to the root node
            root->children[index] = child;
        }

        // recursion call by passing the child and next character of the word
        inserUtil(child, word.substr(1)); // pass the remaining part of the word
    }
    // making a function for insertion 
    void insertWord(string word){
        inserUtil(root, word);
    }
    
    // making the search utility function using recursion
    bool searchUtil(TrieNode* root, string word){
        // base case
        if(word.size() == 0){
            return root->isTerminal; // return true if the current node is terminal
        }
        
        int index = word[0] - 'A'; // get the index of the character
        TrieNode* child;
         
        // check if the root node is not null 
        if(root -> children[index] != NULL){
            child = root->children[index]; // if present, move to the child node
        }else{
            return false; // if its null then there no such word in the trie
        }

        // recursion call 
        return searchUtil(child, word.substr(1)); // pass the remaining part of the word
      
    }

    // making the search function
    bool search(string word){
        return searchUtil(root, word);
    }

    // making the remove function with utility function
    void remove(TrieNode* root, string word){
        
    } 
};



int main (){
    // creating a trie object and inserting a word into it
    Trie* t = new Trie();
    // inserting words into the trie
    t->insertWord("HELLO");
    // checking if the word is present in the trie 
    cout << "present Or not in the trie "<<t->search("HELLO")<<endl;
    
    return 0;
}