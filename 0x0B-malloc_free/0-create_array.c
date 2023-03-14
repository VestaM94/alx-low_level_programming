#include <stdlib.h>


/**




* create_array - creates an arry of chars, and initializes it with a char


* @size: size of array


* @c: specific char


* Return: returns a pointer to the array, or NULL if it fails


*/



char* create_array(unsigned int size, char c) {
    if (size == 0) {
        return NULL;
    }

    char* array = (char*) malloc(size * sizeof(char));
    if (array == NULL) {
        return NULL;
    }

    for (unsigned int i = 0; i < size; i++) {
        array[i] = c;
    }

    return array;
}

