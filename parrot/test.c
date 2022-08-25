#include <stdio.h>

// int numberOfDigit(char* str, int size) {
//     int count = 0;
//     for (int i = 0; i < size; ++i ) {
//         if (str + i >= '0' && str + i <= '9') {
//             ++count;
//         }
//     }
//     return count;
// }

// unsigned int frobnicate(unsigned int x) {
//     unsigned int tmp;
//     tmp = x >>
// }

// int countNumberZeroByte(char * path) {
//     FILE* file;
//     char ch;
//     file = fopen(path, "r");

//     if (NULL == file)
//         return 0;

//     int count = 0;
//     do {
//         ch = fgetc(file);
//         if (ch = ' ')
//             ++count;
//     } while (ch != EOF);

//     fclose(file);
//     return count;
// }

// struct node {
//     struct node *left;
//     struct node *right;
//     int value;
// }
// void dump_tree(const struct node *node) {
//     if (node->left != NULL)
//         dump_tree(node->left);
//     printf("%d", node->value);
//     if (node->right != NULL)
//         dump_tree(node->right);
// }

#define MAX(x,y) ((x < y) ? y : x)
void max_array1(const int *a, const int *b, int *c, size_t len) {
    while (len--)
    {
        printf("array1: %d %d\n", a, b);
        *c++ = MAX(*a++, *b++);
    }
}

void max_array2(const int *a, const int *b, int *c, size_t len) {
    size_t i;

    for (i = 0; i < len; i++)
        c[i] = MAX(a[i], b[i]);
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    
}
int main() {
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {3, 1, 5, 6, 2};
    int c[5];
    max_array1(a, b, c, 5);
    // for (int i = 0; i < 5; ++i)
    //     printf("%d ", c[i]);

    max_array2(a, b, c, 5);
    // for (int i = 0; i < 5; ++i)
    //     printf("%d ", c[i]);
    
    return 0;
}