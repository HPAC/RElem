#################
### Aux functions
#################

.isDistMatrix<-function(MatrixA){
  parts<-strsplit(class(MatrixA),"_")
  ifelse (parts[[1]][1]=="ElDistMatrix",TRUE,FALSE)
}

#########
### Grids
#########


GridRow<-function(Grid){
  .Call("gridRow", Grid@ptr)
}

GridCol<-function(Grid){
  .Call("gridCol", Grid@ptr)
}

GridRank<-function(Grid){
  .Call("gridRank", Grid@ptr)
}

GridHeight<-function(Grid){
  .Call("gridHeight", Grid@ptr)
}

GridWidth<-function(Grid){
  .Call("gridWidth", Grid@ptr)
}

GridSize<-function(Grid){
  .Call("gridSize", Grid@ptr)
}

GridMCRank<-function(Grid){
  .Call("gridMCRank", Grid@ptr)
}

GridMRRank<-function(Grid){
  .Call("gridMRRank", Grid@ptr)
}

GridVCRank<-function(Grid){
  .Call("gridVCRank", Grid@ptr)
}

GridVRRank<-function(Grid){
  .Call("gridVRRank", Grid@ptr)
}

GridMCSize<-function(Grid){
  .Call("gridMCSize", Grid@ptr)
}

GridMRSize<-function(Grid){
  .Call("gridMRSize", Grid@ptr)
}

GridVCSize<-function(Grid){
  .Call("gridVCSize", Grid@ptr)
}

GridVRSize<-function(Grid){
  .Call("gridVRSize", Grid@ptr)
}

GridGCD<-function(Grid){
  .Call("gridGCD", Grid@ptr)
}

GridLCM<-function(Grid){
  .Call("gridLCM", Grid@ptr)
}

GridInGrid<-function(Grid){
  .Call("gridInGrid", Grid@ptr)
}

GridHaveViewers<-function(Grid){
  .Call("gridHaveViewers", Grid@ptr)
}

GridOwningRank<-function(Grid){
  .Call("gridOwningRank", Grid@ptr)
}

GridViewingRank<-function(Grid){
  .Call("gridViewingRank", Grid@ptr)
}

GridVCToViewing<-function(Grid, VCRank){
  .Call("gridVCToViewing", Grid@ptr, as.integer(VCRank))
}

GridDiag<-function(Grid, VCRank){
  .Call("gridDiag", Grid@ptr, as.integer(VCRank))
}

GridDiagRank<-function(Grid, VCRank){
  .Call("gridDiagRank", Grid@ptr, as.integer(VCRank))
}

GridFindFactor<-function( procs ){
  .Call("gridFindFactor", as.integer(procs))
}





#######################
### Sequential Matrices
#######################


MatrixAttach<-function(MatrixA, height, width, buffer, ldim){
  .Call( paste0("attach", .getElement(MatrixA)), MatrixA@ptr, as.integer(height),
         as.integer(width), buffer, as.integer(ldim) )
}

MatrixLockedAttach<-function(MatrixA, height, width, buffer, ldim){
  .Call( paste0("lockedAttach", .getElement(MatrixA)), MatrixA@ptr,
         as.integer(height), as.integer(width), buffer, as.integer(ldim) )
}



########################
### Distributed Matrices
########################


#TODO: think in a better way to use this function
ShowDistData<-function(DistMatrixA){
  .Call( paste0("showDistData_", DistMatrixA@datatype), DistMatrixA@ptr)
}

DistMatrixDistComm<-function(DistMatrixA, Comm){
  .Call( paste0("distCommDistMatrix_", DistMatrixA@datatype), DistMatrixA@ptr,
         Comm)
}

DistMatrixSetGrid<-function(DistMatrixA, GridG){
  .Call( paste0("setGridDistMatrix_", DistMatrixA@datatype), DistMatrixA@ptr,
         GridG@ptr )
}

DistMatrixGrid<-function(DistMatrixA, GridG){
  .Call( paste0("gridDistMatrix_", DistMatrixA@datatype), DistMatrixA@ptr,
         GridG@ptr )
}


DistMatrixSetRoot<-function(DistMatrixA, Root, constrain){
  .Call( paste0("setRootDistMatrix_", DistMatrixA@datatype), DistMatrixA@ptr,
         as.integer(Root), as.logical(constrain) )
}

DistMatrixAttach<-function(DistMatrixA, heigth, width, grid, colAlign, rowAlign,
                           buffer, ldim, root){
  .Call( paste0("attachDistMatrix_", DistMatrixA@datatype), DistMatrixA@ptr,
         heigth, width, grid@ptr, colAlign, rowAlign, buffer, ldim, root )
}

DistMatrixLockedAttach<-function(DistMatrixA, heigth, width, grid, colAlign,
                                 rowAlign, buffer, ldim, root){
  .Call( paste0("lockedAttachDistMatrix_", DistMatrixA@datatype), DistMatrixA@ptr,
         heigth, width, grid@ptr, colAlign, rowAlign, buffer, ldim, root )
}

DistMatrixToMatrix<-function(DistMatrixA, MatrixA){
  .Call( paste0("matrixDistMatrix_", DistMatrixA@datatype), DistMatrixA@ptr,
         MatrixA@ptr )
}

DistMatrixToLockedMatrix<-function(DistMatrixA, MatrixA){
  .Call( paste0("lockedMatrixDistMatrix_", DistMatrixA@datatype), DistMatrixA@ptr,
         MatrixA@ptr )
}

DistMatrixLocalHeight<-function(DistMatrixA){
  .Call( paste0("localHeightDistMatrix_", DistMatrixA@datatype),
         DistMatrixA@ptr );
}

DistMatrixLocalWidth<-function(DistMatrixA){
  .Call( paste0("localWidthDistMatrix_", DistMatrixA@datatype),
         DistMatrixA@ptr );
}

DistMatrixGetLocal<-function(DistMatrixA, i, j){
  .Call( paste0("getLocalDistMatrix_", DistMatrixA@datatype), DistMatrixA@ptr,
         as.integer(i), as.integer(j) )
} 

DistMatrixSetLocal<-function(DistMatrixA, i, j, alpha){
  .Call( paste0("setLocalDistMatrix_", DistMatrixA@datatype), DistMatrixA@ptr,
         as.integer(i), as.integer(j), as.double(alpha) )
} 


###-------------------------
### Common Matrix Properties
###-------------------------

MatrixDestroy<-function(MatrixA){
  .Call( paste0("destroy", .getElement(MatrixA) ), MatrixA@ptr )
}


MatrixGet<-function(MatrixA, i, j){
  .Call( paste0("get", .getElement(MatrixA)), MatrixA@ptr,
         as.integer(i),as.integer(j) )
} 

MatrixSet<-function(MatrixA, i, j, alpha){
  .Call( paste0("set", .getElement(MatrixA)), MatrixA@ptr,
         as.integer(i),as.integer(j),as.double(alpha) )
} 

MatrixUpdate<-function(MatrixA, i, j, alpha){
  .Call( paste0("update", .getElement(MatrixA)), MatrixA@ptr,
         as.integer(i),as.integer(j),as.double(alpha) )
} 

MatrixHeight<-function(MatrixA){
  .Call( paste0("height", .getElement(MatrixA)), MatrixA@ptr )
}

MatrixWidth<-function(MatrixA){
  .Call( paste0("width", .getElement(MatrixA)), MatrixA@ptr )
}

MatrixLDim<-function(MatrixA){
  .Call( paste0("ldim", .getElement(MatrixA)), MatrixA@ptr )
}


MatrixEmpty<-function(MatrixA, freeMem = true){
  .Call( paste0("empty", .getElement(MatrixA)), MatrixA@ptr, as.logical(freeMem) )
}

MatrixResize<-function(MatrixA, height, width){
  .Call( paste0("resize", .getElement(MatrixA)), MatrixA@ptr, as.integer(height),
         as.integer(width) )
}

MatrixResizeLDim<-function(MatrixA, height, width, ldim){
  .Call( paste0("resize", .getElement(MatrixA)), MatrixA@ptr, as.integer(height),
         as.integer(width), as.integer(ldim) )
}

MatrixDiagonalLength<-function(MatrixA){
  .Call( paste0("diagonalLength", .getElement(MatrixA)), MatrixA@ptr )
}

MatrixViewing<-function(MAtrixA){
  .Call( paste0("viewing", .getElement(MatrixA)), MatrixA@ptr )
}

MatrixLocked<-function(MAtrixA){
  .Call( paste0("locked", .getElement(MatrixA)), MatrixA@ptr )
}


#attach and locked attach are different



################
### Matrix Views
################

#A is a view of B
ViewNormal<-function(MatrixA, MatrixB, fromi, toi, fromj, toj){
  .Call( paste0("view", .getSuffix(MatrixA)), MatrixA@ptr, MatrixB@ptr,
         as.integer(fromi), as.integer(toi),
         as.integer(fromj), as.integer(toj) )
}

LockedView<-function(MatrixA, MatrixB, fromi, toi, fromj, toj){
  .Call( paste0("lockedView", .getSuffix(MatrixA)), MatrixA@ptr, MatrixB@ptr,
         as.integer(fromi), as.integer(toi),
         as.integer(fromj), as.integer(toj) )
}

ViewOffset<-function(MatrixA, MatrixB, i, j, height, width){
  .Call( paste0("viewOffset", .getSuffix(MatrixA)), MatrixA@ptr, MatrixB@ptr,
         as.integer(i), as.integer(j), as.integer(height), as.integer(width) )
}

LockedViewOffset<-function(MatrixA, MatrixB, i, j, height, width){
  .Call( paste0("lockedViewOffset", .getSuffix(MatrixA)), MatrixA@ptr, MatrixB@ptr,
         as.integer(i), as.integer(j), as.integer(height), as.integer(width) )
}

ViewFull<-function(MatrixA, MatrixB){
  .Call( paste0("viewFull", .getSuffix(MatrixA)), MatrixA@ptr, MatrixB@ptr )
}

