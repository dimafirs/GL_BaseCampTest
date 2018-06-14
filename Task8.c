/* This fuction calculate amount of water that will left between blocks
  after rain*/
   
int calc_water_amount(int *blockArray, int length) {
	unsigned int i;
	int leftIndex = 0, rightIndex = length - 1, maxIndex = 0;
	int absMax = blockArray[maxIndex];
	int leftMax = 0, rightMax = 0;
	int waterAmount = 0;

	//search absolute maximum from input blocks
	for (i = 1; i < length; i++)
		if (blockArray[i] > absMax) {
			absMax = blockArray[i];
			maxIndex = i;
		}

	//calculate amount of water at the left side from absMax
	while (leftIndex < maxIndex) {
		if (blockArray[leftIndex] > leftMax) //search local maximum
			leftMax = blockArray[leftIndex];
		waterAmount += leftMax - blockArray[leftIndex]; //add amount of water in current block
		leftIndex++; // go right
	}

	//the same thing from a right side
	while (rightIndex > maxIndex) {
		if (blockArray[rightIndex] > rightMax)
			rightMax = blockArray[rightIndex];
		waterAmount += rightMax - blockArray[rightIndex];
		rightIndex--;
	}

	return waterAmount;
}
