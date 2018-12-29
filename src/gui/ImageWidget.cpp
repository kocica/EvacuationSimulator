/**
 * Cellular Automata Evacuation Model Considering Information 
 * Transfer in Building with Obstacles
 *
 * @file ImageWidget.cpp
 * @date 15/11/2018
 *
 * @author Filip Kocica   <xkocic01@stud.fit.vutbr.cz>
 * @author Ondrej Vasicek <xvasic25@stud.fit.vutbr.cz>
 *
 * @brief Implementation of display widget
 */

#include "ImageWidget.h"

namespace _GUI
{
	ImageWidget::ImageWidget(size_t width,
		                     size_t height,
		                     QWidget *parent)
	: QRightClickButton(parent)
	, m_width{ width }
	, m_height{ height }
	{
		QPixmap p{ ":img/Empty.jpg" };
        this->resize(64, 64);
		//this->setPixmap(p);
		QIcon ButtonIcon(p);
		this->setIcon(ButtonIcon);
		//button->setIconSize(pixmap.rect().size());

		connect(this, SIGNAL(clicked()), this, SLOT(cellLeftClicked()));
		connect(this, SIGNAL(rightClicked()), this, SLOT(cellRightClicked()));
	}

    ImageWidget::ImageWidget(QWidget *parent)
	: QRightClickButton(parent)
	{
		QPixmap p{ ":img/Empty.jpg" };
        this->resize(64, 64);
		//this->setPixmap(p);
		QIcon ButtonIcon(p);
		this->setIcon(ButtonIcon);
		//button->setIconSize(pixmap.rect().size());

		connect(this, SIGNAL(clicked()), this, SLOT(cellLeftClicked()));
		connect(this, SIGNAL(rightClicked()), this, SLOT(cellRightClicked()));
	}

	ImageWidget::~ImageWidget()
	{
		// Dont free resources here
	}

	void ImageWidget::updateImage(const QString& imagePath)
	{
		QPixmap p{ imagePath };
        //this->resize(DEFAULT_WIDTH, DEFAULT_HEIGHT);
		//this->setPixmap(p);
		QIcon ButtonIcon(p);
		this->setIcon(ButtonIcon);
		//button->setIconSize(pixmap.rect().size());
	}

	void ImageWidget::updateResolution(size_t width,
	    	                           size_t height)
	{
		this->resize(width, height);
	}

	std::pair<size_t, size_t> ImageWidget::getResolution() const
	{
		return std::make_pair(m_width, m_height);
	}

	void ImageWidget::cellLeftClicked()
	{
		// a cell initialized as exit
		if (m_origType == CellType_t::EXIT)
		{
			if ( m_cell->getCellType() == CellType_t::EXIT )
			{
				QPixmap p{ ":img/Border.jpg" };
				QIcon ButtonIcon(p);
				this->setIcon(ButtonIcon);

				m_cell->setCellType(CellType_t::BORDER);
				m_cell->setCellFact(0);
			}
			else
			{
				QPixmap p{ ":img/Exit.jpg" };
				QIcon ButtonIcon(p);
				this->setIcon(ButtonIcon);

				m_cell->setCellType(CellType_t::EXIT);
				m_cell->setCellFact(m_origFact);
			}
		}
		// all other cells
		else
		{
			if ( m_cell->getCellType() == CellType_t::EXIT )
			{
				QPixmap p{ ":img/Empty.jpg" };
				QIcon ButtonIcon(p);
				this->setIcon(ButtonIcon);

				m_cell->setCellType(m_origType);
				m_cell->setCellFact(m_origFact);
			}
			else
			{
				QPixmap p{ ":img/Exit.jpg" };
				QIcon ButtonIcon(p);
				this->setIcon(ButtonIcon);

				m_cell->setCellType(CellType_t::EXIT);
				m_cell->setCellFact(m_exitFact);
			}
		}
	}

	void ImageWidget::cellRightClicked()
	{
		if (m_cell->getCellType() == CellType_t::BORDER)
			return;

		if ( m_cell->isOnFire() )
		{
			QPixmap p{ ":img/Empty.jpg" };
			QIcon ButtonIcon(p);
			this->setIcon(ButtonIcon);

			m_cell->setOnFire(false);
		}
		else
		{
			QPixmap p{ ":img/Fire.jpg" };
			QIcon ButtonIcon(p);
			this->setIcon(ButtonIcon);

			m_cell->setOnFire(true);
		}
	}

	void ImageWidget::setCell(Cell_t * cell, TAV_t exitFact)
	{
		m_cell = cell;
		m_origType = m_cell->getCellType();
		m_origFact = m_cell->getCellFact();
		m_exitFact = exitFact;
	}
}