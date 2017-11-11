// Problema: 755 - 487–3279
// Autor:    FernandoJerezano
// Fecha:    10-Noviembre-2017
import java.io.*;
import java.util.*;

class Main{

	static int valores[] = new int[150];
	
	public static void main(String[]args)throws IOException{
		
		
		BufferedReader br = new BufferedReader(
		new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(
		new OutputStreamWriter(System.out));
		
		
		TreeMap<String,Integer> map = new TreeMap<String,Integer>();
		String key;
		Integer value;
		
		/*
		BufferedReader br = new BufferedReader(
		new FileReader("entrada.txt"));
		PrintWriter pw = new PrintWriter("salida.txt");
		*/
		
		
		int t;
		int n;
		t = Integer.parseInt(br.readLine());
		String s;
		
		init();
		Integer v;
		int tot;
		
		for(int i=0;i<t;i++){
			br.readLine();
			
			n = Integer.parseInt(br.readLine().trim());
			map.clear();
			for(int j=0;j<n;j++){
				s = br.readLine();
				
				s = trans(s);
				v = map.get(s);
				if(v==null){
					map.put(s,1);
				}else{
					v++;
					map.put(s,v);
				}
				
			}
			
			tot = 0;
			
			for(Map.Entry<String,Integer> entry : map.entrySet()){
				key = entry.getKey();
				value = entry.getValue();
				if(value>1){
					tot++;
					pw.println(key+" "+value);
				}
			}
			if(tot==0)
				pw.println("No duplicates.");
			if(i!=t-1)
				pw.println();
		}
		
		br.close();
		pw.close();
	}
	
	public static boolean isValid(String s){
		
		String str[] = s.split("-");
		if(str.length!=2)
			return false;
		return true;
	}
	
	public static void init(){
		int v = 2;
		int c = 0;
		for(int i='A';i<='Y';i++){
			if(i=='Q')
				continue;
			if(c==3){
				v++;
				c = 0;
			}
			valores[i] = v;
			c++;
		}

	}
	
	public static String trans(String s){
		
		s = s.replaceAll("-","");
		
		s = s.substring(0,3)+"-"+s.substring(3,7);
		char arr[] = s.toCharArray();
		
		
		for(int i=0;i<8;i++){
			if(arr[i]>='A' && arr[i]<='Z'){
				arr[i] = (char)(valores[arr[i]]+'0');
			}
			
		}
		return new String(arr);
	}

}
















