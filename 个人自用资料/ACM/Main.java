

import java.util.Random;
import java.util.Scanner;


public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        char c;
        String a;
        System.out.println("您好，欢迎来到本银行的贷款界面");
        int sj=(int)(Math.random()*41+60);
        System.out.printf("您的信用良好，信用积分为：%d\n",sj);
        System.out.printf("您的贷款额度为：%d\n",1000+sj*10);
        System.out.printf("请问是否需要贷款？(y/n)\n");
        do{
            a=sc.next();
			//ca.charAt(0);
		    System.out.println(c);
            if(a.charAt(0)!='y'||a.charAt(0)!='n'){
                System.out.println("输入有误。请重新输入");
            }
        }while(c!='y'||c!='n');
        if(c=='y'){
            System.out.println("贷款成功");
        }
    }

}