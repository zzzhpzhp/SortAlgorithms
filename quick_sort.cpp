#include "quick_sort.h"

namespace algorithm_ns
{
    void QuickSort::sort()
    {
        _sort(0, (int)nums_.size()-1);
    }

    void QuickSort::_sort(int l, int h)
    {
        if (l >= h)
        {
            return;
        }
        else
        {
            int pivot_idx = l;
            auto pivot = nums_[l];

            for (int i = l+1; i <= h; i++)
            {
                if (nums_[i] < pivot)
                {
                    if (i - pivot_idx == 1)
                    {
                        std::swap(nums_[i], nums_[pivot_idx]);
                        pivot_idx = i;
                    }
                    else
                    {
                        std::swap(nums_[i], nums_[pivot_idx+1]);
                        std::swap(nums_[pivot_idx], nums_[pivot_idx+1]);
                        pivot_idx = pivot_idx+1;
                    }
                }
            }

            _sort(l, pivot_idx);
            _sort(pivot_idx+1, h);
        }
    }
}