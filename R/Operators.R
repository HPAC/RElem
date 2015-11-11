#############
### Constants
#############

MAX_SIZE_PRINT <- 100

############
### Addition
############

setMethod("+",
          signature(e1 = "ElMatrix", e2 = "ElMatrix"),
          function (e1, e2) 
          {
            if(e1@datatype !=e2@datatype)
              stop("Matrices have to be of the same datatype")
            if(e1$Height() != e2$Height() && e1$Width() != e2$Width())
              stop("Matrices should have the same size")
            matA <- Matrix(e1@datatype)
            Copy(e1, matA)
            Axpy(1.0, e2, matA)
            matA
          }
          )

setMethod("+",
          signature(e1 = "ElDistMatrix", e2 = "ElDistMatrix"),
          function (e1, e2) 
          {
            if(e1@datatype !=e2@datatype)
              stop("Matrices have to be of the same datatype")
            if(e1$Height() != e2$Height() && e1$Width() != e2$Width())
              stop("Matrices should have the same size")
            matA <- Matrix(e1@datatype)
            Copy(e1, matA)
            Axpy(1.0, e2, matA)
            matA
          }
          )

###############
### Subtraction
###############

setMethod("-",
          signature(e1 = "ElMatrix", e2 = "ElMatrix"),
          function (e1, e2) 
          {
            if(e1@datatype !=e2@datatype)
              stop("Matrices have to be of the same datatype")
            if(e1$Height() != e2$Height() && e1$Width() != e2$Width())
              stop("Matrices should have the same size")
            matA <- Matrix(e1@datatype)
            Copy(e1, matA)
            Axpy(-1.0, e2, matA)
            matA
          }
          )

setMethod("-",
          signature(e1 = "ElDistMatrix", e2 = "ElDistMatrix"),
          function (e1, e2) 
          {
            if(e1@datatype !=e2@datatype)
              stop("Matrices have to be of the same datatype")
            if(e1$Height() != e2$Height() && e1$Width() != e2$Width())
              stop("Matrices should have the same size")
            matA <- Matrix(e1@datatype)
            Copy(e1, matA)
            Axpy(-1.0, e2, matA)
            matA
          }
          )

##########################################################
### Multiplication (including R and El object interaction)
##########################################################

setMethod("%*%",
          signature(x = "ElMatrix", y = "ElMatrix"),
          function (x, y) 
          {
            if(x@datatype !=y@datatype)
              stop("Matrices have to be of the same datatype")
            if(x$Width() != y$Height() )
              stop("Matrices cannot be multiplied, A$Width()!=B$Height()")
            matC <- Matrix(x@datatype)
            MatrixResize(matC, x$Height(), y$Width())
            if(y$Width() == 1){
              Gemv("NORMAL", 1.0, x, y, 0.0, matC)
            }else{
              Gemm("NORMAL", "NORMAL", 1.0, x, y, 0.0, matC)
            }
            matC
          }
          )

setMethod("%*%",
          signature(x = "ElMatrix", y = "numeric"),
          function (x, y) 
          {
            y2 <- Matrix(tag = x@datatype, rmat = y)
            x %*% y2
          }
          )

setMethod("%*%",
          signature(x = "numeric", y = "ElMatrix"),
          function (x, y) 
          {
            x2 <- Matrix(tag = y@datatype, rmat = x)
            x2 %*% y
          }
          )


setMethod("%*%",
          signature(x = "ElDistMatrix", y = "ElDistMatrix"),
          function (x, y) 
          {
            if(x@datatype !=y@datatype)
              stop("Matrices have to be of the same datatype")
            if(x$Width() != y$Height() )
              stop("Matrices cannot be multiplied, A$Width()!=B$Height()")
            matC <- Matrix(x@datatype)
            MatrixResize(matC, x$Height(), y$Width())
            if(y$Width() == 1){
              Gemv("NORMAL", 1.0, x, y, 0.0, matC)
            }else{
              Gemm("NORMAL", "NORMAL", 1.0, x, y, 0.0, matC)
            }
            matC
          }
          )