LockedViewFull<-function(MatrixA, MatrixB){
  .Call( paste0("lockedViewFull", .getSuffix(MatrixA)), MatrixA@ptr, MatrixB@ptr )
}



##############
### Partitions
##############

PartitionDown<-function(MatrixA, MatrixAT, MatrixAB, heightAT){
  .Call( paste0("partitionDown", .getSuffix(MatrixA)), MatrixA@ptr, MatrixAT@ptr,
         MatrixAB@ptr, as.integer(heightAT) )
}

LockedPartitionDown<-function(MatrixA, MatrixAT, MatrixAB, heightAT){
  .Call( paste0("lockedPartitionDown", .getSuffix(MatrixA)), MatrixA@ptr,
         MatrixAT@ptr, MatrixAB@ptr, as.integer(heightAT) )
}

PartitionUp<-function(MatrixA, MatrixAT, MatrixAB, heightAT){
  .Call( paste0("partitionUp", .getSuffix(MatrixA)), MatrixA@ptr, MatrixAT@ptr,
         MatrixAB@ptr, as.integer(heightAB) )
}

LockedPartitionUp<-function(MatrixA, MatrixAT, MatrixAB, heightAT){
  .Call( paste0("lockedPartitionUp", .getSuffix(MatrixA)), Matrix@ptr,
         MatrixAT@ptr, MatrixAB@ptr, as.integer(heightAB) )
}

PartitionLeft<-function(MatrixA, MatrixAL, MatrixAR, widthAR){
  .Call( paste0("partitionLeft", .getSuffix(MatrixA)), MatrixA@ptr, MatrixAL@ptr,
         MatrixAR@ptr, as.integer(widthAR) )
}

LockedPartitionLeft<-function(MatrixA, MatrixAL, MatrixAR, widthAR){
  .Call( paste0("lockedPartitionLeft", .getSuffix(MatrixA)), MatrixA@ptr,
         MatrixAL@ptr, MatrixAR@ptr, as.integer(widthAR) )
}

PartitionRight<-function(MatrixA, MatrixAL, MatrixAR, widthAL){
  .Call( paste0("partitionRight", .getSuffix(MatrixA)), MatrixA@ptr, MatrixAL@ptr,
         MatrixAR@ptr, as.integer(widthAL) )
}

LockedPartitionRight<-function(MatrixA, MatrixAL, MatrixAR, widthAL){
  .Call( paste0("lockedPartitionRight", .getSuffix(MatrixA)), MatrixA@ptr,
         MatrixAL@ptr, MatrixAR@ptr, as.integer(widthAL) )
}

PartitionDownDiagonal<-function( MatrixA, MatrixATL, MatrixATR,
                                 MatrixABL, MatrixABR, diagDist ){
  .Call( paste0("partitionDownDiagonal", .getSuffix(MatrixA)), MatrixA@ptr,
         MatrixATL@ptr, MatrixATR@ptr, MatrixABL@ptr, MatrixABR@ptr,
         as.integer(diagDist) )
}

LockedPartitionDownDiagonal<-function( MatrixA, MatrixATL, MatrixATR,
                                       MatrixABL, MatrixABR, diagDist ){
  .Call( paste0("lockedPartitionDownDiagonal", .getSuffix(MatrixA)), MatrixA@ptr,
         MatrixATL@ptr, MatrixATR@ptr, MatrixABL@ptr, MatrixABR@ptr,
         as.integer(diagDist) )
}

PartitionDownOffsetDiagonal<-function( offset,
                                       MatrixA, MatrixATL, MatrixATR,
                                       MatrixABL, MatrixABR, diagDist ){
  .Call( paste0("partitionDownOffsetDiagonal", .getSuffix(MatrixA)), offset,
         MatrixA@ptr, MatrixATL@ptr, MatrixATR@ptr, MatrixABL@ptr,
         MatrixABR@ptr, as.integer(diagDist) )
}

LockedPartitionDownOffsetDiagonal<-function( offset,
                                             MatrixA, MatrixATL, MatrixATR,
                                             MatrixABL, MatrixABR, diagDist ){
  .Call( paste0("lockedPartitionDownOffsetDiagonal", .getSuffix(MatrixA)),
         offset, MatrixA@ptr, MatrixATL@ptr, MatrixATR@ptr, MatrixABL@ptr,
         MatrixABR@ptr, as.integer(diagDist) )
}


PartitionUpDiagonal<-function( MatrixA, MatrixATL, MatrixATR,
                               MatrixABL, MatrixABR, diagDist ){
  .Call( paste0("partitionUpDiagonal", .getSuffix(MatrixA)), MatrixA@ptr,
         MatrixATL@ptr, MatrixATR@ptr, MatrixABL@ptr, MatrixABR@ptr,
         as.integer(diagDist) )
}

LockedPartitionUpDiagonal<-function( MatrixA, MatrixATL, MatrixATR,
                                     MatrixABL, MatrixABR, diagDist ){
  .Call( paste0("lockedPartitionUpDiagonal", .getSuffix(MatrixA)), MatrixA@ptr,
         MatrixATL@ptr, MatrixATR@ptr, MatrixABL@ptr, MatrixABR@ptr,
         as.integer(diagDist) )
}

PartitionUpOffsetDiagonal<-function( offset,
                                     MatrixA, MatrixATL, MatrixATR,
                                     MatrixABL, MatrixABR, diagDist ){
  .Call( paste0("partitionUpOffsetDiagonal", .getSuffix(MatrixA)), offset,
         MatrixA@ptr, MatrixATL@ptr, MatrixATR@ptr, MatrixABL@ptr,
         MatrixABR@ptr, as.integer(diagDist) )
}

LockedPartitionUpOffsetDiagonal<-function( offset,
                                           MatrixA, MatrixATL, MatrixATR,
                                           MatrixABL, MatrixABR, diagDist ){
  .Call( paste0("lockedPartitionUpOffsetDiagonal", .getSuffix(MatrixA)), offset,
         MatrixA@ptr, MatrixATL@ptr, MatrixATR@ptr, MatrixABL@ptr,
         MatrixABR@ptr, as.integer(diagDist) )
}

###------------
### Repartition
###------------

###----------------
### Slide Partition
###----------------

###------
### Merge
###------

Merge1x2<-function( MatrixA, MatrixBL, MatrixBR){
  .Call( paste0("merge1x2", .getSuffix(MatrixA)), MatrixA@ptr,
         MatrixBL@ptr, MatrixBR@ptr )
}

LockedMerge1x2<-function( MatrixA, MatrixBL, MatrixBR){
  .Call( paste0("lockedMerge1x2", .getSuffix(MatrixA)), MatrixA@ptr,
         MatrixBL@ptr, MatrixBR@ptr )
}

Merge2x1<-function( MatrixA, MatrixBT, MatrixBB){
  .Call( paste0("merge2x1", .getSuffix(MatrixA)), MatrixA@ptr,
         MatrixBT@ptr, MatrixBB@ptr )
}

LockedMerge2x1<-function( MatrixA, MatrixBT, MatrixBB){
  .Call( paste0("lockedMerge2x1", .getSuffix(MatrixA)), MatrixA@ptr,
         MatrixBT@ptr, MatrixBB@ptr )
}

Merge2x2<-function( MatrixA, MatrixBTL, MatrixBTR, MatrixBBL, MatrixBBR){
  .Call( paste0("merge2x1", .getSuffix(MatrixA)), MatrixA@ptr, MatrixBTL@ptr,
         MatrixBTR@ptr, MatrixBBL@ptr, MatrixBBR@ptr)
}

LockedMerge2x2<-function( MatrixA, MatrixBTL, MatrixBTR, MatrixBBL, MatrixBBR){
  .Call( paste0("lockedMerge2x1", .getSuffix(MatrixA)), MatrixA@ptr,
         MatrixBTL@ptr, MatrixBTR@ptr, MatrixBBL@ptr, MatrixBBR@ptr)
}



#####################
### Matrix Generators
#####################

Demmel<-function(MatrixA, n){
  .Call( paste0("demmel", .getSuffix(MatrixA)), MatrixA@ptr, as.integer(n) )
}

Diagonal<-function(MatrixA, MatrixD){
  .Call( paste0("diagonal", .getSuffix(MatrixA)), MatrixA@ptr, MatrixD@ptr )
}

HermitianUniformSpectrum<-function(MatrixA, n, lower, upper){
  if (MatrixA@datatype=="z"){
    lower <- as.complex(lower)
    upper <- as.complex(upper)
  }
  .Call( paste0("hermitianUniformSpectrum", .getSuffix(MatrixA)), MatrixA@ptr,
         as.integer(n), lower, upper)

}

Hilbert<-function(MatrixA, n){
  .Call( paste0("hilbert", .getSuffix(MatrixA)), MatrixA@ptr, as.integer(n) )
}

Identity<-function(MatrixA, rows, cols){
  .Call( paste0("identity", .getSuffix(MatrixA)), MatrixA@ptr, as.integer(rows),
         as.integer(cols))
}

Jordan<-function(MatrixA, n, lambda){
  if (MatrixA@datatype=="z")
    lambda <- as.complex(lambda)
  .Call( paste0("jordan", .getSuffix(MatrixA)), MatrixA@ptr, as.integer(n), lambda )
}

Kahan<-function(MatrixA, n, phi){
  if (MatrixA@datatype=="z")
    phi <- as.complex(phi)
  .Call( paste0("kahan", .getSuffix(MatrixA)), MatrixA@ptr, as.integer(n), phi )
}

KMS<-function(MatrixA, n, rho){
  if (MatrixA@datatype=="z")
    rho <- as.complex(rho)
  .Call( paste0("kahan", .getSuffix(MatrixA)), MatrixA@ptr, as.integer(n), rho )
}

Laplacian1D<-function(MatrixA, nx){
  .Call( paste0("laplacian1D", .getSuffix(MatrixA)), MatrixA@ptr, as.integer(nx) )
}

Laplacian2D<-function(MatrixA, nx, ny){
  .Call( paste0("laplacian2D", .getSuffix(MatrixA)), MatrixA@ptr, as.integer(nx),
         as.integer(ny) )
}

