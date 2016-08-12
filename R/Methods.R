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

read.table.dist <- function(name){
        ans <- DistMatrix()
        Read(ans, name)
        ans
        } 
