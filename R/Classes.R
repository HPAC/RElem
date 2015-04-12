###################
#Destructor Closure
###################

.ElDestroy <- function(tag, func){
  function(ptr){
    .Call(paste0(func,"_",tag),ptr)
  }
}

#possibleDatatypes = c('d','z','i')
#
#validMatrix <- function(object){
#  errors <- character()
#  if ( is.na(match(object@datatype, possibleDatatypes)))
#    errors <- c(errors,paste("Unknown datatype:",object@datatype))
#  if ( !object@active )
#    errors <- c(errors,paste("Not initialized"))
#  if (length(errors)==0){
#    TRUE
#  }
#  else{
#    errors
#  }
#}


#' Class to represent the Grid
#'
#' @slot ptr A pointer to the grid (C++)
#' @slot active a boolean value that indicates whether the grid is
#'       still alive or not.
ElGrid <- setClass("ElGrid", representation(ptr="externalptr",
                                            active="logical"))

setMethod("initialize",
          signature(.Object = "ElGrid"),
          function(.Object){
            if ( Initialized() ){
              .Object@ptr <- .Call("newGrid")
              .Object@active <- TRUE
            }
            else{
              cat("To use grids, MPI/Elemental must be Initialized\n")
              .Object@active <- FALSE
            }
            return(.Object)
          })
            

#' Class to represent an elemental Dist Matrix
#'
#' @slot ptr A pointer to the distributed matrix object (C++)
#' @slot datatype A character that stores the datatype
#' @slot active a boolean value that indicates whether the grid is
#'       still alive or not.
ElDistMatrix<- setClass("ElDistMatrix",
                        representation(ptr="externalptr",
                                       active="logical",
                                       datatype="character"))


setMethod("initialize",
          signature(.Object = "ElDistMatrix"),
          function(.Object, tag = "d", colDist="MC", rowDist="MR", grid=new("ElGrid"), rmat=NULL){
            if( Initialized() ){
              .Object@datatype <- tag
              .Object@active <- TRUE
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
              .Object@active <- FALSE
            }
            return(.Object)
          })
            
#' Class to represent an Elemental Matrix
#'
#' @slot ptr A pointer to the matrix object (C++)
#' @slot datatype A character that stores the datatype
#' @slot active a boolean value that indicates whether the grid is
#'       still alive or not.

ElMatrix <- setClass("ElMatrix", representation(ptr="externalptr",
                                                active="logical",
                                                datatype="character"))

setMethod("initialize",
          signature(.Object = "ElMatrix"),
          function(.Object, tag = "d", rmat=NULL){
            .Object@datatype <- tag
            .Object@active <- TRUE
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


#####################
# Adding some aliases
#####################

Matrix <- ElMatrix
DistMatrix <- ElDistMatrix
Grid <- ElGrid


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

