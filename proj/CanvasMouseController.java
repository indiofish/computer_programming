import java.awt.Color;
import java.awt.Container;
import java.awt.Point;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import javax.swing.*;

//FIXME avoid using dummy point.
public class CanvasMouseController implements MouseMotionListener, MouseListener 
{
  private DrawingFrame bT;
  private Point start, end, route;
  private boolean isDragged = false;
  private Point dummy;

  public CanvasMouseController(DrawingFrame jF)
  {
    bT = jF;
    //mouse listening is only done in the shapeContainer
    bT.getShapeContainer().addMouseListener(this);
    bT.getShapeContainer().addMouseMotionListener(this);
    dummy = new Point();
    dummy.setLocation(-99,-99);
  }

  @Override
  public void mouseDragged(MouseEvent arg0) 
  {
    route = arg0.getPoint();
    //when free, draw on route, when other shape, don't
    bT.addShape(dummy,route,dummy);
  }

  @Override
  public void mouseMoved(MouseEvent arg0) 
  {

  }

  @Override
  public void mouseClicked(MouseEvent arg0) 
  {
    //if inside the shapeContainer do sth.
    //getPoint for relative position.
    start = arg0.getPoint();
    bT.addShape(start,start,start);
  }

  @Override
  public void mousePressed(MouseEvent arg0) 
  {
    start = arg0.getPoint();
  }

  @Override
  public void mouseReleased(MouseEvent arg0) 
  {
    end = arg0.getPoint();
    bT.addShape(start,dummy,end);
    //System.out.println(end.toString());
  }

  @Override
  public void mouseEntered(MouseEvent arg0) 
  {

  }

  @Override
  public void mouseExited(MouseEvent arg0) 
  {

  }
}