setMethod("%*%",
          signature(x = "ElDistMatrix", y = "numeric"),
          function (x, y) 
          {
            y2 <- DistMatrix(tag = x@datatype, rmat = y)
            x %*% y2
          }
          )

setMethod("%*%",
          signature(x = "numeric", y = "ElDistMatrix"),
          function (x, y) 
          {
            x2 <- DistMatrix(tag = y@datatype, rmat = x)
            x2 %*% y
          }
          )


###################################
### Entrywise matrix multiplication
###################################



setMethod("*",
          signature(e1 = "ElMatrix", e2 = "ElMatrix"),
          function (e1, e2) 
          {
            if(e1@datatype != e2@datatype)
              stop("Matrices have to be of the same datatype")
            if(e1$Height() != e2$Height() && e1$Width() != e2$Width())
              stop("Matrices should have the same size")
            matC <- Matrix(e1@datatype)
            Hadamard(e1,e2,matC)
            matC
          }
          )

setMethod("*",
          signature(e1 = "ElDistMatrix", e2 = "ElDistMatrix"),
          function (e1, e2) 
          {
            if(e1@datatype != e2@datatype)
              stop("Matrices have to be of the same datatype")
            if(e1$Height() != e2$Height() && e1$Width() != e2$Width())
              stop("Matrices should have the same size")
            matC <- Matrix(e1@datatype)
            Hadamard(e1,e2,matC)
            matC
          }
          )

################
# Matrix Scaling
################

setMethod("*",
          signature(e1 = "ElMatrix", e2 = "numeric"),
          function (e1, e2) {
            if(length(e2) !=1)
              stop("A scalar must be provided")
            ans <- Matrix(e1@datatype)
            Zeros(ans, e1$Height(), e1$Width())
            Axpy(e2, e1, ans)
            ans
          })

setMethod("*",
          signature(e1 = "numeric", e2 = "ElMatrix"),
          function (e1, e2) {
            e2*e1
          })

setMethod("*",
          signature(e1 = "ElDistMatrix", e2 = "numeric"),
          function (e1, e2) 
          {
            if(length(e2) !=1)
              stop("A scalar must be provided")
            ans <- DistMatrix(e1@datatype)
            Zeros(ans, e1$Height(), e1$Width())
            Axpy(e2, e1, ans)
            ans
          })


setMethod("*",
          signature(e1 = "numeric", e2 = "ElDistMatrix"),
          function (e1, e2) {
            e2*e1
          })


###########################
### The default show method
###########################

setMethod("show",
          signature(object = "ElMatrix"),
          function (object) 
          {
            if(object$Height() <=MAX_SIZE_PRINT && object$Width()<=MAX_SIZE_PRINT)
              {
                Print(object)
              }
            else
              {
                callNextMethod(object)
              }
          }
          )

setMethod("show",
          signature(object = "ElDistMatrix"),
          function (object) 
          {
            if(object$Height() <=MAX_SIZE_PRINT && object$Width()<=MAX_SIZE_PRINT)
              {
                Print(object)
              }
            else
              {
                callNextMethod(object)
              }
          }
          )

################
### Print method
################

setMethod("print",
          signature(x = "ElMatrix"),
          function (x) 
          {
            if(x$Height() <=MAX_SIZE_PRINT && x$Width()<=MAX_SIZE_PRINT)
              {
                Print(x)
              }
            else
              {
                callNextMethod(x)
              }
          }
          )

setMethod("print",
          signature(x = "ElDistMatrix"),
          function (x) 
          {
            if(x$Height() <=MAX_SIZE_PRINT && x$Width()<=MAX_SIZE_PRINT)
              {
                Print(x)
              }
            else
              {
                callNextMethod(x)
              }
          }
          )

####################
### Accessor methods
####################


