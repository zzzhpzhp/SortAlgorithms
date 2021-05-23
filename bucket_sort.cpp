#include "bucket_sort.h"
#include <thread>
#include <functional>

namespace algorithm_ns
{
    void BucketSort::sort()
    {
        bucket_size_ = 16;
        buckets_.resize(bucket_size_);
        for (auto &b : buckets_)
        {
            b = std::make_shared<Data>(0);
        }

        std::shared_ptr<Data> head = std::make_shared<Data>(0);
        std::vector<std::shared_ptr<std::thread>> threads(bucket_size_);

        for (int i = 0; i < nums_.size(); i++)
        {
            auto cur = std::make_shared<Data>(nums_[i]);
            threads[i % bucket_size_] = std::make_shared<std::thread>(std::bind(&BucketSort::_insert,
                                                                 this, buckets_[i % bucket_size_], cur));
            if ((i % bucket_size_) == bucket_size_-1)
            {
                for (auto &thr : threads)
                {
                    if (!thr)
                    {
                        continue;
                    }
                    if (thr->joinable())
                    thr->join();
                }
            }
        }

        for (auto &thr : threads)
        {
            if (!thr)
            {
                continue;
            }
            if (thr->joinable())
            thr->join();
        }

        for (auto & bucket : buckets_)
        {
            head = _merge(head, bucket);
        }

        int index = 0;
        head = head->next;
        while(head)
        {
            nums_[index++] = head->val;
            head = head->next;
        }
    }

    std::shared_ptr<BucketSort::Data>
    BucketSort::_merge(std::shared_ptr<Data> &a, std::shared_ptr<Data> &b)
    {
        if (!a || !b)
        {
            if (a)
            {
                return a;
            }
            if (b)
            {
                return b;
            }
        }

        auto pre_pa = a, pre_pb = b;
        auto pa = pre_pa->next, pb = pre_pb->next;
        auto new_head = std::make_shared<Data>(0);

        auto new_cur = new_head;
        while (pa && pb)
        {
            if (pa->val <= pb->val)
            {
                new_cur->next = pa;
                new_cur = new_cur->next;

                pa = pa->next;
            }
            else
            {
                new_cur->next = pb;
                new_cur = new_cur->next;

                pb = pb->next;
            }
        }

        if (pa)
        {
            new_cur->next = pa;
        }

        if (pb)
        {
            new_cur->next = pb;
        }

        return new_head;
    }

    void
    BucketSort::_insert(std::shared_ptr<Data> &head, std::shared_ptr<Data> &d)
    {
        auto pre = head;
        auto cur = head->next;

        bool ok = false;
        while (cur)
        {
            if (d->val < cur->val)
            {
                pre->next = d;
                d->next = cur;
                ok = true;
                break;
            }
            pre = cur;
            cur = cur->next;
        }

        if (!ok)
        {
            pre->next = d;
        }
    }
}
