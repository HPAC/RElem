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
  .Call( paste0("newMatrix_",dataType) )
}



#---------------------
# Distributed Matrices
#---------------------

DistMatrix<-function(Grid, dataType="d"){
  .Call( paste0("newDistMatrix_",dataType), Grid, dataType )
}

DistMatrixSpecific<-function(ColDist, RowDist, Grid, dataType="d"){
  .Call( paste0("newDistMatrixSpecific_", dataType), as.character(ColDist),
         as.character(RowDist), Grid )
}
ShowDistData<-function(DistMatrixA){
  .Call( paste0("showDistData_", getType(DistMatrixA)), DistMatrixA)
}

#-------------------------
# Common Matrix Properties
#-------------------------

MatrixGet<-function(MatrixA, i, j){
  .Call( paste0("get", getElement(MatrixA)), MatrixA,
         as.integer(i),as.integer(j) )
} 

MatrixSet<-function(MatrixA, i, j){
  .Call( paste0("set", getElement(MatrixA)), MatrixA,
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

#attach and locked attach are different



#------------------
# Matrix generators
#------------------

Diagonal<-function(MatrixA, dSize, buffer){
  .Call( paste0("diagonal", getSuffix(MatrixA)), MatrixA, as.integer(dSize),
         buffer )
}

Uniform<-function(MatrixA, rows, cols, center=0.0, radius=1.0){
  .Call( paste0("uniform", getSuffix(MatrixA)), MatrixA, as.integer(rows),
         as.integer(cols), center, radius )
}

Identity<-function(MatrixA, rows, cols){
  .Call( paste0("identity", getSuffix(MatrixA)), MatrixA, as.integer(rows),
         as.integer(cols))
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
  .Call( paste0("symm", getSuffix(MatrixA)), uplo, orientation, alpha, MatrixA,
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

#
# Solvers
#

GaussianElimination<-function( MatrixA, MatrixB){
  .Call( paste0("gaussianElimination", getSuffix(MatrixA)), MatrixA, MatrixB )
}

GLM<-function( MatrixA, MatrixB, MatrixD, MatrixY){
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
matB<-Matrix()
Uniform(matB,4,4)
matC<-Matrix()
Uniform(matC,4,4)


vecX<-Matrix()
Uniform(vecX,4,1)

vecY<-Matrix()
Uniform(vecY,4,1)
