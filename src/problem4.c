#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define true 1
#define false 0

int main()
{
  int i,j,cur1,cur2;
  i = 999;
  while (i > 1)
  {
    cur1 = i * i;
    cur2 = i * (i - 1);
    char cur_str1[7];
    char cur_str2[7];
    memset(cur_str1, 0, 7);
    memset(cur_str2, 0, 7);
    sprintf(cur_str1, "%d", cur1);
    sprintf(cur_str2, "%d", cur2);
    if (is_palindrome(cur_str1) == true)
    {
      printf("Largest 3-digit palindrome: ");
      printf(cur_str1);
      printf("\n");
      printf("Found by multiplying %d and %d\n", i, i);
      exit(0);
    }
    if (is_palindrome(cur_str2) == true)
    {
      printf("Largest 3-digit palindrome: ");
      printf(cur_str2);
      printf("\n");
      printf("Found by multiplying %d and %d\n", i, (i-1));
      exit(0);
    }
    i--;
  }
}

int is_palindrome(char * str)
{
  // set pointers to front and end of str
  int start = 0;
  int end = 5;
  while (str[end] == 0)
  {
    end--;
  }
  while (start <= end)
  {
    if (str[start] != str[end])
    {
      return false;
    }
    start++;
    end--;
  }
  return true;
}
