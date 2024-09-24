#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// creates a square with user input

void squareCreate(char charString[], int shapeSize, size_t stringSize){

    // if string is empty, print only stars
    if(stringSize == 0){
        charString = "*";
        stringSize = 1;
    }

    printf("\n");

    int index = 0;
    
    
    for(int i = 0; i < shapeSize;i++){
        // print full row only if first or last run of loop
        if(i == 0 || i == shapeSize -1){
            for(int j = 0; j < shapeSize;j++){
                printf("%c",charString[index % stringSize]);
                index++;
            }
        }else{

            // print a character, followed by spaces, and another character to create the unfilled square
            printf("%c",charString[index % stringSize]);

            index++;
                
            for(int j = 0; j < shapeSize - 2; j++){
                
                printf(" ");
            }

            printf("%c",charString[index % stringSize]);

            index++;
        }

        printf("\n");
    }

    printf("\n");

}

void emptyDiamond(char charString[], int shapeSize, size_t stringSize){

    // if string is empty, print only stars
    if(stringSize == 0){
        charString = "*";
        stringSize = 1;
    }

    int index = 0;

    // prints first half of diamond
	for(int i = 0; i< shapeSize;i++){

        // print number of characters equal to the shapesize - current loop index
		for(int k = 0;k < shapeSize - i ;k++){
			
            printf("%c",charString[index % stringSize]);
            index++;
		}

        // fill with whitespaces
		for(int j = 0;j < i*2 ;j++){
			printf(" ");
		}

        // print other half of diamond
        for(int k = 0;k < shapeSize - i ;k++){
			
            printf("%c",charString[index % stringSize]);
            index++;
		}

        if(i != shapeSize -1 ){
		    printf("\n");
        }

	}

    // prints lower half of diamond
    for(int i = shapeSize; i >= 0 ;i--){
        // print number of characters equal to the shapesize - current loop index
		for(int k = 0;k < shapeSize - i;k++){
            printf("%c",charString[index % stringSize]);
            index++;
		}

        // fill with whitespaces
		for(int j = 0;j < i*2;j++){
			printf(" ");
		}

        // print other half of diamond
        for(int k = 0;k < shapeSize - i;k++){
            printf("%c",charString[index % stringSize]);
            index++;
		}

		printf("\n");

	}
}

int main(int argc, char *argv[]){

    // make sure there are 3 user defined arguments
    if(argc < 4){
        printf("Need at least 3 arguments\n");
        return 0;
    }


    // checks that length of shape choice string is > 0, and shape size > 0
    if(strlen(argv[1]) > 0 && atoi(argv[3]) > 0){

        // prints shape based on user input
        if(strcmp(argv[1],"square") == 0){

            printf("Creating square with input \"%s\" and size %d\n", argv[1],atoi(argv[2]));
        
            squareCreate(argv[2],atoi(argv[3]),strlen(argv[2]));
        
        }

        else if(strcmp(argv[1],"diamond") == 0){
            printf("Creating diamond with input \"%s\" and size %d\n", argv[1],atoi(argv[2]));
        
            emptyDiamond(argv[2],atoi(argv[3]),strlen(argv[2]));
        } else if(strcmp(argv[1],"both") == 0){
            printf("Creating diamond and square with input \"%s\" and size %d\n", argv[1],atoi(argv[2]));
            squareCreate(argv[2],atoi(argv[3]),strlen(argv[2]));
            emptyDiamond(argv[2],atoi(argv[3]),strlen(argv[2]));
        }else{
            printf("\"%s\" is not a valid shape. Options are square, diamond, both.",argv[1]);
        }
    } else{
        printf("Program requires 3 arguments: shape (string), text (string), size (int). Options for shape are square, diamond, both.");
    }

    return 0;
}