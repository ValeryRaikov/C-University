#include <stdio.h>
#include <stdlib.h>

// Създаваме структура за възел в списъка
struct Node {
    int data;
    struct Node* next;
};

// Създаваме структура за кръгов свързан списък
struct CircularLinkedList {
    struct Node* head;
    int size;
};

// Конструктор за инициализация на празен списък
void initializeCircularLinkedList(struct CircularLinkedList* list) {
    list->head = NULL;
    list->size = 0;
}

// Метод за добавяне на нов елемент в края на списъка
void add(struct CircularLinkedList* list, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (list->head == NULL) {
        list->head = newNode;
        list->head->next = list->head;
    } else {
        newNode->next = list->head->next;
        list->head->next = newNode;
    }
    list->size++;
}

// Метод за удвояване на размера на списъка, ако е необходимо
void doubleSizeIfNeeded(struct CircularLinkedList* list) {
    if (list->size == 0) {
        return;
    }
    struct Node* current = list->head;
    int count = 1;
    while (count < list->size) {
        current = current->next;
        count++;
    }
    current->next = list->head;

    if (list->size * 2 >= count) {
        return;
    }

    struct Node* newHead = NULL;
    struct Node* tail = NULL;
    current = list->head;
    count = 0;
    while (count < list->size) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = current->data;
        if (newHead == NULL) {
            newHead = newNode;
            tail = newHead;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        current = current->next;
        count++;
    }
    tail->next = newHead;
    list->head = newHead;
}

// Метод за извеждане на елементите на списъка
void print(struct CircularLinkedList* list) {
    if (list->size == 0) {
        return;
    }
    struct Node* current = list->head;
    int count = 0;
    do {
        printf("%d ", current->data);
        current = current->next;
        count++;
    } while (count < list->size);
    printf("\n");
}

int main() {
    struct CircularLinkedList list;
    initializeCircularLinkedList(&list);

    printf("Is the circular list empty before adding elements: %s\n", !list.size ? "Yes" : "No");
    printf("Size of the circular list before adding elements: %d\n", list.size);

    add(&list, 1);
    add(&list, 2);
    add(&list, 3);
    add(&list, 4);
    add(&list, 5);

    printf("Is the circular list empty after adding elements: %s\n", !list.size ? "Yes" : "No");
    printf("Size of the circular list after adding elements: %d\n", list.size);

    printf("Original list:\n");
    print(&list);

    doubleSizeIfNeeded(&list);

    printf("List after doubling if needed:\n");
    print(&list);

    return 0;
}
