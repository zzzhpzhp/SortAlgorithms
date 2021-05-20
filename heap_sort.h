#ifndef SORTALGORITHM_HEAP_SORT_H
#define SORTALGORITHM_HEAP_SORT_H

#include "algorithm_interface.h"
#include <memory>

namespace algorithm_ns
{
    struct Heap
    {
        explicit Heap(int v)
        {
            val = v;
        }
        int val;
        std::shared_ptr<Heap> left, right;
    };

    class HeapSort : public AlgorithmInterface
    {
    public:
        HeapSort(std::string name, std::vector<int> &nums)
        {
            AlgorithmInterface::initialize(name, nums);
        }

        void
        sort() override;

    private:
        std::shared_ptr<Heap> heap_;
        void _create_heap(std::shared_ptr<Heap> &p, int i);
        std::shared_ptr<Heap> _sort(std::shared_ptr<Heap>& h);
        void _print_heap(std::shared_ptr<Heap> &h);
        int _i = 0;
    };
}

#endif //SORTALGORITHM_HEAP_SORT_H
