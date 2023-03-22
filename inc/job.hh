#pragma once
#include <vector>
#include <string>
#include <algorithm>

class Job
{
private:
    int _id;
    int _p; // czas trwania
    int _w; // waga
    int _d; // pożądany czas zakończenia

public:
    Job(int id, int p, int w, int d) : _id(id), _p(p), _w(w), _d(d) {}

    int getId() const { return _id; }
    int getWeight() const { return _w; }
    int getLength() const { return _p; }
    int getDeadline() const { return _d; }
    int getDelay(int c) const { return c > _d ? c - _d : 0; }
    int getPenalty(int c) const { return getDelay(c) * _w; }
};

int getWeightedDelaysSum(const std::vector<Job>& jobs);
int getCmax(const std::vector<Job>& jobs);
std::vector<Job> getJobsFromFile(std::string filename, int dataset_number);
std::vector<Job> getPDAlgorithmJobs(const std::vector<Job>& jobs);
std::vector<Job> getJobsFromOperationNumber(const std::vector<Job>& jobs, int number);
void printJobs(const std::vector<Job>& jobs);