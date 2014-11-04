bool solve(cube Cube, uint8_t rdepth){
  if(rdepth>0){
cout << "minDepth:" << minDepth(Cube)+0 << "\n";
    if(rdepth>=minDepth(Cube)){
      for(uint8_t move=0;move<36;move++){
        cube nCube=movecube(Cube,move);
	if(solve(nCube,rdepth-1)){
	  solution[rdepth]=move;
	  return true;
	}
      }
    }
  }else
    return solved(Cube);
}
