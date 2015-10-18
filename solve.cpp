bool solve(cube Cube, uint8_t rdepth, uint8_t t){
  if(rdepth>0){
    if(rdepth>=minDepth(Cube)){
      for(uint8_t move=0;move<36;move++){
        cube nCube=movecube(Cube,move);
    if(solve(nCube,rdepth-1,t)){
      solution[t][rdepth-1]=move;
      return true;
    }
      }
    }
    return false;
  }else
    return solved(Cube);
}

bool solvepar(cube Cube, uint8_t rdepth){
  future<bool> par[36];
  for(uint8_t move=0;move<36;move++){
    solution[move][rdepth-1]=move;
    cube nCube=movecube(Cube,move);
    par[move] =async(launch::async,solve,nCube,rdepth-1,move);
  }
  for(uint8_t i=0;i<36;i++)
    par[i].wait();
  bool res=false;
  for(uint8_t i=0;i<36;i++)
    if(par[i].get()){
      res=true;
      for(uint8_t j=0;j<rdepth;j++)
        cout << solution[i][j]+0 << ";";
      cout << "\n";
    }
  return res;
}
