#include <stdio.h>

//create function
int banknote()
{
    int A,B,S,N,z; //declare variables
    scanf("%d %d %d %d",&A,&B,&S,&N); //get inputs
    z=(S-B*N)/(A-B); //find z
    return (z);
}

//main function
void main()
{
    int retval;
    retval=banknote(); //z to retval
    if(retval<0)
        {
            printf("%d",-1);
        }else{
            printf("%d",retval);
        }
}
