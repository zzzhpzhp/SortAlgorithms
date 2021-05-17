#include "insertion_sort.h"

void algorithm_ns::InsertionSort::sort()
{
    int pre, cur;
    for (int i = 0; i < nums_.size() - 1; i++)
    {
        pre = i;
        cur = i+1;
        while(pre >= 0 && nums_[cur] < nums_[pre])
        {
            std::swap(nums_[cur], nums_[pre]);
            pre--;
            cur--;
        }
    }
}
