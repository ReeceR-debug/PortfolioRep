
import java.util.Scanner;
public class test
{
    public static void main(String args[])
   {
      int num;
      int doz;
      int loose;
      double total;
      double loosePrice = .45;
      double dozPrice = 3.25;
      Scanner input = new Scanner(System.in);
      System.out.print("Enter the number of eggs that you would like to buy: ");
      num = input.nextInt();
      doz = num / 12;
      loose = num - (doz * 12);
      total = (doz * dozPrice) + (loose * loosePrice);
      System.out.print("You ordered " + num + " eggs. That’s " + doz + " dozen at $3.25 per dozen and "+ loose + " loose eggs at 45 cents each for a total of " + total + ".");
    
   }

}

