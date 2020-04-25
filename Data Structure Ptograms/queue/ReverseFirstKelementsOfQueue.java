package queue;
import java.util.LinkedList;
import java.util.Stack;
import java.util.Queue;

public class ReverseFirstKelementsOfQueue {

	static Queue<Integer> queue;
	
	static Queue<Integer> reverseKelements(int k){
		if(queue.isEmpty()){
			return queue;
		}
		Stack<Integer> st = new Stack<Integer>();
		for(int i = 1 ; i <= k ; i++){
			int data = queue.peek();
			queue.remove();
			st.push(data);
		}
		while(!st.isEmpty()){
			queue.add(st.peek());
			st.pop();
		}
		int size = queue.size();
		for(int i = 1 ; i <= size-k ; i++){
			 queue.add(queue.peek()); 
	         queue.remove(); 
		}
		return queue;
	}
	
	public static void main(String[] args) {
		
		queue = new LinkedList<Integer>();
		queue.add(10);
		queue.add(20);
		queue.add(30);
		queue.add(40);
		queue.add(50);
		queue.add(60);
		queue.add(70);
		queue.add(80);
		queue.add(90);
		queue.add(100);
		System.out.println(queue);
		queue = reverseKelements(5);
		System.out.println(queue);

	}

}
