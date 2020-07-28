#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;
const char base = 'a';
//basic structure of Trie
struct TrieNode {
	TrieNode* child[ALPHABET_SIZE];
	bool wordEnd;
};

//Function to return a new node
TrieNode* getNode(){
	TrieNode* node = new TrieNode;

	node -> wordEnd = false;

	for(int i = 0; i < ALPHABET_SIZE; i++) {
		node -> child[i] = NULL;
	}
	return node;
}


void insert(TrieNode* root, string key) {

	TrieNode *crawler  = root;

	for(int i = 0; i < key.length(); i++) {
		int index = key[i] - base;
		if(crawler -> child[index] == NULL) {
			crawler -> child[index] = getNode();
		}
		crawler = crawler -> child[index];
	}
	crawler -> wordEnd = true;
}


bool search(TrieNode* root, string key) {

	if(root == NULL)
		return false;

	TrieNode *crawler = root;

	for(int i = 0; i < key.length(); i++) {
		int index = key[i] - base;
		if(crawler -> child[index] == NULL) 
			return false;
		crawler = crawler -> child[index];
	}

	return crawler -> wordEnd && crawler != NULL;
}


// Returns true if root has no children, else false 
bool isEmpty(TrieNode* root) 
{ 
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        if (root -> child[i]) 
            return false; 
    return true; 
} 

TrieNode* deleteWord(TrieNode* root, string key, int depth = 0) {

	if(root == NULL)
		return NULL;

	//when end of word is reached
	if(depth == key.size()) {

		if(root -> wordEnd)
			root -> wordEnd = false;

		if(isEmpty(root)) {
			delete(root);
			root = NULL;
		}
		return root;
	}

	int index = key[depth] - base;
	root -> child[index] = deleteWord(root -> child[index], key, depth + 1);

	if(isEmpty(root) && root -> wordEnd == false){
		delete(root);
		root = NULL;
	}

	return root;
}


int main() {

	string keys[] = {"the", "a", "there", 
                    "answer", "any", "by", 
                     "bye", "their" }; 
    int n = sizeof(keys)/sizeof(keys[0]); 
  	
  	//create root node
    struct TrieNode *root = getNode(); 
  
    // Construct trie 
    for (int i = 0; i < n; i++) 
        insert(root, keys[i]); 
  
    // Search for different keys 
    search(root, "the")? cout << "Yes\n" : 
                         cout << "No\n"; 
    search(root, "these")? cout << "Yes\n" : 
                           cout << "No\n"; 
    deleteWord(root, "there"); 
    search(root, "the") ? cout << "Yes\n" : cout << "No\n";
    return 0; 
}
