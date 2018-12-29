/**
 * Cellular Automata Evacuation Model Considering Information 
 * Transfer in Building with Obstacles
 *
 * @file Grid.cpp
 * @date 15/11/2018
 *
 * @author Filip Kocica   <xkocic01@stud.fit.vutbr.cz>
 * @author Ondrej Vasicek <xvasic25@stud.fit.vutbr.cz>
 *
 * @brief Implementation of Grid of Cells
 */

#include "Grid.h"
#include "TAV.h"

const double Grid_t::timeStep = 0.6;

Grid_t::Grid_t(TAV_t statImp, TAV_t repImp, TAV_t crowdImp, TAV_t exitF, TAV_t aisF, TAV_t repF, TAV_t crowdI, unsigned int LoS, TAV_t fireFact, TAV_t fireSpread) : 
    m_gridRepulsiveForce{repF}, m_gridCrowdInfluence{crowdI}, m_gridStaticImpact{statImp}, m_gridRepulsiveImpact{repImp}, m_gridCrowdImpact{crowdImp}, m_gridFireSpread{fireSpread}, m_gridFireFactor{fireFact}, m_deadPeople{0}, m_gridLoS{LoS}, m_gridAisleFactor{aisF}, m_gridExitFactor{exitF},
    m_grid{{
        { {CellType_t::BORDER, 0.0}, {CellType_t::BORDER, 0.0}, {CellType_t::BORDER, 0.0}, {CellType_t::BORDER,   0.0}, {CellType_t::BORDER,   0.0}, {CellType_t::BORDER,   0.0}, {CellType_t::BORDER,   0.0}, {CellType_t::BORDER,   0.0}, {CellType_t::BORDER,   0.0}, {CellType_t::BORDER, 0.0}, {CellType_t::BORDER, 0.0}, {CellType_t::BORDER,   0.0}, {CellType_t::BORDER,   0.0}, {CellType_t::BORDER,   0.0}, {CellType_t::BORDER,   0.0}, {CellType_t::BORDER,   0.0}, {CellType_t::BORDER,   0.0}, {CellType_t::BORDER, 0.0}, {CellType_t::BORDER, 0.0}, {CellType_t::BORDER,   0.0}, {CellType_t::BORDER,   0.0}, {CellType_t::BORDER,   0.0}, {CellType_t::BORDER,   0.0}, {CellType_t::BORDER,   0.0}, {CellType_t::BORDER,   0.0}, {CellType_t::BORDER, 0.0}, {CellType_t::BORDER, 0.0}, {CellType_t::BORDER, 0.0} },
        { {CellType_t::EXIT, exitF}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY,   aisF}, {CellType_t::EMPTY,   aisF}, {CellType_t::EMPTY,   aisF}, {CellType_t::EMPTY,   aisF}, {CellType_t::EMPTY,   aisF}, {CellType_t::EMPTY,   aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY,   aisF}, {CellType_t::EMPTY,   aisF}, {CellType_t::EMPTY,   aisF}, {CellType_t::EMPTY,   aisF}, {CellType_t::EMPTY,   aisF}, {CellType_t::EMPTY,   aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY,   aisF}, {CellType_t::EMPTY,   aisF}, {CellType_t::EMPTY,   aisF}, {CellType_t::EMPTY,   aisF}, {CellType_t::EMPTY,   aisF}, {CellType_t::EMPTY,   aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::EXIT, exitF} },
        { {CellType_t::EXIT, exitF}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY,   aisF}, {CellType_t::EMPTY,   aisF}, {CellType_t::EMPTY,   aisF}, {CellType_t::EMPTY,   aisF}, {CellType_t::EMPTY,   aisF}, {CellType_t::EMPTY,   aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY,   aisF}, {CellType_t::EMPTY,   aisF}, {CellType_t::EMPTY,   aisF}, {CellType_t::EMPTY,   aisF}, {CellType_t::EMPTY,   aisF}, {CellType_t::EMPTY,   aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY,   aisF}, {CellType_t::EMPTY,   aisF}, {CellType_t::EMPTY,   aisF}, {CellType_t::EMPTY,   aisF}, {CellType_t::EMPTY,   aisF}, {CellType_t::EMPTY,   aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::EXIT, exitF} },
        { {CellType_t::BORDER, 0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::BORDER, 0.0} },
        { {CellType_t::BORDER, 0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::BORDER, 0.0} },
        { {CellType_t::BORDER, 0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::BORDER, 0.0} },
        { {CellType_t::BORDER, 0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::BORDER, 0.0} },
        { {CellType_t::BORDER, 0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::BORDER, 0.0} },
        { {CellType_t::BORDER, 0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::BORDER, 0.0} },
        { {CellType_t::BORDER, 0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::BORDER, 0.0} },
        { {CellType_t::BORDER, 0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::BORDER, 0.0} },
        { {CellType_t::BORDER, 0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::BORDER, 0.0} },
        { {CellType_t::BORDER, 0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::BORDER, 0.0} },
        { {CellType_t::BORDER, 0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::OBSTACLE, 0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::BORDER, 0.0} },
        { {CellType_t::BORDER, 0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::PERSON,   0.0}, {CellType_t::EMPTY, aisF}, {CellType_t::EMPTY, aisF}, {CellType_t::BORDER, 0.0} },
        { {CellType_t::BORDER, 0.0}, {CellType_t::BORDER, 0.0}, {CellType_t::BORDER, 0.0}, {CellType_t::BORDER,   0.0}, {CellType_t::BORDER,   0.0}, {CellType_t::BORDER,   0.0}, {CellType_t::BORDER,   0.0}, {CellType_t::BORDER,   0.0}, {CellType_t::BORDER,   0.0}, {CellType_t::BORDER, 0.0}, {CellType_t::BORDER, 0.0}, {CellType_t::BORDER,   0.0}, {CellType_t::BORDER,   0.0}, {CellType_t::BORDER,   0.0}, {CellType_t::BORDER,   0.0}, {CellType_t::BORDER,   0.0}, {CellType_t::BORDER,   0.0}, {CellType_t::BORDER, 0.0}, {CellType_t::BORDER, 0.0}, {CellType_t::BORDER,   0.0}, {CellType_t::BORDER,   0.0}, {CellType_t::BORDER,   0.0}, {CellType_t::BORDER,   0.0}, {CellType_t::BORDER,   0.0}, {CellType_t::BORDER,   0.0}, {CellType_t::BORDER, 0.0}, {CellType_t::BORDER, 0.0}, {CellType_t::BORDER, 0.0} }, 
    }}
{
    m_totalPeople = numOfPeopleInSim();
    m_rng.seed(std::random_device()());

    for (int y = 0; y < m_grid.size(); y++)
    {
        for (int x = 0; x < m_grid.at(y).size(); x++)
        {
            m_eightNeighbours.emplace_back( std::make_pair( x, y ) );
        }
    }

    TAV::update_static(*this);  
}

