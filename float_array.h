struct _float_array {
	float *data;
	int size;
};

typedef struct _float_array farray;

// Either one of these functions can be called to initialize farray
void mallocate(farray *array, int size);
void callocate(farray *array, int size);

// Since we cannot have user-defined behavior for [], we must use functions
int set_value(farray *array, int index, float value);
float access_value(farray *array, int index);

// Need a function to print the data in our user-defined array
void print_farray(farray *array);

// Since we will dynamically allocate memory for data, we must free it
//	when we are done or at the end of the program.
void free_farray(farray *array);
