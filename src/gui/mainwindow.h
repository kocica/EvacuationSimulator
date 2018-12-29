/**
 * Cellular Automata Evacuation Model Considering Information 
 * Transfer in Building with Obstacles
 *
 * @file MainWindow.h
 * @date 15/11/2018
 *
 * @author Filip Kocica   <xkocic01@stud.fit.vutbr.cz>
 * @author Ondrej Vasicek <xvasic25@stud.fit.vutbr.cz>
 *
 * @brief Implementation of main window
 */

#pragma once

// Qt
#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include <QGroupBox>
#include <QCoreApplication>

// Local
#include "GridUI.h"
#include "../DefaultVals.h"
#include "../Args.h"

namespace _GUI
{
    class MainWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = Q_NULLPTR);
        ~MainWindow();

        void printGridUI(const CellGrid_t& grid);

    public slots:
        void startSim();
        void stopSim();
        void stepSim();
        void updtPpl();
        void updtTime();

    protected:
        void setButtonIcon(const QString& s, QPushButton* b);
        void connectSignals2Slots();
        void setStyles();

    private:
        // Layouts
        QHBoxLayout *m_hLayoutControls;
        QHBoxLayout *m_hLayoutSimulation;
        QHBoxLayout *m_hLayoutStatisticsPpl;
        QHBoxLayout *m_hLayoutStatisticsDeadPpl;
        QHBoxLayout *m_hLayoutStatisticsTime;
        QHBoxLayout *m_hLayoutControlsStatistics;
        QVBoxLayout *m_vLayoutStatistics;
        QVBoxLayout *m_vLayout;

        // Simulation control buttons
        QPushButton *m_bStartSim;
        QPushButton *m_bStopSim;
        QPushButton *m_bStepSim;

        // Group boxes
        QGroupBox   *m_controls;
        QGroupBox   *m_statistics;
        QGroupBox   *m_simulation;

        // Labels
        QLabel      *m_peopleInSimLabel;
        QLabel      *m_peopleInSim;
        QLabel      *m_deadPplLabel;
        QLabel      *m_deadPpl;
        QLabel      *m_estimatedTimeLabel;
        QLabel      *m_estimatedTime;

        // Timer
        QTimer      *m_timer;

        // Simulation Grid
        GridUI      *m_gridUI;

        // Grid logic
        // params:  statImp, repImp, crowImp, exitF, aisleF, repF, crowIn, LoS, fireF, fireS
        Grid_t  grid{   DEF_STATIMP, DEF_REPIMP, DEF_CROWDIMP, DEF_EXITFACT, DEF_AISLEFACT, 
                        DEF_REPF, DEF_CROWDI, DEF_LOS, DEF_FIREFACT, DEF_FIRESPR};

        // Estimated time
        size_t      m_estTime;
    };
}