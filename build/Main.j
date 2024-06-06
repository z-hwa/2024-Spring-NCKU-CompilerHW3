.class public Main
.super java/lang/Object
.method public static calculate_pi(I)
    .limit stack 100
    .limit locals 100
    ldc 3.000000
    fstore 1
    ldc 2.000000
    fstore 2
    ldc 1
        ldc 1
        istore 4
        iload 4
        iload 0
        iload 4
        ldc 1
        iadd
        ldc 4
        i2f
        fload 2
        iload 4
        i2f
        fmul
        fload 2
        iload 4
        i2f
        fmul
        ldc 1.000000
        fadd
        fmul
        fload 2
        iload 4
        i2f
        fmul
        fload 2
        fadd
        fmul
        fdiv
        fstore 5
        ifeq else0
            fload 5
            fload 1
            swap
            fadd
            fstore 1
            ldc 0
        goto out0
        else0:
            fload 5
            fload 1
            swap
            fsub
            fstore 1
            ldc 1
        else1:
        out0:
    fload 1
    return
.end method
.method public static main([Ljava/lang/String;)V
    .limit stack 100
    .limit locals 100
    ldc 100
    istore 7
    iload 7
    fstore 8
    getstatic java/lang/System/out Ljava/io/PrintStream;
    ldc "Approximation of Pi after ";
    invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
    iload 7
    getstatic java/lang/System/out Ljava/io/PrintStream;
    swap
    invokevirtual java/io/PrintStream/print(I)V
    getstatic java/lang/System/out Ljava/io/PrintStream;
    ldc " terms: ";
    invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
    fload 8
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
