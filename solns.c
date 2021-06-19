/* Enter your solutions in this file */
#include <stdio.h>
#include <assert.h>


int max(int [], int);
int min(int [], int);
float average(int [], int);
int mode(int [], int);
int factors(int, int []);
int main(void) {
  int x[] = {9,5,6,10,2,-3,4};
  assert (max(x, 7) == 10);

  int y[] = {5};
  assert (max(y, 1) == 5);
  printf("Max: passed\n");

  int a[] = {9,5,6,10,2,-3,4};
  assert (min(a, 7) == -3);

  int b[] = {5};
  assert (min(b, 1) == 5);
  printf("Min: passed\n");

  int c[] = {9,5,6,10,2,-3,4};
  assert ((average(c, 7) - 4.7142) < 0.001);

  int d[] = {5};
  assert (average(d, 1) == 5.0);
  printf("Average: passed\n");

  int e[] = {4, 9,5,6,5,10,0,2,-3, -3,4, 4};
  assert ((mode(e, 12) == 4));

  int f[] = {5};
  assert (mode(f, 1) == 5);
  printf("Mode: passed\n");

  int ret[100] = {0};
  int count = factors(180, ret);
  assert (count == 5);
  assert (ret[0] == 2);
  assert (ret[1] == 2);
  assert (ret[2] == 3);
  assert (ret[3] == 3);
  assert (ret[4] == 5);


  count = factors(143, ret);
  assert (count == 2);
  assert (ret[0] == 11);
  assert (ret[1] == 13);
  printf("Factors: passed\n");
  
  return 0;
  }

  int max(int a[100],int n)
{
  int m=a[0];
  for(int i=1;i<n;++i)
  {
    if(a[i]>m)
      m=a[i];
  }
  return m;
}
int min(int t[100],int n)
{
  int m=t[0];
  for(int i=1;i<n;++i)
  {
    if(t[i]<m)
      m=t[i];
  }
  return m;
}
float average(int t[100], int n)
{
  int s=0;
  for(int i=0;i<n;i++)
    s+=t[i];
  return (float)(s/n);
}
int mode(int a[100], int n)
{
  int mode=a[0];
  int count=0;
  int max=0;
  if(n==1)
    return a[0];
  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      if(a[i]==a[j])
        count++;
    }
    if(count>max)
    {
     max=count;
     mode=a[i];
    }
    }
return mode;
}
int factors(int n, int a[])
{
  int count=0;
  for(int i=0;i<100;++i)
  {
    if(n>0 && n!=1)
    {
      for(int j=2;j<100;j++)
      {
        if(n%j==0)
        {
          a[i]=j;
          count++;
          n=n/j;
          break;
        }

      }
    }
    else
      break;
  }
    return count;
}
