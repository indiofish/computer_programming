import java.awt.*;

@SuppressWarnings("serial")
public class Line extends Shape {
	public Line (Point a1, Point a2) {
		super (a1, a2);
	}
	public Object clone () {
		Line l = new Line (p1,p2);
		return l;
	}

  @Override
  public void paint(Graphics g) 
  {
    g.setColor(color);
    g.drawLine((int)p1.getX(),(int)p1.getY(),(int)p2.getX(),(int)p2.getY());
    validate();
  }
}
