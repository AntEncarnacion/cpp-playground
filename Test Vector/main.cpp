#include <iostream>
#include <vector>

std::vector<int> countPositivesSumNegatives(std::vector<int> input)
{
    if(input.size() == 0)
      return std::vector<int>();

    int count = 0;
    int sum = 0;

    for(int i = 0;i<input.size();i++)
    {
      if(input[i] > 0)
        count++;
      if(input[i] < 0)
        sum += input[i];
    }
    return std::vector<int> {count,sum};
}

int main()
{
    std::vector<int> input = {3, 3, -1, -2};
    std::vector<int> output = countPositivesSumNegatives(input);
    std::cout << output[0] << output[1];


    return 0;
}
