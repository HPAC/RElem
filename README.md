#RElem

[![Build Status](https://travis-ci.org/rocanale/RElem.svg?branch=master)](https://travis-ci.org/rocanale/RElem) using Elemental v0.87.6

This R package links R and the dense linear algebra library
[Elemental](http://www.libelemental.org), providing distributed parallel
computing support in R.  It is based on the C-API included in Elemental
v0.85 and on-wards.

##Functionality

At the moment the coverage of the interface is limited to **double
precision (real and complex)**. The following routines are included in this
package: 

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
    * Optimization Models
* Matrix Generators
* LibFLAME-like
    * Partition
    * Merge
* I/O routines
  


## Installation

The installation of the RElem requires two steps:

#### 1. Install Elemental
- [Install Elemental latest release](https://github.com/elemental/Elemental/releases/tag/v0.87.6) 0.87.6
    - Elemental requires a C/C++ compiler, a fortran compiler and an MPI distribution like mpich. 
- Ideally, Elemental is installed in one of these paths `/usr/local`, `$HOME/local`, `$HOME/.local`


##### Unix Installation example

```
mkdir build
cd build
cmake \
    -D EL_DISABLE_SCALAPACK=ON \
    -D CMAKE_INSTALL_PREFIX=$HOME/local \
    -D EL_DISABLE_PARMETIS=ON \
    ..
make -j4
make install
```

*If you installed Elemental in a non default path, please be sure that libEl.so can be loaded*:

`export LD_LIBRARY_PATH=$HOME/local:$LD_LIBRARY_PATH`

#### 2. Install RElem
We have plans to make R-El available in R's package manager CRAN in the future. Nevertheless it is possible to install it manually.

A zip file from the package can be downloaded from our [releases](https://github.com/rocanale/RElem/releases) and then installed using the following command:

`R CMD INSTALL RElem.zip`

If Elemental was installed in a custom path, the installation command is:

`R CMD INSTALL RElem.zip --configure-args=--with-ElPrefix=/YOUR/PREFIX`

##### Installing the development version

Alternatively, it is possible to install the development branch of this library using devtools from an R session as follows:

```s
install.packages("devtools")
library(devtools)
install_github('rocanale/RElem')
```

In case Elemental is installed in a custom installation path, the path should be provided as follows:
```s
options(devtools.install.args='--configure-args=--with-ElPrefix=/YOUR/PREFIX')
install_github('rocanale/RElem')
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

### Simple Script

The following example invokes a matrix multiplication `GEMM` using distributed matrices

```s
# Load the library
library(RElem)

# Create the Matrices
A <- DistMatrix()
B <- DistMatrix()

#Initialize the Matrices
Uniform(A,6,4)
Uniform(B,3,4)

#Execute GEMM
C <- A%*%B

print(C)

```
