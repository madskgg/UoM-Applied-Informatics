//interface FuncInterface {
//	void abstractfun(int x);
//}

// (όρισμα) -> υλοποίηση

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {

	public static void main(String[] args) {

//		FuncInterface obj = (int x) -> System.out.println(x);
//		
//		obj.abstractfun(5);
		
		
//		ArrayList<Integer> arrL = new ArrayList<>();
//		arrL.add(1);
//		arrL.add(2);
//		arrL.add(3);
//		arrL.add(4);
//		
//		arrL.forEach(n -> System.out.println(n));
//		
//		System.out.println("---------------");
//		arrL.forEach(n -> {if(n%2==0) System.out.println(n);});
		
//		List<Integer> numbers = Arrays.asList(2, 3, 4, 5, 6, 7, 8, 9, 10);
//		
//		numbers.stream().filter(x -> (x%2==1)).map(x -> x*x*x).forEach(n -> System.out.println(n));
		
//		ArrayList<String> list = new ArrayList<>();
//		list.add("One");
//		list.add("oneandonly");
//		list.add("hello");
//		list.add("derek");
//		list.add("Monday");
//		list.add("Italy");
//		list.add("");
//		list.add("Germany");
//		
//		list.stream().filter(element -> element.contains("d")).forEach(element -> System.out.println(element));
		
		List<Integer> numbers = Arrays.asList(120, 340, 570, 860, 940);
		
		numbers.stream().filter(x -> (x>500)).map(x -> (x/2)).forEach(x -> System.out.println(x));
	}
}
