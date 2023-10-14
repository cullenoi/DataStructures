
void insertion_sort(int array[], int length)
{
	int i;
	for (int pass = 0; pass < length - 1; pass++)
	{
		// We will move this value into position
		int temp = array[pass + 1];

		// Move everything larger than 'temp' along one space in the array
		// there is space for this because we can occupy location [pass+1] which
		// contains 'temp'
		for (i = pass + 1; i > 0; i--)
		{
			if (array[i - 1] > temp)
			{
				array[i] = array[i - 1];
			}
			else
			{
				break;
			}
		}

		array[i] = temp;
	}
}

/* Coding challenge: you can write this without using 'break'.
 * The trick is to notice that there are _two_ conditions controlling the inner loop
 * One is that i must be strictly greater than zero for the loop to continue (that's already in the loop condition)
 * The other is that array[i-1] must be greater than temp. That's currently handled by the else/break
 * But you could rewrite the condition of the for loop instead. Try it!
 * /