Laplacian3D<-function(MatrixA, nx, ny, nz){
  .Call( paste0("laplacian3D", .getSuffix(MatrixA)), MatrixA@ptr, as.integer(nx),
         as.integer(ny), as.integer(nz) )
}

Lauchli<-function(MatrixA, n, mu){
  if (MatrixA@datatype=="z")
    mu <- as.complex(mu)
  .Call( paste0("lauchli", .getSuffix(MatrixA)), MatrixA@ptr, as.integer(n), mu )
}

Legendre<-function(MatrixA, n){
  .Call( paste0("legendre", .getSuffix(MatrixA)), MatrixA@ptr, as.integer(n) )
}

Lehmer<-function(MatrixA, n){
  .Call( paste0("lehmer", .getSuffix(MatrixA)), MatrixA@ptr, as.integer(n) )
}

Lotkin<-function(MatrixA, n){
  .Call( paste0("lotkin", .getSuffix(MatrixA)), MatrixA@ptr, as.integer(n) )
}

MinIJ<-function(MatrixA, n){
  .Call( paste0("minIJ", .getSuffix(MatrixA)), MatrixA@ptr, as.integer(n) )
}

Ones<-function(MatrixA, rows, cols){
  .Call( paste0("ones", .getSuffix(MatrixA)), MatrixA@ptr, as.integer(rows),
         as.integer(cols))
}

OneTwoOne<-function(MatrixA, n){
  .Call( paste0("oneTwoOne", .getSuffix(MatrixA)), MatrixA@ptr, as.integer(n) )
}

Parter<-function(MatrixA, n){
  .Call( paste0("parter", .getSuffix(MatrixA)), MatrixA@ptr, as.integer(n) )
}

Pei<-function(MatrixA, n, alpha){
  if (MatrixA@datatype=="z")
    alpha <- as.complex(alpha)
  .Call( paste0("pei", .getSuffix(MatrixA)), MatrixA@ptr, as.integer(n), alpha )
}

Parter<-function(MatrixA, n){
  .Call( paste0("parter", .getSuffix(MatrixA)), MatrixA@ptr, as.integer(n) )
}

Riffle<-function(MatrixA, n){
  .Call( paste0("riffle", .getSuffix(MatrixA)), MatrixA@ptr, as.integer(n) )
}

RiffleStationary<-function(MatrixA, n){
  .Call( paste0("riffleStationary", .getSuffix(MatrixA)), MatrixA@ptr,
         as.integer(n) )
}

RiffleDecay<-function(MatrixA, n){
  .Call( paste0("riffleDecay", .getSuffix(MatrixA)), MatrixA@ptr, as.integer(n) )
}

Ris<-function(MatrixA, n){
  .Call( paste0("ris", .getSuffix(MatrixA)), MatrixA@ptr, as.integer(n) )
}

Triangle<-function(MatrixA, n){
  .Call( paste0("triangle", .getSuffix(MatrixA)), MatrixA@ptr, as.integer(n) )
}

TriW<-function(MatrixA, n, alpha, k){
  if (MatrixA@datatype=="z")
    alpha <- as.complex(alpha)
  .Call( paste0("triW", .getSuffix(MatrixA)), MatrixA@ptr, as.integer(n), alpha,
         as.integer(k) )
}

Uniform<-function(MatrixA, rows, cols, center=0.0, radius=1.0){
  if (MatrixA@datatype=="z"){
    center <- as.complex(center)
    radius <- as.complex(radius)
  }
  .Call( paste0("uniform", .getSuffix(MatrixA)), MatrixA@ptr, as.integer(rows),
         as.integer(cols), center, radius )
}

Walsh<-function(MatrixA, n, binary){
  .Call( paste0("walsh", .getSuffix(MatrixA)), MatrixA@ptr, as.integer(n),
         as.logical(binary) )
}

Whale<-function(MatrixA, n){
  .Call( paste0("whale", .getSuffix(MatrixA)), MatrixA@ptr, as.integer(n) )
}

Wigner<-function(MatrixA, n, mean, stddev){
  if (MatrixA@datatype=="z"){
    mean <- as.complex(mean)
    stddev <- as.complex(stddev)
  }
  .Call( paste0("wigner", .getSuffix(MatrixA)), MatrixA@ptr, as.integer(n), mean,
         stddev)
}

Wilkinson<-function(MatrixA, k){
  .Call( paste0("wilkinson", .getSuffix(MatrixA)), MatrixA@ptr, as.integer(k) )
}

Zeros<-function(MatrixA, rows, cols){
  .Call( paste0("zeros", .getSuffix(MatrixA)), MatrixA@ptr, as.integer(rows),
         as.integer(cols))
}
#############
### Blas Like
#############

###-------------
### Blas Level 1
###-------------

## B = A^H
Adjoint<-function(MatrixA, MatrixB){
  .Call( paste0("adjoint", .getSuffix(MatrixA)), alpha, MatrixA@ptr, MatrixB@ptr)
}

Axpy<-function(alpha, MatrixX, MatrixY){
  .Call( paste0("axpy", .getSuffix(MatrixX)), alpha, MatrixX@ptr, MatrixY@ptr)
}

AxpyTrapezoid<-function(uplo, alpha, MatrixX, MatrixY, offset){
  .Call( paste0("axpyTrapezoid", .getSuffix(MatrixX)), uplo, alpha, MatrixX@ptr,
         MatrixY@ptr, as.integer(offset) )
}

AxpyTriangle<-function(uplo, alpha, MatrixX, MatrixY){
    AxpyTrapezoid(uplo, alpha, MatrixX, MatrixY, 0)
}

Conjugate<- function(MatrixA){
  .Call( paste0("conjugate", .getSuffix(MatrixA)), MatrixA@ptr)
}

##B=A
Copy<-function(MatrixA, MatrixB){
  .Call( paste0("copy", .getSuffix(MatrixA)), MatrixA@ptr, MatrixB@ptr )
}

DiagonalScale<-function(side, Matrixd, MatrixX, orientation="NORMAL"){
  if(MatrixX@datatype=="z"){
    .Call( paste0("diagonalScale", .getSuffix(MatrixX)), side, Matrixd@ptr,
          MatrixX@ptr, orientation)
  }else{
    .Call( paste0("diagonalScale", .getSuffix(MatrixX)), side, Matrixd@ptr,
          MatrixX@ptr)
  }
}

DiagonalScaleTrapezoid<-function(side, uplo, Matrixd, MatrixX, offset){
  if(MatrixX@datatype=="z"){
    .Call( paste0("diagonalScaleTrapezoid", .getSuffix(MatrixX)), side,
          Matrixd@ptr, MatrixX@ptr, orientation)
  }else{
    .Call( paste0("diagonalScaleTrapezoid", .getSuffix(MatrixX)), side,
          Matrixd@ptr, MatrixX@ptr)
  }
}

DiagonalSolve<-function(side, uplo, Matrixd, MatrixX, offset){
  if(MatrixX@datatype=="z"){
    .Call( paste0("diagonalSolve", .getSuffix(MatrixX)), side,
          Matrixd@ptr, MatrixX@ptr, orientation)
  }else{
    .Call( paste0("diagonalSolve", .getSuffix(MatrixX)), side,
          Matrixd@ptr, MatrixX@ptr)
  }
}

Dot<-function(MatrixA, MatrixB){
  .Call( paste0("dot", .getSuffix(MatrixA)), MatrixA@ptr, MatrixB@ptr )
}

Fill<-function(MatrixA, alpha){
  .Call( paste0("fill", .getSuffix(MatrixA)), MatrixA@ptr, alpha )
}

FillDiagonal<-function(MatrixA, alpha, offset=0){
  .Call( paste0("fillDiagonal", .getSuffix(MatrixA)), MatrixA@ptr, alpha,
         as.integer(offset) )
}

Hadamard<-function(MatrixA, MatrixB, MatrixC){
  .Call( paste0("hadamard", .getSuffix(MatrixA)), MatrixA@ptr, MatrixB@ptr,
        MatrixC@ptr )
}

HilbertSchmidt<-function(MatrixA, MatrixB){
  .Call( paste0("hilbertSchmidt", .getSuffix(MatrixA)), MatrixA@ptr, MatrixB@ptr )
}

ImagPart<-function(MatrixA, MatrixAIm){
  .Call( paste0("imagPart", .getSuffix(MatrixA)), MatrixA@ptr, MatrixAIm@ptr )
}

MakeHermitian<-function(uplo, MatrixA){
  .Call( paste0("makeHermitian", .getSuffix(MatrixA)), uplo, MatrixA@ptr )
}

MakeReal<-function(MatrixA){
  .Call( paste0("makeReal", .getSuffix(MatrixA)), MatrixA@ptr )
}

MakeSymmetric<-function(uplo, MatrixA){
  .Call( paste0("makeSymmetric", .getSuffix(MatrixA)), uplo, MatrixA@ptr )
}

MakeTrapezoidal<-function(uplo, MatrixA, offset){
  .Call( paste0("makeTrapezoidal", .getSuffix(MatrixA)), uplo, MatrixA@ptr,
         as.integer(offset) )
}

MakeTriangular<-function(uplo, MatrixA){
    MakeTrapezoidal(uplo, MatrixA, 0)
}

Max<-function(MatrixA){
  .Call( paste0("max", .getSuffix(MatrixA)), MatrixA@ptr )
}

SymmetricMax<-function(uplo, MatrixA){
  .Call( paste0("symmetricMax", .getSuffix(MatrixA)), uplo, MatrixA@ptr )
}

VectorMax<-function(MatrixA){
  .Call( paste0("vectorMax", .getSuffix(MatrixA)), MatrixA@ptr )
}

MaxAbs<-function(MatrixA){
  .Call( paste0("maxAbs", .getSuffix(MatrixA)), MatrixA@ptr )
}

SymmetricMaxAbs<-function(uplo, MatrixA){
  .Call( paste0("symmetricMaxAbs", .getSuffix(MatrixA)), uplo, MatrixA@ptr )
}

