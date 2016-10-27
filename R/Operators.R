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
            matA <- DistMatrix(e1@datatype)
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
            matA <- DistMatrix(e1@datatype)
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
            matC <- DistMatrix(x@datatype)
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
            matC <- DistMatrix(e1@datatype)
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

setGeneric("print")

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
            if (missing(i))
              i<-1:x$Height()
            if (missing(j))
              j<-1:x$Width()
            if (length(i)==1 && length(j)==1){
              MatrixGet(x,i-1,j-1)
            }else{
              g<-Grid()
              DistMatrixGrid(x,g)
              V<-DistMatrix(grid=g, tag=x@datatype);
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
### Matrix Properties
######################

setMethod("dim",
    signature(x = "ElMatrix"),
    function (x) 
    {
	c(x$Height(), x$Width())
    }
)

setMethod("dim",
    signature(x = "ElDistMatrix"),
    function (x) 
    {
	c(x$Height(), x$Width())
    }
)

setMethod("dim<-",
    signature(x = "ElMatrix"),
    function (x, value) 
    {
	x$Resize(value[1],value[2])
    }
)

setMethod("dim<-",
    signature(x = "ElDistMatrix"),
    function (x, value) 
    {
	x$Resize(value[1],value[2])
    }
)

######################
### Solvers
######################

setGeneric("solve")

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

setGeneric("t")

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

setGeneric("eigen")

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
          ans <- Matrix(x@datatype)
          Copy(x, ans)
          Sqrt(ans)
          ans
          })

setMethod("sqrt",
          signature(x = "ElDistMatrix"),
          function(x){
          ans <- DistMatrix(x@datatype)
          Copy(x, ans)
          Sqrt(ans)
          ans
          })

setMethod("log",
          signature(x = "ElMatrix"),
          function(x){
          ans <- Matrix(x@datatype)
          Copy(x, ans)
          Log(ans)
          ans
          })

setMethod("log",
          signature(x = "ElDistMatrix"),
          function(x){
          ans <- DistMatrix(x@datatype)
          Copy(x, ans)
          Log(ans)
          ans
          })

setMethod("exp",
          signature(x = "ElMatrix"),
          function(x){
          ans <- Matrix(x@datatype)
          Copy(x, ans)
          Exp(ans)
          ans
          })

setMethod("exp",
          signature(x = "ElDistMatrix"),
          function(x){
          ans <- DistMatrix(x@datatype)
          Copy(x, ans)
          Exp(ans)
          ans
          })

setMethod("cos",
          signature(x = "ElMatrix"),
          function(x){
          ans <- Matrix(x@datatype)
          Copy(x, ans)
          Cos(ans)
          ans
          })

setMethod("cos",
          signature(x = "ElDistMatrix"),
          function(x){
          ans <- DistMatrix(x@datatype)
          Copy(x, ans)
          Cos(ans)
          ans
          })

setMethod("sin",
          signature(x = "ElMatrix"),
          function(x){
          ans <- Matrix(x@datatype)
          Copy(x, ans)
          Sin(ans)
          ans
          })

setMethod("sin",
          signature(x = "ElDistMatrix"),
          function(x){
          ans <- DistMatrix(x@datatype)
          Copy(x, ans)
          Sin(ans)
          ans
          })

setMethod("tan",
          signature(x = "ElMatrix"),
          function(x){
          ans <- Matrix(x@datatype)
          Copy(x, ans)
          Tan(ans)
          ans
          })

setMethod("tan",
          signature(x = "ElDistMatrix"),
          function(x){
          ans <- DistMatrix(x@datatype)
          Copy(x, ans)
          Tan(ans)
          ans
          })

setMethod("acos",
          signature(x = "ElMatrix"),
          function(x){
          ans <- Matrix(x@datatype)
          Copy(x, ans)
          Acos(ans)
          ans
          })

setMethod("acos",
          signature(x = "ElDistMatrix"),
          function(x){
          ans <- DistMatrix(x@datatype)
          Copy(x, ans)
          Acos(ans)
          ans
          })

setMethod("asin",
          signature(x = "ElMatrix"),
          function(x){
          ans <- Matrix(x@datatype)
          Copy(x, ans)
          Asin(ans)
          ans
          })

setMethod("asin",
          signature(x = "ElDistMatrix"),
          function(x){
          ans <- DistMatrix(x@datatype)
          Copy(x, ans)
          Asin(ans)
          ans
          })

