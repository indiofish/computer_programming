import java.awt.Color;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.Graphics;

@SuppressWarnings("serial")
public class ShapeContainer extends Container implements java.io.Serializable {
	public int s;
	
	public ShapeContainer () {
		super();
		setBackground (Color.white);
		s = 0;
	}
	
  @Override
	public void paint(Graphics g) {
    g.setColor(getBackground());
    g.fillRect(0, 0, getWidth(), getHeight());
    g.setColor (Color.black);
    for (int i = 0; i <this.getComponentCount();i++) {
      this.getComponent(i).paint(g);
    }

    //s++;
    return;
	}

  //public void add(Shape s) 
  //{
  //}



  public Dimension getPreferredSize () {
    return new Dimension (400,500);
  }
}
