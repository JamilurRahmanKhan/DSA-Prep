#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
    🔤 WordDictionary (Trie with Wildcard Support)
    ------------------------------------------------
    This data structure allows:
    1. Adding words to a dictionary (like a Trie)
    2. Searching words, where '.' can match any single letter
    
    Example:
      addWord("bad")
      addWord("dad")
      addWord("mad")

      search("pad") → false
      search("bad") → true
      search(".ad") → true  (matches any of "bad", "dad", "mad")
      search("b..") → true  (matches "bad")
*/

class WordDictionary {
public:
    // 🧱 Each trieNode represents one character in the Trie
    struct trieNode { 
        trieNode *children[26];   // 26 possible lowercase letters
        bool isEndOfWord;         // Marks the end of a valid word
    };
    
    trieNode* root;

    // 🪄 Helper: creates and initializes a new Trie node
    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        newNode->isEndOfWord = false;

        // Initialize all children to NULL
        for (int i = 0; i < 26; i++) {
            newNode->children[i] = NULL;
        }

        return newNode;
    }

    // 🏗️ Constructor: create an empty Trie with just the root node
    WordDictionary() {
        root = getNode();
    }
    
    // 🧩 Add a word to the Trie
    void addWord(string word) {
        trieNode *crawler = root;  // Start from the root
        
        for (int i = 0; i < word.length(); i++) { 
            int index = word[i] - 'a';  // Find index (0-25)
            
            // If no node for this character, create one
            if (!crawler->children[index]) {
                crawler->children[index] = getNode();
            }

            // Move down to that node
            crawler = crawler->children[index];
        }

        // After inserting all letters, mark the end of a word
        crawler->isEndOfWord = true;
    }

    /*
        🔍 Recursive Helper: searchUtil()
        Handles wildcard '.' by exploring *all* possible child nodes.

        Parameters:
            root  → current Trie node
            word  → remaining substring we need to search
    */
    bool searchUtil(trieNode* root, string word) {
        trieNode *crawler = root;
        
        for (int i = 0; i < word.length(); i++) { 
            char ch = word[i];

            // Case 1️⃣: Wildcard ('.') → Try every possible child
            if (ch == '.') {
                for (int j = 0; j < 26; j++) {
                    if (crawler->children[j]) {
                        // Recursively search remaining substring
                        if (searchUtil(crawler->children[j], word.substr(i + 1))) {
                            return true;
                        }
                    }
                }
                return false; // If none of the children matched
            }

            // Case 2️⃣: Normal letter
            int index = ch - 'a';
            if (!crawler->children[index]) {
                return false;  // path doesn’t exist → word not found
            }

            // Move to next character
            crawler = crawler->children[index];
        }

        // Word must end at a valid end-of-word node
        return (crawler != NULL && crawler->isEndOfWord);
    }

    // 🔍 Public Search Function (calls recursive helper)
    bool search(string word) {
        return searchUtil(root, word);
    }
};

// 🧪 Example main() for testing
int main() {
    WordDictionary dict;

    // Adding words to the dictionary
    dict.addWord("bad");
    dict.addWord("dad");
    dict.addWord("mad");

    cout << boolalpha; // print true/false instead of 1/0

    cout << "search('pad'): " << dict.search("pad") << endl;  // false
    cout << "search('bad'): " << dict.search("bad") << endl;  // true
    cout << "search('.ad'): " << dict.search(".ad") << endl;  // true
    cout << "search('b..'): " << dict.search("b..") << endl;  // true
    cout << "search('..d'): " << dict.search("..d") << endl;  // true
    cout << "search('b.d'): " << dict.search("b.d") << endl;  // true
    cout << "search('ma.'): " << dict.search("ma.") << endl;  // true

    return 0;
}