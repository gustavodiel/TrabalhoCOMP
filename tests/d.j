.class public Main
.super java/lang/Object

.method public <init>()V
  aload_0

  invokevirtual java/lang/Object/<init>()V
  return
.end method

.method public static main([Ljava/lang/String;)V
.limit stack 10
.limit locals 5

  iconst_3
  iload 1
  iadd
  istore 3
  iload 3
  iload 0
  iadd
  istore 3
  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc "maior"
  invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
  getstatic java/lang/System/out Ljava/io/PrintStream;
  iload 3
  invokevirtual java/io/PrintStream/println(I)V
  ldc "Frase sem copyr
  istore 4
  getstatic java/lang/System/out Ljava/io/PrintStream;
  iload 4
  invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
  return
.end method