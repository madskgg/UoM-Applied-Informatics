import java.util.HashMap;


public class Main {

	public static void main(String[] args) {
		
		HashMap<String, String> map = new HashMap<String, String>();
		
		map.put("Mary", "2310-538759");
		map.put("Nick", "2310-766350");
		map.put("Helen", "2310-845788");
		map.put("Mike", "2310-224990");
		
		for(String name: map.keySet()) {
			String telephone = map.get(name);
			System.out.println(name + " : " + telephone);
		}
		
	}

}
