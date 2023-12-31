// Implementation of the Queue ADT using a circular array

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"

#define DEFAULT_SIZE 16 // DO NOT change this line

// DO NOT modify this struct
struct queue {
	Item *items;
	int size;
	int capacity;
	int frontIndex;
};

/**
 * Creates a new empty queue
 */
Queue QueueNew(void) {
	Queue q = malloc(sizeof(*q));
	if (q == NULL) {
		fprintf(stderr, "couldn't allocate Queue");
		exit(EXIT_FAILURE);
	}

	q->items = malloc(DEFAULT_SIZE * sizeof(Item));
	if (q->items == NULL) {
		fprintf(stderr, "couldn't allocate Queue");
		exit(EXIT_FAILURE);
	}

	q->size = 0;
	q->capacity = DEFAULT_SIZE;
	q->frontIndex = 0;
	return q;
}

/**
 * Frees all resources associated with the given queue
 */
void QueueFree(Queue q) {
	free(q->items);
	free(q);
}

/**
 * Adds an item to the end of the queue
 */
void QueueEnqueue(Queue q, Item it) {
	// Double the capacity and realloc the size of the array
	if (q->size == q->capacity) {
        int current_capacity = q->capacity;
        q->capacity *= 2;
        q->items = realloc(q->items, q->capacity * sizeof(Item));
        // if array is empty print error to stderr
        if (q->items == NULL) {
            fprintf(stderr, "couldn't resize Queue\n");
            exit(EXIT_FAILURE);
        }
        // for loop to re-arrange all elements before front index to ahead of front index
        for (int i = 0; i < q->frontIndex; i++, current_capacity++) {
            q->items[current_capacity] = q->items[i];
        }
    }

    // finding the back index and adding passed element to the end
    int back_index = (q->size + q->frontIndex) % q->capacity;
    q->size++;
	q->items[back_index] = it;
}

/**
 * Removes an item from the front of the queue and returns it
 * Assumes that the queue is not empty
 */
Item QueueDequeue(Queue q) {
    // Record the deleted element
    int deleted_element = q->items[q->frontIndex];

    // Go to next index
    q->frontIndex = (q->frontIndex + 1) % q->capacity; 
    q->size--;

    // Return the deleted element
    return deleted_element;
}

/**
 * Gets the item at the front of the queue without removing it
 * Assumes that the queue is not empty
 */
Item QueueFront(Queue q) {
	assert(q->size > 0);

	return q->items[q->frontIndex];
}

/**
 * Gets the size of the given queue
 */
int QueueSize(Queue q) {
	return q->size;
}

/**
 * Returns true if the queue is empty, and false otherwise
 */
bool QueueIsEmpty(Queue q) {
	return q->size == 0;
}

/**
 * Prints the queue to the given file with items space-separated
 */
void QueueDump(Queue q, FILE *fp) {
	for (int i = q->frontIndex, j = 0; j < q->size; i = (i + 1) % q->capacity, j++) {
		fprintf(fp, "%d ", q->items[i]);
	}
	fprintf(fp, "\n");
}

/**
 * Prints out information for debugging
 */
void QueueDebugPrint(Queue q) {

}

