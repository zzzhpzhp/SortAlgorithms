#ifndef SORTALGORITHMS_BUCKET_SORT_H
#define SORTALGORITHMS_BUCKET_SORT_H

#include "algorithm_interface.h"
#include <memory>

namespace algorithm_ns
{
    class BucketSort : public AlgorithmInterface
    {
    public:
        BucketSort(std::string name, std::vector<int> &nums)
        {
            AlgorithmInterface::initialize(name, nums);
        }

        void
        sort() override;

    private:

        struct Data
        {
            explicit Data(int v)
            {
                val = v;
            }
            int val;
            std::shared_ptr<Data> next;
        };

        std::shared_ptr<Data> head_;
        int bucket_size_{0};
        std::vector<std::shared_ptr<Data>> buckets_;

        void
        _insert(std::shared_ptr<Data> &head, std::shared_ptr<Data> &d);

        static std::shared_ptr<Data>
        _merge(std::shared_ptr<Data> &a, std::shared_ptr<Data> &b);
    };
}

#endif //SORTALGORITHMS_BUCKET_SORT_H
