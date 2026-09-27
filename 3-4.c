#pragma once
#include <stdio.h>
#define MAX 10

int insertElement(int L[], int n, int x);
int deleteElement(int L[], int n, int x);

int insertElement(int L[], int n, int x) {
    int i, k = n, move = 0;

    for (i = 0; i < n - 1; i++) {
        if (L[i] <= x && x <= L[i + 1]) {
            k = i + 1;
            break;
        }
    }

    for (i = n; i > k; i--) {
        L[i] = L[i - 1];
        move++;
    }

    L[k] = x;
    return move;
}

int deleteElement(int L[], int n, int x) {
    int i, k = n, move = 0;

    for (i = 0; i < n; i++) {
        if (L[i] == x) {
            k = i;
            break;
        }
    }

    if (k == n)
        return 0;

    for (i = k; i < n - 1; i++) {
        L[i] = L[i + 1];
        move++;
    }

    return move;
}

int main(void) {
    int L[MAX] = {1, 3, 5, 7, 9};
    int n = 5;
    int i;

    printf("초기 리스트 : ");
    for (i = 0; i < n; i++)
        printf("%d ", L[i]);
    printf("\n");

    insertElement(L, n, 6);
    n++;

    for (i = 0; i < n; i++)
        printf("%d ", L[i]);
    printf("\n");

    deleteElement(L, n, 5);
    n--;

    printf("삭제 후 : ");
    for (i = 0; i < n; i++)
        printf("%d ", L[i]);

    return 0;
}