.class public Main
.super java/lang/Object
.method public static calculate_pi(I)
    .limit stack 100
    .limit locals 100
    return
.end method
.method public static main([Ljava/lang/String;)V
    .limit stack 100
    .limit locals 100
    getstatic java/lang/System/out Ljava/io/PrintStream;
    ldc "Approximation of Pi after ";
    invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
    getstatic java/lang/System/out Ljava/io/PrintStream;
    ldc " terms: ";
    invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
    getstatic java/lang/System/out Ljava/io/PrintStream;
    ldc "
";
    invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
    return
.end method
