// Problema: 579 - Clock Hands
// Autor:    FernandoJerezano
// Fecha:    04-Febrero-2018
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.DecimalFormat;

public class Main {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    public static void main(String[] args) throws IOException {
        prueba();
    }

    private static void prueba() throws IOException {
        String s,str[];
        int h,m;
        double grad;
        
        while(true){
            s = br.readLine();
            if(s.equals("0:00"))
                break;
            str = s.split(":");
            h = Integer.valueOf(str[0]);
            m = Integer.valueOf(str[1]);
            
            grad = Math.abs((h*30+.5*m)-m*6);
            
            if(grad>180)
                grad = Math.abs(360-grad);
            
            grad = Math.floor(grad*1000+0.5)/1000;
            System.out.printf("%.3f\n",grad);
            
        }
    }
    
}
