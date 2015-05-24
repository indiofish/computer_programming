import java.awt.*;
import java.lang.Math;

@SuppressWarnings("serial")
public class Rectangular extends Shape {

	public Rectangular (Point a1, Point a2) {
		super (a1, a2);
	}
	public Object clone () {
		Rectangular l = new Rectangular (p1,p2);
		return l;
	}

  //FIXME if this is drawn from diffrent direction
  //we have to calculate the left corner
  //before we draw it.
	public void paintComponent (Graphics g) {
    //X left corner, Y left corner.
    //super.paintComponent(g);
    int Xleft = 0;
    int Yleft = 0;
    
    int X1 = (int) p1.getX();
    int Y1 = (int) p1.getY();

    int X2 = (int) p2.getX();
    int Y2 = (int) p2.getY();
    
    int width = Math.abs(X1 - X2);
    int heigth = Math.abs(Y1 - Y2);

    //left corner is minimum x,y of each points
    Xleft = (X1 <= X2 ? X1:X2);
    Yleft = (Y1 <= Y2 ? Y1:Y2);

    g.setColor(color);

    if (isFill()) 
      g.fillRect(Xleft,Yleft,width,heigth);
    else
      g.drawRect(Xleft,Yleft,width,heigth);
  }
}
