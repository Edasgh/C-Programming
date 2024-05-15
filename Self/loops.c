#include <stdio.h>

int main()
{
    int num, i;
    printf("Enter a number\n");
    scanf("%d", &num);
    printf("Now,printing the numbers\n");
    //do-while loop
    // do
    // {
    //     i += 1;
    //     printf("%d\n", i);
    // } while (i < num);

    // while loop
    // while(i<num){
    //     printf("%d\n",i);
    //     i+=1;
    // }

//for loop
for(i=0;i<num;i++){
    printf("%d\n",i);
}
    return 0;
}