VectorMaxAbs<-function(MatrixA){
  .Call( paste0("vectorMaxAbs", .getSuffix(MatrixA)), MatrixA@ptr )
}

Min<-function(MatrixA){
  .Call( paste0("min", .getSuffix(MatrixA)), MatrixA@ptr )
}

SymmetricMin<-function(uplo, MatrixA){
  .Call( paste0("symmetricMin", .getSuffix(MatrixA)), uplo, MatrixA@ptr )
}

VectorMin<-function(MatrixA){
  .Call( paste0("vectorMin", .getSuffix(MatrixA)), MatrixA@ptr )
}

MinAbs<-function(MatrixA){
  .Call( paste0("minAbs", .getSuffix(MatrixA)), MatrixA@ptr )
}

SymmetricMinAbs<-function(uplo, MatrixA){
  .Call( paste0("symmetricMinAbs", .getSuffix(MatrixA)), uplo, MatrixA@ptr )
}

VectorMinAbs<-function(MatrixA){
  .Call( paste0("vectorMinAbs", .getSuffix(MatrixA)), MatrixA@ptr )
}

SymmetricMax<-function(uplo, MatrixA){
  .Call( paste0("symmetricMax", .getSuffix(MatrixA)), uplo, MatrixA@ptr )
}

VectorMax<-function(MatrixA){
  .Call( paste0("vectorMax", .getSuffix(MatrixA)), MatrixA@ptr )
}

MaxAbs<-function(MatrixA){
  .Call( paste0("maxAbs", .getSuffix(MatrixA)), MatrixA@ptr )
}

SymmetricMaxAbs<-function(uplo, MatrixA){
  .Call( paste0("symmetricMaxAbs", .getSuffix(MatrixA)), uplo, MatrixA@ptr )
}

Nrm2<-function(MatrixA){
  .Call( paste0("nrm2", .getSuffix(MatrixA)), MatrixA@ptr )
}

RealPart<-function(MatrixA, MatrixAReal){
  .Call( paste0("realPart", .getSuffix(MatrixA)), MatrixA@ptr, MatrixAReal@ptr )
}

Scale<-function(alpha, MatrixA){
  .Call( paste0("scale", .getSuffix(MatrixA)), alpha, MatrixA@ptr )
}

ScaleTrapezoid<-function(alpha, uplo, MatrixA, offset){
  .Call( paste0("scaleTrapezoid", .getSuffix(MatrixA)), alpha, uplo, MatrixA@ptr,
         as.integer(offset) )
}

Shift<-function(MatrixA, alpha){
  .Call( paste0("shift", .getSuffix(MatrixA)), MatrixA@ptr, alpha)
}


ShiftDiagonal<-function(MatrixA, alpha, offset=0){
  .Call( paste0("shiftDiagonal", .getSuffix(MatrixA)), MatrixA@ptr, alpha,
         as.integer(offset) )
}

Swap<-function(orientation, MatrixX, MatrixY){
  .Call( paste0("swap", .getSuffix(MatrixX)), orientation, MatrixX@ptr,
         MatrixY@ptr )
}

RowSwap<-function(MatrixA, to, from){
  .Call( paste0("rowSwap", .getSuffix(MatrixA)), MatrixA@ptr, as.integer(to),
         as.integer(from) )
}

ColSwap<-function(MatrixA, to, from){
  .Call( paste0("colSwap", .getSuffix(MatrixA)), MatrixA, as.integer(to),
         as.integer(from) )
}

SymmetricSwap<-function(uplo, MatrixA, to, from){
  .Call( paste0("symmetricSwap", .getSuffix(MatrixA)), uplo, MatrixA@ptr,
         as.integer(to), as.integer(from) )
}

Transpose<-function(MatrixA, MatrixB){
  .Call( paste0("transpose", .getSuffix(MatrixA)), MatrixA@ptr, MatrixB@ptr )
}

# Element-wise routines

Sqrt<-function(MatrixA){
  .Call( paste0("sqrt", .getSuffix(MatrixA)), MatrixA@ptr)
}

Log<-function(MatrixA){
  .Call( paste0("log", .getSuffix(MatrixA)), MatrixA@ptr)
}

Exp<-function(MatrixA){
  .Call( paste0("exp", .getSuffix(MatrixA)), MatrixA@ptr)
}

Cos<-function(MatrixA){
  .Call( paste0("cos", .getSuffix(MatrixA)), MatrixA@ptr)
}

Sin<-function(MatrixA){
  .Call( paste0("sin", .getSuffix(MatrixA)), MatrixA@ptr)
}

Tan<-function(MatrixA){
  .Call( paste0("tan", .getSuffix(MatrixA)), MatrixA@ptr)
}

Acos<-function(MatrixA){
  .Call( paste0("acos", .getSuffix(MatrixA)), MatrixA@ptr)
}

Asin<-function(MatrixA){
  .Call( paste0("asin", .getSuffix(MatrixA)), MatrixA@ptr)
}

Atan<-function(MatrixA){
  .Call( paste0("atan", .getSuffix(MatrixA)), MatrixA@ptr)
}


###-------------
### Blas Level 2
###-------------

Gemv<-function( orientationA="NORMAL", alpha, MatrixA, Matrixx, beta, Matrixy){
  .Call( paste0("gemv", .getSuffix(MatrixA)), orientationA, alpha, MatrixA@ptr,
         Matrixx@ptr, beta, Matrixy@ptr )
}

Ger<-function( alpha, Matrixx, Matrixy, MatrixA){
  .Call( paste0("ger", .getSuffix(MatrixA)), alpha, Matrixx@ptr, Matrixy@ptr,
         MatrixA@ptr )
}

Geru<-function( alpha, Matrixx, Matrixy, MatrixA){
  .Call( paste0("geru", .getSuffix(MatrixA)), alpha, Matrixx@ptr, Matrixy@ptr,
         MatrixA@ptr )
}

Hemv<-function( uplo, alpha, MatrixA, Matrixx, beta, Matrixy){
  .Call( paste0("hemv", .getSuffix(MatrixA)), uplo, alpha, MatrixA@ptr,
         Matrixx@ptr, beta, Matrixy@ptr )
}

Her<-function( uplo, alpha, Matrixx, MatrixA){
  .Call( paste0("her", .getSuffix(MatrixA)), uplo, alpha, Matrixx@ptr,
         MatrixA@ptr )
}

Her2<-function( uplo, alpha, Matrixx, Matrixy, MatrixA){
  .Call( paste0("her2", .getSuffix(MatrixA)), uplo, alpha, Matrixx@ptr,
         Matrixy@ptr, MatrixA@ptr )
}

QuasiTrsv<-function( uplo, orientation, MatrixA, Matrixx){
  .Call( paste0("quasiTrsv", .getSuffix(MatrixA)), uplo, orientation,
         MatrixA@ptr, Matrixx@ptr)
}

Symv<-function( uplo, alpha, MatrixA, Matrixx, beta, Matrixy){
  .Call( paste0("symv", .getSuffix(MatrixA)), uplo, alpha, MatrixA@ptr,
         Matrixx@ptr, beta, Matrixy@ptr )
}

Syr<-function( uplo, alpha, Matrixx, MatrixA){
  .Call( paste0("syr", .getSuffix(MatrixA)), uplo, alpha, Matrixx@ptr,
         MatrixA@ptr )
}

Syr2<-function( uplo, alpha, Matrixx, Matrixy, MatrixA){
  .Call( paste0("syr2", .getSuffix(MatrixA)), uplo, alpha, Matrixx@ptr,
         Matrixy@ptr, MatrixA@ptr )
}

Trmv<-function( uplo, orientation, diagUnit, MatrixA, Matrixx){
  .Call( paste0("trmv", .getSuffix(MatrixA)), uplo, orientation, diagUnit,
         MatrixA@ptr, Matrixx@ptr)
}

Trr<-function( uplo, alpha, Matrixx, Matrixy, MatrixA, conjugate=FALSE){
  if( Matrixx@datatype == "z"){
    .Call( paste0("trr", .getSuffix(MatrixA)), uplo, alpha, Matrixx@ptr,
           Matrixy@ptr, MatrixA@ptr, conjugate )
  }else{
    .Call( paste0("trr", .getSuffix(MatrixA)), uplo, alpha, Matrixx@ptr,
           Matrixy@ptr, MatrixA@ptr )
  }
}

Trr2<-function( uplo, alpha, MatrixX, MatrixY, MatrixA, conjugate=FALSE){
  if( Matrixx@datatype == "z"){
    .Call( paste0("trr2", .getSuffix(MatrixA)), uplo, alpha, MatrixX@ptr,
           MatrixY@ptr, MatrixA@ptr, conjugate )
  }else{
    .Call( paste0("trr2", .getSuffix(MatrixA)), uplo, alpha, MatrixX@ptr,
           MatrixY@ptr, MatrixA@ptr )
  }
}

Trsv<-function( uplo, orientation, diagUnit, MatrixA, Matrixx){
  .Call( paste0("trsv", .getSuffix(MatrixA)), uplo, orientation, diagUnit,
         MatrixA@ptr, Matrixx@ptr)
}



###-------------
### Blas Level 3
###-------------

Gemm<-function( orientationA="NORMAL", orientationB="NORMAL", alpha, MatrixA,
                MatrixB, beta, MatrixC){
  .Call( paste0("gemm", .getSuffix(MatrixA)),orientationA, orientationB, alpha,
         MatrixA@ptr, MatrixB@ptr, beta, MatrixC@ptr)
}

GemmX<-function( orientationA="NORMAL", orientationB="NORMAL", alpha, MatrixA,
                MatrixB, beta, MatrixC, algorithm){
  .Call( paste0("gemm", .getSuffix(MatrixA)),orientationA, orientationB, alpha,
         MatrixA@ptr, MatrixB@ptr, beta, MatrixC@ptr, algorithm )
}

