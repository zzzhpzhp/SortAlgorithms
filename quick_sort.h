#ifndef SORTALGORITHM_QUICK_SORT_H
#define SORTALGORITHM_QUICK_SORT_H

#include "algorithm_interface.h"

namespace algorithm_ns
{
    class QuickSort : public AlgorithmInterface
    {
    public:
        QuickSort(std::string name, std::vector<int> &nums)
        {
            AlgorithmInterface::initialize(name, nums);
        }

        void
        sort() override;

    private:

        std::vector<int>
        _sort(int l, int h, const std::vector<int> &tnums);
    };
}

#endif //SORTALGORITHM_QUICK_SORT_H
