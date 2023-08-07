
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int leng(Node temp_b);
int find_tol(Node temp_b, Node temp_a);

// Worst case time complexity of this solution: O(n^2)

int numSubsequences(List listA, List listB, int tolerance) {
	Node temp_a = listA->first;
	Node temp_b = listB->first;
	int num_seq = 0;
	int size_b = leng(temp_b);
	for (temp_a = listA->first; temp_a != NULL; temp_a = temp_a->next) {
		temp_b = listB->first;
		int neg_tol = find_tol(temp_b, temp_a);
		int diff = size_b - neg_tol;
		if (diff <= tolerance) {
			num_seq++;
		}
	}
	return num_seq;
}

int leng(Node temp_b) {
	int size_b = 0;
	for (size_b = 0; temp_b != NULL; temp_b = temp_b->next) {
		size_b++;
	}
	return size_b;
}

int find_tol(Node temp_b, Node temp_a) {
	int neg_tol = 0;
	for (Node temp_c = temp_a; temp_b != NULL && temp_c != NULL; temp_b = temp_b->next, temp_c = temp_c->next) {
		int b_val = temp_b->value;
		int c_val = temp_c->value;
		if (b_val == c_val) {
			neg_tol++;
		}
	}
	return neg_tol;
}