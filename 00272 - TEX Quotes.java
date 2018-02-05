// Problema: 272 - TEX Quotes
// Autor:    FernandoJerezano
// Fecha:    04-Febrero-2018

import java.io.*;

public class Main {

    /**
     * @param args the command line arguments
     */
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    public static void main(String[] args) throws IOException {
        metod();
    }
    
    private static void metod() throws IOException {
        String s,str[] = {"``","''"};
        int c = 0;
        while((s = br.readLine())!=null){
            while(s.indexOf("\"")!=-1){
                s = s.replaceFirst("\"", str[c++%2]);
            }
            System.out.println(s);
        }
    }
    
}
