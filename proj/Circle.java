import java.awt.*;
import java.lang.Math;

@SuppressWarnings("serial")
public class Circle extends Shape {
  private int radius = 0;

  //Point a1 -> left corner, point a2 -> right corner
	public Circle (Point a1, Point a2) {
		super (a1, a2);
    int d1, d2;
    d1 = (int) (a1.getX() - a2.getX());
    d2 = (int) (a1.getY() - a2.getY());

    radius = (int) Math.sqrt(d1*d1 + d2*d2);
	}
	public Object clone () {
		Circle l = new Circle (p1,p2);
    return l;
  }

  @Override
  //FIXME if this is drawn from diffrent direction
  //we have to calculate the left corner
  //before we draw it.
  //Can we know the left corner if any two points are given?
  public void paintComponent (Graphics g) {
    //super.paintComponent(g);
    int Xleft = 0;
    int Yleft = 0;

    int X1 = (int) p1.getX();
    int Y1 = (int) p1.getY();

    int X2 = (int) p2.getX();
    int Y2 = (int) p2.getY();
    
    //left corner is middle of two points - half the radius
    Xleft =  (X1+X2)/2 - radius/2;
    Yleft =  (Y1+Y2)/2 - radius/2;

    g.setColor(color);

    if (isFill()) 
      g.fillOval(Xleft,Yleft,radius,radius);
    else
      g.drawOval(Xleft,Yleft,radius,radius);
  }
}
