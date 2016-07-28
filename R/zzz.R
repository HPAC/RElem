.onLoad <- function(library = find.package("RElem"), package = "RElem"){
        Initialize()       
}

.onDetach <- function(library = find.package("RElem"), package = "RElem"){
         cat("MPI finalized")
         Finalize()
}
