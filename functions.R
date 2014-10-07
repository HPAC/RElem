libraryName ="pureElemental.so"


#-----------------
#Load the library
#-----------------


if ( is.loaded(libraryName) )
  dyn.unload(libraryName)
dyn.load(libraryName)

#--------------
# Aux functions
#--------------

getSuffix<-function(element){
  woUnderscore<-strsplit(class(element),"_")
  ifelse (woUnderscore[[1]][1]=="ElDistMatrix",
          paste0("Dist_",woUnderscore[[1]][2]),
          ifelse (woUnderscore[[1]][1]=="ElMatrix",
                  paste0("_",woUnderscore[[1]][2]),
                  paste0("Function_Not_Defined_For_This_Arg")
                  )
          )
}

getElement<-function(element){
  woUnderscore<-strsplit(class(element),"_")
  ifelse (woUnderscore[[1]][1]=="ElDistMatrix",
          paste0("DistMatrix_",woUnderscore[[1]][2]),
          ifelse (woUnderscore[[1]][1]=="ElMatrix",
                  paste0("Matrix_",woUnderscore[[1]][2]),
                  paste0("Function_Not_Defined_For_This_Arg")
                  )
          )
}


getType<-function(MatrixA){
  woUnderscore<-strsplit(class(MatrixA),"_")
  woUnderscore[[1]][2]
}

isDistMatrix<-function(MatrixA){
  woUnderscore<-strsplit(class(MatrixA),"_")
  ifelse (woUnderscore[[1]][1]=="ElDistMatrix",TRUE,FALSE)
}

#----------------------------
# MPI & Environment Functions
#----------------------------
Initialized<-function(){
  .Call("initialized")
}

