/**
 * Cellular Automata Evacuation Model Considering Information 
 * Transfer in Building with Obstacles
 *
 * @file TAV.cpp
 * @date 15/11/2018
 *
 * @author Filip Kocica   <xkocic01@stud.fit.vutbr.cz>
 * @author Ondrej Vasicek <xvasic25@stud.fit.vutbr.cz>
 *
 * @brief Implementation of total attractivness functions
 */

#include "TAV.h"
#include "Cell.h"
#include <math.h>
#include <limits>

/**
 * Represents an exit cell.
 */
class exit_t {

	public:
		exit_t(int _x, int _y, long double _fam) : idx_x(_x), idx_y(_y), fam(_fam) {};

	private:
		const int idx_x, idx_y; /**< coordinates of the exit					*/
		const long double fam;  /**< familiarity with the exit
								  	 overall higher means more exit impact
									 compared to others exits lower is better 	*/

	public:

		/**
		 * Computed as follows:
		 * 	dist = a_k * sqrt((i - e_1k)^2) + (j - e_2k)^2)
		 */
		long double get_cell_distance(int cell_x, int cell_y) const
		{
			long double dist = this->fam * sqrtl(pow(cell_x - this->idx_x, 2) + pow(cell_y - this->idx_y, 2));
			return dist;
		}
};

/**
 * Represents a fire cell.
 */
class fire_t {

	public:
		fire_t(int _x, int _y, long double _fact) : idx_x(_x), idx_y(_y), fact(_fact) {};

	private:
		const int idx_x, idx_y;	/**< coordinates of the fire					*/
		const long double fact; /**< factor of fire higher means more impact 	*/
	public:

		/**
		 * Computed as follows:
		 * 	dist = f_k * sqrt((i - e_1k)^2) + (j - e_2k)^2)
		 */
		long double get_cell_distance(int cell_x, int cell_y) const
		{
			long double dist = this->fact * sqrtl(pow(cell_x - this->idx_x, 2) + pow(cell_y - this->idx_y, 2));
			return dist;
		}
};



/**
 * Computed according to the following equatation:
 *  S1 = max{ min[a_k * sqrt((i - e_1k)^2) + (j - e_2k)^2)] } - min[a_k * sqrt((i - e_1k)^2) + (j - e_2k)^2)]
 *  S1 = max{ min[a_k * distance_to_exit_k] } - min[a_k * distance_to_exit_k]
 *  S1 = gridwide_maxof_closest_exit - cell_closest_exit
 *  S1 = relative_closest_exit_attracion
 */
