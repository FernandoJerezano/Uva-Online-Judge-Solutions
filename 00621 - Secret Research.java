// Problema: 621 - Secret Research
// Autor:    FernandoJerezano
// Fecha:    04-Febrero-2018
import java.io.*;

public class Main{

	public static void main(String[]args)throws IOException{
	
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int t = Integer.parseInt(br.readLine());
		String s;
		int m;
		
		for(int i=01;i<=t;i++){
			s = br.readLine();
			if(s.equals("1") || s.equals("4") || s.equals("78")){
				System.out.println("+");
				
			}else{
				m = s.length();
				if(s.charAt(m-1)=='5' &&  s.charAt(m-2)=='3'){
					System.out.println("-");
				}else{
					if(s.charAt(0)=='9' && s.charAt(m-1)=='4'){
						System.out.println("*");
					}else{
						System.out.println("?");
					}
				}
				
			}
			
		}
		
	}

}
