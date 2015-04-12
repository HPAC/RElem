#############
### Constants
#############

MAX_SIZE_PRINT <- 10

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

##################
### Multiplication
##################

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
            if (length(i)==1 && length(j)==1){
              MatrixGet(x,i-1,j-1)
            }else{
              V<-Matrix(x@datatype);
              LockedView(V,x,i[1]-1,tail(i,1), j[1]-1, tail(j,1))
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
              LockedView(V,x,i[1]-1,tail(i,1), j[1]-1, tail(j,1))
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
