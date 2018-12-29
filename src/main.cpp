/**
 * Cellular Automata Evacuation Model Considering Information 
 * Transfer in Building with Obstacles
 *
 * @file main.h
 * @date 14/11/2018
 *
 * @author Filip Kocica   <xkocic01@stud.fit.vutbr.cz>
 * @author Ondrej Vasicek <xvasic25@stud.fit.vutbr.cz>
 *
 * @brief Entry point of the application
 */

// STD/STL
#include <chrono>
#include <thread>

// Local
#include "Grid.h"
#include "Args.h"

// Qt
#ifdef GUI
#include <QApplication>
#include <QStyle>
#include <QDesktopWidget>
#include "gui/mainwindow.h"
#endif

// Namespaces
using namespace std::this_thread;
using namespace std::chrono_literals;
using std::chrono::system_clock;

int main(int argc, char *argv[])
{
#ifdef IMS_DEBUG
        std::cout << args.repF << " " << args.crowdI << " " << args.statImp << " " << args.repImp << " "
                  << args.crowdImp << " " << args.fireFactor << " " << args.fireSpread << std::endl;
#endif

    try
    {
#ifdef GUI
        // GUI version

	    QApplication a(argc, argv);

        _GUI::MainWindow window;

        window.setGeometry(
            QStyle::alignedRect(
                Qt::LeftToRight,
                Qt::AlignLeft,
                QSize{1, 1},
                qApp->desktop()->availableGeometry()
            )
        );

        window.show();
#else
        // No GUI, console output

        CArgumentsParser argsParser;
        SArguments args = argsParser.parseArgs(argc, argv);

        /**
         * SIMULATION INITIALIZATION AND STEP LOOP 
         */

        // Create the array of cells
        // set simulation parameters
        Grid_t  grid{args.statImp, args.repImp, args.crowdImp, args.exitFactor, args.aisleFactor, args.repF, args.crowdI, args.LoS, args.fireFactor, args.fireSpread};

        // start a fire if requsted
        if(args.fire_gen)
        {
            grid.startFire();
        }

        std::cout << "Initial state:" << std::endl;
        grid.printGrid(std::cout);
       
        if (!args.visual_mode)
        {
            std::cout << std::endl << "Simulation running..." << std::endl;
        }

        // run until all people evacuate
        int step_count = 0;
        while (!grid.isEbEvacuated())
        {
            step_count++;

            // Compute the next step
            grid.calculateNextStep();

            // Print grid
            if (args.visual_mode)
            {
                std::cout << std::endl << "Elapsed time: " << step_count * grid.timeStep << "s" << std::endl; 
                grid.printGrid(std::cout);
            }

            // Sleep one sec
            sleep_for(100ms);
        }

        // print simulation statistics
        std::cout << std::endl << "Total elapsed time: " << step_count * grid.timeStep << "s" << std::endl;
        std::cout << "People evacuated: " << grid.getTotalNumPpl() - grid.getNumDeadPpl() << std::endl;
        std::cout << "Dead people: " << grid.getNumDeadPpl() << std::endl;


#endif


#ifdef GUI
        return a.exec();
#else
	    return 0;
#endif
    }
    catch(std::exception& e)
    {
        std::cerr << "Unexpected problem has occured during the simulation (" <<
                     e.what() << ")." << std::endl;
    }
}