#pragma once

#include <cmath>
#include <ctime>
#include <vector>
#include <climits>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <sys/time.h>

typedef struct timeval t_timeval;

long str2int (std::string str);
int	argv_check(char **argv);
void swap(int &a, int &b);
void print(std::vector<int>  nums);
void print(std::vector < std::vector<int> > nums);
double	gettime(t_timeval start);
void insert(std::vector<int>& nums, std::vector<int> b);
void merge_sort_vector(std::vector<int>& nums);
void insertion_sort(std::vector<int>& nums);
