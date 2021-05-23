#include <iostream>
#include <random>
#include <memory>
#include <vector>
#include <thread>
#include <chrono>
#include <functional>

#include "algorithm_interface.h"
#include "shell_sort.h"
#include "merge_sort.h"
#include "bubble_sort.h"
#include "selection_sort.h"
#include "insertion_sort.h"
#include "quick_sort.h"
#include "heap_sort.h"
#include "counting_sort.h"
#include "bucket_sort.h"
#include "radix_sort.h"

std::vector<int> nums;
std::vector<std::shared_ptr<algorithm_ns::AlgorithmInterface>> algorithms_ptr;

constexpr const bool print_random_numbers = false;
constexpr const bool print_sorted_numbers = false;
constexpr const int size = 10000;
constexpr const int range = size;

void
sort(const std::shared_ptr<algorithm_ns::AlgorithmInterface> &alg)
{
    auto stamp = clock();
    alg->sort();
    std::cout << alg->getName() << " finished"<< std::endl << std::flush;
    std::cout << "Time consume: " << (double)(clock() - stamp) / CLOCKS_PER_SEC << std::endl;
    if (print_sorted_numbers)
    {
        alg->printNums();
    }
    std::cout << std::endl << std::flush;
    alg->check();
}

int main()
{
    if (range <= 0)
    {
        std::cout << "Number range should greater than 0." << std::endl;
        return 0;
    }
    std::cout << "Sorting " << size << " random numbers with range 0-" << (range - 1) << " ..." << std::endl;
    std::default_random_engine rd;
    rd.seed(time(0));

    if (print_random_numbers)
    {
        std::cout << "Random number size: " << size << ", origin numbers: " << std::endl;
    }
    for (int i = 0; i < size; i++)
    {
        auto rd_num = rd() % range;
        nums.emplace_back(rd_num);
        if (print_random_numbers)
        {
            std::cout << rd_num << " ";
        }
    }
    std::cout << std::endl;

    algorithms_ptr.emplace_back(std::make_shared<algorithm_ns::BubbleSort>("BubbleSort", nums));
    algorithms_ptr.emplace_back(std::make_shared<algorithm_ns::SelectionSort>("SelectionSort", nums));
    algorithms_ptr.emplace_back(std::make_shared<algorithm_ns::InsertionSort>("InsertionSort", nums));
    algorithms_ptr.emplace_back(std::make_shared<algorithm_ns::ShellSort>("ShellSort", nums));
    algorithms_ptr.emplace_back(std::make_shared<algorithm_ns::MergeSort>("MergeSort", nums));
    algorithms_ptr.emplace_back(std::make_shared<algorithm_ns::QuickSort>("QuickSort", nums));
    algorithms_ptr.emplace_back(std::make_shared<algorithm_ns::HeapSort>("HeapSort", nums));
    algorithms_ptr.emplace_back(std::make_shared<algorithm_ns::CountingSort>("CountingSort", nums));
    algorithms_ptr.emplace_back(std::make_shared<algorithm_ns::BucketSort>("BucketSort", nums));
    algorithms_ptr.emplace_back(std::make_shared<algorithm_ns::RadixSort>("RadixSort", nums));

    std::vector<std::shared_ptr<std::thread>> threads;
    threads.reserve(algorithms_ptr.size());
    for (auto &alg : algorithms_ptr)
    {
        threads.push_back(std::make_shared<std::thread>(std::bind(&sort, alg)));
    }

    for (auto &thr : threads)
    {
        thr->join();
    }

    std::cout << "All finished." << std::endl;
    return 0;
}
