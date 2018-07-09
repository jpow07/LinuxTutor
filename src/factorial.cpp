#include "factorial.h"

int factorial(int n){
  if(n < 0)
    return 0;
  if(n == 0 || n == 1) return 1;
  else
    return n * factorial(n-1);

}

int add(int n, int m){
  return n + m;
}

int gcd(int a, int b){
  if (a == 0 || b == 0)
    return 0;
  if(a == b)
    return a;

  if (a > b)
    return gcd(a-b, b);
  return gcd(a, b-a);

}
