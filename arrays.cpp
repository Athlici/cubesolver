unsigned char centermove[36][24] =  {   {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,19,16,17,18,20,21,22,23},
                                        {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,18,19,16,17,20,21,22,23},
                                        {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,17,18,19,16,20,21,22,23},
                                        {12,1,2,15,0,5,6,3,4,9,10,7,8,13,14,11,16,17,18,19,20,21,22,23},
                                        {8,1,2,11,12,5,6,15,0,9,10,3,4,13,14,7,16,17,18,19,20,21,22,23},
                                        {4,1,2,7,8,5,6,11,12,9,10,15,0,13,14,3,16,17,18,19,20,21,22,23},
                                        {0,13,14,3,4,1,2,7,8,5,6,11,12,9,10,15,16,17,18,19,20,21,22,23},
                                        {0,9,10,3,4,13,14,7,8,1,2,11,12,5,6,15,16,17,18,19,20,21,22,23},
                                        {0,5,6,3,4,9,10,7,8,13,14,11,12,1,2,15,16,17,18,19,20,21,22,23},
                                        {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,21,22,23,20},
                                        {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,22,23,20,21},
                                        {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,23,20,21,22},
                                        {0,1,2,3,4,5,6,7,8,9,10,11,15,12,13,14,16,17,18,19,20,21,22,23},
                                        {0,1,2,3,4,5,6,7,8,9,10,11,14,15,12,13,16,17,18,19,20,21,22,23},
                                        {0,1,2,3,4,5,6,7,8,9,10,11,13,14,15,12,16,17,18,19,20,21,22,23},
                                        {20,21,2,3,4,5,6,7,8,9,16,17,12,13,14,15,0,1,18,19,10,11,22,23},
                                        {10,11,2,3,4,5,6,7,8,9,0,1,12,13,14,15,20,21,18,19,16,17,22,23},
                                        {16,17,2,3,4,5,6,7,8,9,20,21,12,13,14,15,10,11,18,19,0,1,22,23},
                                        {0,1,22,23,4,5,6,7,18,19,10,11,12,13,14,15,16,17,2,3,20,21,8,9},
                                        {0,1,8,9,4,5,6,7,2,3,10,11,12,13,14,15,16,17,22,23,20,21,18,19},
                                        {0,1,18,19,4,5,6,7,22,23,10,11,12,13,14,15,16,17,8,9,20,21,2,3},
                                        {0,1,2,3,5,6,7,4,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
                                        {0,1,2,3,6,7,4,5,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
                                        {0,1,2,3,7,4,5,6,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
                                        {3,0,1,2,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
                                        {2,3,0,1,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
                                        {1,2,3,0,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
                                        {0,1,2,3,23,20,6,7,8,9,10,11,12,13,17,18,16,4,5,19,15,21,22,14},
                                        {0,1,2,3,14,15,6,7,8,9,10,11,12,13,4,5,16,23,20,19,18,21,22,17},
                                        {0,1,2,3,17,18,6,7,8,9,10,11,12,13,23,20,16,14,15,19,5,21,22,4},
                                        {0,1,2,3,4,5,21,22,8,9,10,11,19,16,14,15,7,17,18,6,20,12,13,23},
                                        {0,1,2,3,4,5,12,13,8,9,10,11,6,7,14,15,22,17,18,21,20,19,16,23},
                                        {0,1,2,3,4,5,19,16,8,9,10,11,21,22,14,15,13,17,18,12,20,6,7,23},
                                        {0,1,2,3,4,5,6,7,9,10,11,8,12,13,14,15,16,17,18,19,20,21,22,23},
                                        {0,1,2,3,4,5,6,7,10,11,8,9,12,13,14,15,16,17,18,19,20,21,22,23},
                                        {0,1,2,3,4,5,6,7,11,8,9,10,12,13,14,15,16,17,18,19,20,21,22,23}};
unsigned char cornermove[36][24] =  {   {0,1,2,3,4,5,16,17,8,9,10,11,12,13,7,6,21,20,18,19,14,15,22,23},
                                        {0,1,2,3,4,5,21,20,8,9,10,11,12,13,17,16,15,14,18,19,7,6,22,23},
                                        {0,1,2,3,4,5,15,14,8,9,10,11,12,13,20,21,6,7,18,19,17,16,22,23},
                                        {10,1,2,3,4,0,6,7,5,9,8,11,12,13,14,15,16,17,18,19,20,21,22,23},
                                        {8,1,2,3,4,10,6,7,0,9,5,11,12,13,14,15,16,17,18,19,20,21,22,23},
                                        {5,1,2,3,4,8,6,7,10,9,0,11,12,13,14,15,16,17,18,19,20,21,22,23},
                                        {0,11,2,3,1,5,6,7,8,4,10,9,12,13,14,15,16,17,18,19,20,21,22,23},
                                        {0,9,2,3,11,5,6,7,8,1,10,4,12,13,14,15,16,17,18,19,20,21,22,23},
                                        {0,4,2,3,9,5,6,7,8,11,10,1,12,13,14,15,16,17,18,19,20,21,22,23},
                                        {0,1,19,18,4,5,6,7,8,9,10,11,2,3,14,15,16,17,23,22,20,21,12,13},
                                        {0,1,22,23,4,5,6,7,8,9,10,11,19,18,14,15,16,17,13,12,20,21,2,3},
                                        {0,1,12,13,4,5,6,7,8,9,10,11,22,23,14,15,16,17,3,2,20,21,19,18},
                                        {18,19,2,3,4,5,6,7,8,9,16,17,12,13,14,15,1,0,11,10,20,21,22,23},
                                        {11,10,2,3,4,5,6,7,8,9,1,0,12,13,14,15,19,18,17,16,20,21,22,23},
                                        {17,16,2,3,4,5,6,7,8,9,19,18,12,13,14,15,10,11,0,1,20,21,22,23},
                                        {0,1,23,3,4,5,6,2,8,9,10,11,12,13,14,15,16,17,18,19,20,7,22,21},
                                        {0,1,21,3,4,5,6,23,8,9,10,11,12,13,14,15,16,17,18,19,20,2,22,7},
                                        {0,1,7,3,4,5,6,21,8,9,10,11,12,13,14,15,16,17,18,19,20,23,22,2},
                                        {0,1,2,22,4,5,3,7,8,9,10,11,12,13,14,15,16,17,18,19,6,21,20,23},
                                        {0,1,2,20,4,5,22,7,8,9,10,11,12,13,14,15,16,17,18,19,3,21,6,23},
                                        {0,1,2,6,4,5,20,7,8,9,10,11,12,13,14,15,16,17,18,19,22,21,3,23},
                                        {0,1,2,3,13,12,6,7,14,15,10,11,9,8,4,5,16,17,18,19,20,21,22,23},
                                        {0,1,2,3,8,9,6,7,4,5,10,11,15,14,13,12,16,17,18,19,20,21,22,23},
                                        {0,1,2,3,14,15,6,7,13,12,10,11,5,4,8,9,16,17,18,19,20,21,22,23},
                                        {6,7,0,1,2,3,4,5,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
                                        {4,5,6,7,0,1,2,3,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
                                        {2,3,4,5,6,7,0,1,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23},
                                        {0,1,2,3,4,5,6,7,8,9,10,11,18,13,12,15,14,17,16,19,20,21,22,23},
                                        {0,1,2,3,4,5,6,7,8,9,10,11,16,13,18,15,12,17,14,19,20,21,22,23},
                                        {0,1,2,3,4,5,6,7,8,9,10,11,14,13,16,15,18,17,12,19,20,21,22,23},
                                        {0,1,2,3,4,5,6,7,8,9,10,11,12,19,14,13,16,15,18,17,20,21,22,23},
                                        {0,1,2,3,4,5,6,7,8,9,10,11,12,17,14,19,16,13,18,15,20,21,22,23},
                                        {0,1,2,3,4,5,6,7,8,9,10,11,12,15,14,17,16,19,18,13,20,21,22,23},
                                        {0,1,2,3,4,5,6,7,22,23,20,21,12,13,14,15,16,17,18,19,9,8,11,10},
                                        {0,1,2,3,4,5,6,7,11,10,9,8,12,13,14,15,16,17,18,19,23,22,21,20},
                                        {0,1,2,3,4,5,6,7,21,20,23,22,12,13,14,15,16,17,18,19,10,11,8,9}};
unsigned char edgemove[18][24] =  {     {22,23,21,3,4,5,6,7,8,2,0,1,10,9,11,15,16,17,18,19,20,13,12,14},
                                        {12,14,13,3,4,5,6,7,8,21,22,23,0,2,1,15,16,17,18,19,20,9,10,11},
                                        {10,11,9,3,4,5,6,7,8,13,12,14,22,21,23,15,16,17,18,19,20,2,0,1},
                                        {0,1,2,20,18,19,4,5,3,9,10,11,12,13,14,8,6,7,16,17,15,21,22,23},
                                        {0,1,2,15,16,17,18,19,20,9,10,11,12,13,14,3,4,5,6,7,8,21,22,23},
                                        {0,1,2,8,6,7,16,17,15,9,10,11,12,13,14,20,18,19,4,5,3,21,22,23},
                                        {5,3,4,19,20,18,6,7,8,9,10,11,12,13,14,15,16,17,23,21,22,1,2,0},
                                        {18,19,20,21,22,23,6,7,8,9,10,11,12,13,14,15,16,17,0,1,2,3,4,5},
                                        {23,21,22,1,2,0,6,7,8,9,10,11,12,13,14,15,16,17,5,3,4,19,20,18},
                                        {0,1,2,3,4,5,17,15,16,7,8,6,11,10,9,14,13,12,18,19,20,21,22,23},
                                        {0,1,2,3,4,5,12,14,13,15,16,17,6,8,7,9,10,11,18,19,20,21,22,23},
                                        {0,1,2,3,4,5,11,9,10,14,13,12,17,16,15,7,8,6,18,19,20,21,22,23},
                                        {9,10,11,0,1,2,3,4,5,6,7,8,12,13,14,15,16,17,18,19,20,21,22,23},
                                        {6,7,8,9,10,11,0,1,2,3,4,5,12,13,14,15,16,17,18,19,20,21,22,23},
                                        {3,4,5,6,7,8,9,10,11,0,1,2,12,13,14,15,16,17,18,19,20,21,22,23},
                                        {0,1,2,3,4,5,6,7,8,9,10,11,15,17,16,18,19,20,21,22,23,12,14,13},
                                        {0,1,2,3,4,5,6,7,8,9,10,11,18,20,19,21,22,23,12,14,13,15,16,17},
                                        {0,1,2,3,4,5,6,7,8,9,10,11,21,23,22,12,14,13,15,16,17,18,19,20}};
unsigned char cornerturn[23][24];
unsigned char edgeturn[23][24];
unsigned char centerturn[23][24];
