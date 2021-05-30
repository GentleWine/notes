class Solution {
    typedef struct Trie{
        struct Trie* left;
        struct Trie* right;
    }Trie;

    int depth = 31;

public:
    void put(Trie* root, int num)
    {
        for(int d = depth-1; d >= 0; d--)
        {
            if(((num>>d)&1)==0)
            {
                if(!root->left) 
                {
                    root->left = new Trie;
                    root->left->left = NULL;
                    root->left->right = NULL;
                }
                root = root->left;
            }
            else
            {
                if(!root->right) 
                {
                    root->right = new Trie;
                    root->right->left = NULL;
                    root->right->right = NULL;
                }
                root = root->right;
            }

        }   

    }
    int get(Trie* root, int num)
    {
        int result = 0;
        for(int d = depth-1; d >= 0; d--)
        {
            result = result << 1;
            if(((num>>d)&1)==0)
            {
                if(root->right)
                {
                    result += 1;
                    root = root->right;
                }
                else
                {
                    root = root->left;
                }
            }
            else
            {
                if(root->left)
                {
                    result += 1;
                    root = root->left;
                }
                else
                {
                    root = root->right;
                }

            }
        }
        return result;
    }

    int findMaximumXOR(vector<int>& nums) {
        Trie* trie = new Trie;
        trie->left = NULL;
        trie->right = NULL;
        int max = 0;
        for(int i = 1; i< nums.size();i++)
        {
            put(trie, nums[i-1]);
            int temp = get(trie, nums[i]);
            max = temp>max?temp:max;
        }
        return max;
    }
};