#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "../inc/job.hh"

int main(int argc, char const *argv[])
{    
    std::string filename = argv[1];
    std::vector<Job> jobs = getJobsFromFile(filename);
    std::cout << getDelays(jobs) << std::endl;
}