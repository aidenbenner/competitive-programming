

function matrixStringtoMatr(eqnStrArr){
  var rows = eqnStrArr.length;
  var cols = eqnStrArr[0].split(" ").length; 

  var matrix = [];
  for(var i = 0; i<rows; i++){
    var colStrs = eqnStrArr[i].split(",");
    var rowCol = [];
    if(colStrs.length != cols) continue;
    for(var k = 0; k<colStrs.length;k++){
      rowCol.push(parseFloat(colStrs[k]));;
    }
    matrix.push(rowCol);
  }
  return matrix;
}


var N = gets(); 
var strs[N]; 

for(var i = 0; i<N; i++){
  strs[i] = gets();
}

var matr = matrixStringtoMatr(strs); 
var det = gaussianElim(matrix,true);

prints(det); 











function rowMult(matrix, row, c){
  for(var i = 0; i<matrix[row].length; i++ ){
    matrix[row][i] = matrix[row][i] * c; 
  }
}

//adds rowB * c = rowA
function addMult(matrix,rowA,rowB,c){
  for(var i = 0; i<matrix[rowA].length; i++){
    matrix[rowA][i] = matrix[rowA][i] + c * matrix[rowB][i];
  }
}

function interchange(matrix, rowA,rowB){
  for(var i = 0; i<matrix[rowA].length; i++){
    var hold = matrix[rowA][i];
    matrix[rowA][i] = matrix[rowB][i];
    matrix[rowB][i] = hold;
  }
}

//[rows][cols]
function gaussianElim(matrix){
  gaussianElim(matrix, false, false,false);
}

function gaussianElim(matrix, findDet){
  gaussianElim(matrix, findDet, false,false);
}

function solveAugmented(matrix){
  gaussianElim(matrix,false,false,true);
}

function getIdentity(row, col){
  var identity = [];
  for(var i = 0; i<row; i++){
    var rowArr = [];
    for(var k = 0; k<row; k++){
      if(i == k)
        rowArr.push(1);
      else 
        rowArr.push(0);
    }
    identity.push(rowArr);
  }
  return identity;
}

function gaussianElim(matrix, findDet, findInverse, isAugmented) {
  var cols = matrix[0].length;
  if(isAugmented != undefined) cols--; 
  console.log(findDet);
  var rows = matrix.length;
  var pivotInd = 0; 
  var det = 1; 
  var identity;
  if(findInverse != false || findDet != false){
    if(rows != cols){
      return null;
    }
    identity = getIdentity(rows,cols);
  }
  for(var i = 0; i<cols; i++){
    //reduce each column so we only have 1 as a pivot and all zeroes
    for(var k = pivotInd; k<rows; k++){
      if(matrix[k][i] != 0){
        //we found a non zero value in this column.
        //swap it to the row of the pivot we're working on 
        if(pivotInd != k){ 
          interchange(matrix, pivotInd, k);
          if(findInverse){
            interchange(identity, pivotInd, k);
          }
          det = det * -1;
        }
        //reduce this row to 1 
        var leadingVal = matrix[pivotInd][k];
        rowMult(matrix, pivotInd, 1/leadingVal);
        if(findInverse){
          rowMult(identity, pivotInd, 1/leadingVal);
        }
        det = det * leadingVal;

        //now elminate values in other rows
        for(var z = 0; z<rows; z++){
          if(z == pivotInd) continue;
          leadingVal = matrix[z][i];
          if(leadingVal!=0){
            addMult(matrix,z,pivotInd,-leadingVal);
            if(findInverse)
              addMult(identity,z,pivotInd,-leadingVal);
          }  
        }
        pivotInd++;
        break;
      }
    }
  }
  //multiply det 
  for(var i = 0; i<cols; i++){
    for(var k = 0; k<rows; k++){
      if(i != k) continue;
      det *= matrix[i][k];
    }
  }

  if(findInverse){
    if(det == 0){
      return null
    }
    return identity; 
  }
  if(findDet){
    return det;
  }
}

