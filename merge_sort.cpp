#include "merge_sort.h"
#include <stack>
namespace algorithm_ns
{
    void MergeSort::sort()
    {
        auto sorted = _sort(0, nums_.size()-1);
        nums_ = sorted;
    }

    std::vector<int> MergeSort::_sort(int l, int h)
    {
        if (l == h)
        {
            return std::vector<int>{nums_[l]};
        }
        if (h - l > 1)
        {
            auto mid = (l+h) / 2;
            auto v1 = _sort(l, mid);
            auto v2 = _sort(mid+1, h);

            std::vector<int> v;
            std::vector<int> *vh, *vl;
            if (v1.size() >= v2.size())
            {
                vh = &v1;
                vl = &v2;
            }
            else
            {
                vh = &v2;
                vl = &v1;
            }

            int h_idx = 0, l_idx = 0;
            while(l_idx < vl->size() && h_idx < vh->size())
            {
                if ((*vl)[l_idx] >= (*vh)[h_idx])
                {
                    v.emplace_back((*vh)[h_idx++]);
                }
                else
                {
                    v.emplace_back((*vl)[l_idx++]);
                }
            }

            if (l_idx == vl->size())
            {
                v.insert(v.end(), vh->begin() + h_idx, vh->end());
            }
            else if (h_idx == vh->size())
            {
                v.insert(v.end(), vl->begin() + l_idx, vl->end());
            }

            return v;
        }
        else
        {
            std::vector<int> v(2);
            if (nums_[l] >= nums_[h])
            {
                v[0] = nums_[h];
                v[1] = nums_[l];
            }
            else
            {
                v[1] = nums_[h];
                v[0] = nums_[l];
            }

            return v;
        }
    }
}
