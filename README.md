# homework-2
Homework on dynamic memory allocation, due Feb 13 11:59 PM.

## Context
For this assignment you will be creating a user-defined array. This user-defined array will be a structure and it will look like this:

```c
	struct _float_array {
		float *data;
		int size;
	};
	typedef struct _float_array farray;
```

Where the member `data` is going to be the variable that is going to contain (or rather, point to) the contents of the array. You will use dynamic memory allocation to reserve the memory so that you can use `data` as an array. The `size` member is for keeping track of the size of your array so that you do not have to remember what it is constantly.

## Objectives
With this in mind now, your task is to create a library to interact with this data structure.

### Initializing our array
Since `data` is going to be a dynamically allocated array, we need to allocate the memory using either `malloc` and `calloc`. While I will provide an example for `malloc`, it is up to you to implement `calloc`.

```c
    void mallocate(farray *array, int size) {
        array->data = (float *) malloc(size * sizeof(float));
        array->size = size;
    }
```

Here is the function prototype for initializing `data` using `calloc`:

```c
    void callocate(farray *array, int size);
```
### Accessing/changing data in our array
Now that we have functions to initialize our user-made array, we should create functions to access the data and change the data. A function for accessing data, and a function for writing values to our user-defined array, essentially taking the role of the square brackets "[]".

```c
    float access_value(farray *array, int index);
    int set_value(farray *array, int index, float value);
```

The role of `access_value` is to return the value of our array at the position specified by the argument `index`. That is why the function returns a `float`. When you implement `access_value` make sure that the argument `index` is less than the `size` before accessing the data in your array. If `index` is greater than `size`, print that the index is out of bounds and return a `-1.0`.

For `set_value`, like with `access_value`, you need to check that `index` is less than the `size` of your array. If `index` is less than `size` then you access your data using `index` as your index. If you are able to set a value to your array you should return a non-negative number. Otherwise, you should return a negative number, along with a print statement that the index is out of bounds.

### Printing values
Next you should create a function that will print the contents of the array. The structure has a `size` member. **Use it!** Iterate through the entire array and separate each value with a space character (' '). After you iterate, print a new line character('\n').

```c
    void print_farray(farray *array);
```

### Free-ing your data
Since we are using dynamic memory allocation, it is **very important** that we free the memory we reserved. In our case. We need to free `data`. 

```c
    void free_farray(farray *array);
```
Remember for every variable that we create and initialize, we need to free the variable.

### main.c
I have provided a `main.c` file for you to use to make sure that your code works. In addition to the code I gave you, you need to create an additional `farray` variable and initialize it with either `mallocate` or `callocate`. Then you must fill the array with values, then print them. Of course when you are done with you program you are going to free add dynamically allocated data.

## Makefile
This assignment will require that you create a makefile to compile the code. When grading, I will simply type `make` to compile your homework.

## Additional info
Since you will be using dynamic memory allocation I will be testing your program with valgrind.
If you have not installed it, you can do so with this command:

```
    sudo apt install valgrind
```

When grading your assigment, I will be using valgrind's leak-check feature to see if there are any memory leaks in your assignment. Assuming that the name of your executable is ptr_homework. I will run this exact command:

```
    valgrind --leak-check=yes ./ptr_homework
```


## Rubric

|Requirement|Score  |
| :---:     | :---: |
| Header file function prototypes | 25% |
| C file function implementation  | 25% |
| Additional testing in main.c | 15% |
| Makefile | 20%|
| Code runs without error | 15% |
|Total | 100% |
