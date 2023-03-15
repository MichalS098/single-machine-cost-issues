#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "../inc/job.hh"

int main(int argc, char const *argv[])
{
    try
    {
        if (argc != 3)
        {
            std::cout << "Usage: " << argv[0] << " <data_filename> <dataset_number>" << std::endl;
            return 1;
        }
        std::string filename = argv[1];
        int dataset_number = std::stoi(argv[2]);
        std::vector<Job> jobs = getJobsFromFile(filename, dataset_number);
        std::vector<Job> optimal_jobs = getPDAlgorithmJobs(jobs);
        std::cout << "Wynik nieposortowany: " << getWeightedDelaysSum(jobs) << std::endl;
        std::cout << "Wynik posortowany: " << getWeightedDelaysSum(optimal_jobs) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }
}