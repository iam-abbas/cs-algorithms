package labsheet7;

public class Dequeue {

	public int size=5;	
    public int front = -1;
    public int rear = -1;
	 Integer a[];
      Dequeue(int size){
   	   this.size = size;
   	   a= new Integer[size];
   	   front = -1;
   	   rear = -1;
      }
      Dequeue(){
   	   a= new Integer[size];
   	   front = -1;
   	   rear = -1;
      }
      
      public void insertLast(int item){
    	  if(front == (rear+1)%size) {
    		  System.out.println("Dequeue is empty");
    	  }else {
    		  if(front == -1) {
    			  front = 0;
    		  }
    		  rear = (rear+1)%size;
              a[rear] = item;
    	  }
      }
      
      public Integer deleteFirst() {
    	  if(front == -1) {
    		  System.out.println("Queue is empty");
    	      return null; 
    	  }else {
    		  int t = a[front];
    		  if(front == rear) {
    			  rear = -1;
    			  front = -1;
    		  }
    		  front = (front+1)%size;
    		  return t;
    	  }
      }
      
      public void insertFirst(int item) {
    	  if(front == (rear+1)%size) {
    		  System.out.println("Dequeue is full");
    	  }else {
    		  if(front == -1) {
    			  front = 0;
    			  rear = 0;
    		  }else {
    			  if(front == 0) {
    				  front = size;
    			  }
    		  front = front-1;
    		  }
    		  a[front] = item;
         }
      }
      
      public Integer deleteLast() {
    	  if(front == -1) {
    		  System.out.println("dequeue is empty");
    	      return null;
    	  }else {
    		  int t = a[rear];
    		  if(front == rear) {
    			  front = -1;
    			  rear = -1;
    		  }
    		  if(rear == 0) {
    			  rear = size;
    		  }
    		  rear = rear - 1;
    		  return t;
    	  }
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
      		   System.out.println("Circular queue is empty");
      	   }
      }
      
      public int getRear() {
   	   return a[rear];
      }
      
      public int getFront() {
   	   return a[front];
      }
      
      public boolean isFull() {
    	  if(rear == (front-1)%size)
    		  return true;
    	  else
    		  return false;
      }

      public boolean isEmpty() {
    	  if(front == -1)
    		  return true;
    	  else 
    		  return false;
      }
      
}
