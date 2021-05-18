#include "merge_sort.h"
#include <stack>
namespace algorithm_ns
{
    void MergeSort::sort()
    {
        _sort(0, nums_.size());
    }

    void MergeSort::_sort(int l, int r)
    {
        if (l == r)
        {
            return;
        }
        if (l - r > 1)
        {
            auto mid = (l+r) / 2;
            _sort(l, mid);
            _sort(mid+1, r);
//            for ()
        }
        else
        {
            if (nums_[l] > nums_[r])
            {
                std::swap(nums_[l], nums_[r]);
            }
            return;
        }
    }
}
