#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include '../inc/job.hh'

int main(int argc, char const *argv[])
{
    // wczytanie danych z pliku
    std::vector<Job> getJobsFromFile(std::string filename)
    {
        std::vector<Job> jobs;
        std::ifstream file(filename);
        std::string line;
        while (std::getline(file, line))
        {
            std::istringstream iss(line);
            int weight, length;
            if (!(iss >> weight >> length))
            {
                break;
            }
            jobs.push_back(Job(weight, length));
        }
        return jobs;
    }

    int score = 0;
    for (int i = 1; i <= 4; ++i)
    {
        std::string filename = "./../data/data" + std::to_string(i) + ".txt";
        std::string filename_out = "./../data/data" + std::to_string(i) + "_out.txt";
        std::vector<Job> jobs = getJobsFromFile(filename);
        std::vector<Job> ranked_jobs = sortCustom(jobs);
        writeJobsToFile(ranked_jobs, filename_out);
        std::cout << std::endl
                    << "Czas nieposortowany dla pliku " << filename << " : " << calculateJobsTime(jobs) << std::endl;
        std::cout << "Czas posortowany dla pliku " << filename << " : " << calculateJobsTime(ranked_jobs) << std::endl;
        score += calculateJobsTime(ranked_jobs);
    }
    
    // sprawko pdf na za tydfzien
    std::cout << "Wynik: " << score << std::endl;
    
    return 0;
}