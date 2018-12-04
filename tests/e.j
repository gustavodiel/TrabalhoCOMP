.class public Main
.super java/lang/Object

.method public <init>()V
  aload_0

  invokevirtual java/lang/Object/<init>()V
  return
.end method

.method public static main([Ljava/lang/String;)V
.limit stack 10
.limit locals 3

  iconst_3
  istore 0
  iconst_3
  istore 1
  iconst_1
  iload 0
  if_icmplt l1
  goto l2
  l1:	
  iload 0	
  iload 1	
  iadd	
  istore 0	
  goto l3
  l2:	
  iload 0	
  iload 1	
  isub	
  istore 0
  l3:	
  getstatic java/lang/System/outgoto Ljava/io/PrintStream;	
  iload 0	
  invokevirtual java/io/PrintStream/println(I)V	
  getstatic java/lang/System/out Ljava/io/PrintStream;	
  ldc "Wahaha!"	
  invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V	
  iconst_0
  return
.end method