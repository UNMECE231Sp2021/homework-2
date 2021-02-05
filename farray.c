#include <stdio.h>
#include "float_array.h"

void mallocate(farray *array, int size) {
	array->data = (float *) malloc(size * sizeof(float));
	array->size = size;
}
