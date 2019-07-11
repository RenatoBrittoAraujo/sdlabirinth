#ifndef UTIL_HPP
#define UTIL_HPP

#include <string>

class Util
{
public:

	/*
		Returns an integer int the interval [lower,upper]
		Throws exception if lower > upper
	 */
	static int randInt(int lower, int upper);

	/*
		Returns true if any file was found in path passed
	 */
	static const bool fileExists(const std::string &path);

	/*
		Returns true if float a and b are less then 10^(-6)
		far apart from each other false otherwise

	 */
	static const bool fequals(float a, float b);
};

#endif