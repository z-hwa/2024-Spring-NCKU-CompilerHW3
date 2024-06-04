.class public Main
.super java/lang/Object
.method public static calculate_pi(I)
    .limit stack 100
    .limit locals 100
    ldc 3.000000
    ldc 2.000000
    ldc 1
        ldc 1
        ldc 4
        fmul
        fmul
        ldc 1.000000
        fadd
        fmul
        fmul
        fadd
        fmul
        fdiv
            ldc 0
            ldc 1
    return
.end method
.method public static main([Ljava/lang/String;)V
    .limit stack 100
    .limit locals 100
    ldc 100
    getstatic java/lang/System/out Ljava/io/PrintStream;
    ldc "Approximation of Pi after ";
    invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
    getstatic java/lang/System/out Ljava/io/PrintStream;
    swap
    invokevirtual java/io/PrintStream/print(I)V
    getstatic java/lang/System/out Ljava/io/PrintStream;
    ldc " terms: ";
    invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
    getstatic java/lang/System/out Ljava/io/PrintStream;
    swap
    invokevirtual java/io/PrintStream/print(F)V
    getstatic java/lang/System/out Ljava/io/PrintStream;
    ldc "
";
    invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
    ldc 0
    return
.end method
