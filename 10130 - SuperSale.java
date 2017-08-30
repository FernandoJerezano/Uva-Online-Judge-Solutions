// Problema:  10130 - SuperSale
// Autor:     FernandoJerezano
// Fecha:     30-Agosto-2017
import java.io.*;

class Main{
	
	static int V[];
	static int W[];
	static int N;
	static int MAX_N = 1010;
	static int MAX_V = 1010;
	static int MAX_W = 40;
	static int table[][] = new int[MAX_V][MAX_W];
	
	public static void main(String[]args)throws IOException{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
		
		//BufferedReader br = new BufferedReader(new FileReader("entrada.txt"));
		//PrintWriter pw = new PrintWriter("salida.txt");
		
		int T;
		int G;
		int p,w;
		int mw;
		int total;
		String str[];		
		
		T = Integer.parseInt(br.readLine());
		//V = new int[MAX_N];
		//W = new int[MAX_N];
		
		for(int i=0;i<T;i++){
			
			init();
			
			N = Integer.parseInt(br.readLine());
			V = new int[N];
			W = new int[N];
			
			for(int j=0;j<N;j++){
				str = br.readLine().split("\\s+");
				V[j] = Integer.parseInt(str[0]);
				W[j] = Integer.parseInt(str[1]);
			}
			
			total = 0;
			G = Integer.parseInt(br.readLine());
			for(int j=0;j<G;j++){
				mw = Integer.parseInt(br.readLine());
				total+=val_td(0,mw);
			}
			pw.println(total);
		}
		
		br.close();
		pw.close();
	}
	
	public static void init(){
		
		for(int i=0;i<MAX_V;i++){
			for(int j=0;j<MAX_W;j++){
				table[i][j] = -1;
			}
		}
		
	}
	
	public static int max(int a, int b){
		return a > b ? a : b;
	}
	
	public static int val_td(int id, int rw){
		if(id==N || rw<=0)		return 0;
		if(table[id][rw]!=-1)	return table[id][rw];
		if(W[id]>rw)			return table[id][rw] = val_td(id+1,rw);
		return table[id][rw] = max(val_td(id+1,rw),V[id]+val_td(id+1,rw-W[id]));
	}
	
	
}
