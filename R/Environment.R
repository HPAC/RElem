#----------------------------
# MPI & Environment Functions
#----------------------------
Initialized<-function(){
  .Call("initialized")
}

##' Initialize
##'
##' Initializes MPI allowing the use of Distributed Matrices
##'
##' @return None
##'
##' @examples
##' Initialize()
##' A<-DistMatrix()
##' Uniform(A,2,2)
##' Print(A)
##' Finalize()

Initialize<-function(){
  .Call("initialize")
}

##' Finalize
##'
##' Finalizes MPI
##'
##' This function must be called at the end of the script (at least at the end
##' of the distributed part).
##'
##' @return None
Finalize<-function(){
  if( Initialized() )
    .Call("finalize")
}

#' MPI Wold Rank
#'
#' Returns the MPI Rank ammong the different processors
#'
#' @return an integer with the rank
#'
WorldRank<-function(){
  .Call("getWorldRank")
}

#' MPI Wold Size
#'
#' Returns the number of MPI processes involved in the computation
#'
#' @return an integer with the number of processors
#'
WorldSize<-function(){
  .Call("getWorldSize")
}

#' MPI Wall time
#'
#' Returns the MPI Walltime in double precision
#'
#' @return a double precision scalar with the time in seconds.
#'
WTime<-function(){
  .Call("wTime")
}

#' MPI Barrier
#'
#' Creates a barrier, waiting that all the processes reach the same point in
#' the program.
#'
#' @return None
#'
WorldBarrier<-function(){
  .Call("worldBarrier")
}

#' Print Elemental Version
#'
#' Prints Elemental's version, including Git Revision.
#'
#' @return None
#'
PrintVersion <-function(){
  .Call("printVersion")
}

#' Print Elemental Configuration
#'
#' Prints Elemental's build information.
#'
#' @return None
#'
PrintConfig <-function(){
  .Call("printConfig")
}

#' Print Elemental Compiler Information (cc)
#'
#' Prints details about the C Compiler used in Elemental build.
#'
#' @return None
#'
PrintCCompilerInfo <-function(){
  .Call("printCCompilerInfo")
}

#' Print Elemental Compiler Information (cxx)
#'
#' Prints details about the C++ Compiler used in Elemental build.
#'
#' @return None
#'
PrintCxxCompilerInfo <-function(){
  .Call("printCxxCompilerInfo")
}

#' MPI Communicator 
#'
#' Returns the MPI communicator for the process
#'
#' @return a external pointer with the MPI communicator
MPIComm<-function(){
  .Call("newMPIComm")
}

#' Perform a reduction 
#'
#'
#' @param var the variable to reduce (input, output)
#' @param count the number of elements to reduce, for arrays
#'  it can be greater than 1 (input)
#' @param datatype the datatype involved on the reduction,
#'  either "INTEGER" or "DOUBLE"
#' @param op the reduction operation, possible values "MAX", "MIN" or "SUM"
#' @param comm the MPI communicator involved in the reduction. By default,
#'   MPI World
#'
#' @return None
#'
AllReduce<-function(var, count, datatype, op, comm = MPIComm()){
  if (datatype=="INTEGER"){
    .Call("allReduce", as.integer(var), as.integer(count), datatype, op, comm)
  }else{
    .Call("allReduce", var, as.integer(count), datatype, op, comm)
  }
}
