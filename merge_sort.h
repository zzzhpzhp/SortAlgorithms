#ifndef SORTALGORITHMS_MERGE_SORT_H
#define SORTALGORITHMS_MERGE_SORT_H

#include "algorithm_interface.h"

namespace algorithm_ns
{
    class MergeSort : public AlgorithmInterface
    {
    public:
        MergeSort(std::string name, std::vector<int> &nums)
        {
            AlgorithmInterface::initialize(name, nums);
        }

        void
        sort() override;

    private:
        std::vector<int>
        _sort(int l, int r);
    };
}

#endif //SORTALGORITHMS_MERGE_SORT_H
