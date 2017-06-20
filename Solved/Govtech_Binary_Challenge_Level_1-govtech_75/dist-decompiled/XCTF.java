/*     */ import java.io.ByteArrayOutputStream;
/*     */ import java.io.File;
/*     */ import java.io.IOException;
/*     */ import java.io.InputStream;
/*     */ import java.lang.reflect.Method;
/*     */ import java.net.MalformedURLException;
/*     */ import java.net.URL;
/*     */ import java.net.URLClassLoader;
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ 
/*     */ public class XCTF
/*     */   extends URLClassLoader
/*     */ {
/*     */   public static void main(String[] paramArrayOfString)
/*     */     throws Exception
/*     */   {
/*  21 */     XCTF localXCTF = new XCTF(XCTF.class.getClassLoader(), new File("."));
/*     */     
/*     */ 
/*     */ 
/*  25 */     Thread.currentThread().setContextClassLoader(localXCTF);
/*     */     
/*  27 */     Class localClass = localXCTF.loadClass("Main");
/*     */     
/*  29 */     Method localMethod = localClass.getMethod("main", new Class[] { String[].class });
/*  30 */     String[] arrayOfString = new String[0];
/*  31 */     localMethod.invoke(null, new Object[] { arrayOfString });
/*     */   }
/*     */   
/*     */   public Class loadClass(String paramString, boolean paramBoolean)
/*     */     throws ClassNotFoundException
/*     */   {
/*  37 */     Object localObject = null;
/*     */     
/*  39 */     localObject = findLoadedClass(paramString);
/*     */     
/*  41 */     if (localObject == null)
/*     */     {
/*  43 */       Class localClass = null;
/*     */       try
/*     */       {
/*  46 */         localClass = getParent().loadClass(paramString);
/*     */         
/*  48 */         if (localClass.getClassLoader() != getParent()) {
/*  49 */           localObject = localClass;
/*     */         }
/*     */       }
/*     */       catch (ClassNotFoundException localClassNotFoundException1) {}catch (ClassFormatError localClassFormatError) {}
/*     */       
/*  54 */       if (localObject == null)
/*     */       {
/*     */         try
/*     */         {
/*  58 */           localObject = findClass(paramString);
/*     */         }
/*     */         catch (ClassNotFoundException localClassNotFoundException2)
/*     */         {
/*  62 */           localObject = localClass;
/*     */         }
/*     */       }
/*     */     }
/*     */     
/*  67 */     if (localObject == null) {
/*  68 */       throw new ClassNotFoundException(paramString);
/*     */     }
/*  70 */     if (paramBoolean) {
/*  71 */       resolveClass((Class)localObject);
/*     */     }
/*  73 */     return (Class)localObject;
/*     */   }
/*     */   
/*     */   protected Class findClass(String paramString)
/*     */     throws ClassNotFoundException
/*     */   {
/*  79 */     String str = paramString.replace('.', '/') + ".class";
/*  80 */     URL localURL = getResource(str);
/*     */     
/*  82 */     if (localURL == null) {
/*  83 */       throw new ClassNotFoundException(paramString);
/*     */     }
/*     */     
/*  86 */     InputStream localInputStream = null;
/*     */     try
/*     */     {
/*  89 */       localInputStream = localURL.openStream();
/*     */       
/*  91 */       byte[] arrayOfByte = readFully(localInputStream);
/*     */       
/*  93 */       crypt(arrayOfByte);
/*     */       
/*  95 */       return defineClass(paramString, arrayOfByte, 0, arrayOfByte.length);
/*     */     }
/*     */     catch (IOException localIOException)
/*     */     {
/*  99 */       throw new ClassNotFoundException(paramString);
/*     */     }
/*     */     finally
/*     */     {
/* 103 */       if (localInputStream != null) try { localInputStream.close();
/*     */         }
/*     */         catch (Exception localException2) {}
/*     */     }
/*     */   }
/*     */   
/*     */   private XCTF(ClassLoader paramClassLoader, File paramFile) throws MalformedURLException
/*     */   {
/* 111 */     super(new URL[] { paramFile.toURL() }, paramClassLoader);
/*     */     
/* 113 */     if (paramClassLoader == null) {
/* 114 */       throw new IllegalArgumentException("XCTF requires a non-null delegation parent");
/*     */     }
/*     */   }
/*     */   
/*     */   private static void crypt(byte[] paramArrayOfByte)
/*     */   {
/* 120 */     char[] arrayOfChar1 = new char['ā'];
/* 121 */     char[] arrayOfChar2 = new char['ā'];
/*     */     
/*     */ 
/* 124 */     String str = "nomorepptplease!";
/*     */     
/* 126 */     int n = 0;
/* 127 */     int k = 0;
/* 128 */     int m = 0;
/*     */     
/*     */ 
/* 131 */     for (int i = 0; i < 256; i++)
/*     */     {
/* 133 */       arrayOfChar1[i] = ((char)i);
/*     */     }
/*     */     
/* 136 */     i = 0; for (int j = 0; i < 256; i++)
/*     */     {
/* 138 */       if (j == str.length()) {
/* 139 */         j = 0;
/*     */       }
/* 141 */       arrayOfChar2[i] = str.charAt(j++);
/*     */     }
/*     */     
/* 144 */     j = 0;
/* 145 */     for (i = 0; i < 256; i++)
/*     */     {
/* 147 */       j = (j + arrayOfChar1[i] + arrayOfChar2[i]) % 256;
/* 148 */       m = arrayOfChar1[i];
/* 149 */       arrayOfChar1[i] = arrayOfChar1[j];
/* 150 */       arrayOfChar1[j] = ((char)m);
/*     */     }
/*     */     
/* 153 */     i = 0;
/* 154 */     j = 0;
/* 155 */     for (int i1 = 0; i1 < paramArrayOfByte.length; i1++)
/*     */     {
/*     */ 
/* 158 */       i = (char)((i + 1) % 256);
/*     */       
/* 160 */       j = (char)((j + arrayOfChar1[i]) % 256);
/*     */       
/*     */ 
/*     */ 
/*     */ 
/* 165 */       m = arrayOfChar1[i];
/* 166 */       arrayOfChar1[i] = arrayOfChar1[j];
/* 167 */       arrayOfChar1[j] = ((char)m);
/*     */       
/*     */ 
/* 170 */       k = (arrayOfChar1[i] + arrayOfChar1[j]) % 256;
/*     */       
/*     */ 
/* 173 */       n = arrayOfChar1[k];
/*     */       
/*     */ 
/* 176 */       paramArrayOfByte[i1] = ((byte)(paramArrayOfByte[i1] ^ n));
/*     */     }
/*     */   }
/*     */   
/*     */ 
/*     */ 
/*     */ 
/*     */   private static byte[] readFully(InputStream paramInputStream)
/*     */     throws IOException
/*     */   {
/* 186 */     ByteArrayOutputStream localByteArrayOutputStream = new ByteArrayOutputStream();
/* 187 */     byte[] arrayOfByte = new byte[' '];
/*     */     int i;
/* 189 */     while ((i = paramInputStream.read(arrayOfByte)) > 0)
/*     */     {
/* 191 */       localByteArrayOutputStream.write(arrayOfByte, 0, i);
/*     */     }
/*     */     
/* 194 */     return localByteArrayOutputStream.toByteArray();
/*     */   }
/*     */ }


/* Location:              C:\Users\sit\Downloads\dist.zip!\dist\XCTF.class
 * Java compiler version: 8 (52.0)
 * JD-Core Version:       0.7.1
 */