

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        return strdup(""); // Return an empty string if no strings are provided
    }

    char stack[201];
    int top = -1;

    // Fill the stack with characters from the first string
    for (int i = 0; strs[0][i] != '\0'; i++) {
        stack[++top] = strs[0][i];
    }
    stack[top + 1] = '\0'; // Null-terminate the string

    // Compare stack with the next strings
    for (int i = 1; i < strsSize; i++) {
        int j = 0;
        while (strs[i][j] != '\0' && j <= top) {
            if (stack[j] != strs[i][j]) {
                top = j - 1; // Pop from stack
                break;
            }
            j++;
        }
        // If we finished a word that's shorter than what's in the stack
        if (strs[i][j] == '\0') {
            top = j - 1;
        }
    }

    // Allocate a dynamic string for the result
    char* result = (char*)malloc((top + 2) * sizeof(char)); // +1 for the null terminator, +1 because top is index
    if (result == NULL) {
        return NULL; // Return NULL if memory allocation fails
    }

    // Copy the stack content to the result string
    for (int i = 0; i <= top; i++) {
        result[i] = stack[i];
    }
    result[top + 1] = '\0'; // Null-terminate the result string

    return result;
}