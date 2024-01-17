import java.util.*;


public class Main {

	public static void main(String[] args) {
		
		ArrayList<String> names = new ArrayList<String>();
		
		names.add("John");
		names.add("Bob");
		names.add("Nick");
		names.add("Mary");
		names.add("Helen");
		
		System.out.println("----Sorted----");
		Collections.sort(names);
		System.out.println(names);
		
		System.out.println("----Reverse----");
		Collections.reverse(names);
		System.out.println(names);
		
		System.out.println("----Shuffle----");
		Collections.shuffle(names);
		System.out.println(names);
		
		Collections.swap(names, 2, 3);
		System.out.println("----Swap----");
		System.out.println(names);
		
		System.out.println("----Frequency----");
		names.add("Helen");
		names.add("Helen");
		int freq = Collections.frequency(names, "Helen");
		System.out.println("Frequency of Helen: " + freq);
		
		System.out.println("----Min Max----");
		String max = Collections.max(names);
		String min = Collections.min(names);
		System.out.println("Max: " + max + " Min: " + min);
	}

}
