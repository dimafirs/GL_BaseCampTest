struct retdata {
	int min;
	int max;
	int avg;
};


/*Here is just refactored and optimized code,but it's not working correctly.
This code will return the same values as super_func
from example (in example we check only zero element
of the array, because *arr doesn't changing */

int super_func_old(int *array, unsigned int length, struct retdata *ret) {
	ret->min = array[0];
	ret->max = array[0];
	/*in example ret->avg after cycles will be only positive
	code below make the same as abs()*/
	if(array[0]>=0)
		ret->avg = array[0];
	else
		ret->avg = -(array[0]);
	return 0;
}

/*Here is correctly working code that returns max value of *array in
ret->max, min value in ret-> min and average value in ret->avg */

int super_func(int *array, unsigned int length, struct retdata *ret) {
	unsigned int i;
	ret->min = array[0];
	ret->max = array[0];
	ret->avg = array[0];
	for (i = 1; i < length; i++) {
		if (ret->min > array[i])
			ret->min = array[i];

		if (ret->max < array[i])
			ret->max = array[i];

		ret->avg += array[i];
	}
	ret->avg /= length;
	return 0;
}
