// class Solution {
// public:
//     string replaceWords(vector<string>& dictionary, string sentence) {
        
//     }
// };
class TrieNode {
public:
    TrieNode* child[26];
    bool end;

    TrieNode() {
        end = false;
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();

    void insert(string &word) {
        TrieNode* node = root;

        for (char c : word) {
            int idx = c - 'a';
            if (!node->child[idx])
                node->child[idx] = new TrieNode();

            node = node->child[idx];
        }

        node->end = true;
    }

    string search(string &word) {
        TrieNode* node = root;
        string prefix;

        for (char c : word) {
            int idx = c - 'a';

            if (!node->child[idx])
                return word;

            node = node->child[idx];
            prefix += c;

            if (node->end)
                return prefix;
        }

        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {

        for (string &word : dictionary)
            insert(word);

        stringstream ss(sentence);
        string word;
        string ans;

        while (ss >> word) {
            if (!ans.empty())
                ans += " ";

            ans += search(word);
        }

        return ans;
    }
};