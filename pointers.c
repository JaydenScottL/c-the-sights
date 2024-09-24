# include <stdio.h>
# include <stdlib.h>

void doStuff(int *x){
    printf("x: %d\n",x[0]);
    printf("Size of data %ld\n",sizeof(x));
}

int main(){

    

    int x = 10;

    int *p;
    int **o;

    p = &x;
    o = &p;

    printf("%d\n", x);
    printf("%d\n", *p);
    printf("%d\n", **o);

    printf("%p\n", &x);
    printf("%p\n",p);

    int array_x[] = {1,2,3};
    
    doStuff(array_x);

    int *z = malloc(10 * sizeof(int));

    return 0;
}