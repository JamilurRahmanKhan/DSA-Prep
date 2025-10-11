#include <iostream> // For input/output operations (cout, endl)
#include <string>   // For using std::string
using namespace std;

/*
    CLASS: PrefixTree (Trie)

    A Trie (Prefix Tree) is a special data structure used to efficiently store and search strings.
    It is especially useful for applications like:
        - Autocomplete
        - Spell checking
        - Prefix searching (e.g., all words starting with "app")

    Each node in the Trie represents a single character of a word.
*/
class PrefixTree {
public:
    /*
        STRUCT: trieNode
        Each trieNode represents one character in the Trie.

        Fields:
        - isEndOfWord: Marks if this node is the last character of a valid word.
        - children[26]: Pointers to the next letters ('a' to 'z').
    */
    struct trieNode {
        bool isEndOfWord;
        trieNode* children[26];
    };

    // Root node — starting point of all inserted words
    trieNode* root;

    /*
        CONSTRUCTOR: Initializes the Trie by creating an empty root node.
    */
    PrefixTree() {
        root = getNode();
    }

    /*
        FUNCTION: getNode()
        Creates a new trie node and initializes it.
        - Sets isEndOfWord to false (no word ends here yet)
        - Sets all 26 children to NULL (no next letters yet)
    */
    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        newNode->isEndOfWord = false;

        for (int i = 0; i < 26; i++) {
            newNode->children[i] = nullptr;
        }

        return newNode;
    }

    /*
        FUNCTION: insert(string word)
        PURPOSE:
            Inserts a word into the Trie.
        PROCESS:
            - Start from the root.
            - For each character in the word:
                1. Calculate the index (0 for 'a', 1 for 'b', ..., 25 for 'z').
                2. If there’s no node at this index, create a new one.
                3. Move the pointer to that child node.
            - After processing all letters, mark the final node as end of a word.
    */
    void insert(string word) {
        trieNode* crawler = root;

        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a'; // Convert char to index (e.g., 'c' -> 2)
            
            // If path doesn’t exist, create it
            if (!crawler->children[index]) {
                crawler->children[index] = getNode();
            }

            // Move to the next letter node
            crawler = crawler->children[index];
        }

        // After inserting the last character, mark end of word
        crawler->isEndOfWord = true;
    }

    /*
        FUNCTION: search(string word)
        PURPOSE:
            Checks if a complete word exists in the Trie.

        PROCESS:
            - Start from the root.
            - For each character in the word:
                1. Calculate index.
                2. If the child at that index is missing, word doesn’t exist.
                3. Otherwise, move to that child node.
            - After processing all letters, return true only if
              the last node is marked as an end of a word.
    */
    bool search(string word) {
        trieNode* crawler = root;

        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            
            // If path doesn't exist, word not found
            if (!crawler->children[index]) {
                return false;
            }

            // Move to the next node
            crawler = crawler->children[index];
        }

        // Return true only if this is the end of a word
        return (crawler && crawler->isEndOfWord);
    }

    /*
        FUNCTION: startsWith(string prefix)
        PURPOSE:
            Checks if any word in the Trie starts with the given prefix.

        PROCESS:
            - Similar to search(), but we don’t care if it’s an end of a word.
            - As long as the prefix path exists, return true.
    */
    bool startsWith(string prefix) {
        trieNode* crawler = root;

        for (int i = 0; i < prefix.length(); i++) {
            int index = prefix[i] - 'a';
            
            // If a character in prefix doesn’t exist in Trie path
            if (!crawler->children[index]) {
                return false;
            }

            crawler = crawler->children[index];
        }

        // If we finished the loop, prefix exists
        return true;
    }
};

/*
    FUNCTION: main()
    PURPOSE:
        Demonstrates the use of the PrefixTree (Trie) class.
        - Inserts several words.
        - Tests searching for full words.
        - Tests checking prefixes.
*/
int main() {
    PrefixTree trie; // Create a Trie object

    // Insert words into the Trie
    trie.insert("apple");
    trie.insert("app");
    trie.insert("bat");
    trie.insert("bad");

    cout << boolalpha; // Print true/false instead of 1/0

    // --- Search Tests ---
    cout << "Search 'apple': " << trie.search("apple") << endl;  // true
    cout << "Search 'app': " << trie.search("app") << endl;      // true
    cout << "Search 'bat': " << trie.search("bat") << endl;      // true
    cout << "Search 'bar': " << trie.search("bar") << endl;      // false

    // --- Prefix Tests ---
    cout << "Starts with 'ap': " << trie.startsWith("ap") << endl; // true
    cout << "Starts with 'ba': " << trie.startsWith("ba") << endl; // true
    cout << "Starts with 'ca': " << trie.startsWith("ca") << endl; // false

    return 0;
}

/*
root
 ├── a
 │    └── p
 │         └── p
 │              ├── (end) ← "app"
 │              └── l
 │                   └── e (end) ← "apple"
 └── b
      ├── a
           ├── t (end) ← "bat"
           └── d (end) ← "bad"
*/