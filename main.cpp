#include <iostream>
#include <random>
#include <memory>
#include <vector>
#include <thread>
#include <chrono>
#include <functional>

#include "shell_sort.h"
#include "merge_sort.h"
#include "bubble_sort.h"
#include "selection_sort.h"
#include "insertion_sort.h"
#include "algorithm_interface.h"

std::vector<int> nums;
std::vector<std::shared_ptr<algorithm_ns::AlgorithmInterface>> algorithms_ptr;

int size = 10000;
int range = 100000;

void
sort(std::shared_ptr<algorithm_ns::AlgorithmInterface> alg)
{
    alg->sort();
    std::cout << alg->getName() << std::endl;
    alg->printNums();
    alg->check();
}

int main()
{
    std::default_random_engine rd;
    rd.seed(time(0));

    std::cout << "Random number size: " << size << ", origin numbers: " << std::endl;
    for (int i = 0; i < size; i++)
    {
        auto rd_num = rd() % range;
        nums.emplace_back(rd_num);
        std::cout << rd_num << " ";
    }
    std::cout << std::endl;

    algorithms_ptr.emplace_back(std::make_shared<algorithm_ns::BubbleSort>("BubbleSort", nums));
    algorithms_ptr.emplace_back(std::make_shared<algorithm_ns::SelectionSort>("SelectionSort", nums));
    algorithms_ptr.emplace_back(std::make_shared<algorithm_ns::InsertionSort>("InsertionSort", nums));
    algorithms_ptr.emplace_back(std::make_shared<algorithm_ns::ShellSort>("ShellSort", nums));
    algorithms_ptr.emplace_back(std::make_shared<algorithm_ns::MergeSort>("MergeSort", nums));

    std::vector<std::shared_ptr<std::thread>> threads;
    for (auto &alg : algorithms_ptr)
    {
        threads.push_back(std::make_shared<std::thread>(std::bind(&sort, alg)));
    }

    for (auto &thr : threads)
    {
        thr->join();
    }

    return 0;
}
