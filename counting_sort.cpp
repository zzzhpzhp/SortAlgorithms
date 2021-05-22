#include "counting_sort.h"

namespace algorithm_ns
{
    void CountingSort::sort()
    {
        bucket_.reserve(nums_.size());

        for (const auto& n : nums_)
        {
            bucket_[n]++;
        }

        int index = 0;
        for (int i = 0; i < nums_.size(); i++)
        {
            auto size = bucket_[i];
            while (size--)
            {
                nums_[index++] = i;
            }
        }
    }
}