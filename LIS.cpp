/**
 * @file LIS.cpp
 * @brief 
 * @author culbertyang
 * @version 1.0
 * @date 2017-09-11
 */

#include <iostream>
#include <iterator>
#include <unistd.h>
#include <vector>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv)
{
  int inputArray[] = {7, 8, 9, 1, 2, 3, 4};
  std::vector<int> indexArray;
  std::vector<int> preArray;
  int bestIndexEnd = -1;
  int inputArraySize = sizeof(inputArray) / sizeof(inputArray[0]);

  indexArray.push_back(0);
  preArray.push_back(-1);
  bestIndexEnd = 0;

  for(int index = 1; index < inputArraySize; ++index)
  {
    if(inputArray[index] > inputArray[indexArray.back()])
    {
      preArray.push_back(indexArray.back());
      indexArray.push_back(index);
      bestIndexEnd = index;
    }
    else
    {
      int binary_search_begin_index = 0;
      int binary_search_end_index   = static_cast<int>(indexArray.size());
      while(binary_search_begin_index < binary_search_end_index)
      {
        int binary_search_index_middle = (binary_search_begin_index + binary_search_end_index) / 2;
        if(inputArray[indexArray[binary_search_index_middle]] < inputArray[index])
        {
          binary_search_begin_index = binary_search_index_middle + 1;
        }
        else
        {
          binary_search_end_index = binary_search_index_middle;
        }
      }
      indexArray[binary_search_begin_index] = index;
      if(binary_search_begin_index > 0)
      {
        preArray.push_back(indexArray[binary_search_begin_index - 1]);
      }
      else
      {
        preArray.push_back(-1);
      }
    }
  }
  while(bestIndexEnd != -1)
  {
    std::cout<<inputArray[bestIndexEnd]<<" ";
    bestIndexEnd = preArray[bestIndexEnd];
  }
  return EXIT_SUCCESS;
}
