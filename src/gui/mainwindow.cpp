/**
 * Cellular Automata Evacuation Model Considering Information 
 * Transfer in Building with Obstacles
 *
 * @file MainWindow.cpp
 * @date 15/11/2018
 *
 * @author Filip Kocica   <xkocic01@stud.fit.vutbr.cz>
 * @author Ondrej Vasicek <xvasic25@stud.fit.vutbr.cz>
 *
 * @brief Implementation of main window
 */

#include "mainwindow.h"

namespace _GUI
{
    MainWindow::MainWindow(QWidget *parent)
        : QMainWindow   (parent)
        , m_hLayoutControls   (new QHBoxLayout(this))
        , m_hLayoutSimulation (new QHBoxLayout(this))
        , m_hLayoutStatisticsPpl     (new QHBoxLayout(this))
        , m_hLayoutStatisticsDeadPpl (new QHBoxLayout(this))
        , m_hLayoutStatisticsTime    (new QHBoxLayout(this))
        , m_hLayoutControlsStatistics(new QHBoxLayout(this))
        , m_vLayoutStatistics        (new QVBoxLayout(this))
        , m_vLayout     (new QVBoxLayout(this))
        , m_bStartSim   (new QPushButton(this))
        , m_bStopSim    (new QPushButton(this))
        , m_bStepSim    (new QPushButton(this))
        , m_controls    (new QGroupBox("Controls", this))
        , m_statistics  (new QGroupBox("Statistics", this))
        , m_simulation  (new QGroupBox("Simulation", this))
        , m_peopleInSimLabel   (new QLabel("People not left yet: ", this))
        , m_peopleInSim        (new QLabel(this))
        , m_deadPplLabel       (new QLabel("Dead people: ", this))
        , m_deadPpl            (new QLabel(this))
        , m_estimatedTimeLabel (new QLabel("Estimated time: ", this))
        , m_estimatedTime      (new QLabel(this))
        , m_timer       (new QTimer(this))
        , m_gridUI      (new GridUI(this))
        , m_estTime     (0)
    {
        m_gridUI->initGridCells(grid);

        m_hLayoutControls->addWidget(m_bStartSim);
        m_hLayoutControls->addWidget(m_bStopSim);
        m_hLayoutControls->addWidget(m_bStepSim);
        m_hLayoutControls->addSpacing(200);
        m_hLayoutStatisticsPpl->addWidget(m_peopleInSimLabel);
        m_hLayoutStatisticsPpl->addWidget(m_peopleInSim);
        m_hLayoutStatisticsDeadPpl->addWidget(m_deadPplLabel);
        m_hLayoutStatisticsDeadPpl->addWidget(m_deadPpl);
        m_hLayoutStatisticsTime->addWidget(m_estimatedTimeLabel);
        m_hLayoutStatisticsTime->addWidget(m_estimatedTime);
        m_hLayoutSimulation->addWidget(m_gridUI);
        m_vLayoutStatistics->addLayout(m_hLayoutStatisticsPpl);
        m_vLayoutStatistics->addLayout(m_hLayoutStatisticsDeadPpl);
        m_vLayoutStatistics->addLayout(m_hLayoutStatisticsTime);

        setButtonIcon(":/img/Start.jpg", m_bStartSim);
        setButtonIcon(":/img/Stop.jpg", m_bStopSim);
        setButtonIcon(":/img/Step.jpg", m_bStepSim);

        m_controls->setLayout(m_hLayoutControls);
        m_statistics->setLayout(m_vLayoutStatistics);
        m_simulation->setLayout(m_hLayoutSimulation);

        m_hLayoutControlsStatistics->addWidget(m_controls);
        m_hLayoutControlsStatistics->addWidget(m_statistics);

        m_vLayout->addLayout(m_hLayoutControlsStatistics);
        m_vLayout->addWidget(m_simulation);


        QWidget *window = new QWidget();
        window->setLayout(m_vLayout);

        this->setCentralWidget(window);
        this->connectSignals2Slots();
        this->setStyles();

        printGridUI(grid.getCellGrid());
        emit updtPpl();

        ///////////////////////////////////////////////////////////////////////
        // Check existing cmd line args
        QStringList cmdlineArgs = QCoreApplication::arguments();

        char **argv;
        int    argc;
        int    index = 0;

        argc = cmdlineArgs.size();
        argv = new char* [argc];

        for ( auto& arg : cmdlineArgs )
        {
            argv[index] = new char [ arg.length() ];
            strcpy( argv[index++], arg.toStdString().c_str() );
        }

        CArgumentsParser argsParser;
        SArguments args = argsParser.parseArgs(argc, argv);

        grid = Grid_t{args.statImp, args.repImp, args.crowdImp, args.exitFactor, args.aisleFactor, args.repF, args.crowdI, args.LoS, args.fireFactor, args.fireSpread};
    }

    MainWindow::~MainWindow()
    {

    }

    void MainWindow::printGridUI(const CellGrid_t& grid)
    {
        m_gridUI->printGridUI(grid);
    }

    void MainWindow::connectSignals2Slots()
    {
        connect(m_bStartSim, SIGNAL(clicked()), this, SLOT(startSim()));
        connect(m_bStopSim,  SIGNAL(clicked()), this, SLOT(stopSim()));
        connect(m_bStepSim,  SIGNAL(clicked()), this, SLOT(stepSim()));
        connect(m_timer,     SIGNAL(timeout()), this, SLOT(stepSim()));
    }

    void MainWindow::setButtonIcon(const QString& s, QPushButton* b)
    {
        QPixmap p{ s };
        QIcon bIcon(p);
        b->setIcon(bIcon);
        b->setIconSize(p.rect().size());
    }

    void MainWindow::startSim()
    {
        m_timer->start(100);
        emit stepSim();
    }

    void MainWindow::stopSim()
    {
        m_timer->stop();
    }

    void MainWindow::setStyles()
    {
        // Main window
        this->setStyleSheet("background-color: white;");

        // Statistics - people in sim
        m_peopleInSimLabel->setStyleSheet("font: bold 10px");
        m_peopleInSim->setStyleSheet("color: red; font: bold 10px");

        // Statistics - dead people
        m_deadPplLabel->setStyleSheet("font: bold 10px");
        m_deadPpl->setStyleSheet("color: red; font: bold 10px");
        m_deadPpl->setText("0");

        // Statistics - estimated time
        m_estimatedTimeLabel->setStyleSheet("font: bold 10px");
        m_estimatedTime->setStyleSheet("color: blue; font: bold 10px");
        m_estimatedTime->setText("0.0s");
    }

    void MainWindow::updtPpl()
    {
        size_t num = grid.numOfPeopleInSim();
        m_peopleInSim->setText(QString::number(num));

        if ( num == 0 )
        {
            m_peopleInSim->setStyleSheet("color: green; font: bold 10px");
            m_timer->stop();
        }

        // Dead ppl
        m_deadPpl->setText(QString::number(grid.getNumDeadPpl()));
    }

    void MainWindow::updtTime()
    {
        m_estTime += grid.timeStep * 1000;
        m_estimatedTime->setText(QString::number(m_estTime/1000.0) + "s");
    }

    void MainWindow::stepSim()
    {
        // Move pedestrians
        grid.calculateNextStep();

        // Redraw GUI
        printGridUI(grid.getCellGrid());
        
        // Update statistics
        emit updtPpl();
        emit updtTime();

#ifdef IMS_DEBUG
        // Print grid to console
        std::cout << "Print Grid: " << std::endl;
        grid.printGrid(std::cout);
#endif
    }
}