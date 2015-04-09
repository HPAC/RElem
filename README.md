#R-El

This R package links R and the dense linear algebra library
[Elemental](http://www.libelemental.org), providing Elemental functionality in
R.  It is based on the C-interface included in Elemental v0.85 and on-wards.

##Functionality

At the moment the coverage of the interface is limited to **double
precision (real and complex)**. The following routines are included in this package:

* Core and MPI routines
* Sequential Matrices
* Distributed Matrices
* Grids
* BLAS-like
    * Level 1
    * Level 2
    * Level 3
* LAPACK-like
    * Matrix Factorizations
    * Spectral Decomposition
    * Solvers
* Matrix Generators
* LibFLAME-like
    * Partition
    * Merge
    * Repartition (_Not yet active in El headers_)
    * Slide Partition (_Not yet active in El headers_)
* I/O routines
  


## Installation

The installation of the R-El interface requires two steps:

#### 1. Install Elemental
- [Install Elemental](http://libelemental.org/documentation/dev/build.html) as a shared library
- Ideally, Elemental is installed in one of the default paths `/usr/local`, `$HOME/local`, `$HOME/.local`

#### 2. Install R-Elemental
We have plans to make R-El available in R's package manager CRAN in the future.  So far, **a
superuser** can install the interface from R as follows:

A zip file from the package can be downloaded from our [releases](https://github.com/rocanale/R-Elemental/releases) and then installed using the following command:

`R CMD INSTALL R-Elemental.zip`

If Elemental was installed in a custom path, the installation command is:

`R CMD INSTALL R-Elemental.zip --configure-args=--with-ElPrefix=/YOUR/PREFIX`

##### Installing the development version

Alternatively, it is possible to install the development branch of this library using devtools from an R session as follows:

```s
install.packages("devtools")
library(devtools)
install_github('rocanale/R-Elemental')
```

In case Elemental is installed in a custom installation path, the path should be provided as follows:
```s
options(devtools.install.args='--configure-args=--with-ElPrefix=/YOUR/PREFIX')
install_github('rocanale/R-Elemental')
```

## Programming Approach

R-El consists of two layers:

* A C-layer (`src` folder) that wraps Elemental's C-layer in R-friendly
functions in terms of `SEXP` objects (native R data-type), and
* An R-layer (`R/RElem.R`) that provides the user-interface in R, including
functions classes, etc.

### Pointers

Pointers to Elemental objects (such as `Matrix`, `DistMatrix`, or `Grid`) are
treated as R external pointers and are cast to the appropriate pointer type in
the C-layer.  This type-cast was not possible in a pure R-implementation.

### Return Values

For Elemental functions with return values, instead of passing a pointer to R,
the C-layer creates a corresponding R-object.

### Enum values

Enum types are replaced by strings and mapped to the corresponding Elemental
enums in the C-layer.  The passed strings take the same values as the Elemental
enum constants, while the `EL_` prefix is dropped.

### Naming Conventions

In contrast to the C-interface, R-El's functions are datatype-independent, like
Elemental's C++ interface.  Mapping to the corresponding C-interface functions
is based on the class-names of the passed R objects.

### Extra Features

* We recreate C++-like class methods through accessor methods in R.  These methods are for example invoked like `A$Width()`, replacing C++'s `.` with `$`.
* To make use of R's garbage collection, every time a matrix is overwritten or not used anymore, R will call the corresponding destructor, freeing the memory.
* As in the current python-interface, Matrix accesses by indices return matrix `View`s.

## Examples

### Runtime

For distributed computations, R needs to be invoked by MPI as follows:

`mpiexec -n 4 R --no-readline --slave --quiet --vanilla -f SimpleDist.R`

Note: The openmpi library (or the one installed in the system) must be preloaded using the `LD_PRELOAD` environment variable:

`export LD_PRELOAD=/usr/lib/libmpi.so:$LD_PRELOAD`

### Source

The following example invokes `Gemm` with distributed matrices

```s
# Load the library
library(RElem)

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
