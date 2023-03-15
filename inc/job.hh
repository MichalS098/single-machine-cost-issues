#pragma once
#include <vector>
#include <string>

class Job
{
private:
    int _p; // czas trwania
    int _w; // waga
    int _d; // pożądany czas zakończenia

public:
    Job(int p, int w, int d) : _p(p), _w(w), _d(d) {}

    int getWeight() const { return _w; }
    int getLength() const { return _p; }
    int getDeadline() const { return _d; }    

    int getDelay(int c) const
    {
        return c > _d ? c - _d : 0;
    }
};

int getWeightedDelaysSum(std::vector<Job> jobs);
std::vector<Job> getJobsFromFile(std::string filename, int dataset_number);
std::vector<Job> getPDAlgorithmJobs(std::vector<Job> jobs);
