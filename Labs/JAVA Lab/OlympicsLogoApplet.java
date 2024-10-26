import java.applet.Applet;
import java.awt.*;

public class OlympicsLogoApplet extends Applet {

    @Override
    public void paint(Graphics g) {
        // Cast to Graphics2D for better control
        Graphics2D g2d = (Graphics2D) g;

        // Set stroke width for the circles
        g2d.setStroke(new BasicStroke(5));

        // Set color and draw first circle (Blue)
        g2d.setColor(Color.BLUE);
        g2d.drawOval(50, 50, 100, 100);  // x=50, y=50

        // Set color and draw second circle (Yellow)
        g2d.setColor(Color.YELLOW);
        g2d.drawOval(120, 100, 100, 100);  // x=120, y=100

        // Set color and draw third circle (Black)
        g2d.setColor(Color.BLACK);
        g2d.drawOval(190, 50, 100, 100);  // x=190, y=50

        // Set color and draw fourth circle (Green)
        g2d.setColor(Color.GREEN);
        g2d.drawOval(260, 100, 100, 100);  // x=260, y=100

        // Set color and draw fifth circle (Red)
        g2d.setColor(Color.RED);
        g2d.drawOval(330, 50, 100, 100);  // x=330, y=50
    }
}
