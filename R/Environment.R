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
Finalize<-function(){
  if( Initialized() )
    .Call("finalize")
}

WorldRank<-function(){
  .Call("getWorldRank")
}
WorldSize<-function(){
  .Call("getWorldSize")
}
WTime<-function(){
  .Call("wTime")
}
WorldBarrier<-function(){
  .Call("worldBarrier")
}

PrintVersion <-function(){
  .Call("printVersion")
}

PrintConfig <-function(){
  .Call("printConfig")
}

PrintCCompilerInfo <-function(){
  .Call("printCCompilerInfo")
}

PrintCxxCompilerInfo <-function(){
  .Call("printCxxCompilerInfo")
}

MPIComm<-function(){
  .Call("newMPIComm")
}

AllReduce<-function(var, count, datatype, op, comm){
  if (datatype=="INTEGER"){
    .Call("allReduce", as.integer(var), as.integer(count), datatype, op, comm)
  }else{
    .Call("allReduce", var, as.integer(count), datatype, op, comm)
  }
}
