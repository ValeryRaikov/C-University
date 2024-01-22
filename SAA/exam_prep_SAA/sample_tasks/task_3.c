#include <stdio.h>
#include <stdlib.h>

// Структура за представяне на възел в еднопосочен списък
struct Node {
    int data;
    struct Node* next;
};

// Функция за добавяне на елемент в края на списъка
void append(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
}

// Функция за премахване на всеки втори възел
// и добавяне в нов списък с начало Avail
void removeAndAddToAvail(struct Node** head, struct Node** avail) {
    if (*head == NULL || (*head)->next == NULL) {
        // Няма какво да се премахва
        return;
    }

    struct Node* current = *head;
    struct Node* temp;

    while (current != NULL && current->next != NULL) {
        // Запазване на следващия възел
        temp = current->next;

        // Проверка за условието за премахване
        if (temp->data > 3 * current->data) {
            // Премахване на втория възел
            current->next = temp->next;

            // Добавяне в нов списък Avail
            temp->next = *avail;
            *avail = temp;

            // Преместване на текущия възел
            current = current->next;
        } else {
            // Просто преместване към следващия възел
            current = current->next->next;
        }
    }
}

// Функция за извеждане на еднопосочен списък
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Функция за освобождаване на еднопосочен списък
void freeList(struct Node** head) {
    struct Node* current = *head;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

int main() {
    struct Node* list = NULL;   // Основен списък
    struct Node* avail = NULL;  // Списък Avail

    // Добавяне на елементи в основния списък
    append(&list, 10);
    append(&list, 5);
    append(&list, 15);
    append(&list, 8);
    append(&list, 20);

    printf("Original List: ");
    printList(list);

    // Премахване на всеки втори възел и добавяне в списък Avail
    removeAndAddToAvail(&list, &avail);

    printf("Modified List: ");
    printList(list);

    printf("Avail List: ");
    printList(avail);

    // Освобождаване на списъците
    freeList(&list);
    freeList(&avail);

    return 0;
}
