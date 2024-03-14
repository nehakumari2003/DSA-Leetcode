#include <iostream>
using namespace std;

int multiply(int x, int y) {
  
  if (x == 0 || y == 0)
    return 0;


  if (y > 0)
    return x + multiply(x, y - 1); 
  else
    return -x + multiply(x, y + 1); 
}

int main() {
  int n1, n2;
  cout << "Input the first number: ";
  cin >> n1;
  cout << "Input the second number: ";
  cin >> n2;

  
  int result = multiply(n1, n2);

  cout << "Product of " << n1 << " and " << n2 << ": " << result << endl;

  return 0;
}