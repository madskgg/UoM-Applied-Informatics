import java.util.ArrayList;

public class Ship {

	private String name;
	private int capacity;
	private ArrayList<Container> containers = new ArrayList<>();
	
	public Ship(String name, int capacity) {
		this.name = name;
		this.capacity = capacity;
	}
	
    public String getName() {
    	return name;
    }
	
	public void addContainer(Container aContainer) {
		if(containers.size() < capacity) {
			containers.add(aContainer);
			System.out.println("Container has been loaded");
		}
		else
			System.out.println("Sorry, the ship is full");
	}
	
    public double calculateTotalCharge() {
        double totalCharge = 0;
        for (Container container : containers) {
            totalCharge += container.calculateCharge();
        }
        return totalCharge;
    }
    
}
