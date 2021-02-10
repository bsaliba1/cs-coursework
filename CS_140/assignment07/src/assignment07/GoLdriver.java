package assignment07;

import java.awt.Toolkit;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.JFrame;
import javax.swing.JOptionPane;

/**
 * Creates a background to see the Game of Life unfold
 */
public class GoLdriver {
	private int blockSideLength = 10;
	private int actualNumBlocksHoriz;
	private int actualNumBlocksVert;

	public static final int BACKLIMIT = 50;
	private JFrame graph;
	private LifePanel lifePanel;
	private boolean[][] blackSquares;
	private CellGrid cellGrid;
	private double blockWidth;
	private double blockHeight;
	private boolean running;
	private javax.swing.Timer timer;
	private Dimension screenSize;

	/**
	 * Actually creates the on screen objects and computes
	 * the number of blocks that give the best fit
	 */
	public GoLdriver() {
		graph = new JFrame();		
		graph.setUndecorated(true); // removes top bar from frame 
		screenSize = Toolkit.getDefaultToolkit().getScreenSize();
		graph.setSize(screenSize);

		actualNumBlocksHoriz = (int)Math.floor(screenSize.getWidth()/blockSideLength);
		actualNumBlocksVert = (int)Math.floor(screenSize.getHeight()/blockSideLength);
		blockWidth = screenSize.getWidth()/actualNumBlocksHoriz;
		blockHeight = screenSize.getHeight()/actualNumBlocksVert;
		blackSquares = new boolean[actualNumBlocksVert][actualNumBlocksHoriz];

		cellGrid = new CellGrid(actualNumBlocksVert, actualNumBlocksHoriz);

		lifePanel = new LifePanel(this, blockWidth, blockHeight,
				actualNumBlocksHoriz, actualNumBlocksVert,
				(int)screenSize.getWidth(),(int)screenSize.getHeight());
		graph.add(lifePanel);
		graph.setVisible(true);
		graph.addKeyListener(new MyKeyListener());
		JOptionPane.showMessageDialog(null, 
				"Hit E or X to enable the Exit Button Dialog\n" +
				"Use R to run a random pattern\n" +
				"Use N to run a Gosper Gun\n" +
				"and G to run the pattern you selected.\n" +
				"Use B to back up a maximum of " + BACKLIMIT + "times\n" + 
				"Use S to single-step the simulation"
		);
	}
	/**
	 * Gets the number of blocks displayed horizontally in the GUI
	 * @return the actual number of blocks horizontally
	 */
	public int getActualNumBlocksHoriz() {
		return actualNumBlocksHoriz;
	}
	/**
	 * Gets the number of blocks displayed vertically in the GUI
	 * @return the actual number of blocks vertically
	 */
	public int getActualNumBlocksVert() {
		return actualNumBlocksVert;
	}
	/**
	 * The method causes the CellGrid object to update the boolean array 
	 * "blackSquares," which summarizes the states of all the cells in the grid.
	 * The array is passed to the LifePanel before repainting.
	 */
	private void step() {
		cellGrid.executeStep(blackSquares);			
		lifePanel.setGrid(blackSquares);
		graph.repaint();		
	}
	
	/**
	 * main method
	 * @param args command line arguments are not used
	 */
	public static void main(String[] args) {
		//Schedule a job for the event-dispatching thread:
		//creating and showing this application's GUI.
		javax.swing.SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				new GoLdriver();
			}
		});
	}
	/**
	 * Mouse Listener stops the simulation running and gets the cell position 
	 * that is clicked and calls to set that cell to be "alive"
	 * CHANGE THE CODE SO THAT IT FLIPS THE "alive" STATE OF THE CELL.
	 * i.e. add code so that if the cell is alive, its "alive" status is
	 * changed to false.
	 */
	class MyMouseListener extends MouseAdapter {
		@Override
		public void mousePressed(MouseEvent me) {
			running = false;
			int mouseX = me.getX();
			int mouseY = me.getY();
			double cellX = mouseX/blockWidth;
			double cellY = mouseY/blockHeight;
			int row = (int)cellY;
			int col = (int)cellX;
			cellGrid.restartHistory();
			cellGrid.getCell(row, col).setAlive(true);
			cellGrid.setupBooleans(blackSquares);
			lifePanel.setGrid(blackSquares);
			graph.repaint();
		}
	}
	/**
	 * TimerListener object is passed to the Timer object and is called each 
	 * time the Timer times-out. This drives the animation.
	 */
	private class TimerListener implements ActionListener {
		public void actionPerformed(ActionEvent arg0) {
			if (running) {
				step();
			}
		}
	}
	/**
	 * The KeyListener object reacts to keys that are pressed during the 
	 * simulation of the Game of Life:
	 * 	E or X to enable the Exit Button Dialog
	 *  R to initializes the cells in a random pattern
	 *  G to simulates the Game of Life using the pattern you selected
	 *  B steps back through a limited number of previous configurations 
	 *  S changes to single-step the simulation"
	 *  Any other key just brings up a help dialog
	 */
	class MyKeyListener extends KeyAdapter {
		@Override
		public void keyPressed(KeyEvent arg0) {
			if (Character.toUpperCase(arg0.getKeyChar()) == 'B') {
				running = false;
				lifePanel.setGrid(cellGrid.backup());
				graph.repaint();				
			} else if (Character.toUpperCase(arg0.getKeyChar()) == 'E'
				|| Character.toUpperCase(arg0.getKeyChar()) == 'X') {
				running = false;
				int i = JOptionPane.showConfirmDialog(graph, 
						"Do you wish to exit? \nUse R to run a random " +
						"pattern \nand G to run the pattern you selected.\n" +
						"Use B to back up a maximum of " + BACKLIMIT + 
						"times\nUse S to single-step the simulation",
						"Confirm Exit", JOptionPane.YES_NO_OPTION);
				if (i == JOptionPane.YES_OPTION) System.exit(0);
			} else if (Character.toUpperCase(arg0.getKeyChar()) == 'G') {
				running = true;
				if (timer == null) {
					timer =	new javax.swing.Timer(100, new TimerListener());
					timer.start();
				}
			} else if (Character.toUpperCase(arg0.getKeyChar()) == 'R') {
				running = false;
				lifePanel.setGrid(cellGrid.randomStart());
				graph.repaint();				
			} else if (Character.toUpperCase(arg0.getKeyChar()) == 'N') {
				running = false;
				lifePanel.setGrid(cellGrid.GosperGun());
				graph.repaint();				
			} else if (Character.toUpperCase(arg0.getKeyChar()) == 'S') {
				running = false;
				step();
			} else {
				JOptionPane.showMessageDialog(null, 
						"Hit E or X to enable the Exit Button Dialog\n" +
						"Use R to run a random pattern\n" +
						"and G to run the pattern you selected.\n" +
						"Use B to back up a maximum of " + BACKLIMIT + 
						"times\nUse S to single-step the simulation"
				);
			}
		}	
	}
}
