#include <stdio.h>

int main()
{
  int prime;
  scanf("%i", &prime);
  int primeCount = 0;
  for (int i = 2; i < prime; i++)
  {
    if (prime % i == 0)
    {
      primeCount++;
    }
  }
  if (primeCount == 0)
  {
    printf("%d is a prime number!", prime);
    return 0;
  }
  printf("%d is NOT a prime number!", prime);

  return -1;
}