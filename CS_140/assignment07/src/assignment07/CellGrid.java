package assignment07;

/**
 * CellGrid holds the array of Cells that are displayed in the Game of Life
 * @author CS 140
 */
public class CellGrid {
	private Cell[][] cells;
	private int maxRows;
	private int maxCols;
	private boolean[][][] history;
	private int index = 0;
	private int totalMoves = 0;
	/**
	 * Create an array of Cells with maxRows rows and maxCols columns
	 * @param maxRows the number of rows in the CellGrid
	 * @param maxCols the number of columns in the CellGrid
	 */
	public CellGrid(int maxRows, int maxCols) {
		history = new boolean[GoLdriver.BACKLIMIT][maxRows][maxCols];
		this.maxRows = maxRows;
		this.maxCols = maxCols;
		cells = new Cell[maxRows][maxCols];
		for(int i = 0; i < maxRows; i++)
			for(int j = 0; j < maxCols; j++)
				cells[i][j] = new Cell(i,j);
		for(int i = 0; i < maxRows; i++)
			for(int j = 0; j < maxCols; j++)
				cells[i][j].populateNeighbors(cells);
	}
	/**
	 * Gets the cell object at location (row, col)
	 * @param row row number of cell
	 * @param col column number of cell
	 * @return the Cell object at the given location
	 */
	public Cell getCell(int row, int col) {
		return cells[row][col];
	}

	/**
	 * Backs up one position in the array of configurations that have been 
	 * stored up to a maximum given by GoLdriver.BACKLIMIT
	 * @return array of booleans indicated which cells are alive
	 */
	public boolean[][] backup() {
		if (totalMoves > 0) {
			totalMoves = totalMoves - 1;
			index = (history.length + index - 1)%history.length;
			for(int i = 0; i < maxRows; i++)
				for(int j = 0; j < maxCols; j++) {
					cells[i][j].setAlive(history[index][i][j]);
				}
			return history[index];
		}
		return history[index];
	}

	/**
	 * Generate a random layout of cells that are alive for use when starting
	 * the Game of Life simulation
	 * @return a random array of booleans indicating which cells are alive
	 */
	public boolean[][] randomStart() {
		boolean[][] bools = new boolean[maxRows][maxCols];
		java.util.Random random = new java.util.Random();
		for(int i = 0; i < maxRows; i++)
			for(int j = 0; j < maxCols; j++) {
				bools[i][j] = random.nextBoolean();
				cells[i][j].setAlive(bools[i][j]);
			}
		return bools;
	}
	/**
	 * The method stores the current configuration in the history array.
	 * The history has a maximum storage capacity given by 
	 * GoLdriver.BACKLIMIT
	 * Next, it requests that the cells determine their new state in the next
	 * iteration of the Game of Life. Finally, it sets the cells to their new 
	 * states. Since the next state of a cell depends on the state of its 
	 * neighbors, all the new states have to be determined before any cell can
	 * change its state.
	 * @param bools array of booleans used to display the cells that are alive
	 */
	public void executeStep(boolean[][] bools) {
		for(int i = 0; i < maxRows; i++)
			for(int j = 0; j < maxCols; j++)
				history[index][i][j] = cells[i][j].isAlive();
		index = (index + 1)%history.length;
		if (totalMoves < history.length - 1) totalMoves++;

		// in a nesting of 2 loops find the "aliveNextTime" value of each cell
		// and store the values in the array "bools"
		for(int i = 0; i < maxRows; i++)
			for(int j = 0; j < maxCols; j++)
				bools[i][j] = cells[i][j].aliveNextTime();

		// in a nesting of 2 loops use setAlive on the cells to set their
		// "alive state" to the values stored in the array "bools"
		for(int i = 0; i < maxRows; i++)
			for(int j = 0; j < maxCols; j++)
				cells[i][j].setAlive(bools[i][j]);
	}
	/**
	 * Reset the history to "apparently" having nothing stored. This is done
	 * by setting the count of moves made back to 0.
	 * This method is called when the Game of Life is interrupted by a mouse
	 * click to change the "alive" state of the cells. 
	 */
	public void restartHistory() {
		totalMoves = 0;
	}
	/**
	 * Method initializes the array of booleans from the "alive" state of each
	 * cell in the grid. The boolean array is used for the black and white
	 * cells in the display.
	 * @param bools array of booleans used to display the cells that are alive
	 */
	public void setupBooleans(boolean[][] bools) {
		for(int i = 0; i < maxRows; i++)
			for(int j = 0; j < maxCols; j++)
				bools[i][j] = cells[i][j].isAlive();
	}
	/**
	 * Initialize the live cells with a Gosper gun
	 * from http://en.wikipedia.org/wiki/File:Game_of_life_glider_gun.svg
	 */
	public boolean[][] GosperGun() {
		boolean[][] bools = new boolean[maxRows][maxCols];
		bools[5][1] = true;
		bools[5][2] = true;
		bools[6][1] = true;
		bools[6][2] = true;
		bools[1][25] = true;
		bools[2][23] = true;
		bools[2][25] = true;
		bools[3][13] = true;
		bools[3][14] = true;
		bools[3][21] = true;
		bools[3][22] = true;
		bools[3][35] = true;
		bools[3][36] = true;
		bools[4][12] = true;
		bools[4][16] = true;
		bools[4][21] = true;
		bools[4][22] = true;
		bools[4][35] = true;
		bools[4][36] = true;
		bools[5][11] = true;
		bools[5][17] = true;
		bools[5][21] = true;
		bools[5][22] = true;
		bools[6][11] = true;
		bools[6][15] = true;
		bools[6][17] = true;
		bools[6][18] = true;
		bools[6][23] = true;
		bools[6][25] = true;
		bools[7][11] = true;
		bools[7][17] = true;
		bools[7][25] = true;
		bools[8][12] = true;
		bools[8][16] = true;
		bools[9][13] = true;
		bools[9][14] = true;		
		for(int i = 0; i < maxRows; i++) {
			for(int j = 0; j < maxCols; j++) {
				cells[i][j].setAlive(bools[i][j]);
			}
		}
		return bools;
	}
}
