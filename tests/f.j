.class public Main
.super java/lang/Object

.method public <init>()V
  aload_0

  invokevirtual java/lang/Object/<init>()V
  return
.end method

.method public static main([Ljava/lang/String;)V
.limit stack 10
.limit locals 1

  getstatic java/lang/System/out Ljava/io/PrintStream;
  iconst_1
  iconst_1
  iadd
  invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc "Qual o seu nome
  invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
  ldc "Frase sem copyr
  istore 0
  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc "Ola oi"
  invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
  getstatic java/lang/System/out Ljava/io/PrintStream;
  iload 0
  invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
  getstatic java/lang/System/out Ljava/io/PrintStream;
  iconst_1
  iconst_2
  iadd
  invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
  return
.end method