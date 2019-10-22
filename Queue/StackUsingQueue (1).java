package labsheet7;

public class StackUsingQueue {

	public int size;	
    public int front = -1;
    public int rear = -1;
	 Integer a[];
	 StackUsingQueue(int size){
   	   this.size = size;
   	   a= new Integer[size];
   	   front = -1;
   	   rear = -1;
      }
	 StackUsingQueue(){
   	   this.size= 5;
   	   a= new Integer[size];
   	   front = -1;
   	   rear = -1;
      }
      
     public void print() {
   	   int t = front;
   	  if(front != -1) {
   	  while(t != rear) {
   		  System.out.println(a[t]);
   	      t = (t+1)%size;
   	  }
		  System.out.println(a[t]);
   	  }else {
   		  System.out.println("Queue is empty");
   	  }
   }
     
	public void push(int item) {
	
		int t;
		enqueue(item);
		while(a[front] != item) {
			t = dequeue();
			enqueue(t);
		}		
	}
	
	public int pop() {
		int t = dequeue();
		return t;
	}
	
	public void enqueue(int item) {
 	   if(front == (rear+1)%size) {
 		   System.out.println("Can't Enqueue");
 	   }else {
 		   if(front == -1) {
 			   front = 0;
 		   }
 		    rear = (rear+1)%size;
 		   	a[rear] = item;
 	   }
    }
    
    public Integer dequeue() {
 	   if(front == -1) {
 		   System.out.println("Queue is empty");
 	       return null;
 	   }
 	   int t = a[front];
 	   if(front == rear) {
 		front = -1;
 		rear = -1;
 	   }else
 	   front= (front+1)%size;
 	   return t;
    }
}
