/** Write a description of class usingMethods here.
 *
 * @author (your name)
 * @version (a version number or a date)
 */
import java.util.Scanner;
public class insurance
{
   public static void main(String args[])
   {
      int birth;
      int current;
      int premium;
      
      Scanner input = new Scanner(System.in);
      System.out.print("Please enter the year that you were born: ");
      birth = input.nextInt();
      System.out.print("Please enter the current year: ");
      current = input.nextInt();
      premium = computePremium(birth, current);
      
      System.out.println("Your premium will be " + premium);
   }
   public static int computePremium(int birth, int current)
   {
      int cost;
      int decade;
      int rate = 15;
      
      decade = (current - birth) / 10;
      
      cost = (decade + rate) * 20;
      
      return cost;
   }
}