Grid_t::~Grid_t()
{

}

CellGrid_t& Grid_t::getCellGrid()
{
    return m_grid;
}

void Grid_t::removeMovedFlags()
{
    for ( auto& col : m_grid )
    {
        for ( auto& row : col )
        {
            row.setAlreadyMoved(false);
        }
    }
}

void Grid_t::calculateNextStep()
{
    // update static TAV parameters (exit attraction, fire repulsion, aisle attraction)
    TAV::update_static(*this);  

    // create a copy of the previous state
    m_gridCopy = new Grid_t{*this};
    
    removeMovedFlags();

    // Shuffle cell indexes to be processed
    auto m_rngShuffle = std::default_random_engine{};
    std::shuffle(std::begin(m_eightNeighbours), std::end(m_eightNeighbours), m_rngShuffle);

    // process all cells
    for ( auto& coord : m_eightNeighbours )
    {
        int x = coord.first;
        int y = coord.second;
        
        Cell_t cell = m_grid.at(y).at(x);

        // cells have a chance to catch fire
        extendFire(x, y);

        // person movement
        if (cell.isPerson() && !cell.getAlreadyMoved())
        {
            calcTransitionProbabilityPerson(x, y);
        }
    }

    delete m_gridCopy;
}

void Grid_t::calcTransitionProbabilityPerson(size_t x, size_t y)
{
    int i, j;
    int x2, y2;
    int nij, wij, fij;
    TAV_t cellTavSuma, cellTav;
    double cellProb = 0.0, sumCellProb = 0.0;
    std::vector<std::pair<std::pair<int, int>, double>> prob;

    cellTavSuma = getCellTavSuma(x, y);

#ifdef IMS_DEBUG
    std::cout << "Cell (" << x << "," << y << ") probabilities:" << std::endl;
#endif 

    for (i = 1; i >= -1; i--)
    {
        for (j = 1; j >= -1; j--)
        {
            if (i == 0 && j == 0)
            {
                continue;             // Skip middle cell (pedestrian himself)
            }

            x2 = x + i;
            y2 = y + j;

            if (!isOutsideTheBounds(x2, y2))
            {
                fij         = isOnFire(x2, y2)             ? 0 : 1;
                nij         = isOccupiedByPerson(x2, y2)   ? 1 : 0;
                wij         = isOccupiedByObstacle(x2, y2) ? 0 : 1;
                cellTav     = TAV::get_cell_tav(*m_gridCopy, x, y, x2, y2);

                cellProb = (cellTav / cellTavSuma) * (1 - nij) * wij * fij;
#ifdef IMS_DEBUG
                std::cout << "Cell probability (x:" << x << ",y:" << y << ") -> (x:" << x2 << ",y:" << y2 << ") = " << cellProb << std::endl;
#endif
            }
            else
            {
                cellProb = -1.0; // Cant go there since its outside the bounds
            }

            // New most attractive position to move to
            if (!isOccupied(x2, y2) && cellProb >= 0.0)
            {
                sumCellProb += cellProb;
                prob.push_back( std::make_pair( std::make_pair(x2, y2), cellProb ) );
            }
        }
    }

    
    sumCellProb *= 100.0;
    std::uniform_int_distribution<std::mt19937::result_type> distrib(0, sumCellProb);
    double dist = distrib(m_rng);
    double tmp = 0.0;

    for ( auto& it : prob )
    {
        tmp += it.second * 100.0;

#ifdef IMS_DEBUG
        std::cout << dist << " " << tmp << std::endl;
#endif

        if (dist <= tmp)
        {
            cellMoveTo(x, y, it.first.first, it.first.second);
            m_grid.at(y).at(x).setLastDir(std::make_pair(it.first.first, it.first.second));
            break;
        }
    }
}

