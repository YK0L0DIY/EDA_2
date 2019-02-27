#include <stdio.h>
#include <list.h>

struct no {
    int value;
    struct no *next;
};

struct list {
    struct no *root;
};

struct list *list_new() {
    struct list *list = malloc(sizeof(struct list));
    if (list != NULL) {
        list->root = NULL;
    }
    return list;
}

bool list_empty(struct list *list) {
    if (list->root == NULL) {
        return true;
    }
    return false;
}

struct no *no(int value) {
    struct no *no = malloc(sizeof(struct no));
    if (no != NULL) {
        no->value = value;
    }
    return no;
}

bool list_insert(struct list *list, int value) {
    struct no *no = no_new(value);
    if (no != NULL) {
        no->next = list->root;
        list->root = no;
        return true;
    } else
        return false;

}

int list_find(struct list *list, int x) {
    int indice = 0;
    struct no *no = list->root;
    do {
        if (no->value == x) {
            return indice;
        }
        indice++;
        *no = no->next;
    } while (no->next != NULL);
    return -1;
}

void list_print(struct list *list) {
    if (list->root != NULL) {
        struct no *no = list->root;
        printf("[");
        do {
            printf("%d ", no->value);
            *no = no->next;
        } while (no->next != NULL);
        printf("]");
    } else {
        printf("[]");
    }
}

void list_destroy(struct list *list) {

    struct no *no = list->root;
    int aux;

    do {
        aux = no->next;
        free(no);
        *no = aux;
    } while (no->next != NULL);

}