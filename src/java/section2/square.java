import java.util.Scanner;

public class square{
  public static void main(String[] args){
    System.out.print("length: ");
    Scanner scan = new Scanner(System.in);
    int length = scan.nextInt();
    scan.close();

    for(int j=0;j<length;j++){
      for(int i=0;i<length-j-1;i++){
        System.out.print(" ");
      }
      for(int i=0;i<2*j+1;i++){
        System.out.print("*");
      }
      System.out.println();
    }
  }
}