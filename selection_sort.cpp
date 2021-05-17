#include "selection_sort.h"
#include "limits"
namespace algorithm_ns
{
    void SelectionSort::sort()
    {
        int min_idx = 0;
        int min_val = std::numeric_limits<int>::max();

        for (int i = 0; i < nums_.size(); i++)
        {
            for (int j = i+1; j < nums_.size(); j++)
            {
                if (nums_[j] < min_val)
                {
                    min_idx = j;
                    min_val = nums_[j];
                }
            }
            if (nums_[i] > nums_[min_idx])
            {
                std::swap(nums_[i], nums_[min_idx]);
            }
            min_val = std::numeric_limits<int>::max();
        }
    }
}