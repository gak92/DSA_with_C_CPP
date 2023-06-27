#include <bits/stdc++.h> 
class node
{
    public:
        int data;
        int i;
        int j;

        node(int data, int row, int col)
        {
            this->data = data;
            this->i = row;
            this->j = col;
        }
};

class comparator
{
    public:
        bool operator()(node* a, node* b)
        {
            return a->data > b->data;
        }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    priority_queue<node*, vector<node*>, comparator> minheap;

    for(int i=0; i<k; i++)
    {
        node* temp = new node(kArrays[i][0], i, 0);
        minheap.push(temp);
    }

    vector<int> res;
    while(!minheap.empty())
    {
        node* temp = minheap.top();
        res.push_back(temp->data);
        minheap.pop();

        int i = temp->i;
        int j = temp->j;
        if(j+1 < kArrays[i].size())
        {   
            node* next = new node(kArrays[i][j+1], i, j+1);
            minheap.push(next);
        }
    }

    return res;
}





