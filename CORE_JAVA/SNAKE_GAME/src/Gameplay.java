import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.Random;

import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;
import javax.swing.ImageIcon;
import javax.swing.JPanel;
import javax.swing.Timer;

import com.sun.prism.Graphics;

public class Gameplay extends JPanel implements KeyListener,ActionListener{
	private int[] snakexlength = new int[750];
	private int[] snakeylength = new int[750];
	
	private int length=3;
	
	private int score=0;
	private boolean left = false;
	private boolean right = false;
	private boolean up = false;
	private boolean down = false;
	
	private ImageIcon rightm;
	private ImageIcon leftm;
	private ImageIcon upm;
	private ImageIcon downm;
	private ImageIcon snakem;
	private ImageIcon enemy;
	private int moves=0;
	
	private int[] enemyx={25,50,75,100,125,150,175,200,225,250,275,300,325,350,375,400,425,450,475,500,525,550,575,600,625,650,675,700,725,750,775,800,825,850};
	private int[] enemyy={75,100,125,150,175,200,225,250,275,300,325,350,375,400,425,450,475,500,525,550,575,600,625};
	
	private Random random = new Random();
	
	private int xpos = random.nextInt(34);
	private int ypos = random.nextInt(23);
	private Timer timer;
	private int delay=100;
	
private ImageIcon title;
	public Gameplay()
{
		addKeyListener(this);
		setFocusable(true);
		setFocusTraversalKeysEnabled(false);
		timer = new Timer(delay,this);
	timer.start();
	
	try
    {
    	
    AudioInputStream audioIn = AudioSystem.getAudioInputStream(Gameplay.class.getResource("my.wav"));
    Clip clip = AudioSystem.getClip();
    clip.open(audioIn);
    clip.start();
    }
    catch(Exception e)
    {
    }
	
}
	public void paint(java.awt.Graphics g)
	{
		if(moves == 0)
		{
		snakexlength[2]=50;
		snakexlength[1]=75;
		snakexlength[0]=100;
		
		snakeylength[2]=100;
		snakeylength[1]=100;
		snakeylength[0]=100;
		}
		//draw title border
		g.setColor(Color.WHITE);
		g.drawRect(24, 10, 849, 53);
		
		// draw title image
	title = new ImageIcon("title.png");	
	title.paintIcon(this, g, 25, 11);
	
	// draw border for gameplay
	g.setColor(Color.WHITE);
	g.drawRect(24, 74, 856, 582);
	
	// draw background for game play
	g.setColor(Color.BLACK);
	g.fillRect(25, 75, 855, 581);
	
	//draw scores
	g.setColor(Color.WHITE);
	g.setFont(new Font("arial",Font.BOLD,14));
	g.drawString("Scores: "+score, 780, 30);
	
	g.drawString("Length: "+length, 780, 50);
	
	rightm = new ImageIcon("right.png");
	rightm.paintIcon(this, g, snakexlength[0], snakeylength[0]);
	
	for(int a=0; a<length ; a++)
	{
		if(a==0 && right)
		{
			rightm = new ImageIcon("right.png");
			rightm.paintIcon(this, g, snakexlength[a], snakeylength[a]);
		}
		if(a==0 && left)
		{
			leftm = new ImageIcon("left.png");
			leftm.paintIcon(this, g, snakexlength[a], snakeylength[a]);
		}
		if(a==0 && up)
		{
			upm = new ImageIcon("up.png");
			upm.paintIcon(this, g, snakexlength[a], snakeylength[a]);
		}
		if(a==0 && down)
		{
			downm = new ImageIcon("down.png");
			downm.paintIcon(this, g, snakexlength[a], snakeylength[a]);
		}
		if(a!=0)
		{
			snakem = new ImageIcon("img.png");
			snakem.paintIcon(this, g, snakexlength[a], snakeylength[a]);
		}
	}
	
	enemy = new ImageIcon("enemy.png");
	if((enemyx[xpos] == snakexlength[0]) && enemyy[ypos] == snakeylength[0])
	{
	  score++;
	length++;
	xpos = random.nextInt(34);
	ypos = random.nextInt(23);
	}
	
	enemy.paintIcon(this, g, enemyx[xpos], enemyy[ypos]);
	
	for(int b=1;b<length;b++)
	{
		if(snakexlength[b]==snakexlength[0] && snakeylength[b]==snakeylength[0])
		{
			right=false;
			left=false;
			up=false;
			down=false;
			
			g.setColor(Color.white);
			g.setFont(new Font("arial",Font.BOLD,50));
			g.drawString("GAME OVER", 300, 300);
			
			g.setFont(new Font("arial",Font.BOLD,20));
			g.drawString("Space to RESTART", 350, 340);
		}
	}
	
	g.dispose();
	}
	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		timer.start();
		if(right)
		{
			for(int r=length-1;r>=0;r--)
			{
				snakeylength[r+1]=snakeylength[r];
			}
			for(int r=length;r>=0;r--)
			{
				if(r==0)
				{snakexlength[r]=snakexlength[r]+25;
				}
				else
				{
					snakexlength[r]= snakexlength[r-1];
				}
				if(snakexlength[r]>850)
				{
					snakexlength[r]=25;
				}
				}
			repaint();
			
		}
		if(left)
		{
			for(int r=length-1;r>=0;r--)
			{
				snakeylength[r+1]=snakeylength[r];
			}
			for(int r=length;r>=0;r--)
			{
				if(r==0)
				{snakexlength[r]=snakexlength[r]-25;
				}
				else
				{
					snakexlength[r]= snakexlength[r-1];
				}
				if(snakexlength[r]<25)
				{
					snakexlength[r]=850;
				}
				}
			repaint(); 
		}
		if(up)
		{
			for(int r=length-1;r>=0;r--)
			{
				snakexlength[r+1]=snakexlength[r];
			}
			for(int r=length;r>=0;r--)
			{
				if(r==0)
				{snakeylength[r]=snakeylength[r]-25;    
				}
				else
				{
					snakeylength[r]= snakeylength[r-1];
				}
				if(snakeylength[r]<75)
				{
					snakeylength[r]=625;
				}
				}
			repaint();
		}
		if(down)
		{
			for(int r=length-1;r>=0;r--)
			{
				snakexlength[r+1]=snakexlength[r];
			}
			for(int r=length;r>=0;r--)
			{
				if(r==0)
				{snakeylength[r]=snakeylength[r]+25;
				}
				else
				{
					snakeylength[r]= snakeylength[r-1];
				}
				if(snakeylength[r]>625)
				{
					snakeylength[r]=75;
				}
				}
			repaint();
		}
		
	}
	@Override
	public void keyPressed(KeyEvent e) {
		// TODO Auto-generated method stub
		if(e.getKeyCode() == KeyEvent.VK_SPACE)
		{
			moves=0;
			score=0;
			length=3;
			repaint();
		}
		if(e.getKeyCode()== KeyEvent.VK_RIGHT)
		{
			moves++;
			right=true;
			if(!left)
			{
				right=true;
			}
			else
			{
				right = false;
				left = true;
			}
			up=false;
			down=false;
		}
		if(e.getKeyCode()== KeyEvent.VK_LEFT)
		{
			moves++;
			left=true;
			if(!right)
			{
				left=true;
			}
			else
			{
				left = false;
				right = true;
			}
			up=false;
			down=false;
		}
		if(e.getKeyCode()== KeyEvent.VK_UP)
		{
			moves++;
			up=true;
			if(!down)
			{
				up=true;
			}
			else
			{
				up = false;
				down = true;
			}
			left=false;
			right=false;
		}
		if(e.getKeyCode()== KeyEvent.VK_DOWN)
		{
			moves++;
			down=true;
			if(!up)
			{
				down=true;
			}
			else
			{
				down = false;
				up = true;
			}
			left=false;
			right=false;
		}
	}
	@Override
	public void keyReleased(KeyEvent arg0) {
		// TODO Auto-generated method stub
		
	}
	@Override
	public void keyTyped(KeyEvent arg0) {
		// TODO Auto-generated method stub
		
	}
}
