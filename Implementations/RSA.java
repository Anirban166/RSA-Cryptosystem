import java.util.Random;
import java.math.BigInteger;
import java.io.IOException;
import java.io.DataInputStream;
 
public class RSA
{
    private BigInteger p, q, n, phi, e, d;
    private int maxLength = 1024;
    private Random r;
 
    public RSA()
    {
        r = new Random();
        p = BigInteger.probablePrime(maxLength, r);
        q = BigInteger.probablePrime(maxLength, r);
        n = p.multiply(q);
        phi = p.subtract(BigInteger.ONE).multiply(q.subtract(BigInteger.ONE));
        e = BigInteger.probablePrime(maxLength / 2, r);
        while (phi.gcd(e).compareTo(BigInteger.ONE) > 0 && e.compareTo(phi) < 0)
        {
            e.add(BigInteger.ONE);
        }
        d = e.modInverse(phi);
    }
 
    public RSA(BigInteger e, BigInteger d, BigInteger n)
    {
        this.e = e;
        this.d = d;
        this.n = n;
    }
 
    public static void main (String [] arguments) throws IOException
    {
        RSA rsa = new RSA();
        DataInputStream input = new DataInputStream(System.in);
        String inputString;
        System.out.println("Enter message for encryption:");
        inputString = input.readLine();
        System.out.println("Encrypted message: " + inputString);
        System.out.println("Encrypted message in bytes: " + bToS(inputString.getBytes()));
        // Encrypting plaintext:
        byte[] cipher = rsa.encryptMessage(inputString.getBytes());
        // Decrypting ciphertext:
        byte[] plain = rsa.decryptMessage(cipher);
        System.out.println("Decrypted message in bytes: " + bToS(plain));
        System.out.println("Decrypted message: " + new String(plain));
    }
 
    private static String bToS(byte[] cipher)
    {
        String temp = "";
        for (byte b : cipher)
        {
            temp += Byte.toString(b);
        }
        return temp;
    }
 
    // Encryption function:
    public byte[] encryptMessage(byte[] message)
    {
        return (new BigInteger(message)).modPow(e, N).toByteArray();
    }
 
    // Decryption function:
    public byte[] decryptMessage(byte[] message)
    {
        return (new BigInteger(message)).modPow(d, N).toByteArray();
    }
}