/**
 * Calculates whether the cell(x,y) should catch on fire
 * Each neighbour on fire increases the probability
 * 
 * Fires are calculated from the previous state and created in the current state
 */
void Grid_t::extendFire(size_t x, size_t y)
{
    if (m_gridCopy->isBorder(x,y))
        return; // borders cant catch fire

    // check neighbour cells for fires
    int neighOnFire = 0; 
    for (int i = 1; i >= -1; i--)
    {
        for (int j = 1; j >= -1; j--)
        {
            if ( !m_gridCopy->isOutsideTheBounds( x+i, y+j ) && m_gridCopy->isOnFire( x+i, y+j ) && !m_gridCopy->isBorder(x+i, y+j))
            {
                neighOnFire++;
            }
        }
    }

    // calculate the probability
    std::uniform_int_distribution<std::mt19937::result_type> distrib(0, 100);
    int rand = distrib(m_rng);
    int fire_prob = neighOnFire * m_gridFireSpread;
    if (rand < fire_prob)
    {
        m_grid.at(y).at(x).setOnFire(true);

        // person on fire means a dead person
        if (isOccupiedByPerson(x,y))
        {
            m_deadPeople++;
            m_grid.at(y).at(x).setCellType(CellType_t::EMPTY);
        }
        // exit on fire is no longer an exit
        else if (isExit(x,y))
        {
            m_grid.at(y).at(x).setCellType(CellType_t::EMPTY);
        }
    }
}

