import java.io.PrintStream;
import java.security.MessageDigest;

public class solve {
    public static String paramString = "flag1{7171a60f8cf4a789b7fa5906aa78f3e7}";


/*    */   public static String md5(String paramString) {
/* 11 */     MessageDigest localMessageDigest = null;
/* 12 */     try { localMessageDigest = MessageDigest.getInstance("MD5"); } catch (Exception localException) { localException.printStackTrace(System.out); }
/* 13 */     localMessageDigest.update(paramString.getBytes());
/* 14 */     byte[] arrayOfByte1 = localMessageDigest.digest();
/* 15 */     StringBuffer localStringBuffer = new StringBuffer();
/* 16 */     for (int k : arrayOfByte1) {
/* 17 */       localStringBuffer.append(String.format("%02x", new Object[] { Integer.valueOf(k & 0xFF) }));
/*    */     }
/* 19 */     return localStringBuffer.toString();
/*    */   }
/*    */   

    public static void main(String[] paramArrayOfString) {
        for (int j = 0; j < 100000000; j++) {
            paramString = md5(paramString + j);
            if ((paramString.startsWith("00000")) /* && (i == 0) */) {
                break;
            }
            System.out.println("Now on " + j);
        }
        if (paramString.startsWith("00000")) {
            System.out.println("flag2{" + paramString + "}");
        }   
    }
}