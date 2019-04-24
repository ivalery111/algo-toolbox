#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

struct Item
{
  int weigh_;
  int value_;
  double cost_;
  int index_in_weights;
  int index_in_values_;

  bool operator<(const Item &rhs)
  {
    return this->cost_ < rhs.cost_;
  }
};

vector<Item> GetSortedByCost(const vector<int> &weigths, const vector<int> &values)
{
  vector<Item> result;
  for (int i = 0; i < values.size(); ++i)
  {
    double cost = (double)values[i] / (double)weigths[i];

    result.push_back({weigths[i],
                      values[i],
                      cost,
                      i,
                      i});
  }
  std::sort(result.rbegin(), result.rend());
  return result;
}

double get_optimal_value(int capacity, vector<int> &weights, vector<int> &values)
{
  vector<Item> costs = GetSortedByCost(weights, values);
  double value = 0.0;

  for (int i = 0; i < values.size(); ++i)
  {
    if (capacity == 0)
      return value;

    int a = std::min(costs[i].weigh_, capacity);
    value = value + a * costs[i].cost_;
    costs[i].weigh_ - a;
    capacity = capacity - a;
  }

  return value;
}

void TestGetSortedByCost()
{
  {
    vector<int> weights = {20, 50, 30};
    vector<int> values = {60, 100, 120};
    vector<Item> ans = GetSortedByCost(weights, values);
    std::cout << "\n";
  }
  {
    vector<int> weights = {30};
    vector<int> values = {500};
    vector<Item> ans = GetSortedByCost(weights, values);
    std::cout << "\n";
  }
}

void TestGetOptimalValue()
{
  {
    vector<int> weights = {20, 50, 30};
    vector<int> values = {60, 100, 120};
    auto ans_ = get_optimal_value(50, weights, values);
    std::cout << "\n";
  }
}

void FullProgram()
{
  {
    vector<int> weights = {30};
    vector<int> values = {500};
    double optimal_value = get_optimal_value(10, weights, values);

    std::cout.precision(10);
    std::cout << optimal_value << std::endl;
  }
  {
    vector<int> weights = {20, 50, 30};
    vector<int> values = {60, 100, 120};
    double optimal_value = get_optimal_value(50, weights, values);

    std::cout.precision(10);
    std::cout << optimal_value << std::endl;
  }
}

int main()
{
  //TestGetOptimalValue();
  //TestGetSortedByCost();
  //FullProgram();

  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++)
  {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
