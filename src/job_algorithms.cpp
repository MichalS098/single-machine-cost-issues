#include "../inc/job.hh"
#include "../inc/helpers.hh"
#include "../inc/job_algorithms.hh"
#include <map>

std::vector<Job> filterJobsByOperationNumber(const std::vector<Job> &jobs, int decimal_number)
{
    std::vector<Job> result_jobs;
    result_jobs.reserve(jobs.size()); // pre-allocate memory for the result vector

    for (int i = 0, b = 1; i < jobs.size(); i++, b <<= 1)
    {
        if (b & decimal_number)
        {
            result_jobs.push_back(jobs[i]);
        }
    }

    return result_jobs;
}

int getPDAlgorithmWitiSum(const std::vector<Job> &jobs)
{
    int jobs_size = jobs.size();
    int memory_size = 1 << jobs_size;
    int max_op_num = 1 << jobs_size;
    std::map<int, int> weighted_delays = {{0, 0}};

    for (int op_num = 1; op_num < max_op_num; op_num++)
    {
        std::vector<Job> op_jobs = filterJobsByOperationNumber(jobs, op_num);
        int min_witi = INT_MAX;

        for (int i = 0; i < op_jobs.size(); ++i)
        {
            int op_num_without_i = op_num ^ (1 << i);
            int witi = weighted_delays[op_num_without_i] + op_jobs[i].getDelay(getTotalJobLength(op_jobs));

            if (witi < min_witi)
            {
                min_witi = witi;
            }
        }
        weighted_delays[op_num] = min_witi;
    }

    return weighted_delays[max_op_num - 1];
}