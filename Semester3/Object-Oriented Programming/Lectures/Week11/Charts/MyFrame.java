import javax.swing.JFrame;
import org.jfree.chart.*;
import org.jfree.chart.plot.*;
import org.jfree.data.category.*;


public class MyFrame extends JFrame {
	
	public MyFrame() {
		
		DefaultCategoryDataset dataset = new DefaultCategoryDataset();
		dataset.addValue(212, "Classes", "JDK1.0");
		dataset.addValue(504, "Classes", "JDK1.1");
		dataset.addValue(1520, "Classes", "SDK1.2");
		dataset.addValue(1842, "Classes", "SDK1.3");
		dataset.addValue(2991, "Classes", "SDK1.4");
		
		JFreeChart chart = ChartFactory.createBarChart3D("Java Evolution", "Release", "Class Count", dataset, PlotOrientation.HORIZONTAL, false, true, false);
		
		ChartPanel chartPanel = new ChartPanel(chart);
		
		this.setContentPane(chartPanel);
		
		this.setVisible(true);
		this.setSize(500, 500);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
	}
	

}
