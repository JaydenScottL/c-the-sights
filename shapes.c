# include <stdio.h>


/*
Name: Jayden LeCorps
Date: 9/12/2024
*/


// createPyramid function

void createPyramid(int size){

	for(int i =0; i< size;i++){

		// print blank spaces to move the star toward the center of the pyramid
		for(int k = 0;k < size - i;k++){
			printf(" ");
		}

		// print stars to fill the pyramid
		for(int j = 0;j <= i*2;j++){
			printf("*");
		}

		// new line after each row of stars

		printf("\n");

	}
}

// createPyramidReverse function

void createPyramidReverse(int size){

	for(int i = size-1; i >= 0 ;i--){

		// print blank spaces to move the star toward the center of the pyramid
		for(int k = 0;k < size - i;k++){
			printf(" ");
		}

		// print stars to fill the pyramid
		for(int j = 0;j <= i*2;j++){
			printf("*");
		}

		// new line after each row of stars

		printf("\n");

	}
}

int main(){

	

	int size;

	printf("Enter a number: ");
	scanf("%d",&size);

	// call the createPyramid function 

	createPyramid(size);

	printf("\n");

	// call the createPyramidReverse function

	createPyramidReverse(size);

	return 0;
}
