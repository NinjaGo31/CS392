#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mergesort.h"


int int_cmp(const void* a, const void* b) {
    int* e1 = (int*)a;
    int* e2 = (int*)b;
    
    if( (*e1) == (*e2) ) {
        return 0;
    }
    else if ( (*e1) > (*e2) ) {
        return 1;
    }
    else {
        return -1;
    }
}

int dbl_cmp(const void* a, const void* b) {
    double* e1 = (double*)a;
    double* e2 = (double*)b;
    
    if( (*e1) == (*e2) ) {
        return 0;
    }
    else if ( (*e1) > (*e2) ) {
        return 1;
    }
    else {
        return -1;
    }
}

void mrg_sort_helper(void* array, void* array2, size_t len, size_t elem_sz, int (*comp)(const void*, const void*), int left, int right) {
    int mid;
    
    // Runs ONLY IF left is LESS THAN right
    if(left < right) {
        mid = left + (right - left) / 2;

        // Recursion calls
        mrg_sort_helper(array, array2, len, elem_sz, comp, left, mid);
        mrg_sort_helper(array, array2, len, elem_sz, comp, mid+1, right);
        
        // Initializing trackers
        int low = left;
        int high = mid + 1;

        // Begin merge sort algorithm
        // memcpy copies the element in an array to another array with a given byte size (elem_sz)
        // comp activates either int_cmp or dbl_cmp, depending on which function was called as an argument
        for (int i = left; i <= right; i++) {
            if(low == mid + 1) {
                memcpy((char*)array2 + (i * elem_sz), (char*)array + (high * elem_sz), elem_sz);
                high++;
            }
            else if(high == right + 1) {
                memcpy((char*)array2 + (i * elem_sz), (char*)array + (low * elem_sz), elem_sz);
                low++;
            }
            else if(comp(((char*)array + low * elem_sz), ((char*)array + high * elem_sz)) == -1) {
                memcpy((char*)array2 + (i * elem_sz), (char*)array + (low * elem_sz), elem_sz);
                low++;
            }
            else {
                memcpy((char*)array2 + (i * elem_sz), (char*)array + (high * elem_sz), elem_sz);
                high++;
            }
        }
        
        // Copy information in array2 to array
        for(int i = left; i <= right; i++) {
            memcpy(((char*)array + (i * elem_sz)), ((char*)array2 + (i * elem_sz)), elem_sz);
        }
    }
}
void mergesort(void* array, size_t len, size_t elem_sz, int (*comp)(const void*, const void*)) {
    // Initializing left position variable, right position variable,
    // and dynamically allocating secondary array
    int l = 0;
    int r = len - 1;
    void* array2 = (void*)malloc(elem_sz * len);
    
    // Calling helper function with left and right position variables.
    mrg_sort_helper(array, array2, len, elem_sz, comp, l, r);
    
    // Freeing memory secondary array
    free(array2);
}