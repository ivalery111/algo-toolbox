#include <iostream>
#include <vector>
#include <algorithm>

using std::max;
using std::vector;

int KnapSackDP(int W, const vector<int> &weights, int n, vector<vector<int>> &table)
{
  int result;

  // Memoization
  if (table[W][n] != __INT_MAX__)
    return table[W][n];
  //---

  if (n == 0 || W == 0)
    result = 0;
  if (weights[n - 1] > W)
    result = KnapSackDP(W, weights, n - 1, table);
  else
  {
    int tmp1 = KnapSackDP(W, weights, n - 1, table);
    int tmp2 = weights[n - 1] + KnapSackDP(W - weights[n - 1], weights, n - 1, table);
    result = max(tmp1, tmp2);
  }
  // Memoization
  table[W][n] = result;
  //---

  return result;
}

int optimal_weight(int W, const vector<int> &w)
{
  // Memoization table
  vector<vector<int>> table(W + 1, vector<int>(w.size() + 1, __INT_MAX__));
  //---

  int result = KnapSackDP(W, w, w.size(), table);

  return result;
}

int main()
{
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++)
  {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
