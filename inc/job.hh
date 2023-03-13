#pragma once

#include <string>
#include <vector>
#include <iostream>


class Job
{
private:
    int _p;  // czas trwania
    int _w;  // waga
    int _d;  // pożądany termin zakończenia

public:
    Job(int p, int w, int d): _p(p), _w(w), _d(d) {}

    int getWeight() const { return _w; }
    int getLength() const { return _p; }
    


// int getDelays(std::vector<Job> jobs)
// {
    