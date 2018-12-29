#pragma once

// STD
#include <unistd.h>
#include <iostream>
#include <stdlib.h>


/**
 * @brief POD (Plain old data) filled with parsed arguments
 */
struct SArguments
{
public:
	double repF,
		crowdI,
		statImp,
		repImp,
		crowdImp,
		exitFactor,
		aisleFactor,
		fireFactor,
		fireSpread;

	unsigned int LoS;
	
	bool visual_mode,
		fire_gen;
};


/**
 * @brief Class parsing input arguments & provides check if they are valid
 */
class CArgumentsParser
{
public:
	/** @brief Do nothing, succesfully */
	explicit CArgumentsParser();
	/** @brief Virtual destructor */
	virtual ~CArgumentsParser();
	
	/**
	 * @brief Parsing input arguments using getopt
	 *
	 * @param argc [in] Number of arguments
	 * @param argv [in] Argument values
	 * @return Parsed arguments
	 */
	SArguments parseArgs(int argc, char *argv[]);

	/**
	 * @brief Prints help/usage to standard output
	 */
	void printHelp();

private:
	/** @brief Parsed arguments */
	SArguments m_args = {};
};