setMethod("atan",
          signature(x = "ElMatrix"),
          function(x){
          ans <- Matrix(x@datatype)
          Copy(x, ans)
          Atan(ans)
          ans
          })

setMethod("atan",
          signature(x = "ElDistMatrix"),
          function(x){
          ans <- DistMatrix(x@datatype)
          Copy(x, ans)
          Atan(ans)
          ans
          })


#################
### I/O Functions
#################

setGeneric("write.table")

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

#################
# Transformations
#################

setGeneric("as.matrix")

setMethod("as.matrix",
    signature(x = "ElMatrix"),
    function (x, ...){
      ToR(x)
    })

setMethod("as.matrix",
    signature(x = "ElDistMatrix"),
    function (x, ...){
      M<-Matrix()
      DistMatrixToMatrix(x,M)
      ToR(M)
    })

################################
### Principal component analysis
################################

## Aux functions

setGeneric("cov")

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

setGeneric("scale")

setMethod("scale",
    signature(x = "ElMatrix"),
    function (x, center = TRUE, scale = TRUE) {
      .mat_ones <- Matrix(x@datatype)  # Creating aux matrix
      Ones(.mat_ones, x$Height(), 1)
      cen_mat <- Matrix(x@datatype)
      Copy(x, cen_mat)

      if (is.logical(center)){
        cen <- Matrix(x@datatype)  # Stores the Mean of every column
        if (center == TRUE){
          cen$Resize(x$Width(), 1)
          Gemv("T", 1/x$Height(), x, .mat_ones, 0.0, cen)
        } else {
          cen <- NULL
        }
      } else {
        if(class(center) == "ElMatrix") {
          if( center$Width() == 1 && center$Height() == x$Width()){
            cen = center
          } else {
            cen <- NULL
            stop("center must be column vector, with lenght equal to the columns of 'x'")
          }
        } else {
          cen <- NULL
          stop("center must be a logical value or ElMatrix")
        }
      }
      if (!is.null(cen)) {
        Ger(-1.0, .mat_ones, cen, cen_mat)
        attr(cen_mat, "scaled:center") <- cen
      }
      
      if(is.logical(scale)) {
        if(scale) {
          sq_mat <- cen_mat * cen_mat
          factors <- Matrix(x@datatype)
          factors$Resize(x$Width(), 1)
          Gemv("T", 1/(x$Height()-1), sq_mat, .mat_ones, 0.0, factors)
          factors <- sqrt(factors)
        } else {
          factors <- NULL
        }
      } else {
        if(class(scale) == "ElMatrix") {
          if( scale$Width() == 1 && scale$Height() == x$Width()){
            factors = scale
          } else {
            factors <- NULL
            stop("scale must be column vector, with lenght equal to the columns of 'x'")
          }
        } else {
          factors <- NULL
          stop("scale must be a logical value or ElMatrix")
        }
      }
      if (!is.null(factors)) {
        tmp <- Matrix(x@datatype)  # Matrix View
        for ( i in 1:x$Width() ) {
          ViewNormal(tmp, cen_mat, 0, x$Height(), i-1, i)
          Scale(1/factors[i,1], tmp)
        }
      attr(cen_mat, "scaled:scale") <- factors
      }
      cen_mat
    }
)

