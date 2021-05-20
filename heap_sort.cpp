#include "heap_sort.h"

namespace algorithm_ns
{
    void HeapSort::sort()
    {
        if (nums_.empty())
        {
            return;
        }
        heap_ = std::make_shared<Heap>(nums_.front());
        std::shared_ptr<Heap> p;
        for (int i = 1; i < nums_.size(); i++)
        {
            p = heap_;
            auto v = nums_[i];
            while (p)
            {
                if (v > p->val)
                {
                    if (!p->right)
                    {
                        p->right = std::make_shared<Heap>(v);
                        break;
                    }
                    p = p->right;
                }
                else
                {
                    if (!p->left)
                    {
                        p->left = std::make_shared<Heap>(v);
                        break;
                    }
                    p = p->left;
                }
            }
        }
        _print_heap(heap_);
    }

    std::shared_ptr<Heap>
    HeapSort::_sort(std::shared_ptr<Heap>& h)
    {
        return nullptr;
    }

    void HeapSort::_create_heap(std::shared_ptr<Heap> &p, int i)
    {
        auto v = nums_[i];
        p = std::make_shared<Heap>(v);
        i++;
        std::cout << i << " \n";
        if (i < nums_.size())
        {
            auto t = nums_[i];
            if (t > v)
            {
                _create_heap(p->right, i);
            }
            else
            {
                _create_heap(p->left, i);
            }
        }
    }

    void HeapSort::_print_heap(std::shared_ptr<Heap> &h)
    {
        if (!h)
        {
            return;
        }
        _print_heap(h->left);
        nums_[_i++] = h->val;
//        std::cout << h->val << " ";
        _print_heap(h->right);
    }
}