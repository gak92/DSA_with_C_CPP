// ================================================================================== //
//                      Solution # 01
//                      Using two for loop
// ================================================================================== //
string longestCommonPrefix(vector<string> &arr, int n)
{
  // Write your code here
  string res = "";

  for (int i = 0; i < arr[0].length(); i++)
  {
    char ch = arr[0][i];
    bool match = true;

    for (int j = 1; j < n; j++)
    {
      if (arr[j].size() < i || ch != arr[j][i])
      {
        match = false;
        break;
      }
    }
    if (!match)
      break;
    else
      res.push_back(ch);
  }

  return res;
}

// ================================================================================== //
//                      Solution # 2
//                      Using Trie
// ================================================================================== //

class TrieNode
{
public:
  char data;
  TrieNode *children[26];
  int childCount;
  bool isTerminal;

  TrieNode(char data)
  {
    this->data = data;
    for (int i = 0; i < 26; i++)
    {
      children[i] = NULL;
    }
    childCount = 0;
    isTerminal = false;
  }
};

class Trie
{
public:
  TrieNode *root;

  Trie(char ch)
  {
    root = new TrieNode(ch);
  }

  void insertUtil(TrieNode *root, string word)
  {
    if (word.length() == 0)
    {
      root->isTerminal = false;
      return;
    }
    int index = word[0] - 'a';
    TrieNode *child;

    if (root->children[index] != NULL)
    {
      child = root->children[index];
    }
    else
    {
      child = new TrieNode(word[0]);
      root->childCount++;
      root->children[index] = child;
    }
    insertUtil(child, word.substr(1));
  }

  void insertWord(string word)
  {
    insertUtil(root, word);
  }

  void lcp(string str, string &res)
  {
    for (int i = 0; i < str.length(); i++)
    {
      char ch = str[i];
      if (root->childCount == 1)
      {
        res.push_back(ch);
        int index = ch - 'a';
        root = root->children[index];
      }
      else
      {
        break;
      }
      if (root->isTerminal)
        break;
    }
  }
};

string longestCommonPrefix(vector<string> &arr, int n)
{
  // Write your code here
  Trie *t = new Trie('\0');

  for (int i = 0; i < n; i++)
  {
    t->insertWord(arr[i]);
  }

  string first = arr[0];
  string res = "";

  t->lcp(first, res);
  return res;
}
