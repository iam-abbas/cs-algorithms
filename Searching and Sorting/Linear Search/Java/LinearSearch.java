import java.util.Scanner;
class LinearSearch
{
   public static void main(String args[])
   {
      int counter, numOfElements, itemToSearch, array[];
      Scanner input = new Scanner(System.in);
      System.out.println("Enter number of elements:");
      numOfElements = input.nextInt(); 
      array = new int[numOfElements]; 
      System.out.println("Enter elements");
      for (counter = 0; counter < numOfElements; counter++)
        array[counter] = input.nextInt();
      System.out.println("Enter the search value:");
      itemToSearch = input.nextInt();
      for (counter = 0; counter < numOfElements; counter++)
      {
         if (array[counter] == itemToSearch) 
         {
           System.out.println(itemToSearch+" is present at  "+(counter+1));
           break;
         }
      }
      if (counter == numOfElements)
        System.out.println(itemToSearch + " is not present");
   }
}