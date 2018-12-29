/**
 * Cellular Automata Evacuation Model Considering Information 
 * Transfer in Building with Obstacles
 *
 * @file GridUI.cpp
 * @date 15/11/2018
 *
 * @author Filip Kocica   <xkocic01@stud.fit.vutbr.cz>
 * @author Ondrej Vasicek <xvasic25@stud.fit.vutbr.cz>
 *
 * @brief Implementation of GUI Grid
 */

#include "GridUI.h"

namespace _GUI
{
    GridUI::GridUI(QWidget *parent)
        : QWidget      (parent)
        , m_gridLayout (new QGridLayout(this))
    {
        m_grid = {
            { new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this) },
            { new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this) },
            { new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this) },
            { new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this) },
            { new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this) },
            { new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this) },
            { new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this) },
            { new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this) },
            { new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this) },
            { new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this) },
            { new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this) },
            { new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this) },
            { new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this) },
            { new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this) },
            { new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this) },
            { new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this), new ImageWidget(this) },
        };

        this->setLayout(m_gridLayout);
    }

    GridUI::~GridUI()
    {

    }

    void GridUI::printGridUI(const CellGrid_t& grid)
    {
        size_t x, y;

        for ( y = 0; y < grid.size(); y++ )
        {
            for ( x = 0; x < grid.at(y).size(); x++ )
            {
                m_grid.at(y).at(x)->updateImage( cellType2Img( grid.at(y).at(x).getCellType(), grid.at(y).at(x).isOnFire() ) );

                m_gridLayout->addWidget( m_grid.at(y).at(x), y, x );
            }
        }
    }

    QString GridUI::cellType2Img(const CellType_t& cellType, bool isOnFire)
    {
        if ( isOnFire )
        {
            return QString{ ":img/Fire.jpg" };
        }

        switch( cellType )
        {
            case CellType_t::EMPTY:
            {
                return QString{ ":img/Empty.jpg" };
            }
            case CellType_t::PERSON:
            {
                return QString{ ":img/Person.jpg" };
            }
            case CellType_t::OBSTACLE:
            {
                return QString{ ":img/Obstacle.jpg" };
            }
            case CellType_t::EXIT:
            {
                return QString{ ":img/Exit.jpg" };
            }
            case CellType_t::BORDER:
            {
                return QString{ ":img/Border.jpg" };
            }
            default:
            {
                return QString{"Unknown"};
            }
        }

        return QString{"Unknown"};
    }

    void GridUI::initGridCells(Grid_t& cellGrid)
    {
        for (size_t y = 0; y < m_grid.size(); y++)
        {
            for (size_t x = 0; x < m_grid.at(y).size(); x++)
            {
                m_grid.at(y).at(x)->setCell( & cellGrid.getCellGrid().at(y).at(x), cellGrid.getGridExitFactor());
            }
        }
    }
}