bool Grid_t::isEbEvacuated() const
{
    for ( auto& col : m_grid )
    {
        for ( auto& row : col )
        {
            if ( row.getCellType() == CellType_t::PERSON )
            {
                return false;
            }
        }
    }

    return true;
}

TAV_t Grid_t::getCellTavSuma(size_t x, size_t y)
{
    TAV_t result = 0.0;

    for (int i = 1; i >= -1; i--)
    {
        for (int j = 1; j >= -1; j--)
        {
            if (i == 0 && j == 0)   
            {
                continue;             // Skip middle cell (pedestrian himself) - Should be skipped according to the source article!
            }

            TAV_t tav = TAV::get_cell_tav(*m_gridCopy, x, y, x + i, y + j);
            result += tav;
        }
    }

    return result;
}

void Grid_t::cellMoveTo(size_t x_pre, size_t y_pre, size_t x_pos, size_t y_pos)
{
#ifdef IMS_DEBUG
    std::cout << "IMS_DEBUG: Moving pedestrian @ (x:" << x_pre << ",y:" << y_pre << ") -> (x:" << x_pos << ",y:" << y_pos << ")" << std::endl;
#endif

    m_grid.at(y_pre).at(x_pre).setCellType(CellType_t::EMPTY);

    if (m_grid.at(y_pos).at(x_pos).getCellType() != CellType_t::EXIT)
    {
        m_grid.at(y_pos).at(x_pos).setCellType(CellType_t::PERSON);
        m_grid.at(y_pos).at(x_pos).setAlreadyMoved(true);
    }
}

bool Grid_t::isOutsideTheBounds(size_t x, size_t y) const
{
    return (x < 0 || x >= m_grid.at(0).size() || y < 0 || y >= m_grid.size());
}

bool Grid_t::isOccupiedByPerson(size_t x, size_t y) const
{
    return m_grid.at(y).at(x).getCellType() == CellType_t::PERSON;
}

bool Grid_t::isOccupiedByObstacle(size_t x, size_t y) const
{
    return m_grid.at(y).at(x).getCellType() == CellType_t::OBSTACLE || m_grid.at(y).at(x).getCellType() == CellType_t::BORDER;
}

bool Grid_t::isBorder(size_t x, size_t y) const
{
    return m_grid.at(y).at(x).getCellType() == CellType_t::BORDER;
}

bool Grid_t::isExit(size_t x, size_t y) const
{
    return m_grid.at(y).at(x).getCellType() == CellType_t::EXIT;
}

bool Grid_t::isOccupied(size_t x, size_t y) const
{
    return m_grid.at(y).at(x).getCellType() != CellType_t::EMPTY && m_grid.at(y).at(x).getCellType() != CellType_t::EXIT;
}

bool Grid_t::isOnFire(size_t x, size_t y) const
{
    return m_grid.at(y).at(x).isOnFire();
}

