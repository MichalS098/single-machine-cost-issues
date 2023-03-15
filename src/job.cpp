#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "../inc/job.hh"

int getWeightedDelaysSum(std::vector<Job> jobs)
{
    int c = 0;
    int delays = 0;
    for (auto job : jobs)
    {
        c += job.getLength();
        delays += job.getDelay(c) * job.getWeight();
    }
    return delays;
}

std::vector<Job> getPDAlgorithmJobs(std::vector<Job> jobs)
{    
}

std::vector<Job> getJobsFromFile(std::string filename, int dataset_number)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Cannot open file " + filename);
    }

    std::string line;
    std::vector<Job> jobs;
    int p, w, d;
    bool found_dataset = false;

    while (std::getline(file, line))
    {
        // check if line starts with "data.x:"
        if (line.find("data." + std::to_string(dataset_number) + ":") == 0)
        {
            // read number of jobs
            std::getline(file, line);
            int n = std::stoi(line);
            // read jobs
            for (int i = 0; i < n; ++i)
            {
                if (!std::getline(file, line))
                {
                    throw std::runtime_error("Unexpected end of file while reading jobs");
                }
                std::stringstream ss(line);
                if (!(ss >> p >> w >> d))
                {
                    throw std::runtime_error("Error reading job data from file");
                }
                jobs.push_back(Job(p, w, d));
            }
            found_dataset = true;
            break;
        }
    }

    if (!found_dataset)
    {
        throw std::runtime_error("Cannot find dataset " + std::to_string(dataset_number) + " in file " + filename);
    }

    return jobs;
}