#include "bubble_sort.h"

namespace algorithm_ns
{
    void
    BubbleSort::sort()
    {
        auto &nums = nums_;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] > nums[j])
                {
                    std::swap(nums[i], nums[j]);
                }
            }
        }
    }
}