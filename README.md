#R-El

This library does the link between R and linear algebra library
[Elemental](http://www.libelemental.org), allowing to call the Elemental
functions from R

It is created on top the C headers provided in the development version of
the Elemental library

##Functionality

By the moment, the following functions are accessible by R, most of them **only
for double precision matrices**.

* Core and MPI routines
* Sequential Matrices
* Distributed Matrices
* Grids
* Blas
    * Level 1
    * Level 2
    * Level 3
* Lapack Functions
    * Matrix Factorizations
    * Spectral Decomposition
    * Solvers
* Matrix Generators
* Flame
    * Partition
    * Merge
    * Repartition (_Not yet active in El headers_)
    * Slide Partition (_Not yet active in El headers_)
* I/O functions
  


## Installation

By the moment this development version should be installed in two steps, since it is not integrated with the Elemental's build system, the steps are the following 

#### 1. Install Elemental
-  To install this program, it is a prerequisite to [install Elemental](http://libelemental.org/documentation/dev/build.html) as a shared library

#### 2. Download and compile the R-Elemental

1. Clone this git repository
   `git clone https://github.com/rocanale/R-Elemental.git`
2. Edit the Makefile and add the corresponding paths to the built elemental library and to the R headers
3. build the library

## Package Structure

*  The C source files in this package contain the C R-callable functions

*  The file functionsObj.R loads the library and initializes the R functions

## Programming Approach

This library has two layers

  * Compiled C source, that contains functions that receive and return SEXP objects(the R native datatype), and calls the C Elemental functions.
  * An R script that creates the wrappers for those functions and adds extra functionality, like classes, shorthands, etc.

### Pointers

Most of the functions involve Matrices (Distributed and Sequential) or Grids, and they are represented in R as external pointers. In the C layer is possible to cast them to the specific pointer type to call Elemental.

### Return Values

In the cases where the native elemental function returns a value, we try to mimic the same in R, and instead of passing a pointer (like the C headers do) we allocate space and return the value in an R variable.

### Enum values

The enum values are not defined in R, but they are parsed as text values and transformed into their equivalent in C, making it transparent for the user, the names are the same as the original Elemental library, dropping the 'EL_' prefix

### Naming Conventions

The names of the functions are the same as in the Native Elemental library, and it is not necessary to call different functions when the dataypes are different, which makes it easier to code and takes less time to load the functions into R, every time a Matrix is created a class is attached to it, which contains the matrix type and the datatype

### Extra Features

  * Defining clases allows to create accessor methods in R, like A$Width() making more intuitive the use of the interface.
  * Since R has garbage collection, it was configured, that every time a matrix is overwritten or not used anymore, R must call the destroy method, freeing the memory.
  * In the on-going python interface was shown the idea to return a view of the matrix when was accessed using indices, this was also implemented in the R interface.

## Examples

### Runtime

R must be called from mpi, using the following command

`mpiexec -n 4 R --no-readline --slave --quiet --vanilla -f SimpleDist.R`

Note: it is always necessary to preload the openmpi library (or the one installed in the system) using the `LD_PRELOAD` environment variable as follows

`export LD_PRELOAD=/usr/lib/libmpi.so:$LD_PRELOAD`

### Source

This example shows how to run a Gemm with distributed matrices

```
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
```