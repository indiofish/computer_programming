import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

@SuppressWarnings( "serial" )
public class DrawingFrame extends JFrame {
  private ShapeContainer shapeContainer;

  //number of shapes
  int count = 0;

  //Panels
  private Panel buttonPanel; 
  private Panel choicePanel;
  private Panel textPanel;

  //debug purpose

  private JLabel titleLabel;

  //currenst states.
  private int currentShape;
  private Color currentColor;
  private boolean fillState;

  private WhiteBoardService rmiModule;
  private String entity;

  private CanvasMouseController drawer;

  public DrawingFrame(String title, WhiteBoardService rmi)
  {
    super(title);
    entity = title;

    //default states
    currentShape = new Shape().FREE;
    currentColor = Color.BLACK;
    fillState = true;

    rmiModule = rmi;

    //init all panels
    buttonPanel = new Panel();
    textPanel = new Panel();
    choicePanel = new Panel();

    //added by me
    new ButtonController(this);
    getContentPane().add("South",buttonPanel);
    new ChoiceController(this);
    getContentPane().add("East",choicePanel);

    shapeContainer = new ShapeContainer();
    getContentPane().add("Center",shapeContainer);

    titleLabel = new JLabel("그림판", SwingConstants.CENTER);
    getContentPane().add("North",titleLabel);


    drawer = new CanvasMouseController(this);
    //end

    addWindowListener(new LocalWindowListener());

    this.pack();
    //setSize(500,500);

    //show() deprecated, use setVisible(true) instead;
    setVisible(true);
  }

  public Container getShapeContainer() { return shapeContainer; }
  public Panel getButtonPanel() { return buttonPanel; }
  public Panel getChoicePanel() { return choicePanel; }
  public void setShape(int shape) { currentShape = shape; }
  public int myGetShape() { return currentShape; }
  public void setShapeContainer(ShapeContainer s) { getContentPane().add(s); }

  public void addShape(Point start, Point route, Point end)
  { //parameter: left right corner of the shape?
    Shape newShape = new Free(route);

    //default shape is a line(pixel);
    if (myGetShape() == new Shape().LINE)
    {
      newShape = new Line(start,end);
    }

    else if (myGetShape() == new Shape().CIRCLE)
    {
      newShape = new Circle(start,end);
    }
    else if (myGetShape() == new Shape().RECT)
    {
      newShape = new Rectangular(start,end);
    }

    newShape.setColor(getCurrentColor());
    newShape.setFill(getFillState());
    newShape.setBounds(0,0,getShapeContainer().getWidth(), getShapeContainer().getHeight());
    try {
      getShapeContainer().add(newShape);
      //FIXME uncomment this line later.
      rmiModule.add(newShape,entity);
      //removeFrontShape();
    } catch (Exception e) {
      e.printStackTrace();
    }
    validate();
    repaint();
  }

  //used to erase topmost element???
  public void removeFrontShape()
  {
    try {
      rmiModule.removeFrontShape(entity);
    } catch (RemoteException e) {
      e.printStackTrace();
    }
    repaint();
  }

  public void removeAll()
  {
    try {
      rmiModule.removeAll(entity);
    } catch (RemoteException e) {
      e.printStackTrace();
    }
    repaint();
  }


  public void setCurrentColor(Color c) { currentColor = c; }
  public Color getCurrentColor() { return currentColor; }

  public void setFillState(boolean b) { fillState = b; }
  public boolean getFillState() { return fillState; }

  public WhiteBoardService getRmiModule() { return rmiModule; }
  public void setRmiModule(WhiteBoardServiceImpl m) { rmiModule = m; }

  private class LocalWindowListener extends WindowAdapter {
    public void windowClosing(WindowEvent e){
      dispose();
      System.exit(0);
    }
  }
}