setMethod("scale",
    signature(x = "ElDistMatrix"),
    function (x, center = TRUE, scale = TRUE) {
      .mat_ones <- DistMatrix(x@datatype)  # Creating aux matrix
      Ones(.mat_ones, x$Height(), 1)
      cen_mat <- DistMatrix(x@datatype)
      Copy(x, cen_mat)

      if (is.logical(center)) {
        cen <- DistMatrix(x@datatype)  # Stores the Mean of every column
        if (center == TRUE){
          cen$Resize(x$Width(), 1)
          Gemv("T", 1/x$Height(), x, .mat_ones, 0.0, cen)
        } else {
          cen <- NULL
        }
      } else {
        if(class(center) == "ElDistMatrix") {
          if( center$Width() == 1 && center$Height() == x$Width()){
            cen = center
          } else {
            cen <- NULL
            stop("center must be column vector, with lenght equal to the columns of 'x'")
          }
        } else {
          cen <- NULL
          stop("center must be a logical value or ElDistMatrix")
        }
      }
      if (!is.null(cen)){
        Ger(-1.0, .mat_ones, cen, cen_mat)
        attr(cen_mat, "scaled:center") <- cen
      }
      
      if (is.logical(scale)) {
        if (scale) {
          sq_mat <- cen_mat * cen_mat
          factors <- DistMatrix(x@datatype)
          factors$Resize(x$Width(), 1)
          Gemv("T", 1/(x$Height()-1), sq_mat, .mat_ones, 0.0, factors)
          factors <- sqrt(factors)
        } else {
          factors <- NULL
        }
      } else {
        if (class(scale) == "ElDistMatrix") {
          if ( scale$Width() == 1 && scale$Height() == x$Width()) {
            factors = scale
          } else {
            factors <- NULL
            stop("scale must be column vector, with lenght equal to the columns of 'x'")
          }
        } else {
          factors <- NULL
          stop("scale must be a logical value or ElDistMatrix")
        }
      }
      if (!is.null(factors)){
        tmp <- DistMatrix(x@datatype)  # Matrix View
        for ( i in 1:x$Width() ) {
          ViewNormal(tmp, cen_mat, 0, x$Height(), i-1, i)
          Scale(1/factors[i,1], tmp)
        }
      attr(cen_mat, "scaled:scale") <- factors
      }
      cen_mat
    }
)

#### Cov matrix Method

setGeneric("princomp")

setMethod("princomp",
    signature(x = "ElMatrix"),
    function (x, cor = FALSE, scores = TRUE, covmat = NULL,
              subset = rep_len(TRUE, x$Width()), rformat=FALSE, ...){
      cl <- match.call()
      cl[[1L]] <- as.name("princomp")

      if ( x$Width() > x$Height() )
        stop("Matrix must have more observations than variables")
      
      if (cor)
        stop("Not available for correlation matrix yet")

      sc <- Matrix(x@datatype)
      Ones(sc, x$Width(), 1)
      
      if (is.null(covmat)) {
        cv <- cov(x)
      } else {
        if ( class(covmat) == "ElMatrix") {
          cv<-covmat
        } else {
          stop("error, expecting an Elemental covariance matrix")
        }
      }        
      
      cv <- (1 - 1/x$Height()) * cv
      ev <- eigen(cv, symmetric = TRUE)

      
      if (!is.null(covmat)){
        min_evalue <- Min(ev$values)
        if ( min_evalue$value < - 9 * .Machine$double.ev * ev$values[1] )
          stop("covariance matrix is not negative definite")
      }
      
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
      if (rformat){
          cn <- paste0("Comp.", 1L:cv$Width())
          sdev <- as.numeric(as.matrix(sdev))
          sc <- as.numeric(as.matrix(sc))
          scr <- as.matrix(scr)
          names(sdev) <- cn
          cen <- as.numeric(as.matrix(cen))
          vectors <- as.matrix(ev$vectors)
          dimnames(vectors) <- list(dimnames(vectors)[[1L]], cn)
          list(sdev=sdev, loadings=structure(vectors, class="loadings"),
            center=cen, scale=sc, n.obs=x$Height(), scores=scr,
            call=cl )
      } else {
        list(sdev=sdev, loadings=ev$vectors,
             center=cen, scale=sc, n.obs=x$Height(), scores=scr,
             call=cl )
      }

    })

setMethod("princomp",
    signature(x = "ElDistMatrix"),
    function (x, cor = FALSE, scores = TRUE, covmat = NULL,
              subset = rep_len(TRUE, x$Width()), rformat=FALSE, ...){
      cl <- match.call()
      cl[[1L]] <- as.name("princomp")

      if( x$Width() > x$Height() )
        stop("Matrix must have more observations than variables")
      
      if(cor)
        stop("Not available for correlation matrix yet")

      sc <- DistMatrix(x@datatype)
      Ones(sc, x$Width(), 1)
      
      if (is.null(covmat)) {
        cv <- cov(x)
      } else {
        if ( class(covmat) == "ElDistMatrix")
          cv<-covmat
        else
          stop("error, expecting an Elemental covariance matrix")
      }        
      
      cv <- (1 - 1/x$Height()) * cv
      ev <- eigen(cv, symmetric = TRUE)

      
      if (!is.null(covmat)){
        min_evalue <- Min(ev$values)
        if ( min_evalue$value < - 9 * .Machine$double.ev * ev$values[1] )
          stop("covariance matrix is not negative definite")
      }
      
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
      } else {
        scr=NULL
      }
      if (rformat){
          cn <- paste0("Comp.", 1L:cv$Width())
          sdev <- as.numeric(as.matrix(sdev))
          sc <- as.numeric(as.matrix(sc))
          scr <- as.matrix(scr)
          names(sdev) <- cn
          cen <- as.numeric(as.matrix(cen))
          vectors <- as.matrix(ev$vectors)
          dimnames(vectors) <- list(dimnames(vectors)[[1L]], cn)
          list(sdev=sdev, loadings=structure(vectors, class="loadings"),
            center=cen, scale=sc, n.obs=x$Height(), scores=scr,
            call=cl )
      }
      else{
        list(sdev=sdev, loadings=ev$vectors,
             center=cen, scale=sc, n.obs=x$Height(), scores=scr,
             call=cl )
      }

    })

