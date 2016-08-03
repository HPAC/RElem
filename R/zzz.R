.onLoad <- function(libname = find.package("RElem"), pkgname = "RElem"){
        Initialize()       
}

.onDetach <- function(libpath = find.package("RElem")){
         cat("MPI finalized")
         Finalize()
}
