#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> result;
    int m, n;

    // Trie Node structure
    struct trieNode {
        bool endOfWord;
        char ch;
        trieNode* children[26];
    };

    // Create a new Trie node
    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        newNode->endOfWord = false;
        newNode->ch = ' ';
        for (int i = 0; i < 26; i++) {
            newNode->children[i] = NULL;
        }
        return newNode;
    }

    // Insert a word into the Trie
    void insert(trieNode* root, string &word) {
        trieNode* pCrawl = root;

        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];
            int idx = ch - 'a';

            if (pCrawl->children[idx] == NULL) {
                pCrawl->children[idx] = getNode();
                pCrawl->children[idx]->ch = ch;
            }
            pCrawl = pCrawl->children[idx];
        }
        pCrawl->endOfWord = true;
    }

    // Directions for DFS (up, down, left, right)
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // DFS to find all words
    void findWords(vector<vector<char>>& board, int i, int j, trieNode* root, string s) {
        if (i < 0 || i >= m || j < 0 || j >= n)
            return;

        char ch = board[i][j];
        int idx = ch - 'a';
        if (board[i][j] == '$' || root->children[idx] == NULL)
            return;

        root = root->children[idx];
        s.push_back(ch);

        if (root->endOfWord == true) {
            result.push_back(s);
            root->endOfWord = false; // prevent duplicate word collection
        }

        char temp = board[i][j];
        board[i][j] = '$'; // mark visited

        for (vector<int>& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            findWords(board, new_i, new_j, root, s);
        }

        board[i][j] = temp; // backtrack
    }

    // Main function that builds the Trie and starts DFS
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();

        trieNode* root = getNode();

        // Insert all words into Trie
        for (string &word : words) {
            insert(root, word);
        }

        // Start DFS from every board cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char ch = board[i][j];
                int idx = ch - 'a';
                string s = "";
                if (root->children[idx] != NULL)
                    findWords(board, i, j, root, s);
            }
        }

        return result;
    }
};

// --------------------------- MAIN FUNCTION ---------------------------
int main() {
    Solution sol;

    vector<vector<char>> board = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}
    };

    vector<string> words = {"oath", "pea", "eat", "rain", "hklf", "hf"};

    vector<string> foundWords = sol.findWords(board, words);

    cout << "✅ Words found in the board:\n";
    for (string word : foundWords) {
        cout << "- " << word << endl;
    }

    return 0;
}