Hemm<-function( side, uplo, alpha, MatrixA, MatrixB, beta, MatrixC ){
  .Call( paste0("hemm", .getSuffix(MatrixA)), side, uplo, alpha, MatrixA@ptr,
         MatrixB@ptr, beta, MatrixC@ptr )
}

Herk<-function( side, orientation, alpha, MatrixA, beta, MatrixC ){
  .Call( paste0("herk", .getSuffix(MatrixA)), side, orientation, alpha,
         MatrixA@ptr, beta, MatrixC@ptr )
}

Her2k<-function( side, orientation, alpha, MatrixA, MatrixB, beta, MatrixC ){
  .Call( paste0("her2k", .getSuffix(MatrixA)), side, orientation, alpha,
         MatrixA@ptr, MatrixB@ptr, beta, MatrixC@ptr )
}

MultiShiftQuasiTrsm<-function( side, uplo, orientationA, alpha, MatrixA,
                               MatrixShifts, MatrixB ){
  .Call( paste0("multiShiftQuasiTrsm", .getSuffix(MatrixA)), side, uplo,
         orientationA, alpha, MatrixA@ptr, MatrixShifts@ptr, MatrixB@ptr )
}

MultiShiftTrsm<-function( side, uplo, orientationA, alpha, MatrixA,
                          MatrixShifts, MatrixB ){
  .Call( paste0("multiShiftTrsm", .getSuffix(MatrixA)), side, uplo,
         orientationA, alpha, MatrixA@ptr, MatrixShifts@ptr, MatrixB@ptr )
}

QuasiTrsm<-function( side, uplo, orientationA, alpha, MatrixA, MatrixB ){
  .Call( paste0("quasiTrsm", .getSuffix(MatrixA)), side, uplo,
         orientationA, alpha, MatrixA@ptr, MatrixB@ptr )
}

Symm<-function( side, uplo, alpha, MatrixA, MatrixB, beta, MatrixC){
  .Call( paste0("symm", .getSuffix(MatrixA)), side, uplo, alpha, MatrixA@ptr,
         MatrixB@ptr, beta, MatrixC@ptr )
}

Syrk<-function( uplo, orientation, alpha, MatrixA, beta, MatrixC){
  .Call( paste0("syrk", .getSuffix(MatrixA)), uplo, orientation, alpha,
         MatrixA@ptr, beta, MatrixC@ptr )
}

Syr2k<-function( uplo, orientation, alpha, MatrixA, MatrixB, beta, MatrixC){
  .Call( paste0("syr2k", .getSuffix(MatrixA)), uplo, orientation, alpha,
         MatrixA@ptr, MatrixB@ptr, beta, MatrixC@ptr )
}

Trdtrmm<-function( uplo, MatrixA, conjugate=FALSE){
  if( MatrixA@datatype == "z"){
    .Call( paste0("trdtrmm", .getSuffix(MatrixA)), uplo, MatrixA@ptr, conjugate )
  }else{
    .Call( paste0("trdtrmm", .getSuffix(MatrixA)), uplo, MatrixA@ptr )
  }
    
}

TrdtrmmQuasi<-function( uplo, MatrixA, MatrixDOff, conjugate=FALSE ){
  if( MatrixA@datatype == "z"){
    .Call( paste0("trdtrmmQuasi", .getSuffix(MatrixA)), uplo, MatrixA@ptr,
          MatrixDOff@ptr, conjugate )
  }else{
    .Call( paste0("trdtrmmQuasi", .getSuffix(MatrixA)), uplo, MatrixA@ptr,
          MatrixDOff@ptr )    
  }
}

Trmm<-function( side, uplo, orientationA, diagUnit, alpha, MatrixA, MatrixB ){
  .Call( paste0("trmm", .getSuffix(MatrixA)), side, uplo, orientationA, diagUnit,
         alpha, MatrixA@ptr, MatrixB@ptr )
}

Trrk<-function( uplo, orientationA, orientationB, alpha, MatrixA, MatrixB, beta,
                MatrixC ){
  .Call( paste0("trrk", .getSuffix(MatrixA)), uplo, orientationA, orientationB,
         alpha, MatrixA@ptr, MatrixB@ptr, beta, MatrixC@ptr )
}

Trr2k<-function( uplo, orientationA, orientationB, orientationC, orientationD,
                 alpha, MatrixA, MatrixB, beta, MatrixC, MatrixD, gamma, MatrixE ){
  .Call( paste0("trr2k", .getSuffix(MatrixA)), uplo, orientationA, orientationB,
         orientationC, orientationD, alpha, MatrixA@ptr, MatrixB@ptr, beta,
         MatrixC@ptr, MatrixD@ptr, gamma, MatrixE@ptr )
}

Trsm<-function( side, uplo, orientationA, diagUnit, alpha, MatrixA, MatrixB ){
  .Call( paste0("trsm", .getSuffix(MatrixA)), side, uplo, orientationA@ptr,
         diagUnit, alpha, MatrixA@ptr, MatrixB@ptr )
}

Trstrm<-function( side, uplo, orientationA, diagUnit, alpha, MatrixA, MatrixB ){
  .Call( paste0("trstrm", .getSuffix(MatrixA)), side, uplo, orientationA,
         diagUnit, alpha, MatrixA@ptr, MatrixB@ptr )
}

Trtrmm<-function( uplo, MatrixA ){
  if( MatrixA@datatype == "z"){
    .Call( paste0("trtrmm", .getSuffix(MatrixA)), uplo, MatrixA@ptr, conjugate )
  }else{
    .Call( paste0("trtrmm", .getSuffix(MatrixA)), uplo, MatrixA@ptr )
  }
}

TwoSidedTrmm<-function( uplo, diagUnit, MatrixA, MatrixB ){
  .Call( paste0("twoSidedTrmm", .getSuffix(MatrixA)), uplo, diagUnit,
         MatrixA@ptr, MatrixB@ptr )
}

TwoSidedTrsm<-function( uplo, diagUnit, MatrixA, MatrixB ){
  .Call( paste0("twoSidedTrsm", .getSuffix(MatrixA)), uplo, diagUnit,
         MatrixA@ptr, MatrixB@ptr )
}


############### 
### Lapack like
###############

###---------
### Spectral
###---------

HermitianEig<-function(Uplo, MatrixA, EigenValues, Sort="D"){
  .Call( paste0("hermitianEig", .getSuffix(MatrixA)), Uplo, MatrixA@ptr,
        EigenValues, Sort )
}

HermitianEigPair<-function(Uplo, MatrixA, EigenValues, EigenVectors, Sort="D"){
  .Call( paste0("hermitianEigPair", .getSuffix(MatrixA)) , Uplo, MatrixA@ptr,
        EigenValues@ptr, EigenVectors@ptr, Sort )
}

HermitianEigPartial<-function(Uplo, MatrixA, EigenValues, Sort, From, To){
  .Call( paste0("hermitianEigPartial", .getSuffix(MatrixA)), Uplo, MatrixA@ptr,
        EigenValues@ptr, Sort, From, To )
}

HermitianEigPairPartial<-function(Uplo, MatrixA, EigenValues, EigenVectors,
                                  Sort, From, To){
  .Call( paste0("hermitianEigPairPartial", .getSuffix(MatrixA)), Uplo, MatrixA@ptr,
        EigenValues@ptr, EigenVectors@ptr, Sort, From, To )
}

Polar<-function(MatrixA){
  .Call( paste0("polar", .getSuffix(MatrixA)), MatrixA@ptr )
}

HermitianPolar<-function(Uplo, Matrix){
  .Call( paste0("polar", .getSuffix(MatrixA)), Uplo,  MatrixA@ptr )
}

PolarDecomp<-function(MatrixA, MatrixP){
  .Call( paste0("polarDecomp", .getSuffix(MatrixA)), MatrixA@ptr, MatrixP@ptr )
}

HermitianPolarDecomp<-function(Uplo, MatrixA, MatrixP){
  .Call( paste0("hermitianpolarDecomp", .getSuffix(MatrixA)), Uplo, MatrixA@ptr,
         MatrixP@ptr )
}

Schur<-function( MatrixA, Matrixw, isFullTriangle){
  .Call( paste("schur", .getSuffix(MatrixA)), MatrixA@ptr, Matrixw@ptr,
        isFullTriangle )
}

SchurDecomp<-function( MatrixA, Matrixw, MatrixQ, isFullTriangle){
  .Call( paste("schurDecomp", .getSuffix(MatrixA)), MatrixA@ptr, Matrixw@ptr,
        MatrixQ@ptr, isFullTriangle )
}

SingularValues<-function( MatrixA, Matrixs){
  .Call( paste0("singularValues", .getSuffix(MatrixA)), MatrixA@ptr,
         Matrixs@ptr )
}

SVD<-function( MatrixA, Matrixs, MatrixV){
  .Call( paste0("sVD", .getSuffix(MatrixA)), MatrixA@ptr, Matrixs@ptr,
         MatrixV@ptr )
}

###--------
### Solvers
###--------

LinearSolve<-function( MatrixA, MatrixB ){
  .Call( paste0("linearSolve", .getSuffix(MatrixA)), MatrixA@ptr,
         MatrixB@ptr )
}

SymmetricSolve<-function( uplo, orientation, MatrixA, MatrixB ){
  .Call( paste0("symmetricSolve", .getSuffix(MatrixA)), uplo, orientation,
         MatrixA@ptr, MatrixB@ptr )
}

HermitianSolve<-function( uplo, orientation, MatrixA, MatrixB ){
  .Call( paste0("hermitianSolve", .getSuffix(MatrixA)), uplo, orientation,
         MatrixA@ptr, MatrixB@ptr )
}

HPDSolve<-function( uplo, orientation, MatrixA, MatrixB ){
  .Call( paste0("hPDSolve", .getSuffix(MatrixA)), uplo, orientation, MatrixA@ptr,
         MatrixB@ptr )
}


MultiShiftHessSolve<-function( uplo, orientation, alpha, MatrixH, MatrixShifts,
                               MatrixX ){
  .Call( paste0("multiShiftHessSolve", .getSuffix(MatrixH)), uplo, orientation,
         MatrixH@ptr, MatrixShifts@ptr, MatrixX@ptr )
}