setMethod("[","ElMatrix",
          function(x, i, j ,...){
            if (missing(i))
              i<-1:x$Height()
            if (missing(j))
              j<-1:x$Width()
            if (length(i)==1 && length(j)==1){
              MatrixGet(x,i-1,j-1)
            }else{
              V<-Matrix(x@datatype);
              ViewNormal(V,x,i[1]-1,tail(i,1), j[1]-1, tail(j,1))
              V
            }
          })


setMethod("[","ElDistMatrix",
          function(x, i, j ,...){
            if (length(i)==1 && length(j)==1){
              MatrixGet(x,i-1,j-1)
            }else{
              g<-Grid()
              ##DistMatrixGrid(x,g)
              V<-DistMatrix(g, x@datatype);
              ViewNormal(V,x,i[1]-1,tail(i,1), j[1]-1, tail(j,1))
              V
            }
          })



setMethod("[<-",
          signature(x = "ElMatrix"),
          function (x, i, j, ..., value) 
          {
            if (length(i)>1 && length(j)>1){
              stop("It is only possible to set single Elements")
            }
            MatrixSet(x,i-1,j-1,value)
            x
          })

setMethod("[<-",
          signature(x = "ElDistMatrix"),
          function (x, i, j, ..., value) 
          {
            if (length(i)>1 && length(j)>1){
              stop("It is only possible to set single Elements")
            }
            MatrixSet(x,i-1,j-1,value)
            x
          })

######################
### Solvers
######################

setMethod("solve",
    signature(a = "ElMatrix", b = "ElMatrix"),
    function (a, b, ...) 
    {
      x <- Matrix(b@datatype)
      Copy(b,x)
      LinearSolve(a,x)
      x
    }
)

setMethod("solve",
    signature(a = "ElMatrix"),
    function (a, b, ...) 
    {
      ans <- Matrix(a@datatype)
      Copy(a, ans)
      Inverse(ans)
      ans
    }
)

setMethod("solve",
    signature(a = "ElDistMatrix", b = "ElDistMatrix"),
    function (a, b, ...) 
    {
      x <- DistMatrix(b@datatype)
      Copy(b,x)
      LinearSolve(a,x)
      x
    }
)

setMethod("solve",
    signature(a = "ElDistMatrix"),
    function (a, b, ...) 
    {
      ans <- DistMatrix(a@datatype)
      Copy(a, ans)
      Inverse(ans)
      ans
    }
)



#################
### Other Methods
#################

setMethod("t",
          signature(x = "ElMatrix"),
          function (x){
            y <- Matrix(x@datatype)
            Transpose(x,y)
            y
          })

setMethod("t",
          signature(x = "ElDistMatrix"),
          function (x){
            y <- Matrix(x@datatype)
            Transpose(x,y)
            y
          })

### Pending: check if the matrix is symmetric,
### add the general routine for eigenvalues
setMethod("eigen",
          signature(x = "ElMatrix"),
          function (x, symmetric, only.values = FALSE, EISPACK = FALSE){
            if(missing(symmetric) || symmetric == FALSE)
              stop("Not yet implemented for general matrices, set the symmetric flag")
            tmpMat<-Matrix(x@datatype)
            Copy(x, tmpMat)
            evals<-Matrix(x@datatype)
            evecs<-Matrix(x@datatype)
            HermitianEigPair("U", tmpMat, evals, evecs)
            list(values=evals, vectors=evecs)
          })

setMethod("eigen",
          signature(x = "ElDistMatrix"),
          function (x, symmetric, only.values = FALSE, EISPACK = FALSE){
            if(missing(symmetric) || symmetric == FALSE)
              stop("Not yet implemented for general matrices, set the symmetric flag")
            tmpMat<-DistMatrix(x@datatype)
            Copy(x, tmpMat)
            evals<-DistMatrix(x@datatype)
            evecs<-DistMatrix(x@datatype)
            HermitianEigPair("U", tmpMat, evals, evecs)
            list(values=evals, vectors=evecs)
          })

