 int distances[8][8];
    int queue[64][2];
    queue[0][0] = startX;
    queue[0][1] = startY;
    for (int i = 0; i<8; i++){
        for (int j = 0; j<8; j++){
            distances[i][j] = -1;//Using -1 for infinity
        }
    }
    distances[startX][startY] = 0;
    int head = 0;
    int tail = 1;
    while(tail > head){
        int x = queue[head][0];
        int y = queue[head][1];
        head++;
        foreach ((x',y') reachable from (x,y)){
            if(distances[x'][y'] == -1){
                distances[x'][y'] = distances[x][y] + 1;
                queue[tail][0] = x';
                queue[tail][1] = y';
                tail++;
            }
        }
    }