###--------------
### Euclidean Min
###--------------

LeastSquares<-function( orientation, MatrixA, MatrixB, MatrixX ){
  .Call( paste0("leastSquares", .getSuffix(MatrixA)), orientation, MatrixA@ptr,
         MatrixB@ptr, MatrixX@ptr )
}

Ridge<-function( orientation, MatrixA, MatrixB, alpha, MatrixX, algorithm){
  .Call( paste0("ridge", .getSuffix(MatrixA)), orientation, MatrixA@ptr, MatrixB@ptr, alpha,
         MatrixX@ptr, algorithm )
}

Tikhonov<-function( orientation, MatrixA, MatrixB, gamma, MatrixX, algorithm){
  .Call( paste0("tikhonov", .getSuffix(MatrixA)), orientation, MatrixA@ptr, MatrixB@ptr,
         gamma, MatrixX@ptr, algorithm )
}

LSE<-function( orientation, MatrixA, MatrixB, MatrixC, MatrixD, MatrixX ){
  .Call( paste0("lSE", .getSuffix(MatrixA)), orientation, MatrixA@ptr,
        MatrixB@ptr, MatrixC@ptr, MatrixD@ptr, MatrixX@ptr )
}

GLM<-function( MatrixA, MatrixB, MatrixD, MatrixX, MatrixY ){
  .Call( paste0("gLM", .getSuffix(MatrixA)), MatrixA@ptr, MatrixB@ptr,
         MatrixD@ptr, MatrixX@ptr, MatrixY@ptr )
}


###----------------------
### Matrix Factorizations
###----------------------

Cholesky<-function(uplo, MatrixA){
  .Call( paste0("cholesky", .getSuffix(MatrixA)), uplo, MatrixA@ptr )
}

SolveAfterCholesky<-function(uplo, orientation, MatrixA, MatrixB){
  .Call( paste0("solveAfterCholesky", .getSuffix(MatrixA)), uplo, orientation,
         MatrixA@ptr, MatrixB@ptr )
}

ReverseCholesky<-function(uplo, MatrixA){
  .Call( paste0("reverseCholesky", .getSuffix(MatrixA)), uplo, MatrixA@ptr )
}

CholeskyPiv<-function(uplo, MatrixA, MatrixP){
  .Call( paste0("choleskyPiv", .getSuffix(MatrixA)), uplo, MatrixA@ptr, MatrixP@ptr )
}

SolveAfterCholeskyPiv<-function(uplo, orientation, MatrixA, MatrixP, MatrixB){
  .Call( paste0("solveAfterCholeskyPiv", .getSuffix(MatrixA)), uplo,
         orientation, MatrixA@ptr, MatrixP@ptr, MatrixB@ptr )
}

CholeskyMod<-function(uplo, MatrixT, alpha, MatrixV){
  .Call( paste0("choleskyMod", .getSuffix(MatrixT)), uplo, MatrixT@ptr, alpha,
         MatrixV@ptr )
}

HPSDCholesky<-function(uplo, MatrixA){
  .Call( paste0("hPSDCholesky", .getSuffix(MatrixA)), uplo, MatrixA@ptr )
}

LDL<-function(MatrixA){
  .Call( paste0("lDL", .getSuffix(MatrixA)), MatrixA@ptr )
}

LDLPiv<-function(MatrixA, MatrixdSub, Matrixp){
  .Call( paste0("lDLPiv", .getSuffix(MatrixA)), MatrixA@ptr, MatrixdSub@ptr,
         Matrixp@ptr)
}

InertiaAfterLDL<-function(Matrixd, MatrixdSub){
  .Call( paste0("inertiaAfterLDL", .getSuffix(Matrixd)), Matrixd@ptr,
         MatrixdSub@ptr )
}

SolveAfterLDL<-function(MatrixA, MatrixB){
  .Call( paste0("solveAfterLDL", .getSuffix(MatrixA)), MatrixA@ptr, MatrixB@ptr )
}

SolveAfterLDLPiv<-function(MatrixA, MatrixdSub, Matrixp,MatrixB){
  .Call( paste0("solveAfterLDLPiv", .getSuffix(MatrixA)), MatrixA@ptr,
         MatrixdSub@ptr, Matrixp@ptr, MatrixB@ptr )
}

SolveAfterLDL<-function(MatrixA, MatrixB){
  .Call( paste0("solveAfterLDL", .getSuffix(MatrixA)), MatrixA@ptr, MatrixB@ptr )
}

MultiplyAfterLDL<-function(MatrixA, MatrixB){
  .Call( paste0("multiplyAfterLDL", .getSuffix(MatrixA)), MatrixA@ptr, MatrixB@ptr )
}

MultiplyAfterLDLPiv<-function(MatrixA, MatrixdSub, Matrixp,MatrixB){
  .Call( paste0("multiplyAfterLDLPiv", .getSuffix(MatrixA)), MatrixA@ptr,
         MatrixdSub@ptr, Matrixp@ptr, MatrixB@ptr )
}

LU<-function(MatrixA){
  .Call( paste0("lU", .getSuffix(MatrixA)), MatrixA@ptr )
}

SolveAfterLU<-function(orientation, MatrixA, MatrixB){
  .Call( paste0("solveAfterLU", .getSuffix(MatrixA)), orientation, MatrixA@ptr,
         MatrixB@ptr )
}

LUPartialPiv<-function( MatrixA,  Matrixp){
  .Call( paste0("lUPartialPiv", .getSuffix(MatrixA)), MatrixA@ptr, Matrixp@ptr )
}

SolveAfterLUPartialPiv<-function(orientation, MatrixA, Matrixp, MatrixB){
  .Call( paste0("solveAfterLUPartialPiv", .getSuffix(MatrixA)), orientation,
         MatrixA@ptr, Matrixp@ptr, MatrixB@ptr )
}

LUFullPiv<-function( MatrixA,  Matrixp, Matrixq){
  .Call( paste0("luFullPiv", .getSuffix(MatrixA)), MatrixA@ptr, Matrixp@ptr,
         Matrixq@ptr )
}

SolveAfterLUFullPiv<-function(orientation, MatrixA, Matrixp, Matrixq, MatrixB){
  .Call( paste0("solveAfterLUPartialPiv", .getSuffix(MatrixA)), orientation,
         MatrixA@ptr, Matrixp@ptr, Matrixq@ptr, MatrixB@ptr )
}

LUMod<-function(MatrixA, Matrixp, Matrixu, Matrixv, tau){
  .Call( paste0("luPartialPiv", .getSuffix(MatrixA)), MatrixA@ptr, Matrixp@ptr,
         Matrixu@ptr, Matrixv@ptr, tau )
}

LQ<-function(MatrixA, Matrixt, Matrixd){
  .Call( paste0("lQ", .getSuffix(MatrixA)), MatrixA@ptr, Matrixt@ptr,
         Matrixd@ptr )
}

LQExplicit<-function(MatrixL, MatrixA){
  .Call( paste0("lQExplicit", .getSuffix(MatrixA)), MatrixL@ptr, MatrixA@ptr )
}

LQExplicitTriang<-function( MatrixA ){
  .Call( paste0("lQExplicitTriang", .getSuffix(MatrixA)), MatrixA )
}

LQExplicitUnitary<-function( MatrixA ){
  .Call( paste0("lQExplicitUnitary", .getSuffix(MatrixA)), MatrixA )
}

ApplyQAfterLQ<-function( side, orientation, MatrixA, Matrixt, Matrixd,
                         MatrixB ){
  .Call( paste0("applyQAfterLQ", .getSuffix(MatrixA)), side, orientation,
         MatrixA@ptr, Matrixt@ptr, Matrixd@ptr, MatrixB@ptr )
}

SolveQAfterLQ<-function( orientation, MatrixA, Matrixt, Matrixd, MatrixB,
                         MatrixX ){
  .Call( paste0("applyQAfterLQ", .getSuffix(MatrixA)), orientation, MatrixA@ptr,
         Matrixt@ptr, Matrixd@ptr, MatrixB@ptr, MatrixX@ptr )
}

QR<-function( MatrixA, Matrixt, Matrixd ){
  .Call( paste0("qR", .getSuffix(MatrixA)), MatrixA@ptr, Matrixt@ptr,
         Matrixd@ptr )
}

QRColPiv<-function( MatrixA, Matrixt, Matrixd, Matrixp ){
  .Call( paste0("qRColPiv", .getSuffix(MatrixA)), MatrixA@ptr, Matrixt@ptr,
         Matrixd@ptr, Matrixp@ptr )
}

QRExplicitTriang<-function( MatrixA ){
  .Call( paste0("qRExplicitTriang", .getSuffix(MatrixA)), MatrixA@ptr )
}

QRExplicitUnitary<-function( MatrixA ){
  .Call( paste0("qRExplicitUnitary", .getSuffix(MatrixA)), MatrixA@ptr )
}

QRExplicit<-function( MatrixA, MatrixR){
  .Call( paste0("qRExplicitUnitary", .getSuffix(MatrixA)), MatrixA@ptr,
        MatrixR@ptr )
}

QRColPivExplicit<-function( MatrixA, MatrixR, Matrixp ){
  .Call( paste0("qRColPivExplicit", .getSuffix(MatrixA)), MatrixA@ptr,
         MatrixR@ptr, Matrixp )
}

CholeskyQR<-function( MatrixA, MatrixR ){
  .Call( paste0("choleskyQR", .getSuffix(MatrixA)), MatrixA, MatrixR )
}

ApplyQAfterQR<-function( side, orientation, MatrixA, Matrixt, Matrixd,
                         MatrixB ){
  .Call( paste0("ApplyQAfterQR", .getSuffix(MatrixA)), side, orientation,
         MatrixA@ptr, Matrixt@ptr, Matrixd@ptr, MatrixB@ptr)
}

