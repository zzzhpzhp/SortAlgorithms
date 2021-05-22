#include "heap_sort.h"

namespace algorithm_ns
{
    void HeapSort::sort()
    {
        if (nums_.empty())
        {
            return;
        }

        end_index_ = nums_.size();
        _heap_init();

        while(end_index_ != 1)
        {
            std::swap(nums_[0], nums_[end_index_-1]);
            end_index_--;
            _heap_adjust(0);
        }
    }

    void
    HeapSort::_heap_adjust(int i)
    {
        auto left_child = 2 * i + 1;
        auto right_child = 2 * i + 2;

        int max_index = i;

        if (left_child < end_index_ && nums_[left_child] > nums_[max_index])
        {
            max_index = left_child;
        }

        if (right_child < end_index_ && nums_[right_child] > nums_[max_index])
        {
            max_index = right_child;
        }

        if (max_index != i)
        {
            std::swap(nums_[i], nums_[max_index]);
            _heap_adjust(max_index);
        }
    }

    void
    HeapSort::_heap_init()
    {
        for (int i = nums_.size() / 2; i >= 0; i--)
        {
            _heap_adjust(i);
        }
    }
}