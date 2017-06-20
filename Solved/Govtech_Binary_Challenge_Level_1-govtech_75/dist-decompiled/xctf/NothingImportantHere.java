/*    */ package xctf;
/*    */ 
/*    */ import java.io.PrintStream;
/*    */ import java.security.MessageDigest;
/*    */ 
/*    */ public class NothingImportant
/*    */ {
/*  8 */   private static final java.util.Random s_random = new java.util.Random(System.currentTimeMillis());
/*    */   
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
/*    */ 
/*    */ 
/*    */   public static void march_on(String paramString)
/*    */   {
/* 26 */     String[] arrayOfString = new String[6];
/* 27 */     arrayOfString[0] = "If he is not expecting the unexpected, he will not find it.\nIt is not to be reached by search or trail.";
/* 28 */     arrayOfString[1] = "I am getting impatient.";
/* 29 */     arrayOfString[2] = "Try harder";
/* 30 */     arrayOfString[3] = "You can replace it";
/* 31 */     arrayOfString[4] = "Be patience";
/* 32 */     arrayOfString[5] = "Are you sure?";
/*    */     
/* 34 */     String str = "00000";
/* 35 */     int i = 0;
/* 36 */     long l1 = 0L;long l2 = 0L;
/*    */     
/* 38 */     for (int j = 0; j < 100000000; j++) {
/* 39 */       long l3 = (int)(s_random.nextFloat() * 1000.0F);
/* 40 */       if (j % 10 == 0) {
/* 41 */         System.out.println(arrayOfString[(j % arrayOfString.length)]);
/*    */       }
/* 43 */       l1 = System.currentTimeMillis();
/* 44 */       try { Thread.sleep(l3); } catch (Exception localException) { localException.printStackTrace(System.out); }
/* 45 */       l2 = System.currentTimeMillis();
/* 46 */       long l4 = l2 - l1;
/* 47 */       if (l4 < l3) {
/* 48 */         System.out.println("No Cheating...");
/* 49 */         System.exit(1);
/*    */       }
/* 51 */       else if (l4 == l3) {
/* 52 */         paramString = md5(paramString + j);
/* 53 */         if ((paramString.startsWith(str)) && (i == 0)) {
/*    */           break;
/*    */         }
/*    */       }
/*    */       else {
/* 58 */         i = 1;
/*    */       }
/*    */     }
/* 61 */     if (i == 1) {
/* 62 */       System.out.println("I am very impressed with your patience. But ... no...");
/*    */ 
/*    */     }
/* 65 */     else if (paramString.startsWith(str)) {
/* 66 */       System.out.println("flag2{" + paramString + "}");
/*    */     }
/*    */     else {
/* 69 */       System.out.println("Try harder.");
/*    */     }
/*    */   }
/*    */ }


/* Location:              C:\Users\sit\Downloads\dist.zip!\dist\xctf\NothingImportantHere.class
 * Java compiler version: 8 (52.0)
 * JD-Core Version:       0.7.1
 */