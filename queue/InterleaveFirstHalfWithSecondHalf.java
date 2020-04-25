package queue;
import java.util.LinkedList;
import java.util.Stack;
import java.util.Queue;

public class InterleaveFirstHalfWithSecondHalf {

	static Queue<Integer> queue;
	
	static Queue<Integer> interleave(Queue<Integer> q){
		Stack<Integer> st = new Stack<Integer>();
		int length = q.size() / 2;
		for(int i = 0 ; i < length ; i++){
			st.push(q.peek());
			q.remove();
		}
		while(!st.isEmpty()){
			q.add(st.peek());
			st.pop();
		}
		for(int i = 0 ; i < length ; i++){
			q.add(q.peek());
			q.remove();
		}
		for(int i = 0 ; i < length ; i++){
			st.push(q.peek());
			q.remove();
		}
		while(!st.isEmpty()){
			q.add(st.peek());
			st.pop();
			q.add(q.peek());
			q.remove();
		}
		return q;
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
		queue = interleave(queue);
		System.out.println(queue);

	}

}
