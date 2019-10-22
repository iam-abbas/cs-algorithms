package labsheet7;

public class Circularqueue {

	public int size;	
    public int front = -1;
    public int rear = -1;
	 Integer a[];
      Circularqueue(int size){
    	this.size = size;  
   	   a= new Integer[size];
   	   front = -1;
   	   rear = -1;
      }
      Circularqueue(){
    	  this.size = 5;
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
   		   System.out.println("Circular queue is empty");
   	   }
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
      
      public boolean equals(Circularqueue q1) {
   	   while(rear >size && q1.rear > q1.size) {
   		   if(a[rear] != q1.a[q1.rear]) {
   			   return false;
   		   }
   	   }
   	   return true;
      }
      
      public int getFront() {
       return a[front];
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
   	   front = (front+1)%size;
   	   return t;
      }

      public void splitq() {
    	  int i =0;
    	  Circularqueue q1 = new Circularqueue();
    	  Circularqueue q2 = new Circularqueue();
    	  while(front != -1) {
    		  if(i%2 == 0){
    			  q1.enqueue(dequeue());
    		  }
    		  else
    			 q2.enqueue(dequeue()); 
    		  i++;
    	  }
     	  q1.print();
     	  q2.print();
      } 
      
      public int getMinElement() {
    	  int min = dequeue();
    	  Circularqueue q1 = new Circularqueue();
    	  q1.enqueue(min);
    	  int t;
    	  while(front != -1) {
    		  t = dequeue();
    		  if(min>t) {
    			  min = t;
    		  }
    		  q1.enqueue(t); 
    	  }
    	  while(q1.front != -1) {
    		  enqueue(q1.dequeue());
    	  }
    	  return min;
      }
}
