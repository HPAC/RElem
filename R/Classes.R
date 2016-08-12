###################
#Destructor Closure
###################

.ElDestroy <- function(tag, func){
  function(ptr){
    .Call(paste0(func,"_",tag),ptr)
  }
}


#' Class to represent the processes Grid
#'
#' @slot ptr A pointer to the grid (C++)
ElGrid <- setClass("ElGrid", representation(ptr="externalptr"))


setMethod("initialize",
          signature(.Object = "ElGrid"),
          function(.Object){
            if ( Initialized() ){
              .Object@ptr <- .Call("newGrid")
            }
            else{
              cat("To use grids, MPI/Elemental must be Initialized\n")
            }
            return(.Object)
          })
            

#' Class to represent an Elemental Distributed Matrix
#'
#' @slot ptr A pointer to the distributed matrix object (C++)
#' @slot datatype A character that stores the datatype

ElDistMatrix<- setClass("ElDistMatrix",
                        representation(ptr="externalptr",
                                       datatype="character"))


setMethod("initialize",
          signature(.Object = "ElDistMatrix"),
          function(.Object, tag = "d", colDist="MC", rowDist="MR", grid=new("ElGrid"), rmat=NULL){
            if( Initialized() ){
              .Object@datatype <- tag
              if(is.numeric(rmat) || is.complex(rmat)){
                if(is.matrix(rmat)){
                  He <- dim(rmat)[1]
                  Wi <- dim(rmat)[2]
                }else{
                  He <- length(rmat)
                  Wi <- as.integer(1)
                }
                if (tag == "i")
                  rmat <- as.integer(rmat)

                .Object@ptr <- .Call(paste0("toElDist_",tag), rmat, He, Wi, grid@ptr, colDist, rowDist)
              }else{

              .Object@ptr <- .Call(paste0("newDistMatrixSpecific_",tag), colDist, rowDist, grid@ptr)
              }
              reg.finalizer(.Object@ptr, .ElDestroy(tag,"destroyDistMatrix"))
            }
            else{
              cat("To use Distributed Matrices, MPI/Elemental must be Initialized\n")
            }
            return(.Object)
          })
            
#' Class to represent an Elemental Matrix
#'
#' @slot ptr A pointer to the matrix object (C++)
#' @slot datatype A character that stores the datatype

ElMatrix <- setClass("ElMatrix", representation(ptr="externalptr",
                                                datatype="character"))

setMethod("initialize",
          signature(.Object = "ElMatrix"),
          function(.Object, tag = "d", rmat=NULL){
            .Object@datatype <- tag
             if(is.numeric(rmat) || is.complex(rmat)){
              if(is.matrix(rmat)){
                He <- dim(rmat)[1]
                Wi <- dim(rmat)[2]
              }else{
                He <- length(rmat)
                Wi <- as.integer(1)
              }
              if (tag == "i")
                rmat <- as.integer(rmat)
              .Object@ptr <- .Call(paste0("toEl_",tag), rmat, He, Wi)
            }else{
              .Object@ptr <- .Call(paste0("newMatrix_",tag))
            }
            reg.finalizer(.Object@ptr, .ElDestroy(tag,"destroyMatrix"))
            return(.Object)
          })


#' Class to represent an Elemental Distributed Permutation (for pivoting)
#'
#' @slot ptr A pointer to the permutation object (C++)

ElDistPermutation <- setClass("ElDistPermutation", representation(ptr="externalptr"))

setMethod("initialize",
          signature(.Object = "ElDistPermutation"),
          function(.Object, grid = new("ElGrid")){
            if(Initialized()){
              .Object@ptr <- .Call("newDistPermutation", grid)
            }
            else{
              cat("To use Distributed Permutations, MPI/Elemental must be Initialized\n")
            }
            return(.Object)
          })  


#' Class to represent an Elemental Sequential Permutation (for pivoting)
#'
#' @slot ptr A pointer to the permutation object (C++)
ElPermutation <- setClass("ElPermutation", representation(ptr="externalptr"))

setMethod("initialize",
          signature(.Object = "ElPermutation"),
          function(.Object){
            .Object@ptr <- .Call("newPermutation")
            return(.Object)
          })

#####################
# Adding some aliases
#####################

Matrix <- ElMatrix
DistMatrix <- ElDistMatrix
Grid <- ElGrid
Permutation <- ElPermutation
DistPermutation <- ElDistPermutation

#############################################
# Auxiliary Functions to extract the datatype
#############################################

.getSuffix <- function(.Object) 0
setGeneric(".getSuffix", .getSuffix)

setMethod(".getSuffix", signature(.Object = "ElMatrix"),
          function(.Object){
            paste0("_",.Object@datatype)
          })

setMethod(".getSuffix", signature(.Object = "ElDistMatrix"),
          function(.Object){
            paste0("Dist_",.Object@datatype)
          })

setMethod(".getSuffix", signature(.Object = "ElPermutation"),
          function(.Object){
            paste0("")
          })

setMethod(".getSuffix", signature(.Object = "ElDistPermutation"),
          function(.Object){
            paste0("Dist")
          })

.getElement<-function(.Object) 0
setGeneric(".getElement", .getElement)

setMethod(".getElement", signature(.Object = "ElMatrix"),
          function(.Object){
            paste0("Matrix_",.Object@datatype)
          })

setMethod(".getElement", signature(.Object = "ElDistMatrix"),
          function(.Object){
            paste0("DistMatrix_",.Object@datatype)
          })

