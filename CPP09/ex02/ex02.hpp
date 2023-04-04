#pragma once

#include <list>
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
void print(std::vector<int>  nums, size_t precision);
void print(std::list<int> nums, size_t precision);
double	gettime(t_timeval start);
void insertion_sort(std::vector<int>& nums);
void insertion_sort(std::list<int>& nums);
void merge_sort(std::vector<int>& nums);
void merge_sort(std::list<int>& nums);
