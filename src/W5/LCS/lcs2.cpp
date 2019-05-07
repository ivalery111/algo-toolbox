#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::max;
using std::vector;

int lcs(vector<int> &first_sequance, vector<int> &second_sequance)
{

  vector<vector<int>> table(first_sequance.size() + 1, vector<int>(second_sequance.size() + 1));

  for (int row = 0; row <= first_sequance.size(); row++)
  {
    for (int column = 0; column <= second_sequance.size(); column++)
    {
      if (row == 0 || column == 0)
        table[row][column] = 0;
      else if (first_sequance[row - 1] == second_sequance[column - 1])
        table[row][column] = table[row - 1][column - 1] + 1;
      else
        table[row][column] = max(table[row - 1][column], table[row][column - 1]);
    }
  }
  return table[first_sequance.size()][second_sequance.size()];
}

int main()
{
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++)
  {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++)
  {
    std::cin >> b[i];
  }

  std::cout << lcs(a, b) << std::endl;
}
