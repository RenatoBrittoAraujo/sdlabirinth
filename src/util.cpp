#include "util.hpp"
#include "globals.hpp"

#include <random>
#include <string>
#include <fstream>

const int Util::randInt(int lower, int upper)
{
	if (lower > upper)
	{
		throw "randInt(): lower > upper";
	}
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> int_dist(lower, upper);
	return int_dist(mt);
}

const bool Util::fileExists(const std::string &path)
{
	std::ifstream file;
	file.open(path);
	return file.good();
}

const bool Util::fequals(float a, float b)
{
	return fabs(a - b) < 1e-6;
}

const int Util::applyScale(int a)
{
	return (int)(float(a) * globals::SPRITE_SCALE);
}

const float Util::applyScale(float a)
{
	return a * globals::SPRITE_SCALE;
}

template <typename T>
void Util::permute(std::vector<T> &vector)
{
	for(int i = 0; i < vector.size(); i++)
	{
		std::swap( vector[i], vector[randInt(0, vector.size() - 1)] );
	}
}

template void Util::permute<int>(std::vector<int>&);