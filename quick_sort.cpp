#include "quick_sort.h"

namespace algorithm_ns
{
    void QuickSort::sort()
    {
        auto res = _sort(0, (int)nums_.size()-1, nums_);
        nums_ = res;
    }

    std::vector<int> QuickSort::_sort(int l, int h, const std::vector<int> &tnums)
    {
        if (l == h)
        {
            return std::vector<int>{tnums[l]};
        }
        else if (h - l > 1)
        {
            int vsize = h-l+1;
            int idx = 0, hidx = vsize-1;

            std::vector<int> v(vsize);

            for (int i = l + 1; i <= h; i++)
            {
                if (tnums[i] < tnums[l])
                {
                    v[idx++] = tnums[i];
                }
                else
                {
                    v[hidx--] = tnums[i];
                }
            }

            v[idx] = tnums[l];
            std::vector<int> v1, v2;
            if (idx == vsize - 1)
            {
                v1 = _sort(0, idx-1, v);
                v2 = std::vector<int>{tnums[l]};
            }
            else if (hidx == 0)
            {
                v1 = std::vector<int>{tnums[l]};
                v2 = _sort(1, vsize-1, v);
            }
            else
            {
                v1 = _sort(0, idx, v);
                v2 = _sort(idx+1, v.size()-1, v);
            }

            v1.insert(v1.end(), v2.begin(), v2.end());
            return v1;
        }
        else
        {
            std::vector<int> v(2);
            if (tnums[l] <= tnums[h])
            {
                v[0] = tnums[l];
                v[1] = tnums[h];
            }
            else
            {
                v[0] = tnums[h];
                v[1] = tnums[l];
            }

            return v;
        }
    }
}