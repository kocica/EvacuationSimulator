/**
 * Cellular Automata Evacuation Model Considering Information 
 * Transfer in Building with Obstacles
 *
 * @file ImageWidget.h
 * @date 15/11/2018
 *
 * @author Filip Kocica   <xkocic01@stud.fit.vutbr.cz>
 * @author Ondrej Vasicek <xvasic25@stud.fit.vutbr.cz>
 *
 * @brief Implementation of display widget
 */

#pragma once

// Qt
#include <QPushButton>
#include <QPixmap>
#include <QHBoxLayout>

// STL
#include <utility>

// Local
#include "../Cell.h"
#include "RightClickButton.h"

/**
 * @brief Namepsace for GUI components
 */
namespace _GUI
{
	static const int DEFAULT_WIDTH  = 32;
	static const int DEFAULT_HEIGHT = 32;

	/**
	 * @brief Widget used for displaying images
	 */
	class ImageWidget : public QRightClickButton
	{
	    Q_OBJECT

	public:
        explicit ImageWidget(QWidget *parent = Q_NULLPTR);

	    explicit ImageWidget(size_t width    = DEFAULT_WIDTH,
	    	                 size_t height   = DEFAULT_HEIGHT,
	    	                 QWidget *parent = Q_NULLPTR);

	    ~ImageWidget();

	    void updateImage(const QString& imagePath);

		void setCell(Cell_t * cell, TAV_t exitFact);

	    void updateResolution(size_t width  = DEFAULT_WIDTH,
	    	                  size_t height = DEFAULT_HEIGHT);

	    inline std::pair<size_t, size_t> getResolution() const;

	public slots:
		void cellRightClicked();
		void cellLeftClicked();

	protected:

	private:
		size_t        m_width;
		size_t        m_height;
		Cell_t        *m_cell;
		CellType_t	  m_origType;
		TAV_t	  	  m_origFact;
		TAV_t	  	  m_exitFact;

	};

}