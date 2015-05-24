//TODO change this to a combo box later.

//import java.awt.Choice;
import javax.swing.JComboBox;
import java.awt.Color;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;

public class ChoiceController {
  private DrawingFrame bT;

  public ChoiceController(DrawingFrame jF)
  {
    bT = jF;
    LocalColorChoiceHandler ch = new LocalColorChoiceHandler();
    LocalFillChoiceHandler fh = new LocalFillChoiceHandler();

    JComboBox<String> colorChoice = new JComboBox<String>();
      colorChoice.addItem("BLACK");
      colorChoice.addItem("RED");
      colorChoice.addItem("GREEN");
      colorChoice.addItem("BLUE");
      colorChoice.addItemListener(ch);
      colorChoice.setBackground(Color.white);
    bT.getChoicePanel().add(colorChoice);

    JComboBox<String> fillChoice = new JComboBox<String>();
      fillChoice.addItem("Fill");
      fillChoice.addItem("Unfill");
      fillChoice.addItemListener(fh);
      fillChoice.setBackground(Color.white);
    bT.getChoicePanel().add(fillChoice);

    bT.validate();
  }

  private class LocalColorChoiceHandler implements ItemListener{
    public void itemStateChanged(ItemEvent arg0) {
      if (arg0.getItem().equals("BLACK")) {
        bT.setCurrentColor(Color.black);
      }
      else if (arg0.getItem().equals("RED")) {
        bT.setCurrentColor(Color.red);
      }
      else if (arg0.getItem().equals("GREEN")) {
        bT.setCurrentColor(Color.green);
      }
      else if (arg0.getItem().equals("BLUE")) {
        bT.setCurrentColor(Color.blue);
      }
      //some kind of a error
      else {
        bT.setCurrentColor(Color.cyan);
      }
    }
  }

  private class LocalFillChoiceHandler implements ItemListener{
    public void itemStateChanged(ItemEvent arg0) {
      if (arg0.getItem().equals("Fill")) {
        bT.setFillState(true);
      }
      else {
        bT.setFillState(false);
      }
    }
  }
}
