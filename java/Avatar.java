import jssc.SerialPort;
import java.net.URL;
import java.io.*;
import javax.net.ssl.HttpsURLConnection;

public class Avatar {

    public static void main(String[] args) throws Exception {
        String httpsURL = "https://api.thingspeak.com/channels/15012/fields/1/last?key=PTJV0COS1KAVUSQM";
        URL myurl = new URL(httpsURL);
        HttpsURLConnection con = (HttpsURLConnection)myurl.openConnection();
        InputStream ins = con.getInputStream();
        InputStreamReader isr = new InputStreamReader(ins);
        BufferedReader in = new BufferedReader(isr);
     
        String inputLine = in.readLine().replace("\"", "");
        System.out.println("Obtendo dados... Valor encontrado: " + inputLine);

        in.close();

        SerialPort serialPort = new SerialPort(args[0]);
        System.out.println("Conectando na porta " + args[0] + "...");
        serialPort.openPort();
        serialPort.setParams(9600, 8, 1, 0);
        
        System.out.println("Aguarando string de inicializacao...");
        byte[] buffer = serialPort.readBytes(3); // Aguarda o envio dos primeiros bytes de inicialização
        System.out.println("Enviando os dados...");
        serialPort.writeString(inputLine);

        System.out.println("Fechando conexao...");
        serialPort.closePort();
    }
}