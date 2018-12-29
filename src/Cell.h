/**
 * Cellular Automata Evacuation Model Considering Information 
 * Transfer in Building with Obstacles
 *
 * @file Cell.h
 * @date 14/11/2018
 *
 * @author Filip Kocica   <xkocic01@stud.fit.vutbr.cz>
 * @author Ondrej Vasicek <xvasic25@stud.fit.vutbr.cz>
 *
 * @brief Implementation of Cell
 */

#pragma once

#include <utility>
#include "CellType.h"

/**
 * @brief Total attraction value
 * 	representing each cell’s attraction degree to pedestrians
 */
using TAV_t   = long double;
using Coord_t = std::pair<int, int>;

/**
 * @brief Cell represents one grid 0.5 x 0.5 meters
 */
class Cell_t
{
public:
	Cell_t() = delete;
	Cell_t(const CellType_t& t);
	Cell_t(const CellType_t& t, TAV_t fact);
	
	virtual ~Cell_t();

	/// Setters
	void       setCellTav(const TAV_t& tav);
	void       setCellType(const CellType_t& type);
	void       setCellExitAttraction(const TAV_t& attraction);
	void       setCellExitMinDist(const TAV_t& distance);
	void       setCellAisleAttraction(const TAV_t& attraction);
	void       setLastDir(const Coord_t& lastPos);
	void       setAlreadyMoved(const bool& move);
	void       setCellFact(const TAV_t& fact);

	void       setOnFire(const bool& fire);
	void       setCellFireAttraction(const TAV_t& attraction);
	void       setCellFireMinDist(const TAV_t& distance);

	/// Getters
    CellType_t getCellType() const;
    TAV_t      getCellTav()  const;
	TAV_t      getCellExitAttraction() const;
	TAV_t      getCellExitMinDist()  const;
	TAV_t      getCellFact()  const;
	TAV_t      getCellAisleAttraction()  const;
	Coord_t    getLastDir() const;
	bool       getAlreadyMoved() const;
	bool       isPerson() const;

	bool       isOnFire() const;
	TAV_t      getCellFireAttraction() const;
	TAV_t      getCellFireMinDist()  const;

private:
	CellType_t  m_cellType;
	TAV_t       m_cellTav;
	TAV_t       m_cellFact;
	TAV_t       m_exitAttraction;
	TAV_t       m_exitMinDist;
	TAV_t       m_aisleAttraction;
	Coord_t     m_lastPos;
	bool        m_alreadyMoved;

	bool		m_onFire;
	TAV_t       m_fireAttraction;
	TAV_t		m_fireMinDist;
};