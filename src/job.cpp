#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "../inc/job.hh"

int getDelays(std::vector<Job> jobs)
{
    int c = 0;
    int delays = 0;
    for (int i = 0; i < jobs.size(); ++i)
    {
        c += jobs[i].getLength();
        delays += jobs[i].getDelay(c);
    }
    return delays;
}

std::vector<Job> getJobsFromFile(std::string filename) {
    std::ifstream file(filename);
    std::string line;
    std::vector<Job> jobs;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        int p, w, d;
        iss >> p >> w >> d;
        jobs.push_back(Job(p, w, d));
    }
    return jobs;
}
