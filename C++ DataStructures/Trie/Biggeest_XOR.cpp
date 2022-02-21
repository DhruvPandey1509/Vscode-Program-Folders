#include <iostream>
using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    void insert(int n)
    {
        // bits of thr=at number in the trie
        Node *temp = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (n >> i) & 1;
            if (bit == 0)
            {
                if (temp->left == NULL)
                {
                    temp->left = new Node();
                }
                temp = temp->left;
            }
            else
            {
                if (temp->right == NULL)
                {
                    temp->right = new Node();
                }
                temp = temp->right;
            }
        }
    }
    int max_Xor_Helper(int value)
    {
        int curr_ans = 0;
        Node *temp = root;

        for (int i = 31; i >= 0; i--)
        {
            int bit = (value >> i) & 1;
            if (bit == 0)
            {
                // find the opposite value
                if (temp->right != NULL)
                {
                    temp = temp->right;
                    curr_ans += 1 << i;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                if (temp->left != NULL)
                {
                    temp = temp->left;
                    curr_ans += 1 << i;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }

        return curr_ans;
    }

    int max_Xor(int input[], int n)
    {
        int maxXor = 0;
        for (int i = 0; i < n; i++)
        {
            int value = input[i];
            insert(value);
            int curr_xor = max_Xor_Helper(value);
            maxXor = max(maxXor, curr_xor);
        }

        return maxXor;
    }
};

int main()
{
    int input[] = {3, 10, 5, 25, 9, 2};
    int n = sizeof(input) / sizeof(input[0]);
    Trie t;
    cout << t.max_Xor(input, n) << endl;
}