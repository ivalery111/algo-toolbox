#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

long long max_dot_product(vector<int> a, vector<int> b)
{
  // write your code here
  long long result = 0;
  std::sort(a.rbegin(), a.rend());
  std::sort(b.rbegin(), b.rend());

  for (int i = 0; i < a.size(); ++i)
  {
    result += ((long long)a[i]) * b[i];
  }

  // for (size_t i = 0; i < a.size(); i++) {
  //   result += ((long long) a[i]) * b[i];
  // }
  return result;
}

void StressTest()
{
  int n = rand() % 1000000 + 2;
  long long result, expected=0;
  vector<int> a(n), b(n);

  for (int i = 0; i < a.size(); ++i)
  {
    a[i] = rand() % 100000 + 2;
  }
  for (int i = 0; i < b.size(); ++i)
  {
    b[i] = rand() % 100000 + 5;
  }

  result = max_dot_product(a, b);

  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());

  for (int i = 0; i < a.size(); ++i)
  {
    expected = expected + (a[i] * b[i]);
  }

  if (expected == result)
  {
    std::cout << "YES : " << result << " = " << expected << "\n";
  }
  else
  {
    std::cout << "-----NO : " << result << " = " << expected << "\n";
  }
}

void StartTest()
{
  for (int i = 0; i < 10000; i++)
  {
    StressTest();
  }
}

int main()
{
  //StartTest();
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++)
  {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++)
  {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
