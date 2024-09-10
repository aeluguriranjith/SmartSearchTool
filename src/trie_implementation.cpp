#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    bool isEndOfWord;
    TrieNode()
    {
        isEndOfWord = false;
    }
};

class Trie
{
public:
    int total_nodes;
    int total_words;
    TrieNode *root;

    Trie()
    {
        root = new TrieNode();
    }

    void insert(string str);
    // void remove(string str);
    // bool _remove(TrieNode *current, string str, int index);
    TrieNode *search_exact(string str);
    vector<string> search_pre(string str);
    // void draw(TrieNode *current, int depth);
};

void Trie::insert(string str)
{
    TrieNode *current = root;

    for (int i = 0; i < str.size(); ++i)
    {
        char ch = str[i];
        if (current->children.find(ch) != current->children.end())
        {
            current = current->children[ch];
        }
        else
        {
            current->children.insert(make_pair(ch, new TrieNode()));
            current = current->children[ch];
        }
    }

    current->isEndOfWord = true;
}

TrieNode *Trie::search_exact(string str)
{
    TrieNode *current = root;

    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < str.size(); ++i)
    {
        char ch = str[i];
        if (current->children.find(ch) != current->children.end())
        {
            current = current->children[ch];
        }
        else
        {
            return NULL;
        }
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);
    cerr << "\033[32m\n"
         << current->isEndOfWord << " results in " << double(duration.count() / double(1000000)) << " ms.\033[0m\n\n";

    return current->isEndOfWord ? current : NULL;
}

void get_words_dfs(TrieNode *current, string pre, vector<string> &results)
{
    if (current == NULL)
    {
        return;
    }
    if (current->isEndOfWord)
    {
        results.push_back(pre);
    }

    for (auto i : current->children)
    {
        get_words_dfs(i.second, (pre + i.first), results);
    }
}

vector<string> Trie::search_pre(string str)
{
    auto start = chrono::high_resolution_clock::now();

    TrieNode *current = root;
    vector<string> results;

    for (int i = 0; i < str.size(); ++i)
    {
        char ch = str[i];
        if (current->children.find(ch) != current->children.end())
        {
            current = current->children[ch];
        }
        else
        {
            return results;
        }
    }

    get_words_dfs(current, str, results);

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);

    cerr << "\033[32m\n"
         << results.size() << " results in " << double(duration.count() / double(1000000)) << " ms.\033[0m\n\n";

    return results;
}