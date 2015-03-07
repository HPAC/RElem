setMethod("+",
    signature(e1 = "ElMatrix", e2 = "ElMatrix"),
    function (e1, e2) 
    {
        if(e1@datatype !=e2@datatype)
          stop("Matrices have to be of the same datatype")
        if(e1$Height() != e2$Height() && e1$Width() != e2$Width())
          stop("Matrices should have the same size")
        A <- Matrix(e1@datatype)
        Copy(e2, A)
        Axpy(1.0, e1, A)
        A
    }
)