SolveQAfterQR<-function( orientation, MatrixA, Matrixt, Matrixd, MatrixB,
                        MatrixX ){
  .Call( paste0("solveQAfterQR", .getSuffix(MatrixA)), orientation, MatrixA@ptr,
         Matrixt@ptr, Matrixd@ptr, MatrixB@ptr, MatrixX@ptr )
}

RQ<-function( MatrixA, Matrixt, Matrixd ){
  .Call( paste0("rQ", .getSuffix(MatrixA)), MatrixA@ptr, Matrixt@ptr,
         Matrixd@ptr )
}

RQExplicitTriang<-function( MatrixA ){
  .Call( paste0("rQExplicitTriang", .getSuffix(MatrixA)), MatrixA@ptr )
}

ApplyQAfterRQ<-function( side, orientation, MatrixA, Matrixt, Matrixd,
                         MatrixB ){
  .Call( paste0("ApplyQAfterRQ", .getSuffix(MatrixA)), side, orientation,
         MatrixA@ptr, Matrixt@ptr, Matrixd@ptr, MatrixB@ptr)
}

SolveQAfterRQ<-function( orientation, MatrixA, Matrixt, Matrixd, MatrixB,
                        MatrixX ){
  .Call( paste0("solveQAfterRQ", .getSuffix(MatrixA)), orientation, MatrixA@ptr,
         Matrixt@ptr, Matrixd@ptr, MatrixB@ptr, MatrixX@ptr )
}

GQR<-function( MatrixA, MatrixtA, MatrixB, Matrixtb, MatrixdB){
  .Call( paste0("gQR", .getSuffix(MatrixA)), MatrixA@ptr, MatrixtA@ptr,
         MatrixB@ptr, Matrixtb@ptr, MatrixdB@ptr )
}

GQRExplicitTriang<-function( MatrixA, MatrixB ){
  .Call( paste0("gQRExplicitTriang", .getSuffix(MatrixA)), MatrixA@ptr,
         MatrixB@ptr )
}

GRQ<-function( MatrixA, MatrixtA, MatrixB, Matrixtb, MatrixdB){
  .Call( paste0("gRQ", .getSuffix(MatrixA)), MatrixA@ptr, MatrixtA@ptr,
         MatrixB@ptr, Matrixtb@ptr, MatrixdB@ptr )
}

GRQExplicitTriang<-function( MatrixA, MatrixB){
  .Call( paste0("gRQExplicitTriang", .getSuffix(MatrixA)), MatrixA@ptr,
         MatrixB@ptr )
}

###-----------
### Properties
###-----------

FrobeniusNorm<-function(MatrixA){
  .Call( paste0("frobeniusNorm", .getSuffix(MatrixA)), MatrixA@ptr)
}

SymmetricFrobeniusNorm<-function(uplo, MatrixA){
  .Call( paste0("symmetricFrobeniusNorm", .getSuffix(MatrixA)), uplo,
         MatrixA@ptr)
}

InfinityNorm<-function(MatrixA){
  .Call( paste0("infinityNorm", .getSuffix(MatrixA)), MatrixA@ptr)
}

SymmetricInfinityNorm<-function(uplo, MatrixA){
  .Call( paste0("symmetricInfinityNorm", .getSuffix(MatrixA)), uplo,
         MatrixA@ptr)
}

MaxNorm<-function(MatrixA){
  .Call( paste0("maxNorm", .getSuffix(MatrixA)), MatrixA@ptr)
}

###-----------------
### Matrix Functions
###-----------------

Inverse<-function(MatrixA){
  .Call( paste0("inverse", .getSuffix(MatrixA)), MatrixA@ptr)
}

InverseAfterLUPartialPiv<-function(MatrixA, Matrixp){
  .Call( paste0("inverseAfterLUPartialPiv", .getSuffix(MatrixA)), MatrixA@ptr,
         Matrixp@ptr)
}

HPDInverse<-function(uplo, MatrixA){
  .Call( paste0("hPDInverse", .getSuffix(MatrixA)), uplo, MatrixA@ptr)
}

HermitianInverse<-function(uplo, MatrixA){
  .Call( paste0("hermitianInverse", .getSuffix(MatrixA)), uplo, MatrixA@ptr)
}

SymmetricInverse<-function(uplo, MatrixA){
  .Call( paste0("symmetricInverse", .getSuffix(MatrixA)), uplo, MatrixA@ptr)
}

TriangularInverse<-function(uplo, unitDiag, MatrixA){
  .Call( paste0("triangularInverse", .getSuffix(MatrixA)), uplo,
         unitDiag, MatrixA@ptr)
}

Pseudoinverse<-function(MatrixA){
  .Call( paste0("pseudoInverse", .getSuffix(MatrixA)), MatrixA@ptr)
}

HermitianPseudoinverse<-function(uplo, MatrixA){
  .Call( paste0("hermitianPseudoinverse", .getSuffix(MatrixA)), uplo, MatrixA@ptr)
}

Sign<-function(MatrixA){
  .Call( paste0("sign", .getSuffix(MatrixA)), MatrixA@ptr)
}

SignDecomp<-function(MatrixA, MatrixN){
  .Call( paste0("signDecomp", .getSuffix(MatrixA)), MatrixA@ptr, MatrixN@ptr)
}

HermitianSign<-function(uplo, MatrixA){
  .Call( paste0("hermitianSign", .getSuffix(MatrixA)), uplo, MatrixA@ptr)
}

HermitianSignDecomp<-function(uplo, MatrixA, MatrixN){
  .Call( paste0("hermitianSignDecomp", .getSuffix(MatrixA)), uplo, MatrixA@ptr,
         MatrixN@ptr)
}

SquareRoot<-function(MatrixA){
  .Call( paste0("squareRoot", .getSuffix(MatrixA)), MatrixA@ptr)
}

HPSDSquareRoot<-function(uplo, MatrixA){
  .Call( paste0("hPSDSquareRoot", .getSuffix(MatrixA)), uplo, MatrixA@ptr)
}

###-------------
### Matrix Utils
###-------------

Median<-function(MatrixA){
  .Call( paste0("median", .getSuffix(MatrixA)), MatrixA@ptr)
}

Sort<-function(MatrixA, SortType){
  .Call( paste0("sort", .getSuffix(MatrixA)), MatrixA@ptr, SortType)
}

TaggedSort<-function(MatrixA, SortType){
  .Call( paste0("taggedSort", .getSuffix(MatrixA)), MatrixA@ptr, SortType)
}



#########################
### Optimization Routines
#########################

###---------------------
### Optimization: Models
###---------------------

BP<-function(MatrixA, Matrixb, Matrixx){
  .Call( paste0("bP", .getSuffix(MatrixA)), MattixA@ptr, Matrixb@ptr,
         Matrixx@ptr)
}

BPADMM<-function(MatrixA, Matrixb, Matrixz){
  .Call( paste0("bP", .getSuffix(MatrixA)), MattixA@ptr, Matrixb@ptr,
         Matrixz@ptr)
}

CP<-function(MatrixA, Matrixb, Matrixx){
  .Call( paste0("cP", .getSuffix(MatrixA)), MattixA@ptr, Matrixb@ptr,
         Matrixx@ptr)
}

DS<-function(MatrixA, Matrixb, lambda, Matrixx){
  .Call( paste0("dS", .getSuffix(MatrixA)), MattixA@ptr, Matrixb@ptr,
         lambda, Matrixx@ptr)
}

LAV<-function(MatrixA, Matrixb, Matrixx){
  .Call( paste0("lAV", .getSuffix(MatrixA)), MattixA@ptr, Matrixb@ptr,
         Matrixx@ptr)
}

LogisticRegression<-function(MatrixA, Matrixq, Matrixz, gamma, penalty){
  .Call( paste0("logisticRegression", .getSuffix(MatrixA)), MatrixA@ptr,
         Matrixq@ptr, Matrixz@ptr, gamma, penalty)
}

NMF<-function(MatrixA, MatrixX, MatrixY){
  .Call( paste0("nMF", .getSuffix(MatrixA)), MatrixA@ptr, MatrixX@ptr,
         MatrixY@ptr)
}

NNLS<-function(MatrixA, MatrixY, MatrixZ){
  .Call( paste0("nNLS", .getSuffix(MatrixA)), MatrixA@ptr, MatrixY@ptr,
         MatrixZ@ptr)
}

NNLSADMM<-function(MatrixA, MatrixY, MatrixZ){
  .Call( paste0("nNLSADMM", .getSuffix(MatrixA)), MatrixA@ptr, MatrixY@ptr,
         MatrixZ@ptr)
}

BPDN<-function(MatrixA, Matrixb, lambda, Matrixx){
  .Call( paste0("bPDN", .getSuffix(MatrixA)), MattixA@ptr, Matrixb@ptr,
         lambda, Matrixx@ptr)
}

BPDNADMM<-function(MatrixA, Matrixb, lambda, Matrixx){
  .Call( paste0("bPDNADMM", .getSuffix(MatrixA)), MattixA@ptr, Matrixb@ptr,
         lambda, Matrixx@ptr)
}

EN<-function(MatrixA, Matrixb, lambda1, lambda2, Matrixx){
  .Call( paste0("eN", .getSuffix(MatrixA)), MattixA@ptr, Matrixb@ptr,
         lambda1, lambda2, Matrixx@ptr)
}

RPCA<-function(MatrixA, MatrixL, MatrixS){
  .Call( paste0("rPCA", .getSuffix(MatrixA)), MatrixA@ptr, MatrixL@ptr,
         MatrixS@ptr)
}

SVM<-function(MatrixG, Matrixq, gamma, Matrixz){
  .Call( paste0("sVM", .getSuffix(MatrixG)), MatrixG@ptr, Matrixq@ptr,
         gamma, Matrixz@ptr)
}

SVMADMM<-function(MatrixG, Matrixq, gamma, Matrixz){
  .Call( paste0("sVMADMM", .getSuffix(MatrixG)), MatrixG@ptr, Matrixq@ptr,
         gamma, Matrixz@ptr)
}