######### SVD Method
setGeneric("svd")

setMethod("svd",
    signature(x = "ElMatrix"),
    function (x, nu = min(x$Height(), x$Width()),
              nv = min(x$Height(), x$Width()),
              LINPACK = FALSE){
      n <- x$Height()
      p <- x$Width()
      if (nu > min(n,p) || nv > min(n,p))
        stop("Only thin svd is implemented, please change the values of nu / nv")
      U <- Matrix(x@datatype)
      s <- Matrix(x@datatype)
      V <- Matrix(x@datatype)
      SVD(x, U, s, V)      
      ans <- list (d = s)
      if (nv)
        ans$v <- V
      if (nu)
        ans$u <- U
      ans
    }
)

setMethod("svd",
    signature(x = "ElDistMatrix"),
    function (x, nu = min(x$Height(), x$Width()), 
              nv = min(x$Height(), x$Width()),
              LINPACK = FALSE){
      n <- x$Height()
      p <- x$Width()
      if (nu > min(n,p) || nv > min(n,p))
        stop("Only thin svd is implemented, please change the values of nu / nv")
      U <- DistMatrix(x@datatype)
      s <- DistMatrix(x@datatype)
      V <- DistMatrix(x@datatype)
      SVD(x, U, s, V)      
      ans <- list (d = s)
      if (nv)
        ans$v <- V
      if (nu)
        ans$u <- U
      ans
    }
)


setGeneric("prcomp")

setMethod("prcomp",
    signature(x = "ElMatrix"),
    function (x, retx = TRUE, center = TRUE, scale. = FALSE, tol = NULL, rformat=FALSE, ...) {
      if (!is.null(tol))
        stop("tol arg not implemented")
      cen_mat <- scale(x, center, scale.)
      cen <- attr(cen_mat, "scaled:center")
      s <- svd(cen_mat, nu=0)
      s$d <- (1/sqrt(x$Height()-1)) * s$d
      if (rformat) {
        s$d <- as.numeric(as.matrix(s$d))
        s$v <- as.matrix(t(s$v))
        cen <- as.numeric(as.matrix(cen))
        dimnames(s$v) <- list( dimnames(s$v)[[1L]], paste0("PC", seq_len(ncol(s$v))))
        ans <- list( sdev = s$d, rotation = s$v, center = cen)
        class(ans) <- "prcomp"
      } else {
        ans <- list( sdev = s$d, rotation = s$v, center = cen)
      }
      ans
    }
)

setMethod("prcomp",
    signature(x = "ElDistMatrix"),
    function (x, retx = TRUE, center = TRUE, scale. = FALSE, tol = NULL, rformat=FALSE, ...) {
      if (!is.null(tol))
        stop("tol arg not implemented")
      cen_mat <- scale(x, center, scale.)
      cen <- attr(cen_mat, "scaled:center")
      s <- svd(cen_mat, nu=0)
      s$d <- (1/sqrt(x$Height()-1)) * s$d
      if (rformat) {
        s$d <- as.numeric(as.matrix(s$d))
        s$v <- as.matrix(t(s$v))
        cen <- as.numeric(as.matrix(cen))
        dimnames(s$v) <- list( dimnames(s$v)[[1L]], paste0("PC", seq_len(ncol(s$v))))
        ans <- list( sdev = s$d, rotation = s$v, center = cen)
        class(ans) <- "prcomp"
      } else {
        ans <- list( sdev = s$d, rotation = s$v, center = cen)
      }
      ans
    }
)

#setGeneric("prcomp2")

#setMethod("prcomp2",
#    signature(x = "ElDistMatrix"),
#    function(x){
#      sdev <-DistMatrix()
                  
          
          