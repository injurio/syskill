/* Name:Chayathorn Teratanitnan
 * ID:6280945
 */
#include <stdio.h>
#include <stdlib.h>
#include "mergesort.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mergesort.h"

void merge(Entry *output, Entry *L, int nL, Entry *R, int nR) {
    int i, j, k;
    i = j = k = 0;
    while (i < nL && j < nR) {
        if ((L+i)->data < (R+j)->data) {
            (output+k)->data = (L+i)->data;
            (output+k)->name = (L+i)->name;
            i++;
        }
        else {
            (output+k)->data = (R+j)->data;
            (output+k)->name = (R+j)->name;
            j++;
        }
        k++;
    }
    while (i < nL) {
        (output+k)->data = (L+i)->data;
        (output+k)->name = (L+i)->name;
        i++;
        k++;
    }
    while (j < nR) {
        (output+k)->data = (R+j)->data;
        (output+k)->name = (R+j)->name;
        j++;
        k++;
    }
}

void merge_sort(Entry *entries, int n) {
    if (n > 1) {
        int nL = n/2;
        int nR = n-(n/2);
        Entry* L = malloc(sizeof(Entry)*nL);
        Entry* R = malloc(sizeof(Entry)*nR);
        for (int i = 0; i < nL; i++) {
            (L+i)->data = (entries+i)->data;
            (L+i)->name = (entries+i)->name; 
        }
        int j = 0;
        for (int i = nL; i < n; i++) {
            (R+j)->data = (entries+i)->data;
            (R+j)->name = (entries+i)->name;
            j++;
        }
        merge_sort(L, nL);
        merge_sort(R, nR);
        Entry* tmp = malloc(sizeof(Entry)*n);
        merge(tmp, L, nL, R, nR);
        // copy output->entries
        memcpy(entries, tmp, (n * sizeof(Entry)));
        free(L);
        free(R);
        free(tmp);
    }
}

/*
TEST: ./mergesort < test.in
OUTPUT:
1 lsdfjl
2 ghijk
3 ksdljf
5 abc
6 def
*/
nt main(void) {
    int len;
    scanf("%d", &len);
    Entry* input = malloc(sizeof(Entry)*len);
    for (int i = 0; i < len; i++) {
        int d;
        char* s = malloc(sizeof(char)*MAX_NAME_LENGTH);
        scanf("%d %s", &d, s);
        (input+i)->data = d;
        (input+i)->name = s;
    }
    merge_sort(input, len);
    for (int i = 0; i < len; i++) {
        printf("%d %s\n", (input+i)->data, (input+i)->name);
        free((input+i)->name);
    }
}
