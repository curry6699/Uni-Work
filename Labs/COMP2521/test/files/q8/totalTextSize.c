
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Fs.h"

int file_size(File file);

int totalTextSize(Fs fs) {
	int size_f = 0;
	FileList temp = fs->root->files;
	while (temp != NULL) {
		size_f += file_size(temp->file);
		temp = temp->next;
	}
	return size_f;
}

int file_size(File file) {
	if (file->text == NULL) {
		return 0;
	}
	int i = 0;
	while (file->text[i] != '\0') {
		i++;
	}
	return i;
}