#include <iostream>
using namespace std;

class TrieNode
{
public:
  char data;
  TrieNode *children[26];
  bool isTerminal;

  TrieNode(char data)
  {
    this->data = data;
    for (int i = 0; i < 26; i++)
    {
      children[i] = NULL;
    }
    isTerminal = false;
  }
};

class Trie
{
public:
  TrieNode *root;

  Trie()
  {
    root = new TrieNode('\0');
  }

  void insertUtil(TrieNode *root, string word)
  {
    // base case
    if (word.length() == 0)
    {
      root->isTerminal = true;
      return;
    }

    // assumption - word will be in all CAPS
    int index = word[0] - 'A';
    TrieNode *child;

    // present
    if (root->children[index] != NULL)
    {
      child = root->children[index];
    }
    else // absent
    {
      child = new TrieNode(word[0]);
      root->children[index] = child;
    }

    // Call Recursion
    insertUtil(child, word.substr(1));
  }

  void insertWord(string word)
  {
    insertUtil(root, word);
  }

  bool searchUtil(TrieNode *root, string word)
  {
    // base case
    if (word.length() == 0)
    {
      return root->isTerminal;
    }

    int index = word[0] - 'A';
    TrieNode *child;

    if (root->children[index] != NULL)
    {
      child = root->children[index];
    }
    else
    {
      return false;
    }

    return searchUtil(child, word.substr(1));
  }

  bool searchWord(string word)
  {
    return searchUtil(root, word);
  }

  void removeUtil(TrieNode *root, string word)
  {
    if (word.length() == 0)
    {
      root->isTerminal = false;
      return;
    }

    int index = word[0] - 'A';
    TrieNode *child;

    if (root->children[index] != NULL)
    {
      child = root->children[index];
    }
    removeUtil(child, word.substr(1));
  }

  void removeWord(string word)
  {
    removeUtil(root, word);
  }
};

int main()
{
  Trie *t = new Trie();

  t->insertWord("ARM");
  t->insertWord("DO");
  t->insertWord("TIME");

  cout << "TIME (present or absent): " << t->searchWord("TIME") << endl;
  cout << "TIM (present or absent): " << t->searchWord("TIM") << endl;

  t->removeWord("TIME");
  cout << "TIME (present or absent): " << t->searchWord("TIME") << endl;
  cout << "ARM (present or absent): " << t->searchWord("ARM") << endl;

  t->removeWord("ARM");
  cout << "ARM (present or absent): " << t->searchWord("ARM") << endl;

  return 0;
}