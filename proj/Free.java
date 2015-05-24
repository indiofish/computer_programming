import java.awt.*;

@SuppressWarnings("serial")
public class Free extends Shape {
	public Free (Point a1) {
		super (a1, a1);
	}
	public Object clone () {
		Free dot = new Free(p1);
		return dot;
	}

  //instead of paint, override paintComponent
	public void paintComponent (Graphics g) {
    int leftX = (int) p1.getX();
    int leftY = (int) p1.getY();
		
    g.setColor(color);
    g.fillRect(leftX, leftY, 2, 2); 
  }
}
