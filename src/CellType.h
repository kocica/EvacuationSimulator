/**
 * Cellular Automata Evacuation Model Considering Information 
 * Transfer in Building with Obstacles
 *
 * @file CellType.h
 * @date 14/11/2018
 *
 * @author Filip Kocica   <xkocic01@stud.fit.vutbr.cz>
 * @author Ondrej Vasicek <xvasic25@stud.fit.vutbr.cz>
 *
 * @brief Enumerator with types of Cell
 */

#pragma once

enum CellType_t
{
    EMPTY,     /**< Empty Cell                Marked as E */
    PERSON,    /**< Person in the Cell        Marked as P */
    OBSTACLE,  /**< Obstacle in the Cell      Marked as O */
    EXIT,      /**< Exit cell                 Marked as X */
    BORDER     /**< Border cell               Marked as B */
};