void Grid_t::printGrid(std::ostream& os) const
{
    for ( auto& col : m_grid )
    {
        for ( auto& row : col )
        {
            if (row.isOnFire())
            {
                os << "! ";
            }
            else switch( row.getCellType() )
            {
                case CellType_t::EMPTY:
                {
                    os << "  ";
                    break;
                }
                case CellType_t::PERSON:
                {
                    os << "o ";
                    break;
                }
                case CellType_t::OBSTACLE:
                {
                    os << "X ";
                    break;
                }
                case CellType_t::EXIT:
                {
                    os << "@ ";
                    break;
                }
                case CellType_t::BORDER:
                {
                    os << "+ ";
                    break;
                }
                default:
                {
                    os << "? ";
                    break;
                }
            }
        }

        os << std::endl;
    }

#ifdef IMS_DEBUG // TODO remove later
    // print exit familiarity
    os.precision(2);
    os << std::endl << "cell fact:" << std::endl;
    for ( auto& col : m_grid )
    {
        for ( auto& row : col )
        {
            os << std::setw(5) << std::left << row.getCellFact();
        }
        os << std::endl;
    }

    // print exit min dist
    os << std::endl << "grid exit min dist:" << std::endl;
    for ( auto& col : m_grid )
    {
        for ( auto& row : col )
        {
            os << std::setw(5) << std::left << row.getCellExitMinDist();
        }
        os << std::endl;
    }

    // print exit attraction
    os << std::endl << "grid exit attraction:" << std::endl;
    for ( auto& col : m_grid )
    {
        for ( auto& row : col )
        {
            os << std::setw(5) << std::left << row.getCellExitAttraction();
        }
        os << std::endl;
    }

    // print fire min dist
    os << std::endl << "grid fire min dist:" << std::endl;
    for ( auto& col : m_grid )
    {
        for ( auto& row : col )
        {
            os << std::setw(5) << std::left << row.getCellFireMinDist();
        }
        os << std::endl;
    }

    // print fire attraction
    os << std::endl << "grid fire attraction:" << std::endl;
    for ( auto& col : m_grid )
    {
        for ( auto& row : col )
        {
            os << std::setw(5) << std::left << row.getCellFireAttraction();
        }
        os << std::endl;
    }

    // print total static attraction
    os << std::endl << "grid total static attraction:" << std::endl;
    for ( auto& col : m_grid )
    {
        for ( auto& row : col )
        {
            long double total_attraction = 0;
            total_attraction = row.getCellFireAttraction() + row.getCellExitAttraction();
            os << std::setw(5) << std::left << total_attraction;
        }
        os << std::endl;
    }
#endif
}

size_t Grid_t::getNumRows() const
{
    return m_grid.size();
}

size_t Grid_t::getNumCols() const
{
    return m_grid.size() > 0 ? m_grid.at(0).size() : 0;
}

size_t Grid_t::numOfPeopleInSim() const
{
    size_t res = 0;

    for ( auto& col : m_grid )
    {
        for ( auto& row : col )
        {
            if ( row.getCellType() == CellType_t::PERSON )
            {
                res++;
            }
        }
    }

    return res;
}

TAV_t Grid_t::getGridRepulsiveForce() const
{
    return m_gridRepulsiveForce;
}

TAV_t Grid_t::getGridCrowdInfluence() const
{
    return m_gridCrowdInfluence;
}

TAV_t Grid_t::getGridStaticImpact() const
{
    return m_gridStaticImpact;
}

TAV_t Grid_t::getGridRepulsiveImpact() const
{
    return m_gridRepulsiveImpact;
}

TAV_t Grid_t::getGridCrowdImpact() const
{
    return m_gridCrowdImpact;
}

TAV_t Grid_t::getGridFireFactor() const
{
    return m_gridFireFactor;
}

size_t Grid_t::getNumDeadPpl() const
{
    return m_deadPeople;
}

size_t Grid_t::getTotalNumPpl() const
{
    return m_totalPeople;
}


unsigned int Grid_t::getGridLoS() const
{
    return m_gridLoS;
}
TAV_t Grid_t::getGridExitFactor() const
{
    return m_gridExitFactor;
}
TAV_t Grid_t::getGridAisleFactor() const
{
    return m_gridAisleFactor;
}

/**
 * Sets a random cell on fire.
 */
void Grid_t::startFire()
{
    std::uniform_int_distribution<std::mt19937::result_type> rand_x(1, getNumCols() - 2);	
    std::uniform_int_distribution<std::mt19937::result_type> rand_y(1, getNumRows() - 2);	
    m_grid.at(rand_y(m_rng)).at(rand_x(m_rng)).setOnFire(true);
}