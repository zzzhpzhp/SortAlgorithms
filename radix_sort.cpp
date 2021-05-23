#include "radix_sort.h"
#include <limits>
#include <queue>

namespace algorithm_ns
{
    void RadixSort::sort()
    {
        std::vector<std::deque<int>> buckets_(10);
        int base = 1;
        auto t_nums = nums_;
        int max_num = std::numeric_limits<int>::min();

        for (auto &n : nums_)
        {
            if (n > max_num)
            {
                max_num = n;
            }
        }

        while (base < max_num)
        {
            for (int i = 0; i < t_nums.size(); i++)
            {
                auto v = t_nums[i];
                v /= base;
                buckets_[v % 10].push_back(i);
            }

            int index = 0;

            auto tt_nums = t_nums;
            for (auto & i : buckets_)
            {
                while (!i.empty())
                {
                    t_nums[index++] = tt_nums[i.front()];
                    i.pop_front();
                }
            }

            base *= 10;
        }

        nums_ = t_nums;
    }
}
