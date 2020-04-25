package queue;
import java.util.LinkedList;
import java.util.Queue;
public class QueueReversalUsingRecursion {
	
	static Queue<Integer> queue;
	
	static Queue<Integer>  reverseQueue(Queue<Integer> queue){
		if(queue.isEmpty()){
			return queue;
		}
		else{
		int data = queue.peek();
		queue.remove();
		queue= reverseQueue(queue);
		queue.add(data);
		return queue;
		}
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
		System.out.println(queue);
		queue=reverseQueue(queue);
		System.out.println(queue);
	}

}
