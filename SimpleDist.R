# Load the library
source("functions.R")

# Initialize Elemental/MPI
Initialize()

# Create grid
g <- Grid()

# Create the Matrices
A <- DistMatrix(g)
B <- DistMatrix(g)
C <- DistMatrix(g)

#Initialize the Matrices
Uniform(A,6,4)
Uniform(B,3,4)

MatrixResize(C,4,3)

alpha <- 1.0
beta <- 0.0

#Execute Gemm
Gemm("NORMAL", "TRANSPOSE", alpha, A, B, beta, C)

Print(C)
#Finalize El/MPI
Finalize()

