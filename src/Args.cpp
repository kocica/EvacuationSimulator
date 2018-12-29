#include "Args.h"
#include "DefaultVals.h"

CArgumentsParser::CArgumentsParser()
{
	// default values
	m_args.statImp = DEF_STATIMP;
	m_args.repImp = DEF_REPIMP;
	m_args.crowdImp = DEF_CROWDIMP;
	m_args.exitFactor = DEF_EXITFACT;
	m_args.aisleFactor = DEF_AISLEFACT;
	m_args.repF =  DEF_REPF;
	m_args.crowdI = DEF_CROWDI;
	m_args.LoS = DEF_LOS;
	m_args.fireFactor = DEF_FIREFACT;
	m_args.fireSpread = DEF_FIRESPR;

	m_args.visual_mode = false;
	m_args.fire_gen = false;
}

CArgumentsParser::~CArgumentsParser()
{

}

SArguments CArgumentsParser::parseArgs(int argc, char *argv[])
{
	int c;

	while ((c = getopt (argc, argv, "R:C:s:r:c:f:F:e:a:l:vhX")) != -1)
	{
		switch(c)
		{
			case 'R':
				m_args.repF = atof(optarg);
				break;
			case 'C':
				m_args.crowdI = atof(optarg);
				break;
			case 's':
				m_args.statImp = atof(optarg);
				break;
			case 'r':
				m_args.repImp = atof(optarg);
				break;
			case 'c':
				m_args.crowdImp = atof(optarg);
				break;
			case 'e':
				m_args.exitFactor = atof(optarg);
				break;
			case 'a':
				m_args.aisleFactor = atof(optarg);
				break;
			case 'l':
				m_args.LoS = atoi(optarg);
				break;
			case 'f':
				m_args.fireFactor = atof(optarg);
				break;
			case 'F':
				m_args.fireSpread = atof(optarg);
				break;
			case 'v':
				m_args.visual_mode = true;
				break;
			case 'X':
				m_args.fire_gen = true;
				break;
			case 'h':
				printHelp();
				exit(0);
			default:
				std::cout << "Invalid arguments" << std::endl;
				printHelp();
				exit(0);
		}
	}

	return m_args;
}

void CArgumentsParser::printHelp()
{
	std::cout << "\
\nUsage: ./IMS-xkocic01-xvasic25 [-vhX] [-srceaRCfF <double>] [-l <unsigned>]\n\n\
\t-v\tVisual mode for console version\n\t\tPrints the grid in each step\n\n\
\t-h\tPrint this help\n\n\
\t-s <val>\tStatic impact factor\n\
\t-r <val>\tRepulsion force impact factor\n\
\t-c <val>\tCrowd influence impact factor\n\n\
\t-e <val>\tExit familiarity value\n\
\t-a <val>\tAisle atraction value\n\
\t-R <val>\tRepulsion force value (R < 0)\n\
\t-C <val>\tCrowd influence value (C > 0)\n\
\t-l <val>\tLine of sight for crowd influence\n\
\t-f <val>\tFire repulsion value (f > 0)\n\
\t-F <val>\tFire spread probability\n\n\
\t-X\t\tEnable random fire generation\n" << std::endl;
}