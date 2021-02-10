package assignment07;

import java.util.ArrayList;

/**
 * Individual Cell in the grid of the Game of Life. It has a state called
 * "alive" which indicates whether it should appear as a black square or a
 * white square in the graphic
 * @author CS 140
 */
public class Cell {
	private boolean alive;
	private int myRow;
	private int myCol;
	private ArrayList<Cell> neighbors;
	/**
	 * Initialize the position and "alive" status of the Cell
	 * @param row the row location of this cell
	 * @param col the column location of this cell
	 */
	public Cell(int row, int col) {
		alive = false;
		myRow = row;
		myCol = col;
		neighbors = new ArrayList<>();
	}
	/**
	 * Called by CellGrid at the beginning of the simulation to set up the
	 * list of neighbors of each Cell
	 * @param cells
	 */
	public void populateNeighbors(Cell[][] cells) {
		int limitHoriz = cells[0].length;
		int limitVert = cells.length;
		// above left
		if(myRow > 0 && myRow < limitVert-1) {
			if(myCol > 0 && myCol < limitHoriz - 1) {
				// ADD 8 cells to neighbors (see the diagram from the textbook)
				neighbors.add(cells[myRow-1][myCol-1]);
				neighbors.add(cells[myRow-1][myCol]);
				neighbors.add(cells[myRow-1][myCol+1]);
				neighbors.add(cells[myRow][myCol-1]);
				neighbors.add(cells[myRow][myCol+1]);
				neighbors.add(cells[myRow+1][myCol-1]);
				neighbors.add(cells[myRow+1][myCol]);
				neighbors.add(cells[myRow+1][myCol+1]);
			}
			if(myCol == 0) { // left edge not corner
				// ADD 5 cells to neighbors (see the diagram from the textbook)
				neighbors.add(cells[myRow-1][myCol]);
				neighbors.add(cells[myRow-1][myCol+1]);
				neighbors.add(cells[myRow][myCol+1]);
				neighbors.add(cells[myRow+1][myCol]);
				neighbors.add(cells[myRow+1][myCol+1]);
			}
			if(myCol == limitHoriz - 1) { // right edge not corner
				// ADD 5 cells to neighbors (see the diagram from the textbook)
				neighbors.add(cells[myRow-1][myCol-1]);
				neighbors.add(cells[myRow-1][myCol]);
				neighbors.add(cells[myRow][myCol-1]);
				neighbors.add(cells[myRow+1][myCol-1]);
				neighbors.add(cells[myRow+1][myCol]);
			}
		}
		if(myRow == 0) { 
			if(myCol > 0 && myCol < limitHoriz - 1) { // top edge not corner
				neighbors.add(cells[myRow][myCol-1]);
				neighbors.add(cells[myRow][myCol+1]);
				neighbors.add(cells[myRow+1][myCol-1]);
				neighbors.add(cells[myRow+1][myCol]);
				neighbors.add(cells[myRow+1][myCol+1]);

			}
			if(myCol == 0) { // top left corner
				neighbors.add(cells[myRow][myCol+1]);
				neighbors.add(cells[myRow+1][myCol]);
				neighbors.add(cells[myRow+1][myCol+1]);
			}
			if(myCol == limitHoriz - 1) { // top right corner
				neighbors.add(cells[myRow][myCol-1]);
				neighbors.add(cells[myRow+1][myCol-1]);
				neighbors.add(cells[myRow+1][myCol]);
			}
		}
		if(myRow == limitVert-1) { 
			if(myCol > 0 && myCol < limitHoriz - 1) { // bottom edge
				neighbors.add(cells[myRow][myCol-1]);
				neighbors.add(cells[myRow-1][myCol-1]);
				neighbors.add(cells[myRow-1][myCol]);
				neighbors.add(cells[myRow-1][myCol+1]);
				neighbors.add(cells[myRow][myCol+1]);
			}
			if(myCol == 0) { // bottom left corner
				neighbors.add(cells[myRow-1][myCol]);
				neighbors.add(cells[myRow-1][myCol+1]);
				neighbors.add(cells[myRow][myCol+1]);
			}
			if(myCol == limitHoriz - 1) { // bottom right corner
				neighbors.add(cells[myRow][myCol-1]);
				neighbors.add(cells[myRow-1][myCol-1]);
				neighbors.add(cells[myRow-1][myCol]);
			}
		}
	}
	/**
	 * Gets the "alive" state of this cell
	 * @return the alive value
	 */
	public boolean isAlive() {
		return alive;
	}
	/**
	 * Sets the "alive" status of this cell
	 * @param alive the value of alive to be set
	 */
	public void setAlive(boolean alive) {
		this.alive = alive;
	}
	/**
	 * This is the key to the whole Game of Life. 
	 * + Calculate the number of live neighbors, call that "count"
	 * + If this cell is alive and "count" is 0,1,4,5,6,7,8 return false
	 *   (the cell dies of loneliness (count = 0,1) or dies of starvation 
	 *   (count = 4,5,6,7,8)
	 * + If this cell is not alive and "count" is _exactly_ 3, return true
	 *   a new cell is born
	 * + in all other cases return "alive" the current state of the cell.
	 * @return true if this Cell will be alive in next generation
	 */
	public boolean aliveNextTime() {
		boolean retVal = false;
		int num = neighbors.size();
		int num_alive = 0;
		for(int i=0;i<num;i++) {
			if(neighbors.get(i).isAlive()) {
				num_alive++;
			}
		}
		if(num_alive ==3) retVal = true;
		//count the live neighbors and consider the 
		//current alive state of this cell
		// use the rules of the game of life to return
		// true or false to indicate this cell will be alive
		// or not in the next generation.
		// DO NOT CHANGE the value of alive because we have
		// to gather ALL the new values before setting the 
		// state of the next generation
		return retVal;
	}
}
