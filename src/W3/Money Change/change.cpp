#include <iostream>
#include <vector>

std::vector<int> coins = {1, 5, 10};

int get_change_greedy(int m)
{
  int result = 0;

  for (int i = coins.size() - 1; i >= 0; i--)
  {
    while (m >= coins[i])
    {
      result++;
      m -= coins[i];
    }
  }
  return result;
}

int main()
{
  int m;
  std::cin >> m;
  std::cout << get_change_greedy(m) << '\n';
}
