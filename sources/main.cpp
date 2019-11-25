//
// Created by danf2 on 10.11.2019.
//
#include "../include/header.hpp"

#include <boost/lexical_cast.hpp>
#include <boost/log/utility/setup.hpp>
#include <thread>
#include <vector>


void starter()// задаем начальные параметры
{
    srand(time(nullptr));                // иниц рандом
    boost::log::add_file_log("Result.log"); // создаем файл, куда будем выгружаем
    boost::log::add_console_log(std::cout);
}


int main(int argc, char* argv[])
{
    starter();
    size_t countOfThreads = 0; // количество потоков
    if (argc < 2){
        countOfThreads = std::thread::hardware_concurrency(); // макс количество потоков, которые можно обрабатывать
    }
    else {
        countOfThreads = boost::lexical_cast<size_t>(argv[1]); // принимаем 1е значение
    }

    std::vector<std::thread> threads;
    threads.reserve(countOfThreads);

    for (size_t i = 0; i < countOfThreads; ++i) {
        threads.emplace_back(Hash::hashMake);
    }

    for (std::thread& i : threads){
        i.join();
    }

    return 0;
}