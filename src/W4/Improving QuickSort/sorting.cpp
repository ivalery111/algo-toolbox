#include <iostream>
#include <vector>
#include <cstdlib>
#include <utility>

using std::pair;
using std::swap;
using std::vector;

/**
 * Partition3 divide the array to 3 parts:
 * 1-st part: <x
 * 2-nd part: =x
 * 3-rd part: >x
 **/
pair<int, int> partition3(vector<int> &a, int l, int r)
{
  int pivot = l;

  pair<int, int> result;

  while (pivot <= r)
  {
    if (a[pivot] < a[l])
    {
      swap(a[pivot], a[l]);
      ++pivot;
      ++l;
    }
    else if (a[pivot] == a[l])
    {
      ++pivot;
    }
    else
    {
      swap(a[r], a[pivot]);
      --r;
    }
  }

  result.first = l;
  result.second = pivot;

  return result;
}

void randomized_quick_sort(vector<int> &a, int l, int r)
{
  if (l >= r)
  {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);

  auto p = partition3(a, l, r);

  randomized_quick_sort(a, l, p.first);
  randomized_quick_sort(a, p.second, r);
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i)
  {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i)
  {
    std::cout << a[i] << ' ';
  }
}