setMethod("sqrt",
          signature(x = "ElMatrix"),
          function(x){
          ans<-Matrix(x@datatype)
          Copy(x, ans)
          Sqrt(ans)
          ans
          })

setMethod("sqrt",
          signature(x = "ElDistMatrix"),
          function(x){
          ans<-Matrix(x@datatype)
          Copy(x, ans)
          Sqrt(ans)
          ans
          })

setMethod("log",
          signature(x = "ElMatrix"),
          function(x){
          ans<-Matrix(x@datatype)
          Copy(x, ans)
          Log(ans)
          ans
          })

setMethod("log",
          signature(x = "ElDistMatrix"),
          function(x){
          ans<-Matrix(x@datatype)
          Copy(x, ans)
          Log(ans)
          ans
          })

setMethod("exp",
          signature(x = "ElMatrix"),
          function(x){
          ans<-Matrix(x@datatype)
          Copy(x, ans)
          Exp(ans)
          ans
          })

setMethod("exp",
          signature(x = "ElDistMatrix"),
          function(x){
          ans<-Matrix(x@datatype)
          Copy(x, ans)
          Exp(ans)
          ans
          })

setMethod("cos",
          signature(x = "ElMatrix"),
          function(x){
          ans<-Matrix(x@datatype)
          Copy(x, ans)
          Cos(ans)
          ans
          })

setMethod("cos",
          signature(x = "ElDistMatrix"),
          function(x){
          ans<-Matrix(x@datatype)
          Copy(x, ans)
          Cos(ans)
          ans
          })

setMethod("sin",
          signature(x = "ElMatrix"),
          function(x){
          ans<-Matrix(x@datatype)
          Copy(x, ans)
          Sin(ans)
          ans
          })

setMethod("sin",
          signature(x = "ElDistMatrix"),
          function(x){
          ans<-Matrix(x@datatype)
          Copy(x, ans)
          Sin(ans)
          ans
          })

setMethod("tan",
          signature(x = "ElMatrix"),
          function(x){
          ans<-Matrix(x@datatype)
          Copy(x, ans)
          Tan(ans)
          ans
          })

setMethod("tan",
          signature(x = "ElDistMatrix"),
          function(x){
          ans<-Matrix(x@datatype)
          Copy(x, ans)
          Tan(ans)
          ans
          })

setMethod("acos",
          signature(x = "ElMatrix"),
          function(x){
          ans<-Matrix(x@datatype)
          Copy(x, ans)
          Acos(ans)
          ans
          })

setMethod("acos",
          signature(x = "ElDistMatrix"),
          function(x){
          ans<-Matrix(x@datatype)
          Copy(x, ans)
          Acos(ans)
          ans
          })

setMethod("asin",
          signature(x = "ElMatrix"),
          function(x){
          ans<-Matrix(x@datatype)
          Copy(x, ans)
          Asin(ans)
          ans
          })

setMethod("asin",
          signature(x = "ElDistMatrix"),
          function(x){
          ans<-Matrix(x@datatype)
          Copy(x, ans)
          Asin(ans)
          ans
          })

setMethod("atan",
          signature(x = "ElMatrix"),
          function(x){
          ans<-Matrix(x@datatype)
          Copy(x, ans)
          Atan(ans)
          ans
          })

setMethod("atan",
          signature(x = "ElDistMatrix"),
          function(x){
          ans<-Matrix(x@datatype)
          Copy(x, ans)
          Atan(ans)
          ans
          })


#################
### I/O Functions
#################

setMethod("write.table",
    signature(x = "ElMatrix"),
    function (x, file = "", append = FALSE, quote = TRUE, sep = " ", 
        eol = "\n", na = "NA", dec = ".", row.names = TRUE, col.names = TRUE, 
        qmethod = c("escape", "double"), fileEncoding = "") 
    {
        Write(x, file, "ASCII", "")
    }
)


