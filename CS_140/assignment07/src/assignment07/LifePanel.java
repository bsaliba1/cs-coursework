package assignment07;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.geom.Line2D;
import java.awt.geom.Rectangle2D;

import javax.swing.JPanel;

public class LifePanel extends JPanel {
	private static final long serialVersionUID = 6512638741574985313L;
	private double blockWidth;
	private double blockHeight;
	private int screenWidth;
	private int screenHeight;
	private int numBlocksHoriz;
	private int numBlocksVert;
	private boolean[][] blackSquares;
	
	/**
	 * Set up the display panel for the GUI
	 * @param callBack reference back to the class containing the MouseListener
	 * @param blockWidth2 the width of a single block
	 * @param blockHeight2 the height of a single block
	 * @param nBlocksHoriz the number of blocks horizontally
	 * @param nBlocksVert the number of blocks vertically
	 * @param scrWidth the width of the screen in pixels
	 * @param scrHeight the height of the screen in pixels
	 */
	public LifePanel(GoLdriver callBack,
			double blockWidth2, double blockHeight2, 
			int nBlocksHoriz, int nBlocksVert, 
			int scrWidth, int scrHeight) {
		blockWidth = blockWidth2;
		blockHeight = blockHeight2;
		screenWidth = scrWidth;
		screenHeight = scrHeight;
		numBlocksHoriz = nBlocksHoriz;
		numBlocksVert = nBlocksVert;		
		blackSquares = new boolean[numBlocksVert][numBlocksHoriz];
		addMouseListener(callBack.new MyMouseListener());
	}

	/**
	 * Draws the black squares that represent cells that are alive and then 
	 * draws the lines that form the grid of the GUI
	 * @param g the graphics context of the GUI
	 */
	@Override
	public void paintComponent(Graphics g) {
		Graphics2D g2 = (Graphics2D)g;
		for (int i = 0; i < blackSquares.length; i++)
			for (int j = 0; j < blackSquares[i].length; j++)
				if(blackSquares[i][j])
					g2.fill(new Rectangle2D.Double(j*blockWidth, i*blockHeight, 
							blockWidth, blockHeight));
		g2.setColor(Color.BLACK);
		for (int i = 1; i < numBlocksVert; i++)
			g2.draw(new Line2D.Double(0,i*blockHeight, screenWidth, i*blockHeight));
		
		for (int j = 1; j < numBlocksHoriz; j++)
			g2.draw(new Line2D.Double(j*blockWidth, 0, j*blockWidth, screenHeight));
	}
	
	/**
	 * Sets the grid of booleans that contain the "alive" status of each cell
	 * in the cell grid 
	 * @param aGrid
	 */
	public void setGrid(boolean[][] aGrid) {
		blackSquares = aGrid;
	}	
}