#include <bits/stdc++.h> 
using namespace std; 

//Node to store left and right child/subtree of trie data structure
class Node{
    public:
    Node *left;
    Node *right; 
};

//insert node into trie data structure
void insert(Node *root, int data){
    Node *curr = root;

    for(int i=31; i>=0; i--){
        //to get ith bit of data
        int val = (data >> i) & 1;
        //if val is equal to 1 then add it to right of curr node
        if(val){
            //if right of current node does not exist than create one
            if(!curr->right)
                curr->right = new Node();
            //move curr node to its right node
            curr = curr->right;
        }
        //if val is equal to 0 then add it to left of curr node
        else{
            //if left of current node does not exist than create one
            if(!curr->left)
                curr->left = new Node();
            //move curr node to its left node
            curr = curr->left;
        }
    }
}

int maxXORpair(Node *root, int arr[], int n){
    int max_xor = 0;
    /*for each array element find 31 bit binary equivalent,
    and, compare with bit equivalent of all the other elements
    already present in trie data structure.
    */
    for(int i=0; i<n; i++){
        Node *curr = root;
        int data = arr[i], curr_xor = 0;
        int M = pow(2, 31);

        for(int j=31; j>=0; j--){
            int val = (data >> j) & 1;
            //if jth bit is 1 look for left child as it always contain 0
            //and, 1 ^ 0 = 1 thus we are maximizing the curr_xor value
            if(val){
                if(curr->left){
                    curr_xor += M;
                    curr = curr->left;
                }
                //if left node is not present just move to right node
                else
                    curr = curr->right;
            }
            //if jth bit is 0 look for right child because 0 ^ 1 = 1
            else{
                if(curr->right){
                    curr_xor += M;
                    curr = curr->right;
                }
                //if right node is not present just move to left node
                else
                    curr = curr->left;
            }
            M /= 2;
        }
        //update the max_xor value
        max_xor = max(max_xor, curr_xor);
    }
    return max_xor;
}

int main(){
    int n;
    cin >> n;
    
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];

    Node *root = new Node();

    for(int i=0; i<n; i++)
        insert(root, arr[i]);

    int m = maxXORpair(root, arr, n);

    cout << m << std::endl;

    return 0;
}