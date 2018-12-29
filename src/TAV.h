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
 * @brief Total attractivnes functions interface
 */

#pragma once

#include "Grid.h"

namespace TAV {
    /**
     * Updates static parameters for TAV computation
     * @param grid  Reference to the CellGrid_t to initialize
     */
    void update_static(Grid_t &grid);

    /**
     * Computes the TAV of a cell relative to a person
     * @param grid      Reference to the Grid_t
     * @param person_x  X coordinate of the person
     * @param person_y  Y coordinate of the person
     * @param cell_x    X coordinate of the cell
     * @param cell_y    Y coordinate of the cell
     * @return TAV of the cell relative to the person
     */
    TAV_t get_cell_tav(Grid_t &grid, int person_x, int person_y, int cell_x, int cell_y);
}