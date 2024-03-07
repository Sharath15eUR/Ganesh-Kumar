#include <stdio.h>
#include <stdbool.h>

#define MAX 100

struct HashSet {
    int table[MAX];
};

void initHashSet(struct HashSet *set) {
    for (int i = 0; i < MAX; i++) {
        set->table[i] = 0;
    }
}

void insert(struct HashSet *set, int key) {
    set->table[key] = 1;
}

bool exists(struct HashSet *set, int key) {
    return set->table[key] == 1;
}

bool isSubset(int arr1[], int arr2[], int m, int n) {
    struct HashSet set;
    initHashSet(&set);

    for (int i = 0; i < m; i++) {
        insert(&set, arr1[i]);
    }

    for (int i = 0; i < n; i++) {
        if (!exists(&set, arr2[i])) {
            return false;
        }
    }

    return true;
}

int main() {
    int arr1[] = {11, 1, 13, 21, 3, 7};
    int arr2[] = {11, 3, 7, 1};
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);

    if (isSubset(arr1, arr2, m, n)) {
        printf("arr2[] is a subset of arr1[]\n");
    } else {
        printf("arr2[] is not a subset of arr1[]\n");
    }

    return 0;
}
