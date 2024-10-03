#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Name: Jayden LeCorps
Date: 10/1/2024
*/

// room struct
typedef struct{
    char room_name[1024];
    char room_code[100];
    char room_description[4096];


} room;

int main(int argc, char *argv[]){

    // open file with user input
    FILE *fp = fopen(argv[1],"r");

    // end program if file not found
    if(fp == NULL){
        printf("Could not find file.");
        return 0;
    }

    // total lines read
    int count = 0;

    // index of current working struct
    int index = 0;
    
    // empty character array for line read from file
    char line[4096];

    // allocate initial memory for struct
    room *s = (room*)malloc(sizeof(room));

    while(fgets(line,sizeof(line),fp) != NULL){
        
        // op = current operation based on which line we're working with it
        int op = count % 4;

        // removes new line and whitespaces, adds room name to current index
        if(op == 0){

            char *start = line + strspn(line, " \t\n\r");
            char *end = start + strcspn(start, " \t\n\r");
            *end = '\0';
            strcpy(line, start);

            char sub[4096];
            strncpy(sub,line + 11,800);
            strcpy(s[index].room_name, sub);
        }

        // adds room code to current index
        if(op == 1){
            char sub[3];
            strncpy(sub,line + 11,2);
            sub[2] = '\0'; // important to add a null terminator
            
            strcpy(s[index].room_code, sub);
        }

        // removes new line and whitespaces, adds room description to current index
        if(op == 2){
            char *start = line + strspn(line, "\t\n\r");
            char *end = start + strcspn(start, "\t\n\r");
            *end = '\0';
            strcpy(line, start);

            char sub[4096];
            strncpy(sub,line + 18,4000);

            strcpy(s[index].room_description, sub);
        }

        // allocate space for next struct room
        if(op == 3){
            s = realloc(s,(1 + count) * sizeof(room));
            index = (count + 1)/4;
        }

        // increase total lines read
        count++;
    }

    //print all rooms

    for(int i = 0;i < count/4 + 1;i++){
        printf("Room %s: %s",s[i].room_code,s[i].room_name);
    }
}