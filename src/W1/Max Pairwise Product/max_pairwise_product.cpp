#include <iostream>
#include <vector>
#include <algorithm>

int MaxPairwiseProduct(const std::vector<int> &numbers)
{
    int max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first)
    {
        for (int second = first + 1; second < n; ++second)
        {
            max_product = std::max(max_product,
                                   numbers[first] * numbers[second]);
        }
    }

    return max_product;
}

long FastMaxPairwiseProduct(const std::vector<long> &numbers)
{
    long max = 0;
    std::vector<long> temp_vec = numbers;
    sort(temp_vec.begin(), temp_vec.end());
    max = temp_vec[temp_vec.size()-2] * temp_vec[temp_vec.size()-1];
    return max;
}

int main()
{
    long n;
    std::cin >> n;
    std::vector<long> numbers(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> numbers[i];
    }

    //std::cout << MaxPairwiseProduct(numbers) << "\n";
    std::cout << FastMaxPairwiseProduct(numbers) << "\n";
    return 0;
}
