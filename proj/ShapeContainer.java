import java.awt.Color;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Point;

@SuppressWarnings("serial")
public class ShapeContainer extends Container implements java.io.Serializable {
	public int s;
	
	public ShapeContainer () {
		super ();
		setBackground (Color.white);
		s = 0;
	}
	
	public void paint(Graphics g) {
    g.setColor(getBackground());
    g.fillRect(0, 0, getWidth(), getHeight());
    g.setColor (Color.black);
    //this does the drawing job of components added by add()?
    super.paint(g);
	}

  public Dimension getPreferredSize () {
    return new Dimension (400,500);
  }
}
