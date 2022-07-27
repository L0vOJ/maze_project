#pragma once
#include<iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <functional>
#include <vector>
#include <math.h>
#include <ctime>
#include<unistd.h>
#include<termios.h>

struct roulette_Sheet
{
    int div;
	int totalProb;
    int* probList;
    int* mag;
};

struct roulette_Chart
{
    int* count;
	int* earn;
};

class Casino
{
private:
	int __fund;
	int __count;
	int __peak;
	roulette_Sheet __sheet1;
	roulette_Chart __chart1;
public:
	Casino();
	Casino(int fund);
	void sheetConfig1();
	void chartConfig1();
	void __init__(int fund);
	int result_roulette(int* input);
	void fund_roulette(int* input);
	int get_fund();
	int get_peak();
	int get_count();
	int* get_sheet1_mag();
	void show_chart1();
};