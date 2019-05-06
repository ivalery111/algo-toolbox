#include <iostream>
#include <vector>
#include <limits>

using std::numeric_limits;
using std::vector;

int get_change(int money)
{
  vector<int> coins = {1, 3, 4};
  vector<int> MinNumCoins(money + 1);

  for (int m = 1; m <= money; ++m)
  {
    MinNumCoins[m] = numeric_limits<int>::max();
    for (const int &coin : coins)
    {
      if (m >= coin)
      {
        int NumCoins = MinNumCoins[m - coin] + 1;
        if (NumCoins < MinNumCoins[m])
        {
          MinNumCoins[m] = NumCoins;
        }
      }
    }
  }
  return MinNumCoins[money];
}

int main()
{
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
