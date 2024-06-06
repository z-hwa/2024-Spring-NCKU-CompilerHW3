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
    istore 3
        ldc 1
        istore 4
        

        for0:
        iload 4
        iload 0
        

        if_icmplt gtr_true_0
        gtr_false_0:
        iconst_0
        goto gtr_end_0
        gtr_true_0:
        iconst_1
        gtr_end_0:
        

        ifeq out1
        iload 4
        ldc 1
        iadd
        istore 4
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
        iload 3
        

        ifeq else2
            fload 1
            fload 5
            fadd
            fstore 1
            iload 3
            ldc 0
            istore 3
        goto out3
        else2:
            fload 1
            fload 5
            fsub
            fstore 1
            iload 3
            ldc 1
            istore 3
        out3:
        goto for0
    out1:
    

    fload 1
    freturn
.end method
.method public static main([Ljava/lang/String;)V
    .limit stack 100
    .limit locals 100
    ldc 100
    istore 7
    iload 7
    invokestatic Main/check(IILjava/lang/String;B)B
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
