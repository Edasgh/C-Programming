# include <stdio.h>

//print the largest number
void main(){
    int num_1;
    int num_2;

  printf("Enter a number here\n");
  scanf("%d",&num_1);
  printf("Enter another number here\n");
  scanf("%d",&num_2);

  if(num_1>num_2)
  {
    printf("The largest number is %d\n",num_1);
  }else{
    printf("The largest number is %d\n",num_2);
  }

}