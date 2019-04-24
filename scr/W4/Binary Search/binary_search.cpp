#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

// int binary_search(const vector<int> &a, int x)
// {
//   int left = 0, right = (int)a.size();
//   //write your code here
//   int mid = a.size() / 2;
// }

int binary_search_my_impl(const vector<int> &a, int low, int high, int key)
{
  if (high < low) // when searching elements is not found
    return -1;

  int mid = low + (high - low) / 2;

  if (key == a[mid])
    return mid;

  else if (key < a[mid])
    binary_search_my_impl(a, low, mid - 1, key);
  else
    binary_search_my_impl(a, mid + 1, high, key);

  //return {};
}

int linear_search(const vector<int> &a, int x)
{
  for (size_t i = 0; i < a.size(); ++i)
  {
    if (a[i] == x)
      return i;
  }
  return -1;
}

void TestBinSearch()
{
  {
    vector<int> elements = {1, 5, 8, 12, 13};
    vector<int> search_elems = {8, 1, 23, 1, 11};
    vector<int> expected = {2, 0, -1, 0, -1};
    vector<int> result;
    for (int i = 0; i < search_elems.size(); ++i)
    {
      result.push_back(binary_search_my_impl(elements, 0, elements.size() - 1, search_elems[i]));
    }

    std::cout << "\n";
  }
}

int main()
{
  //TestBinSearch();
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++)
  {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i)
  {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i)
  {
    //   //replace with the call to binary_search when implemented
    //std::cout << linear_search(a, b[i]) << ' ';
    std::cout<<binary_search_my_impl(a,0,a.size()-1,b[i])<< ' ';  
  }
}
