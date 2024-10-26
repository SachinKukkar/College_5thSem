import java.applet.Applet;
import java.awt.*;

public class applet extends Applet {
    @Override
    public void paint(Graphics g) {
        // Draw the Olympic rings with colors

        // Blue ring
        g.setColor(Color.BLUE);
        g.drawOval(50, 50, 100, 100);  // Blue ring
       

        // Yellow ring
        g.setColor(Color.YELLOW);
        g.drawOval(120, 100, 100, 100);  // Yellow ring
       

        // Black ring
        g.setColor(Color.BLACK);
        g.drawOval(190, 50, 100, 100); // Black ring
      

        // Green ring
        g.setColor(Color.GREEN);
        g.drawOval(260, 100, 100, 100);  // Green ring
        

        // Red ring
        g.setColor(Color.RED);
        g.drawOval(330, 50, 100, 100); // Red ring
       
    }
}
