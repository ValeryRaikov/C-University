#include <stdio.h>
#include <stdlib.h>

// Създаваме структура за възел в дървото
struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Конструктор за създаване на възел със зададена стойност
struct TreeNode* createTreeNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Метод за проверка за дублиращи се стойности в дърво
int hasDuplicateValues(struct TreeNode* root, struct TreeNode* seenValues[]) {
    // Ако достигнем листо или празно поддърво, няма какво да сравняваме.
    if (root == NULL) {
        return 0;
    }

    // Ако вече сме видели стойността, значи има дублиране.
    for (int i = 0; i < 1000; ++i) {
        if (seenValues[i] != NULL && seenValues[i]->value == root->value) {
            return 1;
        }
    }

    // Добавяме стойността в масива с видяни стойности.
    for (int i = 0; i < 1000; ++i) {
        if (seenValues[i] == NULL) {
            seenValues[i] = root;
            break;
        }
    }

    // Проверяваме дали има дублиращи се стойности в лявото или дясното поддърво.
    int leftResult = hasDuplicateValues(root->left, seenValues);
    int rightResult = hasDuplicateValues(root->right, seenValues);

    // Връщаме резултатът от проверката в поддърветата.
    return leftResult || rightResult;
}

void printTree(struct TreeNode* root, int level) {
    if (root != NULL) {
        printTree(root->right, level + 1);
        for (int i = 0; i < level; i++) {
            printf("   ");
        }
        printf("%d\n", root->value);
        printTree(root->left, level + 1);
    }
}

int main() {
    // Създаваме двоично дърво с дублираща се стойност в лявото поддърво.
    struct TreeNode* root = createTreeNode(1);
    root->left = createTreeNode(2);
    root->right = createTreeNode(3);
    root->left->left = createTreeNode(4);
    root->left->right = createTreeNode(2);  // Дублираща стойност.
    root->right->left = createTreeNode(5);
    root->right->right = createTreeNode(6);

    // Масив за запаметяване на видените стойности
    struct TreeNode* seenValues[1000];
    for (int i = 0; i < 1000; ++i) {
        seenValues[i] = NULL;
    }

    // Извикваме метода за проверка за дублиращи се стойности.
    int hasDuplicates = hasDuplicateValues(root, seenValues);

    // Извеждаме резултата от проверката.
    if (hasDuplicates) {
        printf("There are at least 2 peaks with equal values in the tree.\n");
    } else {
        printf("There aren't peaks with equal values in the tree.\n");
    }

    printf("This is how the tree looks like:\n");
    printTree(root, 0);

    return 0;
}

