#include <stdio.h>
#include <string.h>

//create function
int Palindrome(char *S) {
	//variables decleration
    int len = strlen(S);
    int count = 0;
    int countl=0;
    int countr=0;
    int i, j;

//check letters to left
    for (i = 0, j = len - 1; i < j; ) {
        if (S[i] == S[j]) {
            i++;
            j--;
        } else {
            j--;
            countl++;
        }
    }
//check letters to right
    for (i=len-1,j=0;i>j;){
      if(S[i]==S[j]){
        i--;
        j++;
      }else{
        j++;
        countr++;
      }
    }
//get minimum count
  if (countl<countr){
    count=countl;
  }else{
    count=countr;
  }
    return count;
}

//main function
int main() {
    char string[500];
    printf("Enter any String : ");
    scanf("%s",&string);
    int result = Palindrome(string);
    printf("%d\n", result);

    return 0;
}














/*
#include <stdio.h>
#include <string.h>

int Palindrome(char string[500]) {
    int len = strlen(string);
    int count = 0;
    int countl=0;
    int countr=0;
    int i, j;

    for (i = 0, j = len - 1; i < j; ) {
        if (string[i] == string[j]) {
            i++;
            j--;
        } else {
            j--;
            countl++;
        }
    }
    for (i=len-1,j=0;i>j;){
      if(string[i]==string[j]){
        i--;
        j++;
      }else{
        j++;
        countr++;
      }
    }
  if (countl<countr){
    count=countl;
  }else{
    count=countr;
  }
    return count;
}

int main() {
    char string[500];
    printf("Enter any String : ");
    scanf("%s",&string);
    int result = Palindrome(string);
    printf("%d\n", result);

    return 0;
}

*/
