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

  iconst_1
  istore 0
  getstatic java/lang/System/out Ljava/io/PrintStream;
  iload 0
  iconst_2
  imul
  invokevirtual java/io/PrintStream/println(I)V
  getstatic java/lang/System/out Ljava/io/PrintStream;
  ldc "oi"
  invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
  return
.end method