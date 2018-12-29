/**
 * Cellular Automata Evacuation Model Considering Information 
 * Transfer in Building with Obstacles
 *
 * @file Cell.cpp
 * @date 15/11/2018
 *
 * @author Filip Kocica   <xkocic01@stud.fit.vutbr.cz>
 * @author Ondrej Vasicek <xvasic25@stud.fit.vutbr.cz>
 *
 * @brief Implementation of Cell
 */

#include "Cell.h"

Cell_t::Cell_t(const CellType_t& t) : m_cellType{t}, m_cellTav{0.0}, m_cellFact{0.0}, m_aisleAttraction{0.0}, m_alreadyMoved{false}, m_onFire{false}, m_fireAttraction{0.0}, m_fireMinDist{0.0}
{
    m_lastPos = std::make_pair(0, 0);
}

Cell_t::Cell_t(const CellType_t& t, TAV_t fact) : m_cellType{t}, m_cellTav{0.0}, m_cellFact{fact}, m_aisleAttraction{0.0}, m_alreadyMoved{false}, m_onFire{false}, m_fireAttraction{0.0}, m_fireMinDist{0.0}
{
    m_lastPos = std::make_pair(0, 0);
}

Cell_t::~Cell_t()
{

}
	
CellType_t Cell_t::getCellType() const
{
    return m_cellType;
}

void Cell_t::setLastDir(const Coord_t& lastPos)
{
    m_lastPos = lastPos;
}

Coord_t Cell_t::getLastDir() const
{
    return m_lastPos;
}


TAV_t Cell_t::getCellTav() const
{
    return m_cellTav;
}

void Cell_t::setCellTav(const TAV_t& tav)
{
    m_cellTav = tav;
}

void Cell_t::setCellFact(const TAV_t& fact)
{
    m_cellFact = fact;
}

void Cell_t::setCellType(const CellType_t& type)
{
    m_cellType = type;
}

TAV_t Cell_t::getCellExitAttraction() const
{
    return m_exitAttraction;
}

TAV_t Cell_t::getCellFact()  const
{
    return m_cellFact;
}

void Cell_t::setCellExitAttraction(const TAV_t& attraction)
{
    m_exitAttraction = attraction;
}

void Cell_t::setCellExitMinDist(const TAV_t& distance)
{
    m_exitMinDist = distance;
}

TAV_t Cell_t::getCellExitMinDist() const
{
    return m_exitMinDist;
}

bool Cell_t::isPerson() const
{
    return m_cellType == CellType_t::PERSON;
}

TAV_t Cell_t::getCellAisleAttraction() const
{
    return m_aisleAttraction;
}

void Cell_t::setCellAisleAttraction(const TAV_t& attraction)
{
    m_aisleAttraction = attraction;
}

void Cell_t::setAlreadyMoved(const bool& move)
{
    m_alreadyMoved = move;
}

bool Cell_t::getAlreadyMoved() const
{
    return m_alreadyMoved;
}

void Cell_t::setOnFire(const bool& fire)
{
    m_onFire = fire;
}

bool Cell_t::isOnFire() const
{
    return m_onFire;
}

TAV_t Cell_t::getCellFireAttraction() const
{
    return m_fireAttraction;
}

void Cell_t::setCellFireAttraction(const TAV_t& attraction)
{
    m_fireAttraction = attraction;
}

void Cell_t::setCellFireMinDist(const TAV_t& distance)
{
    m_fireMinDist = distance;
}

TAV_t Cell_t::getCellFireMinDist() const
{
    return m_fireMinDist;
}