/**
 * Cellular Automata Evacuation Model Considering Information 
 * Transfer in Building with Obstacles
 *
 * @file Grid.h
 * @date 14/11/2018
 *
 * @author Filip Kocica   <xkocic01@stud.fit.vutbr.cz>
 * @author Ondrej Vasicek <xvasic25@stud.fit.vutbr.cz>
 *
 * @brief Implementation of Grid of Cells
 */

#pragma once

// STD/STL
#include <vector>
#include <fstream>
#include <ostream>
#include <iostream>
#include <iomanip>
#include <random>
#include <algorithm>

// Local
#include "Cell.h"

// More understandable alias for 2D array of Cells
using CellGrid_t = std::vector < std::vector < Cell_t > >;

// Alias for vector of coords
using CoordBuffer_t = std::vector< std::pair< int, int > >;

// Forward class declaration
class Grid_t;

/**
 * @brief Grid is 2D array of Cells
 */
class Grid_t
{
public:

	explicit Grid_t(TAV_t statImp, TAV_t repImp, TAV_t crowdImp, TAV_t exitF, TAV_t aisleF, TAV_t repF, TAV_t crowdI, unsigned int LoS, TAV_t fireFact, TAV_t fireSpread);
	virtual ~Grid_t();

	static const double timeStep; /**< How much time in seconds equals one simulation step */

    void printGrid(std::ostream& os) const;

	size_t getNumRows() const;
	size_t getNumCols() const;
	size_t numOfPeopleInSim() const;
	size_t getTotalNumPpl() const;
	size_t getNumDeadPpl() const;
	bool isOccupied(size_t x, size_t y) const;
	
	CellGrid_t& getCellGrid();

	void calculateNextStep();

	TAV_t getGridRepulsiveForce() const;
	TAV_t getGridCrowdInfluence() const;
	TAV_t getGridStaticImpact() const;
	TAV_t getGridRepulsiveImpact() const;
	TAV_t getGridCrowdImpact() const;
	unsigned int getGridLoS() const;
	TAV_t getGridExitFactor() const;
	TAV_t getGridAisleFactor() const;

	bool isEbEvacuated() const;
	bool isOutsideTheBounds(size_t x, size_t y) const;
	TAV_t getGridFireFactor() const;
	void startFire();

protected:
	bool isOccupiedByPerson(size_t x, size_t y) const;
	bool isOccupiedByObstacle(size_t x, size_t y) const;
	bool isBorder(size_t x, size_t y) const;
	bool isExit(size_t x, size_t y) const;
	bool isOnFire(size_t x, size_t y) const;
	void calcTransitionProbabilityPerson(size_t x, size_t y);
	void cellMoveTo(size_t x_pre, size_t y_pre, size_t x_pos, size_t y_pos);
	TAV_t getCellTavSuma(size_t x, size_t y);
	void removeMovedFlags();
	void extendFire(size_t x, size_t y);

private:
	CellGrid_t m_grid;
	Grid_t     *m_gridCopy;
	size_t     m_deadPeople;
	size_t		m_totalPeople;

	CoordBuffer_t m_eightNeighbours; /**< Contains coords of eight neighbours of the cell, supposted to be shuffled and iterated over */

	std::mt19937 m_rng;             /**< pRNG engine */

	/**
	 * Simulation parameters
	 */
	TAV_t m_gridStaticImpact;		/**< Impact factor of exit and aisle influence							*/
	TAV_t m_gridRepulsiveImpact;	/**< Impact factor of the people repulsive force						*/
	TAV_t m_gridCrowdImpact;		/**< Impact factor of the crowd influence								*/

	TAV_t m_gridExitFactor;			/**< Value of exit attraction factor									*/
	TAV_t m_gridAisleFactor;		/**< Value of aisle attraction factor									*/
	TAV_t m_gridRepulsiveForce;	    /**< Strength of the repulsive force between people, a negative value	*/
	TAV_t m_gridCrowdInfluence;	    /**< Strength of the influence of the crowd, a positive value			*/
	unsigned int m_gridLoS;			/**< Line of sight used for crowd influence								*/

	TAV_t m_gridFireSpread;			/**< Chance of a fire spreading											*/
	TAV_t m_gridFireFactor;			/**< Value of fire repulsion (similar to exit factor)					*/
};