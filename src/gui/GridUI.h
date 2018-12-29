/**
 * Cellular Automata Evacuation Model Considering Information 
 * Transfer in Building with Obstacles
 *
 * @file GridUI.h
 * @date 15/11/2018
 *
 * @author Filip Kocica   <xkocic01@stud.fit.vutbr.cz>
 * @author Ondrej Vasicek <xvasic25@stud.fit.vutbr.cz>
 *
 * @brief Implementation of GUI Cell
 */

#pragma once

// Qt
#include <QLabel>
#include <QGridLayout>

// Local
#include "../Grid.h"
#include "../CellType.h"
#include "ImageWidget.h"

// STL
#include <vector>

namespace _GUI
{
    using CellGridUi_t = std::vector < std::vector < ImageWidget * > >;

    class GridUI : public QWidget
    {
    public:
        explicit GridUI(QWidget *parent = Q_NULLPTR);
        virtual ~GridUI();

        void printGridUI(const CellGrid_t& grid);
        
        void initGridCells(Grid_t& cellGrid);

    private:
        QString cellType2Img(const CellType_t& cellType, bool isOnFire);

    private:
        QGridLayout   *m_gridLayout;
        CellGridUi_t   m_grid;

    };
}