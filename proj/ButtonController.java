import java.awt.Button;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ButtonController {
	private DrawingFrame bT;
	
	public ButtonController(DrawingFrame jF)
	{
		bT = jF;
    LocalButtonHandler bh = new LocalButtonHandler();

    Button b0 =new Button("FREE");
      b0.addActionListener(bh);

    Button b1 = new Button("LINE");
      b1.addActionListener(bh);

    Button b2 = new Button("CIRCLE");
      b2.addActionListener(bh);

    Button b3 = new Button("RECT");
      b3.addActionListener(bh);

    Button b4 = new Button("CLEAR");
      b4.addActionListener(bh);

    //by default, action command is set to button's label.
    //b1.setActionCommand("line");

    bT.getButtonPanel().add(b0);
    bT.getButtonPanel().add(b1);
    bT.getButtonPanel().add(b2);
    bT.getButtonPanel().add(b3);
    bT.getButtonPanel().add(b4);
	}
	
	private class LocalButtonHandler implements ActionListener {
		public void actionPerformed(ActionEvent ae) {
      //TODO change to switch case?
      if (ae.getActionCommand().equals("FREE")) {
        bT.setShape(new Shape().FREE);
      }
      else if (ae.getActionCommand().equals("LINE")) {
        bT.setShape(new Shape().LINE);
      }
      else if (ae.getActionCommand().equals("CIRCLE")) {
        bT.setShape(new Shape().CIRCLE);
      }
      else if (ae.getActionCommand().equals("RECT")) {
        bT.setShape(new Shape().RECT);
      }
      else if (ae.getActionCommand().equals("CLEAR")){
        bT.removeAll();
      }

		}
	}
}