TV<-function(Matrixb, lambda, Matrixx){
  .Call( paste0("tV", .getSuffix(Matrixb)), Matrixb@ptr, lambda, Matrixx@ptr)
}

### end optimodels

###---------------------
### Optimization Solvers
###---------------------


LPDirect<-function(MatrixA, Matrixb, Matrixc, Matrixx){
  .Call( paste0("lPDirect", .getSuffix(MatrixA)), MatrixA@ptr, Matrixb@ptr,
         Matrixz@ptr, Matrixx@ptr)
}

LPAffine<-function(MatrixA, MatrixG, Matrixb, Matrixc, Matrixh, Matrixx,
                   Matrixy, Matrixz, Matrixs){
  .Call( paste0("lPAffine", .getSuffix(MatrixA)), MatrixA@ptr, MatrixG@ptr,
         Matrixb@ptr, Matrixc@ptr, Matrixh@ptr, Matrixx@ptr, Matrixy@ptr,
         Matrixz@ptr, Matrixs@ptr)
}

QPDirect<-function(MatrixQ, MatrixA, Matrixb, Matrixc, Matrixx, Matrixy,
                   Matrixz){
  .Call( paste0("qPDirect", .getSuffix(MatrixA)), MatrixQ@ptr, MatrixA@ptr,
         Matrixb@ptr, Matrixc@ptr, Matrixx@ptr, Matrixy@ptr, Matrixz@ptr)
}

QPAffine<-function(MatrixQ, MatrixA, MatrixG, Matrixb, Matrixc, Matrixh,
                   Matrixx, Matrixy, Matrixz, Matrixs){
  .Call( paste0("qPAffine", .getSuffix(MatrixA)), MatrixQ@ptr, MatrixA@ptr,
         MatrixG@ptr, Matrixb@ptr, Matrixc@ptr, Matrixh@ptr, Matrixx@ptr,
         Matrixy@ptr, Matrixz@ptr, Matrixs@ptr)
}

###------------------
### Optimization Util
###------------------

Coherence<-function(MatrixA){
  .Call( paste0("coherence", .getSuffix(MatrixA)), MatrixA@ptr )
}

Covariance<-function(MatrixD, MatrixS){
  .Call( paste0("covariance", .getSuffix(MatrixD)), MatrixD@ptr, MatrixS@ptr )
}

LogBarrier<-function(uplo, MatrixA){
  .Call( paste0("logBarrier", .getSuffix(MatrixA)), uplo, MatrixA@ptr )
}

LogGetDiv<-function(uplo, MatrixA, MatrixB){
  .Call( paste0("logGetDiv", .getSuffix(MatrixA)), uplo, MatrixA, MatrixB )
}

###------------------
### Optimization prox
###------------------

LowerClip<-function(MatrixX, lowerbound){
  .Call( paste0("lowerClip", .getSuffix(MatrixX)), MatrixX@ptr, lowerbound)
}

UpperClip<-function(MatrixX, upperbound){
  .Call( paste0("upperClip", .getSuffix(MatrixX)), MatrixX@ptr, upperbound)
}

Clip<-function(MatrixX, lowerbound, upperbound){
  .Call( paste0("clip", .getSuffix(MatrixX)), MatrixX@ptr, lowerbound,
         upperbound)
}

FrobeniusProx<-function(MatrixA, rho){
  .Call( paste0("frobeniusProx", .getSuffix(MatrixA)), MatrixA@ptr, rho )
}

HingeLossProx<-function(MatrixA, rho){
  .Call( paste0("hingeLossProx", .getSuffix(MatrixA)), MatrixA@ptr, rho )
}

LogisticProx<-function(MatrixA, rho){
  .Call( paste0("logisticProx", .getSuffix(MatrixA)), MatrixA@ptr, rho )
}

SVT<-function(MatrixA, rho, relative){
  .Call( paste0("sVT", .getSuffix(MatrixA)), MatrixA@ptr, rho, as.logical(relative) )
}

SoftThreshold<-function(MatrixA, rho, relative){
  .Call( paste0("softThreshold", .getSuffix(MatrixA)), MatrixA@ptr, rho,
         as.logical(relative) )
}


#################
### I/O functions
#################

Print<-function(MatrixA,Title=""){
  .Call( paste0("print", .getSuffix(MatrixA)), MatrixA@ptr, as.character(Title) )
}

Display<-function(MatrixA, Title=""){
  .Call( paste0("display", .getSuffix(MatrixA)), MatrixA@ptr, as.character(Title) )
}

Read<-function(MatrixA, filename, format="ASCII", doSequential=FALSE){
  if(.isDistMatrix(MatrixA)==TRUE){
    .Call( paste0("read", .getSuffix(MatrixA)), MatrixA@ptr, as.character(filename),
          as.character(format), doSequential )
  }
  else{
    .Call( paste0("read", .getSuffix(MatrixA)), MatrixA@ptr, as.character(filename),
          as.character(format) )
  }
}

Write<-function(MatrixA, basename, format, title){
  .Call( paste0("write", .getSuffix(MatrixA)), MatrixA@ptr, as.character(basename),
        as.character(format), as.character(title) )
}

#####################
### Data Input R-Like
#####################


read.matrix<-function(file, tag="d"){
  ans<-Matrix(tag)
  Read(ans, file)
  ans
}

read.dmatrix<-function(file, tag="d"){
  ans<-DistMatrix(tag)
  Read(ans, file)
  ans
}

########################
### Conversion Functions
########################

ToR<-function(MatrixA){
  matrix( .Call( paste0("toR", .getSuffix(MatrixA) ), MatrixA@ptr),
          MatrixHeight(MatrixA), MatrixWidth(MatrixA) )
}

ToEl<-function(MatrixA){
  if(is.complex(MatrixA)){
    mtag="z"
  }else{
    if(is.integer(MatrixA)){
      mtag="i"
    }else{
      if(is.numeric(MatrixA)){
        mtag="d"
      }else{
        stop("Please provide a valid R Matrix")
      }
    }
  }
  Matrix(tag=mtag, rmat=MatrixA)
}

ToElDist<-function(MatrixA){
  if(is.complex(MatrixA)){
    mtag="z"
  }else{
    if(is.integer(MatrixA)){
      mtag="i"
    }else{
      if(is.numeric(MatrixA)){
        mtag="d"
      }else{
        stop("Please provide a valid R Matrix")
      }
    }
  }
  DistMatrix(tag=mtag, rmat=MatrixA)
}

####################################
### Attaching the methods to objects
####################################

GridFunctions=list(
  'Row'   = GridRow,   
  'Col'   = GridCol,  
  'Rank'  = GridRank,  
  'Height'= GridHeight,
  'Width' = GridWidth, 
  'Size'  = GridSize,
  'MCRank'= GridMCRank,
  'MRRank'= GridMRRank,
  'VCRank'= GridVCRank,
  'VRRank'= GridVRRank,
  'MCSize'= GridMCSize,
  'MRSize'= GridMRSize,
  'VCSize'= GridVCSize,
  'VRSize'= GridVRSize
  )

setMethod("$", "ElGrid",
          function(x, name){
            id <- pmatch(name, names(GridFunctions))
            if (is.na(id) ){
              cat(paste("function",name,"not found\n") )
            }else{
              routine <- GridFunctions[[id]]
              function(...){
                routine(x, ...)
              }
            }
          })

MatrixFunctions=list(
  'Destroy' = MatrixDestroy,
  'Get'     = MatrixGet,
  'Set'     = MatrixSet,
  'Update'  = MatrixUpdate,
  'Height'  = MatrixHeight,
  'Width'   = MatrixWidth,
  'LDim'    = MatrixLDim,
  'Empty'   = MatrixEmpty,
  'Resize'  = MatrixResize,
  'ResizeLDim'     = MatrixResizeLDim,
  'DiagonalLength' = MatrixDiagonalLength,
  'Viewing'        = MatrixViewing,
  'Locked'         = MatrixLocked,

  'Attach'         = MatrixAttach,
  'LockedAttach'   = MatrixLockedAttach,
 
  'Print' = Print,

  'ToR' = ToR
  )

  setMethod("$","ElMatrix",
            function(x, name){
              id <- pmatch(name, names(MatrixFunctions))
              if (is.na(id) ){
                cat(paste("function",name,"not found\n") )
              }else{
                routine <- MatrixFunctions[[id]]
                function(...){
                  routine(x, ...)
                }
              }
            })


DistMatrixFunctions=list(
  'Destroy' = MatrixDestroy,
  'Get'     = MatrixGet,
  'Set'     = MatrixSet,
  'Update'  = MatrixUpdate,
  'Height'  = MatrixHeight,
  'Width'   = MatrixWidth,
  'LDim'    = MatrixLDim,
  'Empty'   = MatrixEmpty,
  'Resize'  = MatrixResize,
  'ResizeLDim'     = MatrixResizeLDim,
  'DiagonalLength' = MatrixDiagonalLength,
  'Viewing'        = MatrixViewing,
  'Locked'         = MatrixLocked,

  'SetGrid'        = DistMatrixSetGrid,
  'Grid'           = DistMatrixGrid, 
  'SetRoot'        = DistMatrixSetRoot,
  'Attach'         = DistMatrixAttach,
  'LockedAttach'   = DistMatrixLockedAttach,
  'ToMatrix'       = DistMatrixToMatrix,
  'ToLockedMatrix' = DistMatrixToLockedMatrix,
  'LocalWidth'     = DistMatrixLocalWidth,
  'LocalHeight'    = DistMatrixLocalHeight,
  'SetLocal'       = DistMatrixSetLocal,
  'GetLocal'       = DistMatrixGetLocal,
  'DistComm'       = DistMatrixDistComm,  
  'Print' = Print
  )

setMethod("$",signature(x="ElDistMatrix"),
          function(x, name){
            id <- pmatch(name, names(DistMatrixFunctions))
            if (is.na(id) ){
              stop(paste("function",name,"not found\n") )
            }
            
            routine <- DistMatrixFunctions[[id]]
            function(...){
              routine(x, ...)
            }
          })