void TAV::update_static(Grid_t &grid)
{


	std::vector<exit_t> exits;			/**<	vector of exits found in the grid						*/
	long double grid_max_exit_mindist;	/**<	maximum grid-wide value of minimal cell-exit distance	*/
	std::vector<fire_t> fires;			/**<	vector of fires found in the grid						*/
	long double grid_max_fire_mindist;	/**<	maximum grid-wide value of minimal cell-fire distance	*/

	// find all Exits and Fires
	for (int idx_y = 0; idx_y < grid.getNumRows(); idx_y++)
	{
	   for (int idx_x = 0; idx_x < grid.getNumCols(); idx_x++)
		{
			Cell_t &cell = grid.getCellGrid().at(idx_y).at(idx_x);

			if (cell.getCellType() == CellType_t::EXIT)
			{
				exit_t tmp_exit{idx_x, idx_y, cell.getCellFact()};
				exits.push_back(tmp_exit);
			}

			if (cell.isOnFire())
			{
				fire_t tmp_fire{idx_x, idx_y, grid.getGridFireFactor()};
				fires.push_back(tmp_fire);
			}
		}
	}


	// compute min_exit_distance for each cell and grid_max_exit_mindistance
	// compute min_fire_distance for each cell and grid_max_fire_mindistance

	grid_max_exit_mindist = std::numeric_limits<long double>::min(); // set an initial maximum
	grid_max_fire_mindist = std::numeric_limits<long double>::min(); // set an initial maximum

	for (int idx_y = 0; idx_y < grid.getNumRows(); idx_y++)
	{
	   for (int idx_x = 0; idx_x < grid.getNumCols(); idx_x++)
		{
			Cell_t &cell = grid.getCellGrid().at(idx_y).at(idx_x);

			// Compute distance to exits
			// set an initial minimum
			long double dist = std::numeric_limits<long double>::max();
			cell.setCellExitMinDist(dist);

			// find min
			for (exit_t &exit : exits)
			{
				dist = exit.get_cell_distance(idx_x, idx_y);

				if (dist < cell.getCellExitMinDist())
				{
					cell.setCellExitMinDist(dist);
				}
			}
			// update max
			if (cell.getCellExitMinDist() > grid_max_exit_mindist)
			{
				grid_max_exit_mindist = cell.getCellExitMinDist();
			}

			// Compute distance to fires
			// set an initial minimum
			dist = std::numeric_limits<long double>::max();
			cell.setCellFireMinDist(dist);

			// find min
			for (fire_t &fire : fires)
			{
				dist = fire.get_cell_distance(idx_x, idx_y);

				if (dist < cell.getCellFireMinDist())
				{
					cell.setCellFireMinDist(dist);
				}
			}
			// update max
			if (cell.getCellFireMinDist() > grid_max_fire_mindist)
			{
				grid_max_fire_mindist = cell.getCellFireMinDist();
			}
		}
	}

	// set S_1, S_2 and F for all cells
	for (int idx_y = 0; idx_y < grid.getNumRows(); idx_y++)
	{
	   for (int idx_x = 0; idx_x < grid.getNumCols(); idx_x++)
		{
			Cell_t &cell = grid.getCellGrid().at(idx_y).at(idx_x);

 			// S1 = gridwide_maxof_closest_exit - cell_closest_exit
			long double S1 = grid_max_exit_mindist - cell.getCellExitMinDist();
			cell.setCellExitAttraction(S1);

			// S2
			if (cell.getCellType() == CellType_t::EMPTY || cell.getCellType() == CellType_t::PERSON || cell.getCellType() == CellType_t::EXIT)
			{
				long double cell_factor = cell.getCellFact();
				cell.setCellAisleAttraction(cell_factor);
			}

			// F = -(gridwide_maxof_closest_fire - cell_closest_fire)
			long double F = -(grid_max_fire_mindist - cell.getCellFireMinDist());
			cell.setCellFireAttraction(F);
		}
	}
}

/**
 * Returns the influence of the crowd
 */
long double get_crowd_inluence(Grid_t &grid, int person_x, int person_y, int cell_x, int cell_y)
{
	// get cell direction
	int cell_dx = cell_x - person_x;
	int cell_dy = cell_y - person_y;

	// get crowd direction
	int crowd_dx = 0; 
	int crowd_dy = 0;

	const int los = 3; // line of sight TODO make global?
	for (int y = -los; y < los; y++)
	{
		for (int x = -los; x < los; x++)
		{
			if (!grid.isOutsideTheBounds(x, y))
			{
				Cell_t cell = grid.getCellGrid().at(y).at(x);
				if (cell.getCellType() == CellType_t::PERSON)
				{
					std::pair<int, int> tmp_delta;

					tmp_delta = cell.getLastDir();
					crowd_dx += tmp_delta.first; 
					crowd_dy += tmp_delta.second; 
				}
			}
		}
	}

	// check whether the cell delta is the same as the crowd delta
	if (cell_dx == crowd_dx && cell_dy == crowd_dy)
		return grid.getGridCrowdInfluence();
	else
		return 0;
}

/**
 * Computed according to the following equatation:
 *  N_ij = exp[k_s * (S_1 + S_2) + k_r * R + k_d * D + F]
 */
TAV_t TAV::get_cell_tav(Grid_t &grid, int person_x, int person_y, int cell_x, int cell_y)
{
	Cell_t cell = grid.getCellGrid().at(cell_y).at(cell_x);
	Cell_t person = grid.getCellGrid().at(person_y).at(person_x);

	long double k_s = grid.getGridStaticImpact();
	long double S_1 = cell.getCellExitAttraction();
	long double S_2 = cell.getCellAisleAttraction();
	long double k_r = grid.getGridRepulsiveImpact();
	long double k_d = grid.getGridCrowdImpact();

	long double R = 0.0;
	if (grid.isOccupied(cell_x, cell_y))
	{
		R = grid.getGridRepulsiveForce();
	} 

	long double D = get_crowd_inluence(grid, person_x, person_y, cell_x, cell_y);

	long double F = cell.getCellFireAttraction();	/* Fire repulsion extension	*/

	long double tav = expl(k_s * (S_1 + S_2 + F) + k_r * R + k_d * D);
	if (tav < 0)
		tav = 0;	// TAV should not be less than zero TODO

	return tav; 
}
