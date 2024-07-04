/**
 * Definition for a binary tree struct TreeNode.
 * struct Treestruct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int* arr = NULL;
    struct TreeNode** stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
    int top = -1;
    int stackSize = 1; // Initialize stack size

    while (root != NULL || top != -1) {
        while (root != NULL) {
            // Check if stack needs to be resized
            if (top + 1 >= stackSize) {
                stackSize *= 2;
                stack = (struct TreeNode**)realloc(stack, stackSize * sizeof(struct TreeNode*));
            }
            stack[++top] = root;
            root = root->left;
        }
        root = stack[top--];
        arr = (int*)realloc(arr, (*returnSize + 1) * sizeof(int));
        arr[(*returnSize)++] = root->val;
        root = root->right;
    }

    free(stack);
    return arr;
}

