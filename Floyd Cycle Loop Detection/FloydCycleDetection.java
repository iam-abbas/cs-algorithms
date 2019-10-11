import java.util.*; 
  
public class FloydCycleDetection { 
    static Node head; 
    static class Node { 
        int data; 
        Node next; 
        Node(int d) 
        { 
            data = d; 
            next = null; 
        } 
    } 
 
    static public void push(int new_data) 
    { 
        Node newNode = new Node(new_data); 
  
        newNode.next = head; 
  
        head = newNode; 
    } 
   
    static boolean detectLoop(Node h) 
    { 
        HashSet<Node> s = new HashSet<Node>(); 
        while (h != null) { 
            if (s.contains(h)) 
                return true; 
  
            s.add(h); 
  
            h = h.next; 
        } 
  
        return false; 
    } 
  
    public static void main(String[] args) 
    { 
        FloydCycleDetection llist = new FloydCycleDetection(); 
  
        llist.push(20); 
        llist.push(4); 
        llist.push(15); 
        llist.push(10); 
  
        llist.head.next.next.next.next = llist.head; 
  
        if (detectLoop(head)) 
            System.out.println("Cycle Deteced"); 
        else
            System.out.println("No Cycle"); 
    } 
} 