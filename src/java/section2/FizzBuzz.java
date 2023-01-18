import java.util.Scanner;

public class FizzBuzz {
  public static void main(String args[]){
    System.out.print("num: ");
    Scanner scan = new Scanner(System.in);
    int num = scan.nextInt();
    scan.close();

    for(int i=1;i<=num;i++){
      if(i%15 == 0){
        System.out.println(i+": FizzBuzz");
      }else if(i%3 == 0){
        System.out.println(i+": Fizz");
      }else if(i%5 == 0){
        System.out.println(i+": Buzz");
      }else{
        System.out.println(i);
      }
    }
  }
}
