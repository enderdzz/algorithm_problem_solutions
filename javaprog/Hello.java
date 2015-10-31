/*Hello.java*/
public class Hello{
	public static void main(String[] args){
		double ans = 0.0, eps = 1e-12;
		int i = 1, flag = 1;
		while(1.0/i > eps){
			ans = ans + (1.0/i)*flag;
			i+=2;
			flag*=(-1);
		}
		System.out.println("F**k world.  "+ans*4.0);
	}
}
