
#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"

int main(void) {
	Queue q = QueueNew();
	for (int i = 1; i <= 100000; i++) {
		QueueEnqueue(q, i);
			
	}
	// dequeue 1 to 50000
	for (int j = 1; j <= 50000; j++) {	
		QueueDequeue(q);
	}
	// enqueue 11 to 20000
	for (int i = 11, j = 6; i <= 20000; i++, j++) {
		QueueEnqueue(q, i);	
	}
	// dequeue 16 to 20000
	for (int j = 16; j <= 20000; j++) {
		QueueDequeue(q);
	}
	QueueFree(q);
}

