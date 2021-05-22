#include <iostream>

int transpile(char teste)
{
  switch (teste)
  {
  case 'I':
    return 1;
  case 'V':
    return 5;
  case 'X':
    return 10;
  case 'L':
    return 50;
  case 'C':
    return 100;
  case 'D':
    return 500;
  case 'M':
    return 1000;
  default:
    return 0;
  }
}

int main()
{
  char romanNumber[10];
  scanf("%s", romanNumber);

  int numberArray[sizeof(romanNumber) - 1];
  for (int i = 0; i < sizeof(romanNumber); i++)
  {
    numberArray[i] = transpile(romanNumber[i]);
  }
  int sum = numberArray[sizeof(romanNumber) - 1];
  int prevNumber;
  for (int i = sizeof(romanNumber) - 2; i >= 0; i--)
  {
    if (numberArray[i] < numberArray[i + 1])
    {
      prevNumber = numberArray[i + 1];
      sum = sum - numberArray[i];
    }
    else if (numberArray[i] < prevNumber)
    {
      sum = sum - numberArray[i];
    }
    else
    {
      sum = sum + numberArray[i];
    }
  }
  printf("%d\n", sum);

  return 0;
}