setMethod("write.table",
    signature(x = "ElDistMatrix"),
    function (x, file = "", append = FALSE, quote = TRUE, sep = " ", 
        eol = "\n", na = "NA", dec = ".", row.names = TRUE, col.names = TRUE, 
        qmethod = c("escape", "double"), fileEncoding = "") 
    {
        Write(x, file, "ASCII", "")
    }
)

setMethod("as.matrix",
    signature(x = "ElMatrix"),
    function (x, ...){
      ToR(x)
    })

setMethod("as.matrix",
    signature(x = "ElDistMatrix"),
    function (x, ...){
      ToR(x)
    })

################################
### Principal component analysis
################################

setMethod("cov",
    signature(x = "ElMatrix"),
    function (x, y = NULL, use = "everything", method = c("pearson", 
              "kendall", "spearman")){
      ans <- Matrix(x@datatype) 
      Covariance(x, ans)
      ans
    })

setMethod("cov",
    signature(x = "ElDistMatrix"),
    function (x, y = NULL, use = "everything", method = c("pearson", 
              "kendall", "spearman")){
      ans <- DistMatrix(x@datatype) 
      Covariance(x, ans)
      ans
    })


setMethod("princomp",
    signature(x = "ElMatrix"),
    function (x, cor = FALSE, scores = TRUE, covmat = NULL,
              subset = rep_len(TRUE, x$Width()), ...){
      if( x$Width() > x$Height() ){
        stop("Matrix must have more observations than variables")
      }
      if(cor){
        stop("Not available for correlation matrix yet")
      }
      if(is.null(covmat)){
        cv <- cov(x)
      }        
      cv <- (1 - 1/x$Height()) * cv
      ev <- eigen(cv, symmetric = TRUE)
      sdev <- sqrt(ev$values)
      cen <- Matrix(x@datatype)
      cen_mat <- Matrix(x@datatype)
      Copy(x, cen_mat)
      cen$Resize(x$Width(), 1)
      .mat_ones <- Matrix(x@datatype)
      Ones(.mat_ones, x$Height(), 1)
      Gemv("T", 1/x$Height(), x, .mat_ones, 0.0, cen)
      if (scores){
        Ger(-1.0, .mat_ones, cen, cen_mat) 
        scr<-cen_mat %*% ev$vectors
      }
      else{
        scr=NULL
      }
      list(sdev=sdev, loadings=ev$vectors, center=cen,
           scale=NULL, n.obs=x$Height(), scores=scr, call=match.call() )

    })

setMethod("princomp",
    signature(x = "ElDistMatrix"),
    function (x, cor = FALSE, scores = TRUE, covmat = NULL,
              subset = rep_len(TRUE, x$Width()), ...){
      if( x$Width() > x$Height() ){
        stop("Matrix must have more observations than variables")
      }
      if(cor){
        stop("Not available for correlation matrix yet")
      }
      if(is.null(covmat)){
        cv <- cov(x)
      }        
      cv <- (1 - 1/x$Height()) * cv
      ev <- eigen(cv, symmetric = TRUE)
      sdev <- sqrt(ev$values)
      cen <- DistMatrix(x@datatype)
      cen_mat <- DistMatrix(x@datatype)
      Copy(x, cen_mat)
      cen$Resize(x$Width(), 1)
      .mat_ones <- DistMatrix(x@datatype)
      Ones(.mat_ones, x$Height(), 1)
      Gemv("T", 1/x$Height(), x, .mat_ones, 0.0, cen)
      if (scores){
        Ger(-1.0, .mat_ones, cen, cen_mat) 
        scr<-cen_mat %*% ev$vectors
      }
      else{
        scr=NULL
      }
      list(sdev=sdev, loadings=ev$vectors, center=cen,
           scale=NULL, n.obs=x$Height(), scores=scr, call=match.call() )

    })
