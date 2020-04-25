package queue;
import java.util.LinkedList;
import java.util.Stack;
import java.util.Queue;

public class ReverseLinkedList {

	 static void reverseQueue(Queue<Integer> queue){
		Stack<Integer> st = new Stack<Integer>();
		while(!queue.isEmpty()){
			st.add(queue.peek());
			queue.remove();
		}
		while(!st.isEmpty()){
			queue.add(st.peek());
			st.pop();
		}
	}
	
	
	public static void main(String[] args) {
		Queue<Integer> queue = new LinkedList();
		queue.add(10);
		queue.add(20);
		queue.add(30);
		queue.add(40);
		queue.add(50);
		queue.add(60);
		System.out.println(queue);
		reverseQueue(queue);
		System.out.println(queue);

	}

}
