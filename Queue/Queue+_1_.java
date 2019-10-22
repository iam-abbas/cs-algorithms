package labsheet7;

public class Queue {

     public int size;	
     public int front = -1;
     public int rear = -1;
	 Integer a[];
       Queue(int size){
    	   this.size = size;
    	   a= new Integer[size];
    	   front = -1;
    	   rear = -1;
       }
       Queue(){
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
    	      t++;
    	  }
		  System.out.println(a[t]);
    	  }else {
    		  System.out.println("Queue is empty");
    	  }
       }
       
       public void enqueue(int item) {
    	   if(rear > size) {
    		   System.out.println("Can't Enqueue");
    	   }else {
    		   if(front == -1) {
    			   front = 0;
    		   }
    		   
    		   	a[++rear] = item;
    	   }
       }
       
       public boolean equals(Queue q1) {
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
    	   front++;
    	   return t;
       }
       
}
