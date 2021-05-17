#include "shell_sort.h"

namespace algorithm_ns
{
    void ShellSort::sort()
    {
        int delta = nums_.size() / 2;
        int pre, cur;
        while (delta >= 1)
        {
            for(int i = 0; i < nums_.size() - delta; i+=delta)
            {
                pre = i;
                cur = pre + delta;
                while (pre >= 0 && nums_[cur] < nums_[pre])
                {
                    std::swap(nums_[cur], nums_[pre]);
                    cur -= delta;
                    pre -= delta;
                }
            }

            delta /= 2;
        }
    }
}