Initialize<-function(){
  .Call("initialize")
}
Finalize<-function(){
  if( Initialized() )
    .Call("finalize")
  else
    cat("Not initialized\n");
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

#------
# Grids
#------
Grid<-function(){
  if ( Initialized() ){
    .Call("newGrid")
  }
  else{
    cat("To use grids, MPI/Elemental must be Initialized\n")
  }
}

GridRow<-function(Grid){
  .Call("gridRow", Grid)
}

GridCol<-function(Grid){
  .Call("gridCol", Grid)
}

GridRank<-function(Grid){
  .Call("gridRank", Grid)
}

GridHeight<-function(Grid){
  .Call("gridHeight", Grid)
}

GridWidth<-function(Grid){
  .Call("gridWidth", Grid)
}

GridSize<-function(Grid){
  .Call("gridSize", Grid)
}

GridMCRank<-function(Grid){
  .Call("gridMCRank", Grid)
}

GridMRRank<-function(Grid){
  .Call("gridMRRank", Grid)
}

GridVCRank<-function(Grid){
  .Call("gridVCRank", Grid)
}

GridVRRank<-function(Grid){
  .Call("gridVRRank", Grid)
}

GridMCSize<-function(Grid){
  .Call("gridMCSize", Grid)
}

GridMRSize<-function(Grid){
  .Call("gridMRSize", Grid)
}

GridVCSize<-function(Grid){
  .Call("gridVCSize", Grid)
}

GridVRSize<-function(Grid){
  .Call("gridVRSize", Grid)
}




#--------------------
# Sequential Matrices
#--------------------

Matrix<-function(dataType="d"){
  ans<-.Call( paste0("newMatrix_",dataType) )
  reg.finalizer(ans, MatrixDestroy)
  ans
}

MatrixCopy<-function(MatrixFrom, MatrixTo){
  .Call( paste0("copy", getElement(MatrixFrom)), MatrixFrom, MatrixTo )
}

MatrixAttach<-function(MatrixA, height, width, buffer, ldim){
  .Call( paste0("attach", getElement(MatrixA)), MatrixA, as.integer(height),
         as.integer(width), buffer, as.integer(ldim) )
}

MatrixLockedAttach<-function(MatrixA, height, width, buffer, ldim){
  .Call( paste0("lockedAttach", getElement(MatrixA)), MatrixA, as.integer(height),
         as.integer(width), buffer, as.integer(ldim) )
}



#---------------------
# Distributed Matrices
#---------------------

DistMatrix<-function(Grid, dataType="d"){
  ans<-.Call( paste0("newDistMatrix_",dataType), Grid, dataType )
  reg.finalizer(ans, MatrixDestroy)
  ans

}

DistMatrixSpecific<-function(ColDist, RowDist, Grid, dataType="d"){
  ans<-.Call( paste0("newDistMatrixSpecific_", dataType), as.character(ColDist),
         as.character(RowDist), Grid )
  reg.finalizer(ans, MatrixDestroy)
  ans
}

ShowDistData<-function(DistMatrixA){
  .Call( paste0("showDistData_", getType(DistMatrixA)), DistMatrixA)
}

DistMatrixSetGrid<-function(DistMatrixA, GridG){
  .Call( paste0("setGridDistMatrix_", getType(DistMatrixA)), DistMatrixA,
         GridG )
}

DistMatrixGrid<-function(DistMatrixA, GridG){
  .Call( paste0("gridDistMatrix_", getType(DistMatrixA)), DistMatrixA,
         GridG )
}


DistMatrixsetRoot<-function(DistMatrixA, Root){
  .Call( paste0("setRootDistMatrix_", getType(DistMatrixA)), DistMatrixA,
         as.integer(Root) )
}

DistMatrixAttach<-function(DistMatrixA, heigth, width, grid, colAlign, rowAlign,
                           buffer, ldim, root){
  .Call( paste0("attachDistMatrix_", getType(DistMatrixA)), DistMatrixA, heigth,
         width, grid, colAlign, rowAlign, buffer, ldim, root )
}

DistMatrixLockedAttach<-function(DistMatrixA, heigth, width, grid, colAlign,
                                 rowAlign, buffer, ldim, root){
  .Call( paste0("lockedAttachDistMatrix_", getType(DistMatrixA)), DistMatrixA,
         heigth, width, grid, colAlign, rowAlign, buffer, ldim, root )
}

DistMatrixToMatrix<-function(DistMatrixA, MatrixA){
  .Call( paste0("matrixDistMatrix_", getType(DistMatrixA)), DistMatrixA,
         MatrixA )
}

DistMatrixToLockedMatrix<-function(DistMatrixA, MatrixA){
  .Call( paste0("lockedMatrixDistMatrix_", getType(DistMatrixA)), DistMatrixA,
         MatrixA )
}

#-------------------------
# Common Matrix Properties
#-------------------------

MatrixDestroy<-function(MatrixA){
  .Call( paste0("destroy", getElement(MatrixA)), MatrixA )
}


MatrixGet<-function(MatrixA, i, j){
  .Call( paste0("get", getElement(MatrixA)), MatrixA,
         as.integer(i),as.integer(j) )
} 

MatrixSet<-function(MatrixA, i, j, alpha){
  .Call( paste0("set", getElement(MatrixA)), MatrixA,
         as.integer(i),as.integer(j),as.double(alpha) )
} 

MatrixUpdate<-function(MatrixA, i, j, alpha){
  .Call( paste0("update", getElement(MatrixA)), MatrixA,
         as.integer(i),as.integer(j),as.double(alpha) )
} 

MatrixHeight<-function(MatrixA){
  .Call( paste0("height", getElement(MatrixA)), MatrixA )
}

MatrixWidth<-function(MatrixA){
  .Call( paste0("width", getElement(MatrixA)), MatrixA )
}

MatrixLDim<-function(MatrixA){
  .Call( paste0("ldim", getElement(MatrixA)), MatrixA )
}


MatrixEmpty<-function(MatrixA){
  .Call( paste0("empty", getElement(MatrixA)), MatrixA )
}

MatrixResize<-function(MatrixA, height, width){
  .Call( paste0("resize", getElement(MatrixA)), MatrixA, as.integer(height),
         as.integer(width) )
}

MatrixResizeLDim<-function(MatrixA, height, width, ldim){
  .Call( paste0("resize", getElement(MatrixA)), MatrixA, as.integer(height),
         as.integer(width), as.integer(ldim) )
}

MatrixDiagonalLength<-function(MatrixA){
  .Call( paste0("diagonalLength", getElement(MatrixA)), MatrixA )
}

MatrixViewing<-function(MAtrixA){
  .Call( paste0("viewing", getElement(MatrixA)), MatrixA )
}

MatrixLocked<-function(MAtrixA){
  .Call( paste0("locked", getElement(MatrixA)), MatrixA )
}

MatrixGetDiagonal<-function(MatrixA, offset, MatrixD){
  .Call( paste0("getDiagonal", getElement(MatrixA)), MatrixA, as.integer(offset),
         as.integer(MatrixD) )
}

MatrixSetDiagonal<-function(MatrixA, MatrixD, offset){
  .Call( paste0("setDiagonal", getElement(MatrixA)), MatrixA, MatrixD,
         as.integer(offset) )
}



#attach and locked attach are different



#-------------
# Matrix Views
#-------------

#A is a view of B
View<-function(MatrixA, MatrixB, fromi, toi, fromj, toj){
  .Call( paste0("view", getSuffix(MatrixA)), MatrixA, MatrixB,
         as.integer(fromi), as.integer(toi),
         as.integer(fromj), as.integer(toj) )
}

LockedView<-function(MatrixA, MatrixB, fromi, toi, fromj, toj){
  .Call( paste0("lockedView", getSuffix(MatrixA)), MatrixA, MatrixB,
         as.integer(fromi), as.integer(toi),
         as.integer(fromj), as.integer(toj) )
}

ViewOffset<-function(MatrixA, MatrixB, i, j, height, width){
  .Call( paste0("viewOffset", getSuffix(MatrixA)), MatrixA, MatrixB,
         as.integer(i), as.integer(j), as.integer(height), as.integer(width) )
}

LockedViewOffset<-function(MatrixA, MatrixB, i, j, height, width){
  .Call( paste0("lockedViewOffset", getSuffix(MatrixA)), MatrixA, MatrixB,
         as.integer(i), as.integer(j), as.integer(height), as.integer(width) )
}

ViewFull<-function(MatrixA, MatrixB){
  .Call( paste0("viewFull", getSuffix(MatrixA)), MatrixA, MatrixB )
}

LockedViewFull<-function(MatrixA, MatrixB){
  .Call( paste0("lockedViewFull", getSuffix(MatrixA)), MatrixA, MatrixB )
}

#-----------
# Partitions
#-----------

PartitionDown<-function(MatrixA, MatrixAT, MatrixAB, heightAT){
  .Call( paste0("partitionDown", getSuffix(MatrixA)), MatrixA, MatrixAT,
         MatrixAB, as.integer(heightAT) )
}

LockedPartitionDown<-function(MatrixA, MatrixAT, MatrixAB, heightAT){
  .Call( paste0("lockedPartitionDown", getSuffix(MatrixA)), MatrixA, MatrixAT,
         MatrixAB, as.integer(heightAT) )
}

PartitionUp<-function(MatrixA, MatrixAT, MatrixAB, heightAT){
  .Call( paste0("partitionUp", getSuffix(MatrixA)), MatrixA, MatrixAT,
         MatrixAB, as.integer(heightAB) )
}

LockedPartitionUp<-function(MatrixA, MatrixAT, MatrixAB, heightAT){
  .Call( paste0("lockedPartitionUp", getSuffix(MatrixA)), MatrixA, MatrixAT,
         MatrixAB, as.integer(heightAB) )
}

PartitionLeft<-function(MatrixA, MatrixAL, MatrixAR, widthAR){
  .Call( paste0("partitionLeft", getSuffix(MatrixA)), MatrixA, MatrixAL,
         MatrixAR, as.integer(widthAR) )
}

LockedPartitionLeft<-function(MatrixA, MatrixAL, MatrixAR, widthAR){
  .Call( paste0("lockedPartitionLeft", getSuffix(MatrixA)), MatrixA, MatrixAL,
         MatrixAR, as.integer(widthAR) )
}

PartitionRight<-function(MatrixA, MatrixAL, MatrixAR, widthAL){
  .Call( paste0("partitionRight", getSuffix(MatrixA)), MatrixA, MatrixAL,
         MatrixAR, as.integer(widthAL) )
}

LockedPartitionRight<-function(MatrixA, MatrixAL, MatrixAR, widthAL){
  .Call( paste0("lockedPartitionRight", getSuffix(MatrixA)), MatrixA, MatrixAL,
         MatrixAR, as.integer(widthAL) )
}

PartitionDownDiagonal<-function( MatrixA, MatrixATL, MatrixATR,
                                 MatrixABL, MatrixABR, diagDist ){
  .Call( paste0("partitionDownDiagonal", getSuffix(MatrixA)), MatrixA,
         MatrixATL, MatrixATR, MatrixABL, MatrixABR, as.integer(diagDist) )
}

LockedPartitionDownDiagonal<-function( MatrixA, MatrixATL, MatrixATR,
                                       MatrixABL, MatrixABR, diagDist ){
  .Call( paste0("lockedPartitionDownDiagonal", getSuffix(MatrixA)), MatrixA,
         MatrixATL, MatrixATR, MatrixABL, MatrixABR, as.integer(diagDist) )
}

PartitionDownOffsetDiagonal<-function( offset,
                                       MatrixA, MatrixATL, MatrixATR,
                                       MatrixABL, MatrixABR, diagDist ){
  .Call( paste0("partitionDownOffsetDiagonal", getSuffix(MatrixA)), offset,
         MatrixA, MatrixATL, MatrixATR, MatrixABL, MatrixABR,
         as.integer(diagDist) )
}

LockedPartitionDownOffsetDiagonal<-function( offset,
                                             MatrixA, MatrixATL, MatrixATR,
                                             MatrixABL, MatrixABR, diagDist ){
  .Call( paste0("lockedPartitionDownOffsetDiagonal", getSuffix(MatrixA)), offset,
         MatrixA, MatrixATL, MatrixATR, MatrixABL, MatrixABR,
         as.integer(diagDist) )
}


PartitionUpDiagonal<-function( MatrixA, MatrixATL, MatrixATR,
                               MatrixABL, MatrixABR, diagDist ){
  .Call( paste0("partitionUpDiagonal", getSuffix(MatrixA)), MatrixA,
         MatrixATL, MatrixATR, MatrixABL, MatrixABR, as.integer(diagDist) )
}

LockedPartitionUpDiagonal<-function( MatrixA, MatrixATL, MatrixATR,
                                     MatrixABL, MatrixABR, diagDist ){
  .Call( paste0("lockedPartitionUpDiagonal", getSuffix(MatrixA)), MatrixA,
         MatrixATL, MatrixATR, MatrixABL, MatrixABR, as.integer(diagDist) )
}

PartitionUpOffsetDiagonal<-function( offset,
                                     MatrixA, MatrixATL, MatrixATR,
                                     MatrixABL, MatrixABR, diagDist ){
  .Call( paste0("partitionUpOffsetDiagonal", getSuffix(MatrixA)), offset,
         MatrixA, MatrixATL, MatrixATR, MatrixABL, MatrixABR,
         as.integer(diagDist) )
}

LockedPartitionUpOffsetDiagonal<-function( offset,
                                           MatrixA, MatrixATL, MatrixATR,
                                           MatrixABL, MatrixABR, diagDist ){
  .Call( paste0("lockedPartitionUpOffsetDiagonal", getSuffix(MatrixA)), offset,
         MatrixA, MatrixATL, MatrixATR, MatrixABL, MatrixABR,
         as.integer(diagDist) )
}

#------------
# Repartition
#------------

#----------------
# Slide Partition
#----------------

#------
# Merge
#------

Merge1x2<-function( MatrixA, MatrixBL, MatrixBR){
  .Call( paste0("merge1x2", getSuffix(MatrixA)), MatrixA,
         MatrixBL, MatrixBR )
}

LockedMerge1x2<-function( MatrixA, MatrixBL, MatrixBR){
  .Call( paste0("lockedMerge1x2", getSuffix(MatrixA)), MatrixA,
         MatrixBL, MatrixBR )
}

Merge2x1<-function( MatrixA, MatrixBT, MatrixBB){
  .Call( paste0("merge2x1", getSuffix(MatrixA)), MatrixA,
         MatrixBT, MatrixBB )
}

LockedMerge2x1<-function( MatrixA, MatrixBT, MatrixBB){
  .Call( paste0("lockedMerge2x1", getSuffix(MatrixA)), MatrixA,
         MatrixBT, MatrixBB )
}

Merge2x2<-function( MatrixA, MatrixBTL, MatrixBTR, MatrixBBL, MatrixBBR){
  .Call( paste0("merge2x1", getSuffix(MatrixA)), MatrixA, MatrixBTL,
         MatrixBTR, MatrixBBL, MatrixBBR)
}

LockedMerge2x2<-function( MatrixA, MatrixBTL, MatrixBTR, MatrixBBL, MatrixBBR){
  .Call( paste0("lockedMerge2x1", getSuffix(MatrixA)), MatrixA, MatrixBTL,
         MatrixBTR, MatrixBBL, MatrixBBR)
}



#------------------
# Matrix generators
#------------------

Demmel<-function(MatrixA, n){
  .Call( paste0("demmel", getSuffix(MatrixA)), MatrixA, as.integer(n) )
}

Diagonal<-function(MatrixA, dSize, buffer){
  .Call( paste0("diagonal", getSuffix(MatrixA)), MatrixA, as.integer(dSize),
         buffer )
}

HermitianUniformSpectrum<-function(MatrixA, n, lower, upper){
  .Call( paste0("hermitianUniformSpectrum", getSuffix(MatrixA)), MatrixA,
         as.integer(n), lower, upper)
}

Hilbert<-function(MatrixA, n){
  .Call( paste0("hilbert", getSuffix(MatrixA)), MatrixA, as.integer(n) )
}

Uniform<-function(MatrixA, rows, cols, center=0.0, radius=1.0){
  .Call( paste0("uniform", getSuffix(MatrixA)), MatrixA, as.integer(rows),
         as.integer(cols), center, radius )
}

Identity<-function(MatrixA, rows, cols){
  .Call( paste0("identity", getSuffix(MatrixA)), MatrixA, as.integer(rows),
         as.integer(cols))
}

Jordan<-function(MatrixA, n, lambda){
  .Call( paste0("jordan", getSuffix(MatrixA)), MatrixA, as.integer(n), lambda )
}

Kahan<-function(MatrixA, n, phi){
  .Call( paste0("kahan", getSuffix(MatrixA)), MatrixA, as.integer(n), phi )
}

KMS<-function(MatrixA, n, rho){
  .Call( paste0("kahan", getSuffix(MatrixA)), MatrixA, as.integer(n), rho )
}

Laplacian1D<-function(MatrixA, nx){
  .Call( paste0("laplacian1D", getSuffix(MatrixA)), MatrixA, as.integer(nx) )
}

Laplacian2D<-function(MatrixA, nx, ny){
  .Call( paste0("laplacian2D", getSuffix(MatrixA)), MatrixA, as.integer(nx),
         as.integer(ny) )
}

Laplacian3D<-function(MatrixA, nx, ny, nz){
  .Call( paste0("laplacian3D", getSuffix(MatrixA)), MatrixA, as.integer(nx),
         as.integer(ny), as.integer(nz) )
}

Lauchli<-function(MatrixA, n, mu){
  .Call( paste0("lauchli", getSuffix(MatrixA)), MatrixA, as.integer(n), mu )
}

Legendre<-function(MatrixA, n){
  .Call( paste0("legendre", getSuffix(MatrixA)), MatrixA, as.integer(n) )
}

Lehmer<-function(MatrixA, n){
  .Call( paste0("lehmer", getSuffix(MatrixA)), MatrixA, as.integer(n) )
}

Lotkin<-function(MatrixA, n){
  .Call( paste0("lotkin", getSuffix(MatrixA)), MatrixA, as.integer(n) )
}

MinIJ<-function(MatrixA, n){
  .Call( paste0("minIJ", getSuffix(MatrixA)), MatrixA, as.integer(n) )
}

Ones<-function(MatrixA, rows, cols){
  .Call( paste0("ones", getSuffix(MatrixA)), MatrixA, as.integer(rows),
         as.integer(cols))
}

OneTwoOne<-function(MatrixA, n){
  .Call( paste0("oneTwoOne", getSuffix(MatrixA)), MatrixA, as.integer(n) )
}

Parter<-function(MatrixA, n){
  .Call( paste0("parter", getSuffix(MatrixA)), MatrixA, as.integer(n) )
}

Pei<-function(MatrixA, n, alpha){
  .Call( paste0("pei", getSuffix(MatrixA)), MatrixA, as.integer(n), alpha )
}

Parter<-function(MatrixA, n){
  .Call( paste0("parter", getSuffix(MatrixA)), MatrixA, as.integer(n) )
}

Riffle<-function(MatrixA, n){
  .Call( paste0("riffle", getSuffix(MatrixA)), MatrixA, as.integer(n) )
}

RiffleStationary<-function(MatrixA, n){
  .Call( paste0("riffleStationary", getSuffix(MatrixA)), MatrixA,
         as.integer(n) )
}

RiffleDecay<-function(MatrixA, n){
  .Call( paste0("riffleDecay", getSuffix(MatrixA)), MatrixA, as.integer(n) )
}

Ris<-function(MatrixA, n){
  .Call( paste0("ris", getSuffix(MatrixA)), MatrixA, as.integer(n) )
}

Triangle<-function(MatrixA, n){
  .Call( paste0("triangle", getSuffix(MatrixA)), MatrixA, as.integer(n) )
}

TriW<-function(MatrixA, n, alpha, k){
  .Call( paste0("triW", getSuffix(MatrixA)), MatrixA, as.integer(n), alpha,
         as.integer(k) )
}

Walsh<-function(MatrixA, n, binary){
  .Call( paste0("walsh", getSuffix(MatrixA)), MatrixA, as.integer(n),
         as.logical(binary) )
}

Whale<-function(MatrixA, n){
  .Call( paste0("whale", getSuffix(MatrixA)), MatrixA, as.integer(n) )
}

Wigner<-function(MatrixA, n, mean, stddev){
  .Call( paste0("wigner", getSuffix(MatrixA)), MatrixA, as.integer(n), mean,
         stddev)
}

Wilkinson<-function(MatrixA, k){
  .Call( paste0("wilkinson", getSuffix(MatrixA)), MatrixA, as.integer(k) )
}

Zeros<-function(MatrixA, rows, cols){
  .Call( paste0("zeros", getSuffix(MatrixA)), MatrixA, as.integer(rows),
         as.integer(cols))
}

#-------------
# Blas Level 1
#-------------

Axpy<-function(alpha, MatrixX, MatrixY){
  .Call( paste0("axpy", getSuffix(MatrixX)), alpha, MatrixX, MatrixY)
}

AxpyTriangle<-function(uplo, alpha, MatrixX, MatrixY){
  .Call( paste0("axpyTriangle", getSuffix(MatrixX)), uplo, alpha, MatrixX,
         MatrixY)
}

Copy<-function(MatrixA, MatrixB){
  .Call( paste0("copy", getSuffix(MatrixA)), MatrixA, MatrixB )
}

DiagonalScale<-function(side, Matrixd, MatrixX){
  .Call( paste0("diagonalScale", getSuffix(MatrixX)), side, Matrixd, MatrixX)
}

DiagonalScaleTrapezoid<-function(side, uplo, Matrixd, MatrixX, offset){
  .Call( paste0("diagonalScaleTrapezoid", getSuffix(MatrixX)), side, uplo,
         Matrixd, MatrixX, as.integer(offset) )
}

Dot<-function(MatrixA, MatrixB){
  .Call( paste0("dot", getSuffix(MatrixA)), MatrixA, MatrixB )
}

Dotu<-function(MatrixA, MatrixB){
  .Call( paste0("dotu", getSuffix(MatrixA)), MatrixA, MatrixB )
}

Fill<-function(MatrixA, alpha){
  .Call( paste0("fill", getSuffix(MatrixA)), MatrixA, alpha )
}

Hadamard<-function(MatrixA, MatrixB, MatrixC){
  .Call( paste0("hadamard", getSuffix(MatrixA)), MatrixA, MatrixB, MatrixC )
}

HilbertSchmidt<-function(MatrixA, MatrixB){
  .Call( paste0("hilbertSchmidt", getSuffix(MatrixA)), MatrixA, MatrixB )
}

MakeSymmetric<-function(uplo, MatrixA){
  .Call( paste0("makeSymmetric", getSuffix(MatrixA)), uplo, MatrixA )
}

MakeTrapezoidal<-function(uplo, MatrixA, offset){
  .Call( paste0("makeTrapezoidal", getSuffix(MatrixA)), uplo, MatrixA,
         as.integer(offset) )
}

MakeTriangular<-function(uplo, MatrixA){
  .Call( paste0("makeTriangular", getSuffix(MatrixA)), uplo, MatrixA )
}

Max<-function(MatrixA){
  .Call( paste0("max", getSuffix(MatrixA)), MatrixA )
}

SymmetricMax<-function(uplo, MatrixA){
  .Call( paste0("symmetricMax", getSuffix(MatrixA)), uplo, MatrixA )
}

VectorMax<-function(MatrixA){
  .Call( paste0("vectorMax", getSuffix(MatrixA)), MatrixA )
}

MaxAbs<-function(MatrixA){
  .Call( paste0("maxAbs", getSuffix(MatrixA)), MatrixA )
}

SymmetricMaxAbs<-function(uplo, MatrixA){
  .Call( paste0("symmetricMaxAbs", getSuffix(MatrixA)), uplo, MatrixA )
}

VectorMaxAbs<-function(MatrixA){
  .Call( paste0("vectorMaxAbs", getSuffix(MatrixA)), MatrixA )
}

Min<-function(MatrixA){
  .Call( paste0("min", getSuffix(MatrixA)), MatrixA )
}

SymmetricMin<-function(uplo, MatrixA){
  .Call( paste0("symmetricMin", getSuffix(MatrixA)), uplo, MatrixA )
}

VectorMin<-function(MatrixA){
  .Call( paste0("vectorMin", getSuffix(MatrixA)), MatrixA )
}

MinAbs<-function(MatrixA){
  .Call( paste0("minAbs", getSuffix(MatrixA)), MatrixA )
}

SymmetricMinAbs<-function(uplo, MatrixA){
  .Call( paste0("symmetricMinAbs", getSuffix(MatrixA)), uplo, MatrixA )
}

VectorMinAbs<-function(MatrixA){
  .Call( paste0("vectorMinAbs", getSuffix(MatrixA)), MatrixA )
}

SymmetricMax<-function(uplo, MatrixA){
  .Call( paste0("symmetricMax", getSuffix(MatrixA)), uplo, MatrixA )
}

VectorMax<-function(MatrixA){
  .Call( paste0("vectorMax", getSuffix(MatrixA)), MatrixA )
}

MaxAbs<-function(MatrixA){
  .Call( paste0("maxAbs", getSuffix(MatrixA)), MatrixA )
}

SymmetricMaxAbs<-function(uplo, MatrixA){
  .Call( paste0("symmetricMaxAbs", getSuffix(MatrixA)), uplo, MatrixA )
}

Nrm2<-function(MatrixA){
  .Call( paste0("nrm2", getSuffix(MatrixA)), MatrixA )
}

Scale<-function(alpha, MatrixA){
  .Call( paste0("scale", getSuffix(MatrixA)), alpha, MatrixA )
}

ScaleTrapezoid<-function(alpha, uplo, MatrixA, offset){
  .Call( paste0("scaleTrapezoid", getSuffix(MatrixA)), alpha, uplo, MatrixA,
         as.integer(offset) )
}

SetDiagonal<-function(MatrixA, alpha, offset){
  .Call( paste0("setDiagonal", getSuffix(MatrixA)), MatrixA, alpha,
         as.integer(offset) )
}

Swap<-function(orientation, MatrixX, MatrixY){
  .Call( paste0("swap", getSuffix(MatrixX)), orientation, MatrixX, MatrixY )
}

RowSwap<-function(MatrixA, to, from){
  .Call( paste0("rowSwap", getSuffix(MatrixA)), MatrixA, as.integer(to),
         as.integer(from) )
}

ColSwap<-function(MatrixA, to, from){
  .Call( paste0("colSwap", getSuffix(MatrixA)), MatrixA, as.integer(to),
         as.integer(from) )
}

SymmetricSwap<-function(uplo, MatrixA, to, from){
  .Call( paste0("symmetricSwap", getSuffix(MatrixA)), uplo, MatrixA,
         as.integer(to), as.integer(from) )
}

Transpose<-function(MatrixA, MatrixB){
  .Call( paste0("transpose", getSuffix(MatrixA)), MatrixA, MatrixB )
}

UpdateDiagonal<-function(MatrixA, alpha, offset){
  .Call( paste0("updateDiagonal", getSuffix(MatrixA)), MatrixA, alpha,
         as.integer(offset) )
}

#-------------
# Blas Level 2
#-------------

Gemv<-function( orientationA="NORMAL", alpha, MatrixA, Matrixx, beta, Matrixy){
  .Call( paste0("gemv", getSuffix(MatrixA)), orientationA, alpha, MatrixA,
         Matrixx, beta, Matrixy )
}

Ger<-function( alpha, Matrixx, Matrixy, MatrixA){
  .Call( paste0("ger", getSuffix(MatrixA)), alpha, Matrixx, Matrixy, MatrixA )
}

QuasiTrsv<-function( uplo, orientation, MatrixA, Matrixx){
  .Call( paste0("quasiTrsv", getSuffix(MatrixA)), uplo, orientation, MatrixA,
         Matrixx)
}

Symv<-function( uplo, alpha, MatrixA, Matrixx, beta, Matrixy){
  .Call( paste0("symv", getSuffix(MatrixA)), uplo, alpha, MatrixA, Matrixx,
         beta, Matrixy )
}

Syr<-function( uplo, alpha, Matrixx, MatrixA){
  .Call( paste0("syr", getSuffix(MatrixA)), uplo, alpha, Matrixx, MatrixA )
}

Syr2<-function( uplo, alpha, Matrixx, Matrixy, MatrixA){
  .Call( paste0("syr2", getSuffix(MatrixA)), uplo, alpha, Matrixx, Matrixy,
         MatrixA )
}

Trmv<-function( uplo, orientation, diagUnit, MatrixA, Matrixx){
  .Call( paste0("trmv", getSuffix(MatrixA)), uplo, orientation, diagUnit,
         MatrixA, Matrixx)
}

Trr<-function( uplo, alpha, Matrixx, Matrixy, MatrixA){
  .Call( paste0("trr", getSuffix(MatrixA)), uplo, alpha, Matrixx, Matrixy,
         MatrixA )
}

Trr2<-function( uplo, alpha, MatrixX, MatrixY, MatrixA){
  .Call( paste0("trr2", getSuffix(MatrixA)), uplo, alpha, MatrixX, MatrixY,
         MatrixA )
}

Trsv<-function( uplo, orientation, diagUnit, MatrixA, Matrixx){
  .Call( paste0("trsv", getSuffix(MatrixA)), uplo, orientation, diagUnit,
         MatrixA, Matrixx)
}



#-------------
# Blas Level 3
#-------------

Gemm<-function( orientationA="NORMAL", orientationB="NORMAL", alpha, MatrixA,
                MatrixB, beta, MatrixC){
  .Call( paste0("gemm", getSuffix(MatrixA)),orientationA, orientationB, alpha,
         MatrixA, MatrixB, beta, MatrixC)
}

GemmX<-function( orientationA="NORMAL", orientationB="NORMAL", alpha, MatrixA,
                MatrixB, beta, MatrixC, algorithm){
  .Call( paste0("gemm", getSuffix(MatrixA)),orientationA, orientationB, alpha,
         MatrixA, MatrixB, beta, MatrixC, algorithm )
}

MultiShiftQuasiTrsm<-function( side, uplo, orientationA, alpha, MatrixA,
                               MatrixShifts, MatrixB ){
  .Call( paste0("multiShiftQuasiTrsm", getSuffix(MatrixA)), side, uplo,
         orientationA, alpha, MatrixA, MatrixShifts, MatrixB )
}

MultiShiftTrsm<-function( side, uplo, orientationA, alpha, MatrixA,
                          MatrixShifts, MatrixB ){
  .Call( paste0("multiShiftTrsm", getSuffix(MatrixA)), side, uplo,
         orientationA, alpha, MatrixA, MatrixShifts, MatrixB )
}

QuasiTrsm<-function( side, uplo, orientationA, alpha, MatrixA, MatrixB ){
  .Call( paste0("quasiTrsm", getSuffix(MatrixA)), side, uplo,
         orientationA, alpha, MatrixA, MatrixB )
}

Symm<-function( side, uplo, alpha, MatrixA, MatrixB, beta, MatrixC){
  .Call( paste0("symm", getSuffix(MatrixA)), side, uplo, alpha, MatrixA,
         MatrixB, beta, MatrixC )
}

Syrk<-function( uplo, orientation, alpha, MatrixA, beta, MatrixC){
  .Call( paste0("syrk", getSuffix(MatrixA)), uplo, orientation, alpha, MatrixA,
         beta, MatrixC )
}

Syr2k<-function( uplo, orientation, alpha, MatrixA, MatrixB, beta, MatrixC){
  .Call( paste0("syr2k", getSuffix(MatrixA)), uplo, orientation, alpha, MatrixA,
         MatrixB, beta, MatrixC )
}

Trdtrmm<-function( uplo, MatrixA){
  .Call( paste0("trdtrmm", getSuffix(MatrixA)), uplo, MatrixA )
}

TrdtrmmQuasi<-function( uplo, MatrixA, MatrixDOff ){
  .Call( paste0("trdtrmmQuasi", getSuffix(MatrixA)), uplo, MatrixA, MatrixDOff )
}

Trmm<-function( side, uplo, orientationA, diagUnit, alpha, MatrixA, MatrixB ){
  .Call( paste0("trmm", getSuffix(MatrixA)), side, uplo, orientationA, diagUnit,
         alpha, MatrixA, MatrixB )
}

Trrk<-function( uplo, orientationA, orientationB, alpha, MatrixA, MatrixB, beta,
                MatrixC ){
  .Call( paste0("trrk", getSuffix(MatrixA)), uplo, orientationA, orientationB,
         alpha, MatrixA, MatrixB, beta, MatrixC )
}

Trr2k<-function( uplo, orientationA, orientationB, orientationC, orientationD,
                 alpha, MatrixA, MatrixB, MatrixC, MatrixD, beta, MatrixE ){
  .Call( paste0("trr2k", getSuffix(MatrixA)), uplo, orientationA, orientationB,
         orientationC, orientationD, alpha, MatrixA, MatrixB, MatrixC, MatrixD,
         beta, MatrixE )
}

Trsm<-function( side, uplo, orientationA, diagUnit, alpha, MatrixA, MatrixB ){
  .Call( paste0("trsm", getSuffix(MatrixA)), side, uplo, orientationA, diagUnit,
         alpha, MatrixA, MatrixB )
}

Trstrm<-function( side, uplo, orientationA, diagUnit, alpha, MatrixA, MatrixB ){
  .Call( paste0("trstrm", getSuffix(MatrixA)), side, uplo, orientationA,
         diagUnit, alpha, MatrixA, MatrixB )
}

Trtrmm<-function( uplo, MatrixA ){
  .Call( paste0("trtrmm", getSuffix(MatrixA)), uplo, MatrixA )
}

TwoSidedTrmm<-function( uplo, diagUnit, MatrixA, MatrixB ){
  .Call( paste0("twoSidedTrmm", getSuffix(MatrixA)), uplo, diagUnit, MatrixA,
         MatrixB )
}

TwoSidedTrsm<-function( uplo, diagUnit, MatrixA, MatrixB ){
  .Call( paste0("twoSidedTrsm", getSuffix(MatrixA)), uplo, diagUnit, MatrixA,
         MatrixB )
}


#----------
# Lapack
#----------

#---------
# Spectral
#---------

HermitianEig<-function(Uplo, MatrixA, EigenValues, Sort){
  .Call( paste0("hermitianEig", getSuffix(MatrixA)), Uplo, MatrixA,
        EigenValues, Sort )
}

HermitianEigPair<-function(Uplo, MatrixA, EigenValues, EigenVectors, Sort){
  .Call( paste0("hermitianEigPair", getSuffix(MatrixA)) , Uplo, MatrixA,
        EigenValues, EigenVectors, Sort )
}

HermitianEigPartial<-function(Uplo, MatrixA, EigenValues, Sort, From, To){
  .Call( paste0("hermitianEigPartial", getSuffix(MatrixA)), Uplo, MatrixA,
        EigenValues, Sort, From, To )
}

HermitianEigPairPartial<-function(Uplo, MatrixA, EigenValues, Sort, Frotm, TO){
  .Call( paste0("hermitianEigPartial", getSuffix(MatrixA)), Uplo, MatrixA,
        EigenValues, Sort, From, To )
}

Polar<-function(MatrixA){
  .Call( paste0("polar", getSuffix(MatrixA)), MatrixA )
}

HermitianPolar<-function(Uplo, Matrix){
  .Call( paste0("polar", getSuffix(MatrixA)), Uplo,  MatrixA )
}

PolarDecomp<-function(MatrixA, MatrixP){
  .Call( paste0("polarDecomp", getSuffix(MatrixA)), MatrixA, MatrixP )
}

HermitianPolarDecomp<-function(Uplo, MatrixA, MatrixP){
  .Call( paste0("hermitianpolarDecomp", getSuffix(MatrixA)), Uplo, MatrixA,
         MatrixP )
}

Schur<-function( MatrixA, Matrixw, isFullTriangle){
  .Call( paste("schur", getSuffix(MatrixA)), MatrixA, Matrixw,
        isFullTriangle )
}

SchurDecomp<-function( MatrixA, Matrixw, MatrixQ, isFullTriangle){
  .Call( paste("schurDecomp", getSuffix(MatrixA)), MatrixA, Matrixw,
        MatrixQ, isFullTriangle )
}

SingularValues<-function( MatrixA, Matrixs){
  .Call( paste0("singularValues", getSuffix(MatrixA)), MatrixA, Matrixs )
}

SVD<-function( MatrixA, Matrixs, MatrixV){
  .Call( paste0("sVD", getSuffix(MatrixA)), MatrixA, Matrixs, MatrixV )
}

#--------
# Solvers
#--------

GaussianElimination<-function( MatrixA, MatrixB ){
  .Call( paste0("gaussianElimination", getSuffix(MatrixA)), MatrixA, MatrixB )
}

GLM<-function( MatrixA, MatrixB, MatrixD, MatrixY ){
  .Call( paste0("gLM", getSuffix(MatrixA)), MatrixA, MatrixB, MatrixD, MatrixY )
}

HermitianSolve<-function( uplo, orientation, MatrixA, MatrixB ){
  .Call( paste0("hermitianSolve", getSuffix(MatrixA)), uplo, orientation,
         MatrixA, MatrixB )
}

HPDSolve<-function( uplo, orientation, MatrixA, MatrixB ){
  .Call( paste0("hPDSolve", getSuffix(MatrixA)), uplo, orientation, MatrixA,
         MatrixB )
}

LeastSquares<-function( orientation, MatrixA, MatrixB, MatrixX ){
  .Call( paste0("leastSquares", getSuffix(MatrixA)), orientation, MatrixA,
         MatrixB, MatrixX )
}

LSE<-function( orientation, MatrixA, MatrixB, MatrixC, MatrixD, MatrixX ){
  .Call( paste0("lSE", getSuffix(MatrixA)), orientation, MatrixA, MatrixB,
         MatrixC, MatrixD, MatrixX )
}

MultiShiftHessSolve<-function( uplo, orientation, alpha, MatrixH, MatrixShifts,
                               MatrixX ){
  .Call( paste0("multiShiftHessSolve", getSuffix(MatrixH)), uplo, orientation,
         MatrixH, MatrixShifts, MatrixX )
}

Ridge<-function( MatrixA, MatrixB, alpha, MatrixX, algorithm){
  .Call( paste0("ridge", getSuffix(MatrixA)), MatrixA, MatrixB, alpha, MatrixX,
         algorithm )
}

SymmetricSolve<-function( uplo, orientation, MatrixA, MatrixB ){
  .Call( paste0("symmetricSolve", getSuffix(MatrixA)), uplo, orientation,
         MatrixA, MatrixB )
}

Tikhonov<-function( MatrixA, MatrixB, gamma, MatrixX, algorithm){
  .Call( paste0("tikhonov", getSuffix(MatrixA)), MatrixA, MatrixB, gamma,
         MatrixX, algorithm )
}

#----------------------
# Matrix Factorizations
#----------------------

Cholesky<-function(uplo, MatrixA){
  .Call( paste0("cholesky", getSuffix(MatrixA)), uplo, MatrixA )
}

SolveAfterCholesky<-function(uplo, orientation, MatrixA, MatrixB){
  .Call( paste0("solveAfterCholesky", getSuffix(MatrixA)), uplo, orientation,
         MatrixA, MatrixB )
}

ReverseCholesky<-function(uplo, MatrixA){
  .Call( paste0("reverseCholesky", getSuffix(MatrixA)), uplo, MatrixA )
}

CholeskyPiv<-function(uplo, MatrixA, MatrixP){
  .Call( paste0("choleskyPiv", getSuffix(MatrixA)), uplo, MatrixA, MatrixP )
}

SolveAfterCholeskyFullPiv<-function(uplo, orientation, MatrixA, MatrixP,
                                    MatrixB){
  .Call( paste0("solveAfterCholeskyFullPiv", getSuffix(MatrixA)), uplo,
         orientation, MatrixA, MatrixP, MatrixB )
}

CholeskyMod<-function(uplo, MatrixT, alpha, MatrixV){
  .Call( paste0("choleskyMod", getSuffix(MatrixT)), uplo, MatrixT, alpha, MatrixV )
}

HPSDCholesky<-function(uplo, MatrixA){
  .Call( paste0("hPSDCholesky", getSuffix(MatrixA)), uplo, MatrixA )
}

LDL<-function(MatrixA){
  .Call( paste0("lDL", getSuffix(MatrixA)), MatrixA )
}

LDLPiv<-function(MatrixA, MatrixdSub, Matrixp, pivotType){
  .Call( paste0("lDLPiv", getSuffix(MatrixA)), MatrixA, MatrixdSub, Matrixp,
         pivotType )
}

InertiaAfterLDL<-function(Matrixd, MatrixdSub){
  .Call( paste0("inertiaAfterLDL", getSuffix(Matrixd)), Matrixd, MatrixdSub )
}

SolveAfterLDL<-function(MatrixA, MatrixB){
  .Call( paste0("solveAfterLDL", getSuffix(MatrixA)), MatrixA, MatrixB )
}

SolveAfterLDLPiv<-function(MatrixA, MatrixdSub, Matrixp,MatrixB){
  .Call( paste0("solveAfterLDLPiv", getSuffix(MatrixA)), MatrixA, MatrixdSub,
         Matrixp, MatrixB )
}

SolveAfterLDL<-function(MatrixA, MatrixB){
  .Call( paste0("solveAfterLDL", getSuffix(MatrixA)), MatrixA, MatrixB )
}

MultiplyAfterLDL<-function(MatrixA, MatrixB){
  .Call( paste0("multiplyAfterLDL", getSuffix(MatrixA)), MatrixA, MatrixB )
}

MultiplyAfterLDLPiv<-function(MatrixA, MatrixdSub, Matrixp,MatrixB){
  .Call( paste0("multiplyAfterLDLPiv", getSuffix(MatrixA)), MatrixA, MatrixdSub,
         Matrixp, MatrixB )
}

LU<-function(MatrixA){
  .Call( paste0("lU", getSuffix(MatrixA)), MatrixA )
}

SolveAfterLU<-function(orientation, MatrixA, MatrixB){
  .Call( paste0("solveAfterLU", getSuffix(MatrixA)), orientation, MatrixA,
         MatrixB )
}


LUPartialPiv<-function( MatrixA,  Matrixp){
  .Call( paste0("lUPartialPiv", getSuffix(MatrixA)), MatrixA, Matrixp )
}

SolveAfterLUPartialPiv<-function(orientation, MatrixA, Matrixp, MatrixB){
  .Call( paste0("solveAfterLUPartialPiv", getSuffix(MatrixA)), orientation,
         MatrixA, Matrixp, MatrixB )
}

LUFullPiv<-function( MatrixA,  Matrixp, Matrixq){
  .Call( paste0("luFullPiv", getSuffix(MatrixA)), MatrixA, Matrixp, Matrixq )
}

SolveAfterLUFullPiv<-function(orientation, MatrixA, Matrixp, Matrixq, MatrixB){
  .Call( paste0("solveAfterLUPartialPiv", getSuffix(MatrixA)), orientation,
         MatrixA, Matrixp, Matrixq, MatrixB )
}

LUMod<-function(MatrixA, Matrixp, Matrixu, Matrixv, tau){
  .Call( paste0("luPartialPiv", getSuffix(MatrixA)), MatrixA, Matrixp,
         Matrixu, Matrixv, tau )
}

LQ<-function(MatrixA, Matrixt, Matrixd){
  .Call( paste0("lQ", getSuffix(MatrixA)), MatrixA, Matrixt, Matrixd )
}

LQExplicit<-function(MatrixL, MatrixA){
  .Call( paste0("lQExplicit", getSuffix(MatrixA)), MatrixL, MatrixA )
}

LQExplicitTriang<-function( MatrixA ){
  .Call( paste0("lQExplicitTriang", getSuffix(MatrixA)), MatrixA )
}

LQExplicitUnitary<-function( MatrixA ){
  .Call( paste0("lQExplicitUnitary", getSuffix(MatrixA)), MatrixA )
}

ApplyQAfterLQ<-function( side, orientation, MatrixA, Matrixt, Matrixd,
                         MatrixB ){
  .Call( paste0("applyQAfterLQ", getSuffix(MatrixA)), side, orientation,
         MatrixA, Matrixt, Matrixd, MatrixB )
}

SolveQAfterLQ<-function( orientation, MatrixA, Matrixt, Matrixd, MatrixB,
                         MatrixX ){
  .Call( paste0("applyQAfterLQ", getSuffix(MatrixA)), orientation, MatrixA,
         Matrixt, Matrixd, MatrixB, MatrixX )
}

QR<-function( MatrixA, Matrixt, Matrixd ){
  .Call( paste0("qR", getSuffix(MatrixA)), MatrixA, Matrixt, Matrixd )
}

QRColPiv<-function( MatrixA, Matrixt, Matrixd, Matrixp ){
  .Call( paste0("qRColPiv", getSuffix(MatrixA)), MatrixA, Matrixt, Matrixd,
         Matrixp )
}

QRExplicitTriang<-function( MatrixA ){
  .Call( paste0("qRExplicitTriang", getSuffix(MatrixA)), MatrixA )
}

QRExplicitUnitary<-function( MatrixA ){
  .Call( paste0("qRExplicitUnitary", getSuffix(MatrixA)), MatrixA )
}

QRColPivExplicit<-function( MatrixA, MatrixR, Matrixp ){
  .Call( paste0("qRColPivExplicit", getSuffix(MatrixA)), MatrixA, MatrixR,
         Matrixp )
}

CholeskyQR<-function( MatrixA, MatrixR ){
  .Call( paste0("choleskyQR", getSuffix(MatrixA)), MatrixA, MatrixR )
}

ApplyQAfterQR<-function( side, orientation, MatrixA, Matrixt, Matrixd,
                         MatrixB ){
  .Call( paste0("ApplyQAfterQR", getSuffix(MatrixA)), side, orientation,
         MatrixA, Matrixt, Matrixd, MatrixB)
}

SolveQAfterQR<-function( orientation, MatrixA, Matrixt, Matrixd, MatrixB,
                        MatrixX ){
  .Call( paste0("solveQAfterQR", getSuffix(MatrixA)), orientation, MatrixA,
         Matrixt, Matrixd, MatrixB, MatrixX )
}



RQ<-function( MatrixA, Matrixt, Matrixd ){
  .Call( paste0("rQ", getSuffix(MatrixA)), MatrixA, Matrixt, Matrixd )
}

RQExplicitTriang<-function( MatrixA ){
  .Call( paste0("rQExplicitTriang", getSuffix(MatrixA)), MatrixA )
}

ApplyQAfterRQ<-function( side, orientation, MatrixA, Matrixt, Matrixd,
                         MatrixB ){
  .Call( paste0("ApplyQAfterRQ", getSuffix(MatrixA)), side, orientation,
         MatrixA, Matrixt, Matrixd, MatrixB)
}

SolveQAfterRQ<-function( orientation, MatrixA, Matrixt, Matrixd, MatrixB,
                        MatrixX ){
  .Call( paste0("solveQAfterRQ", getSuffix(MatrixA)), orientation, MatrixA,
         Matrixt, Matrixd, MatrixB, MatrixX )
}

GQR<-function( MatrixA, MatrixtA, MatrixB, Matrixtb, MatrixdB){
  .Call( paste0("gQR", getSuffix(MatrixA)), MatrixA, MatrixtA, MatrixB,
         Matrixtb, MatrixdB )
}

GQRExplicitTriang<-function( MatrixA, MatrixB){
  .Call( paste0("gQRExplicitTriang", getSuffix(MatrixA)), MatrixA, MatrixB )
}

GRQ<-function( MatrixA, MatrixtA, MatrixB, Matrixtb, MatrixdB){
  .Call( paste0("gRQ", getSuffix(MatrixA)), MatrixA, MatrixtA, MatrixB,
         Matrixtb, MatrixdB )
}

GRQExplicitTriang<-function( MatrixA, MatrixB){
  .Call( paste0("gRQExplicitTriang", getSuffix(MatrixA)), MatrixA, MatrixB )
}


#--------------------
# I/O functions
#-------------------

Print<-function(MatrixA,Title=""){
  .Call( paste0("print", getSuffix(MatrixA)), MatrixA, as.character(Title) )
}

Display<-function(MatrixA, Title=""){
  .Call( paste0("display", getSuffix(MatrixA)), MatrixA, as.character(Title) )
}

Read<-function(MatrixA, filename, format="ASCII", doSequential=FALSE){
  if(isDistMatrix(MatrixA)==TRUE){
    .Call( paste0("read", getSuffix(MatrixA)), MatrixA, as.character(filename),
          as.character(format), doSequential )
  }
  else{
    .Call( paste0("read", getSuffix(MatrixA)), MatrixA, as.character(filename),
          as.character(format) )
  }
}

Write<-function(MatrixA, basename, format, title){
  .Call( paste0("write", getSuffix(MatrixA)), MatrixA, as.character(basename),
        as.character(format), as.character(title) )
}

#Debug Matrices:

matA<-Matrix()
Uniform(matA,4,4)
matAL<-Matrix()
matAR<-Matrix()

matB<-Matrix()
Uniform(matB,4,4)
matC<-Matrix()
Uniform(matC,4,4)


vecX<-Matrix()
Uniform(vecX,4,1)

vecY<-Matrix()
Uniform(vecY,4,1)

matR<-runif(10)
matE<-Matrix()
MatrixResize(matE,2,5)
