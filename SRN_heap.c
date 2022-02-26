// Name: Manodnya K H
// SRN: PES2UG20CS187
#include "heap.h"
#include <stdlib.h>

// Initialise heap
// Set heap size to 0
// Set heap max_size to paramter max_size
// Allocate memory of max_size to the array
void init_heap(heap_t *heap, int max_size)
{
    heap_t *h;
    h = malloc(sizeof(heap_t));
    h->size = 0;
    h->arr = malloc(max_size);
}

// Insert element "key" to heap "heap"
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
void insert(heap_t *heap, int key, int *count_ptr)
{
    count_ptr = 0;
    int i;
    if (heap->size == heap->max_size)
        return;
    // resizeHeap(heap);
    heap->size++;
    i = heap->size - 1;
    while (i >= 0 && key > heap->arr[(i - 1) / 2])
    {
        heap->arr[i] = heap->arr[(i - 1) / 2];
        i = i - 1 / 2;
    }
    heap->arr[i] = key;
}

// *Removes and Returns* the maximum element in the heap
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
int extract_max(heap_t *heap, int *count_ptr)
{
    int data;
    if (heap->size == 0)
        return -1;
    data = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--; // reducing the heap size 
    heapify(heap, 0);  
    count_ptr = 1;
    return data;  
}

// Searches for the element key in the heap
// Returns the element if found, else -1
int search(const heap_t *heap, int key, int *count_ptr)
{
    if (heap->size==0)
    {
        return -1;
    }
    else
    {
        for(int i =0; i<heap->size; i++){
            if (key==heap->arr[i])
            {
                return key;
            }
        }
    }
    return -1;
}

// Returns the maximum value of the element in the heap
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
int find_max(const heap_t *heap, int *count_ptr)
{
    if (heap->size == 0)
        return -1;
    count_ptr = 1;
    return heap->arr[0];
}

// Returns the minimum value in the heap
int find_min(const heap_t *heap, int *count_ptr) {
    return heap->arr[(heap->size) - 1];
}

// Clears the heap for reuse
void clear_heap(heap_t *heap) {}

// Frees all resources acquired to initialize heap
void free_heap(heap_t *heap) {}

void heapify(heap_t *h, int i)
{
    int l, r, max, temp;
    l = leftChild(h, i);
    r = rightChild(h, i);
    if (l != -1 && h->arr[l] > h->arr[i])
        max = l;
    else
        max = i;
    if (r != -1 && h->arr[r] > h->arr[max])
        max = r;
    if (max != i)
    {
        temp = h->arr[i];
        h->arr[i] = h->arr[max];
        h->arr[max] = temp;
        heapify(h, max);
    }
}
