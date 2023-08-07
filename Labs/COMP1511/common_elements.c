// copy all of the values in source1 which are also found in source2 into destination
// return the number of elements copied into destination

int common_elements(int length, int source1[length], int source2[length], int destination[length]) {
    int i = 0;
        while (i < length) {
            int j = 0;
                while (j < length) {
                    if (source1[i] == source2[j]) {
                        int k = 0;
                        while (k < length) {
                            destination[k] = source1[i];
                            k++;
                        }
                    }
                }
        }      
    return 42;
}



// You may optionally add a main function to test your common_elements function.
// It will not be marked.
// Only your common_elements function will be marked.
